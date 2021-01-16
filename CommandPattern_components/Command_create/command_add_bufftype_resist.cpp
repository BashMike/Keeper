#include "command_add_bufftype_resist.hpp"

commander::Command_add_bufftype_resist::Command_add_bufftype_resist(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_add_bufftype_resist::execute() {
	std::vector<std::string> bufftype_resist_data = this->_controller->read_bufftype_resist_data();

	if (!bufftype_resist_data.empty()) {
		std::string result_message = this->_model->transaction_module()->add_bufftype_resist(bufftype_resist_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
