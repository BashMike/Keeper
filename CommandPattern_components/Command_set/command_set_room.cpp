#include "command_set_room.hpp"

commander::Command_set_room::Command_set_room(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_room::execute() {
	std::vector<std::string> room_data = this->_controller->read_room_change_parameter_data();

	if (!room_data.empty()) {
		if (room_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_room(room_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(room_data.begin()+1, room_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
