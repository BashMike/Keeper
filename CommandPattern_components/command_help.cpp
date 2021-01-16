#include "command_help.hpp"

commander::Command_help::Command_help(view::View* view)
	: _view(view)
{}

void commander::Command_help::execute() {
	this->_view->print_help();
}
