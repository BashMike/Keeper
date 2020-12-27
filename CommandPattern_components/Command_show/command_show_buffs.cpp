#include "command_show_buffs.hpp"

commander::Command_show_buffs::Command_show_buffs(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_buffs::execute() {
	std::vector<std::vector<std::string>> buffs_info = this->_model->info_module()->get_buffs_info();
	this->_view->output_buffs_info(buffs_info);
}
