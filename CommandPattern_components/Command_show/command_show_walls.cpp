#include "command_show_walls.hpp"

commander::Command_show_walls::Command_show_walls(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_walls::execute() {
	std::vector<std::vector<std::string>> walls_info = this->_model->info_module()->get_walls_info();
	this->_view->output_walls_info(walls_info);
}
