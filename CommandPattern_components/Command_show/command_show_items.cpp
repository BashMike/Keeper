#include "command_show_items.hpp"

commander::Command_show_items::Command_show_items(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_items::execute() {
	std::vector<std::vector<std::string>> items_info = this->_model->info_module()->get_items_info();
	this->_view->output_items_info(items_info);
}
