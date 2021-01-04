#include "controller_console.hpp"

#include <iostream>

#include "../additional.hpp"

controller::Controller_console::Controller_console(model::Model* model, view::View* view, Database_connector* database_connector)
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

std::vector<std::string> controller::Controller_console::read_level_data() const {
	std::vector<std::string> result;

	std::string level_name;
	std::cout << "    type level\'s name: ";
	std::getline(std::cin, level_name);

	std::string level_music_filepath;
	std::cout << "    type level\'s file path of the background music: ";
	std::getline(std::cin, level_music_filepath);

	result.push_back(level_name);
	result.push_back(level_music_filepath);

	return result;
}

std::vector<std::string> controller::Controller_console::read_room_data() const {
	std::vector<std::string> result;

	std::string roomtype_name;
	std::cout << "    type room type\'s name: ";
	std::getline(std::cin, roomtype_name);

	std::string level_name;
	std::cout << "    type level\'s name: ";
	std::getline(std::cin, level_name);

	result.push_back(roomtype_name);
	result.push_back(level_name);

	return result;
}

std::vector<std::string> controller::Controller_console::read_roomtype_data() const {
	std::vector<std::string> result;

	std::string roomtype_name;
	std::cout << "    type room type\'s name: ";
	std::getline(std::cin, roomtype_name);

	result.push_back(roomtype_name);

	return result;
}

std::vector<std::string> controller::Controller_console::read_wall_data() const {
	std::vector<std::string> result;

	std::string gameobject_x;
	std::cout << "    type wall\'s X: ";
	std::getline(std::cin, gameobject_x);
	if (!is_integer(gameobject_x)) { return std::vector<std::string>(); }

	std::string gameobject_y;
	std::cout << "    type wall\'s Y: ";
	std::getline(std::cin, gameobject_y);
	if (!is_integer(gameobject_y)) { return std::vector<std::string>(); }

	std::string roomtype_name;
	std::cout << "    type room type\'s name: ";
	std::getline(std::cin, roomtype_name);

	std::string level_name;
	std::cout << "    type level\'s name: ";
	std::getline(std::cin, level_name);

	std::string animation_filepath;
	std::cout << "    type animation\'s file path: ";
	std::getline(std::cin, animation_filepath);

	std::string wall_damage;
	std::cout << "    type wall\'s damage: ";
	std::getline(std::cin, wall_damage);
	if (!is_integer(wall_damage)) { return std::vector<std::string>(); }

	result.push_back(gameobject_x);
	result.push_back(gameobject_y);
	result.push_back(roomtype_name);
	result.push_back(level_name);
	result.push_back(animation_filepath);
	result.push_back(wall_damage);

	return result;
}

std::vector<std::string> controller::Controller_console::read_npc_data() const {
	std::vector<std::string> result;

	std::string gameobject_x;
	std::cout << "    type NPC\'s X: ";
	std::getline(std::cin, gameobject_x);
	if (!is_integer(gameobject_x)) { return std::vector<std::string>(); }

	std::string gameobject_y;
	std::cout << "    type NPC\'s Y: ";
	std::getline(std::cin, gameobject_y);
	if (!is_integer(gameobject_y)) { return std::vector<std::string>(); }

	std::string roomtype_name;
	std::cout << "    type room type\'s name: ";
	std::getline(std::cin, roomtype_name);

	std::string level_name;
	std::cout << "    type level\'s name: ";
	std::getline(std::cin, level_name);

	std::string animation_filepath;
	std::cout << "    type animation\'s file path: ";
	std::getline(std::cin, animation_filepath);

	std::string npc_name;
	std::cout << "    type NPC\'s name: ";
	std::getline(std::cin, npc_name);

	std::string npctype_name;
	std::cout << "    type NPC\'s type \'s name: ";
	std::getline(std::cin, npctype_name);

	std::string npc_health;
	std::cout << "    type NPC\'s health: ";
	std::getline(std::cin, npc_health);
	if (!is_integer(npc_health)) { return std::vector<std::string>(); }

	std::string npc_speed;
	std::cout << "    type NPC\'s speed: ";
	std::getline(std::cin, npc_speed);
	if (!is_integer(npc_speed)) { return std::vector<std::string>(); }

	std::string npc_damage;
	std::cout << "    type NPC\'s damage: ";
	std::getline(std::cin, npc_damage);
	if (!is_integer(npc_damage)) { return std::vector<std::string>(); }

	result.push_back(gameobject_x);
	result.push_back(gameobject_y);
	result.push_back(roomtype_name);
	result.push_back(level_name);
	result.push_back(animation_filepath);

	result.push_back(npc_name);
	result.push_back(npctype_name);
	result.push_back(npc_health);
	result.push_back(npc_speed);
	result.push_back(npc_damage);

	return result;
}

std::vector<std::string> controller::Controller_console::read_npctype_data() const {
	std::vector<std::string> result;

	std::string npctype_name;
	std::cout << "    type npc type\'s name: ";
	std::getline(std::cin, npctype_name);

	result.push_back(npctype_name);

	return result;
}

std::vector<std::string> controller::Controller_console::read_item_data() const {
	std::vector<std::string> result;

	std::string gameobject_x;
	std::cout << "    type item\'s X: ";
	std::getline(std::cin, gameobject_x);
	if (!is_integer(gameobject_x)) { return std::vector<std::string>(); }

	std::string gameobject_y;
	std::cout << "    type item\'s Y: ";
	std::getline(std::cin, gameobject_y);
	if (!is_integer(gameobject_y)) { return std::vector<std::string>(); }
	
	std::string roomtype_name;
	std::cout << "    type room type\'s name: ";
	std::getline(std::cin, roomtype_name);

	std::string level_name;
	std::cout << "    type level\'s name: ";
	std::getline(std::cin, level_name);

	std::string animation_filepath;
	std::cout << "    type animation\'s file path: ";
	std::getline(std::cin, animation_filepath);

	std::string item_name;
	std::cout << "    type item\'s name: ";
	std::getline(std::cin, item_name);

	std::string itemtype_name;
	std::cout << "    type item\'s type \'s name: ";
	std::getline(std::cin, itemtype_name);

	std::string item_damage;
	std::cout << "    type item\'s damage: ";
	std::getline(std::cin, item_damage);
	if (!is_integer(item_damage)) { return std::vector<std::string>(); }

	result.push_back(gameobject_x);
	result.push_back(gameobject_y);
	result.push_back(roomtype_name);
	result.push_back(level_name);
	result.push_back(animation_filepath);

	result.push_back(item_name);
	result.push_back(itemtype_name);
	result.push_back(item_damage);

	return result;
}

std::vector<std::string> controller::Controller_console::read_itemtype_data() const {
	std::vector<std::string> result;

	std::string itemtype_name;
	std::cout << "    type item type\'s name: ";
	std::getline(std::cin, itemtype_name);

	result.push_back(itemtype_name);

	return result;
}

std::vector<std::string> controller::Controller_console::read_buff_data() const {
	std::vector<std::string> result;

	std::string bufftype_name;
	std::cout << "    type buff type\'s name: ";
	std::getline(std::cin, bufftype_name);

	std::string buff_effecttime;
	std::cout << "    type buff\'s effect time (float): ";
	std::getline(std::cin, buff_effecttime);
	if (!is_float(buff_effecttime)) { return std::vector<std::string>(); }

	result.push_back(bufftype_name);
	result.push_back(buff_effecttime);
	
	return result;
}

std::vector<std::string> controller::Controller_console::read_bufftype_data() const {
	std::vector<std::string> result;

	std::string bufftype_name;
	std::cout << "    type buff type\'s name: ";
	std::getline(std::cin, bufftype_name);

	result.push_back(bufftype_name);

	return result;
}

std::vector<std::string> controller::Controller_console::read_rooms_data() const {
	std::vector<std::string> result;

	std::string firstroom_id;
	std::cout << "    type first room\'s id: ";
	std::getline(std::cin, firstroom_id);
	if (!is_integer(firstroom_id)) { return std::vector<std::string>(); }

	std::string secondroom_id;
	std::cout << "    type second room\'s id: ";
	std::getline(std::cin, secondroom_id);
	if (!is_integer(secondroom_id)) { return std::vector<std::string>(); }

	if (firstroom_id > secondroom_id) {
		std::string buffer;

		buffer = firstroom_id;
		firstroom_id = secondroom_id;
		secondroom_id = buffer;
	}

	result.push_back(firstroom_id);
	result.push_back(secondroom_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_level_define_data() const {
	std::vector<std::string> result;

	std::string level_id;
	std::cout << "    type level\'s id: ";
	std::getline(std::cin, level_id);
	if (!is_integer(level_id)) { return std::vector<std::string>(); }

	result.push_back(level_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_room_define_data() const {
	std::vector<std::string> result;

	std::string room_id;
	std::cout << "    type room\'s id: ";
	std::getline(std::cin, room_id);
	if (!is_integer(room_id)) { return std::vector<std::string>(); }

	result.push_back(room_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_roomtype_define_data() const {
	std::vector<std::string> result;

	std::string roomtype_id;
	std::cout << "    type roomtype\'s id: ";
	std::getline(std::cin, roomtype_id);
	if (!is_integer(roomtype_id)) { return std::vector<std::string>(); }

	result.push_back(roomtype_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_wall_define_data() const {
	std::vector<std::string> result;

	std::string gameobject_id;
	std::cout << "    type wall\'s id: ";
	std::getline(std::cin, gameobject_id);
	if (!is_integer(gameobject_id)) { return std::vector<std::string>(); }

	result.push_back(gameobject_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_npc_define_data() const {
	std::vector<std::string> result;

	std::string gameobject_id;
	std::cout << "    type npc\'s id: ";
	std::getline(std::cin, gameobject_id);
	if (!is_integer(gameobject_id)) { return std::vector<std::string>(); }

	result.push_back(gameobject_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_npctype_define_data() const {
	std::vector<std::string> result;

	std::string gameobject_id;
	std::cout << "    type npc type\'s id: ";
	std::getline(std::cin, gameobject_id);
	if (!is_integer(gameobject_id)) { return std::vector<std::string>(); }

	result.push_back(gameobject_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_item_define_data() const {
	std::vector<std::string> result;

	std::string gameobject_id;
	std::cout << "    type item\'s id: ";
	std::getline(std::cin, gameobject_id);
	if (!is_integer(gameobject_id)) { return std::vector<std::string>(); }

	result.push_back(gameobject_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_itemtype_define_data() const {
	std::vector<std::string> result;

	std::string gameobject_id;
	std::cout << "    type item type\'s id: ";
	std::getline(std::cin, gameobject_id);
	if (!is_integer(gameobject_id)) { return std::vector<std::string>(); }

	result.push_back(gameobject_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_buff_define_data() const {
	std::vector<std::string> result;

	std::string buff_id;
	std::cout << "    type buff\'s id: ";
	std::getline(std::cin, buff_id);
	if (!is_integer(buff_id)) { return std::vector<std::string>(); }

	result.push_back(buff_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_bufftype_define_data() const {
	std::vector<std::string> result;

	std::string bufftype_id;
	std::cout << "    type buff type\'s id: ";
	std::getline(std::cin, bufftype_id);
	if (!is_integer(bufftype_id)) { return std::vector<std::string>(); }

	result.push_back(bufftype_id);

	return result;
}
