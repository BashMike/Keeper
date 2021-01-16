#include "view_console.hpp"
#include "../additional.hpp"

#include <iostream>

view::View_console::View_console(model::Model* model) : View(model) {} 
view::View_console::~View_console() {}

void view::View_console::print_title() {
	std::cout << file_content("Keeper_title.txt");
}

void view::View_console::print_help() {
	std::cout << file_content("help_commands.txt");
}

void view::View_console::output_message_str(const std::string& message_str) {
	std::cout << message_str << std::endl;
}

void view::View_console::output_message(const view::Message_code& message_code) {
	if (message_code == view::MSG_HELLO) {
		std::cout << "Hello! (type \'help\' to get list of all commands)" << std::endl;
	}
	else if (message_code == view::MSG_EXIT) {
		std::cout << "End of the program..." << std::endl;
	}
	else if (message_code == view::MSG_DB_ACCESS) {
		std::cout << "You\'re in \"Dungeon\" database." << std::endl;
	}
	else if (message_code == view::MSG_QUERY_SUCCESS) {
		std::cout << "QUERY SUCCESS." << std::endl;
	}
	else if (message_code == view::ERR_DB_CONNECTION) {
		std::cout << "ERROR: failed to connect to the database." << std::endl;
	}
	else if (message_code == view::ERR_DB_INSERT) {
		std::cout << "ERROR: failed to insert data to the database table." << std::endl;
	}
	else if (message_code == view::ERR_INVALID_ARGUMENT) {
		std::cout << "ERROR: invalid argument." << std::endl;
	}
}

void view::View_console::output_object_types(const std::vector<std::vector<std::string>>& object_types) {
	int index = 1;
	for (const auto& object_type : object_types) {
		std::printf("%6i: (id: %4s) - name = %s\n", index, object_type.at(0).c_str(), object_type.at(1).c_str());
		index++;
	}

	std::cout << std::endl;
}

void view::View_console::output_levels_info(const std::vector<std::vector<std::string>>& levels_info) {
	int index = 1;
	for (const auto& level_info : levels_info) {
		std::printf("%6i: (id: %4s) - name = %15s, music\'s file path: \"%s\"\n", index, level_info.at(0).c_str(), level_info.at(1).c_str(), level_info.at(2).c_str());
		index++;
	}

	std::cout << std::endl;
}

void view::View_console::output_rooms_info(const std::vector<std::vector<std::string>>& rooms_info) {
	int index = 1;
	for (const auto& room_info : rooms_info) {
		std::printf("%6i: (id: %4s) - type = %20s, level = %s\n", index, room_info.at(0).c_str(), room_info.at(1).c_str(), room_info.at(2).c_str());
		index++;
	}

	std::cout << std::endl;
}

void view::View_console::output_walls_info(const std::vector<std::vector<std::string>>& walls_info)	{
	int index = 1;
	for (const auto& wall_info : walls_info) {
		std::printf("%6i: (id: %4s) - x = %4s, y = %4s, room type = %20s, level = %20s, damage = %5s, animation\'s file path = \"%s\"\n", index, 
					wall_info.at(0).c_str(),
					wall_info.at(1).c_str(),
					wall_info.at(2).c_str(),
					wall_info.at(3).c_str(),
					wall_info.at(4).c_str(),
					wall_info.at(5).c_str(),
					wall_info.at(6).c_str());
		index++;
	}
	
	std::cout << std::endl;
}

void view::View_console::output_NPCs_info(const std::vector<std::vector<std::string>>& npcs_info) {
	int index = 1;
	for (int i=0; i<npcs_info.size(); i+=2) {
		std::printf("%6i: (id: %4s) - x = %s, y = %s, room\'s type = %s, level = %s, name = %s, type = %s,\n", index, 
					npcs_info.at(i).at(0).c_str(),
					npcs_info.at(i).at(1).c_str(),
					npcs_info.at(i).at(2).c_str(),
					npcs_info.at(i).at(3).c_str(),
					npcs_info.at(i).at(4).c_str(),
					npcs_info.at(i).at(5).c_str(),
					npcs_info.at(i).at(6).c_str()
					);

		std::printf("        animation\'s file path = \"%s\",\n",
					npcs_info.at(i).at(7).c_str());

		std::printf("        health = %s, speed = %s, damage = %s,\n\n",
					npcs_info.at(i).at(8).c_str(),
					npcs_info.at(i).at(9).c_str(),
					npcs_info.at(i).at(10).c_str());

		std::printf("        attack sound\'s file path = \"%s\",\n",
					npcs_info.at(i).at(11).c_str());

		std::printf("        hurt sound\'s file path = \"%s\",\n",
					npcs_info.at(i).at(12).c_str());

		if (npcs_info.at(i).at(13) != "") {
			std::printf("        drop item\'s name = %s, drop item\'s type = %s,\n\n",
						npcs_info.at(i).at(13).c_str(),
						npcs_info.at(i).at(14).c_str());
		}

		if (npcs_info.at(i).at(15) != "") {
			std::printf("        attack buff\'s name = %s, attack buff\'s effect time = %s,\n",
						npcs_info.at(i).at(15).c_str(),
						npcs_info.at(i).at(16).c_str());
		}

		if (npcs_info.at(i).at(17) != "") {
			std::printf("        on death buff\'s name = %s, on death buff\'s effect time = %s\n\n",
						npcs_info.at(i).at(17).c_str(),
						npcs_info.at(i).at(18).c_str());
		}

		if (!npcs_info.at(i+1).empty()) {
			std::cout << "        resists on buff types:" << std::endl;
			for (const auto& bufftype_resist_name : npcs_info.at(i+1)) {
				std::cout << "          - " << bufftype_resist_name << std::endl;
			}
			std::cout << std::endl;
		}

		index++;
	}

	std::cout << std::endl;
}

void view::View_console::output_items_info(const std::vector<std::vector<std::string>>& items_info)	{
	int index = 1;
	for (const auto& item_info : items_info) {
		std::printf("%6i: (id: %4s) - x = %s, y = %s, room\'s type = %s, level = %s, name = %s, type = %s,\n", index, 
					item_info.at(0).c_str(),
					item_info.at(1).c_str(),
					item_info.at(2).c_str(),
					item_info.at(3).c_str(),
					item_info.at(4).c_str(),
					item_info.at(5).c_str(),
					item_info.at(6).c_str());

		std::printf("        animation\'s file path = \"%s\",\n",
					item_info.at(7).c_str());

		std::printf("        damage = %s,\n",
					item_info.at(8).c_str());

		std::printf("        pick up sound\'s file path = \"%s\"\n\n",
					item_info.at(9).c_str());

		index++;
	}
}

void view::View_console::output_buffs_info(const std::vector<std::vector<std::string>>& buffs_info)	{
	int index = 1;
	for (const auto& buff_info : buffs_info) {
		std::printf("%6i: (id: %4s) - buff\'s type = %20s, effect time = %s\n", index, 
					buff_info.at(0).c_str(),
					buff_info.at(1).c_str(),
					buff_info.at(2).c_str());

		index++;
	}

	std::cout << std::endl;
}

void view::View_console::output_level_map(const std::vector<std::vector<std::string>>& level_map_info) {
	std::vector<std::vector<std::string>> rooms_info;
	std::vector<std::vector<std::string>> room_connections_info;

	for (const auto& line_info : level_map_info) {
		if (line_info.size() == 6) {
			room_connections_info.push_back(line_info);
		}
		else {
			rooms_info.push_back(line_info);
		}
	}

	std::cout << "    rooms info:" << std::endl;
	this->output_rooms_info(rooms_info);

	std::cout << "    room connections:" << std::endl;
	for (const auto& room_connection_info : room_connections_info) {
		std::printf("     - (id = %5s) [roomtype\'s name: %12s, level\'s name: %12s] <-> (id = %5s) [roomtype\'s name: %12s, level\'s name: %12s]\n",
					room_connection_info.at(0).c_str(),
					room_connection_info.at(1).c_str(),
					room_connection_info.at(2).c_str(),
					room_connection_info.at(3).c_str(),
					room_connection_info.at(4).c_str(),
					room_connection_info.at(5).c_str());
	}
	std::cout << std::endl;
}

void view::View_console::output_room_objects(const std::vector<std::vector<std::string>>& room_objects_info) {
	std::vector<std::vector<std::string>> npcs_info;
	std::vector<std::vector<std::string>> items_info;
	std::vector<std::vector<std::string>> walls_info;

	for (const auto& line_info : room_objects_info) {
		if (line_info.at(0) == "1") {
			npcs_info.push_back(line_info);
		}
		else if (line_info.at(0) == "2") {
			items_info.push_back(line_info);
		}
		else if (line_info.at(0) == "3") {
			walls_info.push_back(line_info);
		}
	}

	std::cout << "    npcs info :" << std::endl;
	for (const auto& npc_info : npcs_info) {
		std::printf("     - (id = %5s) x: %4s, y: %4s, ", npc_info.at(1).c_str(), npc_info.at(2).c_str(), npc_info.at(3).c_str());
		std::printf("name: %20s, type: %s\n", npc_info.at(4).c_str(), npc_info.at(5).c_str());
	}
	std::cout << std::endl;

	std::cout << "    items info :" << std::endl;
	for (const auto& item_info : items_info) {
		std::printf("     - (id = %5s) x: %4s, y: %4s, ", item_info.at(1).c_str(), item_info.at(2).c_str(), item_info.at(3).c_str());
		std::printf("name: %20s, type: %s\n", item_info.at(4).c_str(), item_info.at(5).c_str());
	}
	std::cout << std::endl;

	std::cout << "    walls info :" << std::endl;
	for (const auto& wall_info : walls_info) {
		std::printf("     - (id = %5s) x: %4s, y: %4s, ", wall_info.at(1).c_str(), wall_info.at(2).c_str(), wall_info.at(3).c_str());
		std::printf("damage: %s\n", wall_info.at(6).c_str());
	}
	std::cout << std::endl;
}

void view::View_console::output_changeable_parameters(const std::vector<std::string>& params_dictionary) {
	std::cout << "    list of acceptable parameters to change:" << std::endl;
	for (const auto& parameter_name : params_dictionary) {
		std::cout << "     - " << parameter_name << std::endl;
	}
	std::cout << std::endl;
}
