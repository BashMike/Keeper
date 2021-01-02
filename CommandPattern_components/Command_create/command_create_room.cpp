#include "command_create_room.hpp"

commander::Command_create_room::Command_create_room(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_room::execute() {
	std::vector<std::string> room_data = this->_controller->read_room_data();

	if (!room_data.empty()) {
		view::Message_code result_message = this->_model->transaction_module()->create_room(room_data);

		if (result_message != view::NO_MESSAGE) {
			this->_view->output_message(result_message);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
