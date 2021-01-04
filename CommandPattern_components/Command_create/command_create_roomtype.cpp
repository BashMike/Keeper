#include "command_create_roomtype.hpp"

commander::Command_create_roomtype::Command_create_roomtype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_roomtype::execute() {
	std::vector<std::string> roomtype_data = this->_controller->read_roomtype_data();

	if (!roomtype_data.empty()) {
		std::string result_message = this->_model->transaction_module()->create_roomtype(roomtype_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
