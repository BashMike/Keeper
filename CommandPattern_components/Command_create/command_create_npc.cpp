#include "command_create_npc.hpp"

commander::Command_create_npc::Command_create_npc(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_npc::execute() {
	std::vector<std::string> npc_data = this->_controller->read_npc_data();

	if (!npc_data.empty()) {
		view::Message_code result_message = this->_model->transaction_module()->create_npc(npc_data);

		if (result_message != view::NO_MESSAGE) {
			this->_view->output_message(result_message);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
