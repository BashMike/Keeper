#include "view_console.hpp"
#include "../additional.hpp"

#include <iostream>

view::View_console::View_console(model::Model* model) : View(model) {} 
view::View_console::~View_console() {}

void view::View_console::print_title() {
	std::cout << file_content("Keeper_title.txt");
}

void view::View_console::output_text(const std::vector<std::string>& text) {
	int index = 1;
	for (const std::string& line : text) {
		std::printf("%6i: %s\n", index, line.c_str());
		index++;
	}
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
