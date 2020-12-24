#pragma once
#include <string>

#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

class App {
	// ============== ATTRIBUTES ==============
	int				_major_version;
	int				_minor_version;
	int				_child_version;

	Model* 			_model;
	View*			_view;
	Controller* 	_controller;

	// ============== OPERATIONS ==============
public:
	// ----------- creating ------------
	App(Model* model, View* view, Controller* controller);

	// ----------- contract ------------
	void run();

	// ---------- additional -----------
	std::string version_str();
};
