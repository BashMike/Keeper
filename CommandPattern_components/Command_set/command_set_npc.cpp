#include "command_set_npc.hpp"

commander::Command_set_npc::Command_set_npc(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_npc::execute() {
	std::vector<std::string> npc_data = this->_controller->read_npc_change_parameter_data();

	if (!npc_data.empty()) {
		if (npc_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_npc(npc_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(npc_data.begin()+1, npc_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
