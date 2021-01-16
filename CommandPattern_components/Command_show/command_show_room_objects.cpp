#include "command_show_room_objects.hpp"
#include <iostream>

commander::Command_show_room_objects::Command_show_room_objects(controller::Controller* controller, model::Model* model, view::View* view)
	: 	_controller(controller),
		_model(model),
		_view(view)	
{}

void commander::Command_show_room_objects::execute() {
	std::vector<std::string> room_data = this->_controller->read_object_define_data();

	if (!room_data.empty()) {
		std::vector<std::vector<std::string>> room_objects_data = this->_model->info_module()->get_room_objects(room_data);

		if (!room_objects_data.empty()) {
			this->_view->output_room_objects(room_objects_data);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
