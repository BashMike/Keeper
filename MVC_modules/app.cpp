#include "app.hpp"

#include <iostream>
#include "../additional.hpp"

App::App(Model* model, View* view, Controller* controller) {
	this->_major_version = 0;
	this->_minor_version = 0;
	this->_child_version = 0;

	this->_model 		= model;
	this->_view 		= view;
	this->_controller 	= controller;
}

void App::run() {
	// Print title of the application
	std::cout << file_content("Keeper_title.txt");
}

std::string App::version_str() {
	std::string result = "";

	result += std::to_string(this->_major_version) + ".";
	result += std::to_string(this->_minor_version) + ".";
	result += std::to_string(this->_child_version);

	return result;
}
