#include "command_show_roomtypes.hpp"

commander::Command_show_roomtypes::Command_show_roomtypes(model::Model* model, view::View* view)
	: 	_model(model),
		_view(view)	
{}

void commander::Command_show_roomtypes::execute() {
	std::vector<std::vector<std::string>> roomtypes_info = this->_model->info_module()->get_roomtypes_info();
	this->_view->output_id_and_name_objects(roomtypes_info);
}
