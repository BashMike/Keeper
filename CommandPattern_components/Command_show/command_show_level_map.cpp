#include "command_show_level_map.hpp"
#include <iostream>

commander::Command_show_level_map::Command_show_level_map(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_show_level_map::execute() {
	std::vector<std::string> level_data = this->_controller->read_object_define_data();

	if (!level_data.empty()) {
		std::vector<std::vector<std::string>> map_data = this->_model->info_module()->get_level_map(level_data);
		this->_view->output_level_map(map_data);
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
