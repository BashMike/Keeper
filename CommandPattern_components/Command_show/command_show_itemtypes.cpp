#include "command_show_itemtypes.hpp"

commander::Command_show_itemtypes::Command_show_itemtypes(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_itemtypes::execute() {
	std::vector<std::vector<std::string>> itemtypes_info = this->_model->info_module()->get_itemtypes_info();
	this->_view->output_object_types(itemtypes_info);
}
