#include "command_quit.hpp"

commander::Command_quit::Command_quit(controller::Controller* controller) {
	this->_controller = controller;
}

void commander::Command_quit::execute() {
	this->_controller->quit();
}
