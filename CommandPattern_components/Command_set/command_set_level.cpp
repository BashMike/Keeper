#include "command_set_level.hpp"

commander::Command_set_level::Command_set_level(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_level::execute() {
	std::vector<std::string> level_data = this->_controller->read_level_change_parameter_data();

	if (!level_data.empty()) {
		if (level_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_level(level_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(level_data.begin()+1, level_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
