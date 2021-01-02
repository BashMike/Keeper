#include "command_connect_rooms.hpp"

commander::Command_connect_rooms::Command_connect_rooms(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_connect_rooms::execute() {
	std::vector<std::string> rooms_data = this->_controller->read_rooms_data();

	if (!rooms_data.empty()) {
		view::Message_code result_message = this->_model->transaction_module()->create_rooms_connection(rooms_data);

		if (result_message != view::NO_MESSAGE) {
			this->_view->output_message(result_message);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
