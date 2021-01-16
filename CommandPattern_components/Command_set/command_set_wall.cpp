#include "command_set_wall.hpp"

commander::Command_set_wall::Command_set_wall(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_wall::execute() {
	std::vector<std::string> wall_data = this->_controller->read_wall_change_parameter_data();

	if (!wall_data.empty()) {
		if (wall_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_wall(wall_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(wall_data.begin()+1, wall_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
