#include "command_create_bufftype.hpp"

commander::Command_create_bufftype::Command_create_bufftype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_bufftype::execute() {
	std::vector<std::string> bufftype_data = this->_controller->read_bufftype_data();

	if (!bufftype_data.empty()) {
		std::string result_message = this->_model->transaction_module()->create_bufftype(bufftype_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
