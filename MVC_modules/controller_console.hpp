#pragma once
#include "controller.hpp"

class Controller_console : public Controller {
	// ============== OPERATIONS ==============
public:
	// ----------- creating ------------
	Controller_console(Model* model, View* view);

	// ----------- contract ------------
	virtual Command* get_command() const override;
};
