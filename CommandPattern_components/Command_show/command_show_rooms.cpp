#include "command_show_rooms.hpp"

commander::Command_show_rooms::Command_show_rooms(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_rooms::execute() {
	std::vector<std::vector<std::string>> rooms_info = this->_model->info_module()->get_rooms_info();
	this->_view->output_rooms_info(rooms_info);
}
