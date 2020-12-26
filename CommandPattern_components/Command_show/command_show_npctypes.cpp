#include "command_show_npctypes.hpp"

commander::Command_show_npctypes::Command_show_npctypes(model::Model* model, view::View* view) {
	this->_model 	= model;
	this->_view 	= view;
}

void commander::Command_show_npctypes::execute() {
	std::vector<std::string> npctypes_info = this->_model->info_module()->get_npctypes_info();
	this->_view->output_text(npctypes_info);
}
