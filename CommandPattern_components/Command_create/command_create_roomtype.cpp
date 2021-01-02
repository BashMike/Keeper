#include "command_create_roomtype.hpp"

commander::Command_create_roomtype::Command_create_roomtype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_roomtype::execute() {
	std::vector<std::string> roomtype_data = this->_controller->read_roomtype_data();

	if (!roomtype_data.empty()) {
		view::Message_code result_message = this->_model->transaction_module()->create_roomtype(roomtype_data);

		if (result_message != view::NO_MESSAGE) {
			this->_view->output_message(result_message);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
