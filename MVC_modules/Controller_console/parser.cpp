#include "parser.hpp"

#include <iostream>

#include "../../CommandPattern_components/command_quit.hpp"

controller::Parser::Parser(Controller_console* controller_console, Model* model, View* view) {
	this->_controller_console 	= controller_console;
	this->_model 				= model;
	this->_view 				= view;
}

std::vector<std::string> controller::Parser::split_command_str(const std::string& command_str) const {
	std::vector<std::string> result;

	size_t begin = 0, end = 0;
	while (begin != std::string::npos) {
		end = command_str.find(' ', begin);

		std::string str = command_str.substr(begin, end-begin);
		if (str != "") { result.push_back(str); }

		(end != std::string::npos) ? (begin = end+1) : (begin = end);
	}

	return result;
}

commander::Command* controller::Parser::define_command_by_words(const std::vector<std::string>& command_words) const {
	commander::Command* result = nullptr;

	if (command_words.size() == 1) {
		if (command_words.at(0) == "quit") {
			return new commander::Command_quit((Controller*)this->_controller_console);
		}
	}

	return result;
}

commander::Command* controller::Parser::parse(const std::string& command_str) const {
	std::vector<std::string> command_words = this->split_command_str(command_str);
	commander::Command* result = this->define_command_by_words(command_words);

	return result;
}
