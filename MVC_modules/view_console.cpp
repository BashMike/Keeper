#include "view_console.hpp"
#include "../additional.hpp"

#include <iostream>

view::View_console::View_console(model::Model* model) : View(model) {} 
view::View_console::~View_console() {}

void view::View_console::print_title() {
	std::cout << file_content("Keeper_title.txt");
}

void view::View_console::output_message(const view::Message_code& message_code) {
	if (message_code == view::MSG_HELLO) {
		std::cout << "Hello!" << std::endl;
	}
	else if (message_code == view::MSG_EXIT) {
		std::cout << "End of the program..." << std::endl;
	}
	else if (message_code == view::MSG_DB_ACCESS) {
		std::cout << "You\'re in \"Dungeon\" database." << std::endl;
	}
	else if (message_code == view::ERR_DB_CONNECTION) {
		std::cout << "ERROR: failed to connect to the database." << std::endl;
	}
}

void view::View_console::output_id_and_name_objects(const std::vector<std::vector<std::string>>& object_types) {
	int index = 1;
	for (const auto& object_type : object_types) {
		std::printf("%6i: (id: %4s) - name = %s\n", index, object_type.at(0).c_str(), object_type.at(1).c_str());
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
		std::printf("%6i: (id: %4s) - x = %4s, y = %4s, room type = %20s, level = %20s, damage = %s\n", index, 
					wall_info.at(0).c_str(),
					wall_info.at(1).c_str(),
					wall_info.at(2).c_str(),
					wall_info.at(3).c_str(),
					wall_info.at(4).c_str(),
					wall_info.at(5).c_str());
		index++;
	}
	
	std::cout << std::endl;
}

void view::View_console::output_NPCs_info(const std::vector<std::vector<std::string>>& npcs_info) {
	int index = 1;
	for (const auto& npc_info : npcs_info) {
		std::printf("%6i: (id: %4s) - x = %s, y = %s, room\'s type = %s, level = %s, name = %s, type = %s,\n", index, 
					npc_info.at(0).c_str(),
					npc_info.at(1).c_str(),
					npc_info.at(2).c_str(),
					npc_info.at(3).c_str(),
					npc_info.at(4).c_str(),
					npc_info.at(5).c_str(),
					npc_info.at(6).c_str()
					);

		std::printf("        animation\'s file path = \"%s\",\n",
					npc_info.at(7).c_str());

		std::printf("        health = %s, speed = %s, damage = %s,\n\n",
					npc_info.at(8).c_str(),
					npc_info.at(9).c_str(),
					npc_info.at(10).c_str());

		std::printf("        attack sound\'s file path = \"%s\",\n",
					npc_info.at(11).c_str());

		std::printf("        hurt sound\'s file path = \"%s\",\n",
					npc_info.at(12).c_str());

		if (npc_info.at(13) != "") {
			std::printf("        drop item\'s name = %s, drop item\'s type = %s,\n\n",
						npc_info.at(13).c_str(),
						npc_info.at(14).c_str());
		}

		if (npc_info.at(15) != "") {
			std::printf("        attack buff\'s name = %s, attack buff\'s effect time = %s,\n",
						npc_info.at(15).c_str(),
						npc_info.at(16).c_str());
		}

		if (npc_info.at(17) != "") {
			std::printf("        on death buff\'s name = %s, on death buff\'s effect time = %s\n\n",
						npc_info.at(17).c_str(),
						npc_info.at(18).c_str());
		}

		index++;
	}
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
		std::printf("%6i: (id: %4s) - buff\' type = %20s, effect time = %s,\n", index, 
					buff_info.at(0).c_str(),
					buff_info.at(1).c_str(),
					buff_info.at(2).c_str());

		index++;
	}

	std::cout << std::endl;
}
