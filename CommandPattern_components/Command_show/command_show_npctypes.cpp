#include "command_show_npctypes.hpp"

commander::Command_show_npctypes::Command_show_npctypes(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_npctypes::execute() {
	std::vector<std::vector<std::string>> npctypes_info = this->_model->info_module()->get_npctypes_info();
	this->_view->output_id_and_name_objects(npctypes_info);
}
