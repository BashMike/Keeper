#include "command_show_levels.hpp"

commander::Command_show_levels::Command_show_levels(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_levels::execute() {
	std::vector<std::vector<std::string>> levels_info = this->_model->info_module()->get_levels_info();
	this->_view->output_id_and_name_objects(levels_info);
}
