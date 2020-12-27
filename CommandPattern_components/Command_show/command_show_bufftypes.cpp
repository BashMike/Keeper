#include "command_show_bufftypes.hpp"

commander::Command_show_bufftypes::Command_show_bufftypes(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_bufftypes::execute() {
	std::vector<std::vector<std::string>> bufftypes_info = this->_model->info_module()->get_bufftypes_info();
	this->_view->output_id_and_name_objects(bufftypes_info);
}
