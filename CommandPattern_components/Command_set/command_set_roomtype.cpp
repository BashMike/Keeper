#include "command_set_roomtype.hpp"

commander::Command_set_roomtype::Command_set_roomtype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_roomtype::execute() {
	std::vector<std::string> roomtype_data = this->_controller->read_roomtype_change_parameter_data();

	if (!roomtype_data.empty()) {
		if (roomtype_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_roomtype(roomtype_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(roomtype_data.begin()+1, roomtype_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
