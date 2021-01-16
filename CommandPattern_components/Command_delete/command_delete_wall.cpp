#include "command_delete_wall.hpp"

commander::Command_delete_wall::Command_delete_wall(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_delete_wall::execute() {
	std::vector<std::string> wall_data = this->_controller->read_object_define_data();

	if (!wall_data.empty()) {
		std::string result_message = this->_model->transaction_module()->delete_wall(wall_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
