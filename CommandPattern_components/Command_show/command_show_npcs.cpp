#include "command_show_npcs.hpp"

commander::Command_show_npcs::Command_show_npcs(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_npcs::execute() {
	std::vector<std::vector<std::string>> npcs_info = this->_model->info_module()->get_NPCs_info();
	this->_view->output_NPCs_info(npcs_info);
}
