#include "controller_console.hpp"

#include <iostream>
#include <map>

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

std::vector<std::string> controller::Controller_console::read_bufftype_resist_data() const {
	std::vector<std::string> result;

	std::string npc_id;
	std::cout << "    type npc\'s id: ";
	std::getline(std::cin, npc_id);
	if (!is_integer(npc_id)) { return std::vector<std::string>(); }

	std::string bufftype_id;
	std::cout << "    type buff type\'s id: ";
	std::getline(std::cin, bufftype_id);
	if (!is_integer(bufftype_id)) { return std::vector<std::string>(); }

	result.push_back(npc_id);
	result.push_back(bufftype_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_object_define_data() const {
	std::vector<std::string> result;

	std::string object_id;
	std::cout << "    type id: ";
	std::getline(std::cin, object_id);
	if (!is_integer(object_id)) { return std::vector<std::string>(); }

	result.push_back(object_id);

	return result;
}

std::vector<std::string> controller::Controller_console::read_object_change_parameter_data(	const std::vector<std::string>& str_params_info,
																							const std::vector<std::string>& int_params_info,
																							const std::vector<std::string>& float_params_info) const
{
	std::vector<std::string> result;

	std::string parameter_name;
	std::cout << "    # Type \'help\' to see all changeable parameters" << std::endl;
	std::cout << "    parameter\'s name: ";
	std::getline(std::cin, parameter_name);
	result.push_back(parameter_name);

	if (parameter_name != "help") {
		std::string parameter_data;
		std::cout << "    parameter\'s data: ";
		std::getline(std::cin, parameter_data);
		result.push_back(parameter_data);

		std::vector<std::string> object_info = this->read_object_define_data();
		result.insert(result.begin(), object_info.begin(), object_info.end());

		if (!object_info.empty()) {
			bool is_proper_string_data 	= (std::find(str_params_info.begin(), str_params_info.end(), parameter_name) != str_params_info.end());
			bool is_proper_integer_data = (std::find(int_params_info.begin(), int_params_info.end(), parameter_name) != int_params_info.end() 			&& is_integer(parameter_data));
			bool is_proper_float_data 	= (std::find(float_params_info.begin(), float_params_info.end(), parameter_name) != float_params_info.end() 	&& is_float(parameter_data));

			if (is_proper_string_data) {
				result.at(2) = "\'" + result.at(2) + "\'";
			}

			if (!is_proper_string_data && !is_proper_integer_data && !is_proper_float_data) {
				result.clear();
			}
		}
		else {
			result.clear();
		}
	}
	else {
		std::vector<std::string> params;

		params.push_back("help");
		params.insert(params.end(), str_params_info.begin(),	str_params_info.end());
		params.insert(params.end(), int_params_info.begin(),	int_params_info.end());
		params.insert(params.end(), float_params_info.begin(), 	float_params_info.end());

		result = params;
	}

	return result;
}

std::vector<std::string> controller::Controller_console::read_level_change_parameter_data() const {
	std::vector<std::string> str_param_info = {"name", "music_filepath"};
	std::vector<std::string> int_param_info;

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}

std::vector<std::string> controller::Controller_console::read_room_change_parameter_data() const {
	std::vector<std::string> str_param_info;
	std::vector<std::string> int_param_info = {"roomtype_id", "level_id"};

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}

std::vector<std::string> controller::Controller_console::read_roomtype_change_parameter_data() const {
	std::vector<std::string> str_param_info = {"name"};
	std::vector<std::string> int_param_info;

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}

std::vector<std::string> controller::Controller_console::read_wall_change_parameter_data() const {
	std::vector<std::string> str_param_info = {"animation_filepath"};
	std::vector<std::string> int_param_info = {"x", "y", "room_id", "damage"};

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}

std::vector<std::string> controller::Controller_console::read_npc_change_parameter_data() const {
	std::vector<std::string> str_param_info = {"animation_filepath", "name", "attacksound_filepath", "hurtsound_filepath"};
	std::vector<std::string> int_param_info = {"x", "y", "room_id", "health", "speed", "damage", "npctype_id", "dropitem_id", "attackbuff_id", "ondeathbuff_id"};

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}

std::vector<std::string> controller::Controller_console::read_npctype_change_parameter_data() const {
	std::vector<std::string> str_param_info = {"name"};
	std::vector<std::string> int_param_info;

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}

std::vector<std::string> controller::Controller_console::read_item_change_parameter_data() const {
	std::vector<std::string> str_param_info = {"animation_filepath", "name", "pickupsound_filepath"};
	std::vector<std::string> int_param_info = {"x", "y", "room_id", "itemtype_id", "damage"};

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}

std::vector<std::string> controller::Controller_console::read_itemtype_change_parameter_data() const {
	std::vector<std::string> str_param_info = {"name"};
	std::vector<std::string> int_param_info;

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}

std::vector<std::string> controller::Controller_console::read_buff_change_parameter_data() const {
	std::vector<std::string> str_param_info;
	std::vector<std::string> int_param_info = {"bufftype_id"};
	std::vector<std::string> float_param_info = {"effecttime"};

	return this->read_object_change_parameter_data(str_param_info, int_param_info, float_param_info);
}

std::vector<std::string> controller::Controller_console::read_bufftype_change_parameter_data() const {
	std::vector<std::string> str_param_info = {"name"};
	std::vector<std::string> int_param_info;

	return this->read_object_change_parameter_data(str_param_info, int_param_info, std::vector<std::string>());
}
