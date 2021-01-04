#include "command_create_npc.hpp"

commander::Command_create_npc::Command_create_npc(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_npc::execute() {
	std::vector<std::string> npc_data = this->_controller->read_npc_data();

	if (!npc_data.empty()) {
		std::string result_message = this->_model->transaction_module()->create_npc(npc_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
