#pragma once
#include <string>

#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"
#include "database_connector.hpp"

class App {
	// ============== ATTRIBUTES ==============
	int	_major_version;
	int	_minor_version;
	int	_child_version;

	Model* 						_model;
	view::View*					_view;
	controller::Controller* 	_controller;
	Database_connector*			_database_connector;

	// ============== OPERATIONS ==============
public:
	// ----------- creating ------------
	App();

	void finalize();

	// ----------- contract ------------
	void run();

	// ---------- additional -----------
	std::string version_str();
};
