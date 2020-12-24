#pragma once
#include "model.hpp"
#include "view.hpp"
#include "../CommandPattern_components/command.hpp"

class Controller {
	// ============== ATTRIBUTES ==============
	Model* 	_model;
	View* 	_view;

	// ============== OPERATIONS ==============
public:
	// ----------- creating ------------
	Controller(Model* model, View* view);

	// ----------- contract ------------
	virtual Command* get_command() const = 0;
};
