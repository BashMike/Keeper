#include "parser.hpp"

#include <iostream>

#include "../../CommandPattern_components/command_quit.hpp"

#include "../../CommandPattern_components/Command_show/command_show_levels.hpp"
#include "../../CommandPattern_components/Command_show/command_show_rooms.hpp"
#include "../../CommandPattern_components/Command_show/command_show_roomtypes.hpp"
#include "../../CommandPattern_components/Command_show/command_show_walls.hpp"
#include "../../CommandPattern_components/Command_show/command_show_npcs.hpp"
#include "../../CommandPattern_components/Command_show/command_show_npctypes.hpp"
#include "../../CommandPattern_components/Command_show/command_show_items.hpp"
#include "../../CommandPattern_components/Command_show/command_show_itemtypes.hpp"
#include "../../CommandPattern_components/Command_show/command_show_buffs.hpp"
#include "../../CommandPattern_components/Command_show/command_show_bufftypes.hpp"

controller::Parser::Parser(Controller_console* controller_console, model::Model* model, view::View* view)
	: 	_controller_console(controller_console),
		_model(model),
		_view(view)
{}

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
	else if (command_words.size() == 2) {
		if (command_words.at(0) == "show") {
			if (command_words.at(1) == "npctypes") {
				return new commander::Command_show_npctypes(this->_model, this->_view);
			}
			else if (command_words.at(1) == "itemtypes") {
				return new commander::Command_show_itemtypes(this->_model, this->_view);
			}
			else if (command_words.at(1) == "roomtypes") {
				return new commander::Command_show_roomtypes(this->_model, this->_view);
			}
			else if (command_words.at(1) == "bufftypes") {
				return new commander::Command_show_bufftypes(this->_model, this->_view);
			}
			else if (command_words.at(1) == "levels") {
				return new commander::Command_show_levels(this->_model, this->_view);
			}
			else if (command_words.at(1) == "buffs") {
				return new commander::Command_show_buffs(this->_model, this->_view);
			}
			else if (command_words.at(1) == "walls") {
				return new commander::Command_show_walls(this->_model, this->_view);
			}
			else if (command_words.at(1) == "npcs") {
				return new commander::Command_show_npcs(this->_model, this->_view);
			}
			else if (command_words.at(1) == "rooms") {
				return new commander::Command_show_rooms(this->_model, this->_view);
			}
			else if (command_words.at(1) == "items") {
				return new commander::Command_show_items(this->_model, this->_view);
			}
		}
	}

	return result;
}

commander::Command* controller::Parser::parse(const std::string& command_str) const {
	std::vector<std::string> command_words = this->split_command_str(command_str);
	commander::Command* result = this->define_command_by_words(command_words);

	return result;
}
