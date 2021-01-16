#pragma once

#include "../database_connector.hpp" 

#include <vector>
#include <string>

#include "../view_message_codes.hpp"

namespace model {
	class Analytics_module {
		// ============== ATTRIBUTES ==============
		Database_connector* 	_database_connector;

		// ============== OPERATIONS ==============
		// ----------- creating ------------
	public:
		Analytics_module(Database_connector* database_connector);

		// ----------- contract ------------
	private:
		std::vector<std::vector<std::string>> _script_exec(const std::string& script_str) const;

	public:
		std::vector<std::vector<std::string>> analytics_strongest_npc(const std::vector<std::string>& room_info) const;
		std::vector<std::vector<std::string>> analytics_strongest_item() const;
	};
}
