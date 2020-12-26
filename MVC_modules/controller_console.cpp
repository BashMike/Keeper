#include "controller_console.hpp"

#include <iostream>

#include "../additional.hpp"

controller::Controller_console::Controller_console(Model* model, view::View* view, Database_connector* database_connector)
	: Controller(model, view, database_connector),
		_parser(this, model, view)
{}

controller::Controller_console::~Controller_console() {
}

commander::Command* controller::Controller_console::get_command() const {
	std::cout << this->_user_name << "@ ";

	std::string command_str;
	std::getline(std::cin, command_str);

	return this->_parser.parse(command_str);
}

void controller::Controller_console::quit() {
	this->_database_connector->disconnect();

	this->_is_running = false;
}

bool controller::Controller_console::connect_to_database(std::string& user_name) const {
	std::cout << "database connection process started..." << std::endl;

	user_name.clear();

	std::cout << "type your user name: ";
	std::getline(std::cin, user_name);

	std::string user_password;

	set_stdin_echo(false);
	std::cout << "type your user password: ";
	std::getline(std::cin, user_password);
	std::cout << std::endl;
	set_stdin_echo(true);

	return this->_database_connector->connect(user_name, user_password);
}
