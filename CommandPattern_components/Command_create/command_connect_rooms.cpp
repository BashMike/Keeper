#include "command_connect_rooms.hpp"

commander::Command_connect_rooms::Command_connect_rooms(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_connect_rooms::execute() {
	std::vector<std::string> rooms_data = this->_controller->read_rooms_data();

	if (!rooms_data.empty()) {
		std::string result_message = this->_model->transaction_module()->create_rooms_connection(rooms_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
