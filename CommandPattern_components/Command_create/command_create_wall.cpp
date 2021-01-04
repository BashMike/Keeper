#include "command_create_wall.hpp"

commander::Command_create_wall::Command_create_wall(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_wall::execute() {
	std::vector<std::string> wall_data = this->_controller->read_wall_data();

	if (!wall_data.empty()) {
		std::string result_message = this->_model->transaction_module()->create_wall(wall_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
