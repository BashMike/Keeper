#include "app.hpp"

#include <iostream>
#include "../additional.hpp"

#include "view_console.hpp"
#include "controller_console.hpp"

App::App() {
	this->_major_version = 0;
	this->_minor_version = 0;
	this->_child_version = 0;

	this->_model				= new Model();
	this->_view					= new view::View_console(this->_model);
	this->_database_connector	= new Database_connector();
	this->_controller 			= new controller::Controller_console(this->_model, this->_view, this->_database_connector);
}

void App::run() {
	// Print title of the application
	this->_view->print_title();
	this->_view->output_message(view::MSG_HELLO);

	// Conneciton to the database
	std::string user_name;
	bool database_connection_success = this->_controller->connect_to_database(user_name);

	if (database_connection_success) {
		this->_view->output_message(view::MSG_DB_ACCESS);
	}
	else {
		this->_view->output_message(view::ERR_DB_CONNECTION);
	}

	this->_controller->set_user_name(user_name);

	// Main application loop
	while (this->_controller->is_running() && database_connection_success) {
		// Get command to execute
		commander::Command* command = this->_controller->get_command();

		// Execute command
		if (command != nullptr) {
			command->execute();
			delete command;
		}
	}

	// End of the application
	this->finalize();
}

std::string App::version_str() {
	std::string result = "";

	result += std::to_string(this->_major_version) + ".";
	result += std::to_string(this->_minor_version) + ".";
	result += std::to_string(this->_child_version);

	return result;
}

void App::finalize() {
	this->_view->output_message(view::MSG_EXIT);

	delete this->_database_connector;
	delete this->_controller;
	delete this->_view;
	delete this->_model;
}
