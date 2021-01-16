#include "command_set_item.hpp"

commander::Command_set_item::Command_set_item(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_item::execute() {
	std::vector<std::string> item_data = this->_controller->read_item_change_parameter_data();

	if (!item_data.empty()) {
		if (item_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_item(item_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(item_data.begin()+1, item_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
