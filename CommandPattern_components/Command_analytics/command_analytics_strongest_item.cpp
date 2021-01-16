#include "command_analytics_strongest_item.hpp"

commander::Command_analytics_strongest_item::Command_analytics_strongest_item(model::Model* model, view::View* view)
	:	_model(model),
		_view(view)
{}

void commander::Command_analytics_strongest_item::execute() {
	std::vector<std::vector<std::string>> item_info = this->_model->analytics_module()->analytics_strongest_item();
	this->_view->output_items_info(item_info);
}
