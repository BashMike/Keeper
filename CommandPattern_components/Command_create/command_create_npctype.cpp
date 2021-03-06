#include "command_create_npctype.hpp"

commander::Command_create_npctype::Command_create_npctype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_npctype::execute() {
	std::vector<std::string> npctype_data = this->_controller->read_npctype_data();

	if (!npctype_data.empty()) {
		std::string result_message = this->_model->transaction_module()->create_npctype(npctype_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
