#include "controller_console.hpp"

Controller_console::Controller_console(Model* model, View* view) : Controller(model, view) {
}

Command* Controller_console::get_command() const {
	return nullptr;
}
