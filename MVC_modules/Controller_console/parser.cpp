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

#include "../../CommandPattern_components/Command_show/command_show_level_map.hpp"
#include "../../CommandPattern_components/Command_show/command_show_room_objects.hpp"

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
#include "../../CommandPattern_components/Command_create/command_add_bufftype_resist.hpp"

#include "../../CommandPattern_components/Command_delete/command_delete_level.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_room.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_roomtype.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_wall.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_npc.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_npctype.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_item.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_itemtype.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_buff.hpp"
#include "../../CommandPattern_components/Command_delete/command_delete_bufftype.hpp"
#include "../../CommandPattern_components/Command_delete/command_disconnect_rooms.hpp"
#include "../../CommandPattern_components/Command_delete/command_remove_bufftype_resist.hpp"

#include "../../CommandPattern_components/Command_set/command_set_level.hpp"
#include "../../CommandPattern_components/Command_set/command_set_room.hpp"
#include "../../CommandPattern_components/Command_set/command_set_roomtype.hpp"
#include "../../CommandPattern_components/Command_set/command_set_wall.hpp"
#include "../../CommandPattern_components/Command_set/command_set_npc.hpp"
#include "../../CommandPattern_components/Command_set/command_set_npctype.hpp"
#include "../../CommandPattern_components/Command_set/command_set_item.hpp"
#include "../../CommandPattern_components/Command_set/command_set_itemtype.hpp"
#include "../../CommandPattern_components/Command_set/command_set_buff.hpp"
#include "../../CommandPattern_components/Command_set/command_set_bufftype.hpp"

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
			if (command_words.at(1) == "levels") 			{ result = new commander::Command_show_levels(this->_model, this->_view); }
			else if (command_words.at(1) == "rooms") 		{ result = new commander::Command_show_rooms(this->_model, this->_view); }
			else if (command_words.at(1) == "roomtypes") 	{ result = new commander::Command_show_roomtypes(this->_model, this->_view); }
			else if (command_words.at(1) == "walls") 		{ result = new commander::Command_show_walls(this->_model, this->_view); }
			else if (command_words.at(1) == "npcs") 		{ result = new commander::Command_show_npcs(this->_model, this->_view); }
			else if (command_words.at(1) == "npctypes") 	{ result = new commander::Command_show_npctypes(this->_model, this->_view); }
			else if (command_words.at(1) == "items") 		{ result = new commander::Command_show_items(this->_model, this->_view); }
			else if (command_words.at(1) == "itemtypes") 	{ result = new commander::Command_show_itemtypes(this->_model, this->_view); }
			else if (command_words.at(1) == "buffs") 		{ result = new commander::Command_show_buffs(this->_model, this->_view); }
			else if (command_words.at(1) == "bufftypes") 	{ result = new commander::Command_show_bufftypes(this->_model, this->_view); }
		}
		else if (command_words.at(0) == "create") {
			if (command_words.at(1) == "level") 			{ result = new commander::Command_create_level((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "room") 		{ result = new commander::Command_create_room((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "roomtype") 	{ result = new commander::Command_create_roomtype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "wall") 		{ result = new commander::Command_create_wall((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "npc") 			{ result = new commander::Command_create_npc((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "npctype") 		{ result = new commander::Command_create_npctype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "item") 		{ result = new commander::Command_create_item((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "itemtype") 	{ result = new commander::Command_create_itemtype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "buff") 		{ result = new commander::Command_create_buff((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "bufftype") 	{ result = new commander::Command_create_bufftype((Controller*)this->_controller_console, this->_model, this->_view); }
		}
		else if (command_words.at(0) == "delete") {
			if (command_words.at(1) == "level") 			{ result = new commander::Command_delete_level((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "room") 		{ result = new commander::Command_delete_room((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "roomtype") 	{ result = new commander::Command_delete_roomtype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "wall") 		{ result = new commander::Command_delete_wall((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "npc") 			{ result = new commander::Command_delete_npc((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "npctype") 		{ result = new commander::Command_delete_npctype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "item") 		{ result = new commander::Command_delete_item((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "itemtype") 	{ result = new commander::Command_delete_itemtype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "buff") 		{ result = new commander::Command_delete_buff((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "bufftype") 	{ result = new commander::Command_delete_bufftype((Controller*)this->_controller_console, this->_model, this->_view); }
		}
		else if (command_words.at(0) == "set") {
			if (command_words.at(1) == "level") 			{ result = new commander::Command_set_level((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "room") 		{ result = new commander::Command_set_room((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "roomtype") 	{ result = new commander::Command_set_roomtype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "wall") 		{ result = new commander::Command_set_wall((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "npc") 			{ result = new commander::Command_set_npc((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "npctype") 		{ result = new commander::Command_set_npctype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "item") 		{ result = new commander::Command_set_item((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "itemtype") 	{ result = new commander::Command_set_itemtype((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "buff") 		{ result = new commander::Command_set_buff((Controller*)this->_controller_console, this->_model, this->_view); }
			else if (command_words.at(1) == "bufftype") 	{ result = new commander::Command_set_bufftype((Controller*)this->_controller_console, this->_model, this->_view); }
		}
		else if (command_words.at(0) == "connect" && command_words.at(1) == "rooms") {
			result = new commander::Command_connect_rooms((Controller*)this->_controller_console, this->_model, this->_view);
		}
		else if (command_words.at(0) == "disconnect" && command_words.at(1) == "rooms") {
			result = new commander::Command_disconnect_rooms((Controller*)this->_controller_console, this->_model, this->_view);
		}
	}
	else if (command_words.size() == 3) {
		if (command_words.at(0) == "show" && command_words.at(1) == "level" && command_words.at(2) == "map") {
			result = new commander::Command_show_level_map((Controller*)this->_controller_console, this->_model, this->_view);
		}
		else if (command_words.at(0) == "show" && command_words.at(1) == "room" && command_words.at(2) == "objects") {
			result = new commander::Command_show_room_objects((Controller*)this->_controller_console, this->_model, this->_view);
		}
		else if (command_words.at(0) == "add" && command_words.at(1) == "buff" && command_words.at(2) == "resist") {
			result = new commander::Command_add_bufftype_resist((Controller*)this->_controller_console, this->_model, this->_view);
		}
		else if (command_words.at(0) == "remove" && command_words.at(1) == "buff" && command_words.at(2) == "resist") {
			result = new commander::Command_remove_bufftype_resist((Controller*)this->_controller_console, this->_model, this->_view);
		}
	}

	return result;
}

commander::Command* controller::Parser::parse(const std::string& command_str) const {
	std::vector<std::string> command_words = this->split_command_str(command_str);
	commander::Command* result = this->define_command_by_words(command_words);

	return result;
}
