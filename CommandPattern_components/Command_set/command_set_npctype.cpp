#include "command_set_npctype.hpp"

commander::Command_set_npctype::Command_set_npctype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_npctype::execute() {
	std::vector<std::string> npctype_data = this->_controller->read_npctype_change_parameter_data();

	if (!npctype_data.empty()) {
		if (npctype_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_npctype(npctype_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(npctype_data.begin()+1, npctype_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
