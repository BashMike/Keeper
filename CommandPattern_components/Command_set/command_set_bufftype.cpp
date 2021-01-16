#include "command_set_bufftype.hpp"

commander::Command_set_bufftype::Command_set_bufftype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_bufftype::execute() {
	std::vector<std::string> bufftype_data = this->_controller->read_bufftype_change_parameter_data();

	if (!bufftype_data.empty()) {
		if (bufftype_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_bufftype(bufftype_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(bufftype_data.begin()+1, bufftype_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
