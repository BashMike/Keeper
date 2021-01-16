#include "command_set_itemtype.hpp"

commander::Command_set_itemtype::Command_set_itemtype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_itemtype::execute() {
	std::vector<std::string> itemtype_data = this->_controller->read_itemtype_change_parameter_data();

	if (!itemtype_data.empty()) {
		if (itemtype_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_itemtype(itemtype_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(itemtype_data.begin()+1, itemtype_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
