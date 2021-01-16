#include "command_analytics_strongest_npc.hpp"

commander::Command_analytics_strongest_npc::Command_analytics_strongest_npc(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_analytics_strongest_npc::execute() {
	std::vector<std::string> room_info = this->_controller->read_object_define_data();

	if (!room_info.empty()) {
		std::vector<std::vector<std::string>> npc_info = this->_model->analytics_module()->analytics_strongest_npc(room_info);
		this->_view->output_NPCs_info(npc_info);
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
