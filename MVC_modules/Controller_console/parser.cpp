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

#include "../../CommandPattern_components/Command_create/command_create_level.hpp"
#include "../../CommandPattern_components/Command_create/command_create_room.hpp"
#include "../../CommandPattern_components/Command_create/command_create_roomtype.hpp"
#include "../../CommandPattern_components/Command_create/command_create_wall.hpp"
#include "../../CommandPattern_components/Command_create/command_create_npc.hpp"
#include "../../CommandPattern_components/Command_create/command_create_npctype.hpp"
#include "../../CommandPattern_components/Command_create/command_create_item.hpp"
#include "../../CommandPattern_components/Command_create/command_create_itemtype.hpp"
#include "../../CommandPattern_components/Command_create/command_create_buff.hpp"
#include "../../CommandPattern_components/Command_create/command_create_bufftype.hpp"

#include "../../CommandPattern_components/Command_create/command_connect_rooms.hpp"

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
			result = new commander::Command_quit((Controller*)this->_controller_console);
		}
	}
	else if (command_words.size() == 2) {
		if (command_words.at(0) == "show") {
			if (command_words.at(1) == "levels") {
				result = new commander::Command_show_levels(this->_model, this->_view);
			}
			else if (command_words.at(1) == "rooms") {
				result = new commander::Command_show_rooms(this->_model, this->_view);
			}
			else if (command_words.at(1) == "roomtypes") {
				result = new commander::Command_show_roomtypes(this->_model, this->_view);
			}
			else if (command_words.at(1) == "walls") {
				result = new commander::Command_show_walls(this->_model, this->_view);
			}
			else if (command_words.at(1) == "npcs") {
				result = new commander::Command_show_npcs(this->_model, this->_view);
			}
			if (command_words.at(1) == "npctypes") {
				result = new commander::Command_show_npctypes(this->_model, this->_view);
			}
			else if (command_words.at(1) == "items") {
				result = new commander::Command_show_items(this->_model, this->_view);
			}
			else if (command_words.at(1) == "itemtypes") {
				result = new commander::Command_show_itemtypes(this->_model, this->_view);
			}
			else if (command_words.at(1) == "buffs") {
				result = new commander::Command_show_buffs(this->_model, this->_view);
			}
			else if (command_words.at(1) == "bufftypes") {
				result = new commander::Command_show_bufftypes(this->_model, this->_view);
			}
		}
		else if (command_words.at(0) == "create") {
			if (command_words.at(1) == "level") {
				result = new commander::Command_create_level((Controller*)this->_controller_console, this->_model, this->_view);
			}
			else if (command_words.at(1) == "room") {
				result = new commander::Command_create_room((Controller*)this->_controller_console, this->_model, this->_view);
			}
			else if (command_words.at(1) == "roomtype") {
				result = new commander::Command_create_roomtype((Controller*)this->_controller_console, this->_model, this->_view);
			}
			else if (command_words.at(1) == "wall") {
				result = new commander::Command_create_wall((Controller*)this->_controller_console, this->_model, this->_view);
			}
			else if (command_words.at(1) == "npc") {
				result = new commander::Command_create_npc((Controller*)this->_controller_console, this->_model, this->_view);
			}
			if (command_words.at(1) == "npctype") {
				result = new commander::Command_create_npctype((Controller*)this->_controller_console, this->_model, this->_view);
			}
			else if (command_words.at(1) == "item") {
				result = new commander::Command_create_item((Controller*)this->_controller_console, this->_model, this->_view);
			}
			else if (command_words.at(1) == "itemtype") {
				result = new commander::Command_create_itemtype((Controller*)this->_controller_console, this->_model, this->_view);
			}
			else if (command_words.at(1) == "buff") {
				result = new commander::Command_create_buff((Controller*)this->_controller_console, this->_model, this->_view);
			}
			else if (command_words.at(1) == "bufftype") {
				result = new commander::Command_create_bufftype((Controller*)this->_controller_console, this->_model, this->_view);
			}
		}
		else if (command_words.at(0) == "connect" && command_words.at(1) == "rooms") {
			result = new commander::Command_connect_rooms((Controller*)this->_controller_console, this->_model, this->_view);
		}
	}

	return result;
}

commander::Command* controller::Parser::parse(const std::string& command_str) const {
	std::vector<std::string> command_words = this->split_command_str(command_str);
	commander::Command* result = this->define_command_by_words(command_words);

	return result;
}
