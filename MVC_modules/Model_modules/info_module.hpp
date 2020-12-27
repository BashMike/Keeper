#pragma once
#include "../database_connector.hpp" 

#include <vector>
#include <string>

namespace model {
	class Info_module {
		// ============== ATTRIBUTES ==============
		Database_connector* 	_database_connector;

		// ============== OPERATIONS ==============
		// ----------- creating ------------
	public:
		Info_module(Database_connector* database_connector);

		// ----------- contract ------------
	private:
		std::vector<std::vector<std::string>> _select(const std::string& script_str) const;

	public:
		std::vector<std::vector<std::string>> get_levels_info() const;
		std::vector<std::vector<std::string>> get_rooms_info() const;
		std::vector<std::vector<std::string>> get_roomtypes_info() const;
		std::vector<std::vector<std::string>> get_walls_info() const;

		std::vector<std::vector<std::string>> get_NPCs_info() const;
		std::vector<std::vector<std::string>> get_npctypes_info() const;
		std::vector<std::vector<std::string>> get_items_info() const;
		std::vector<std::vector<std::string>> get_itemtypes_info() const;

		std::vector<std::vector<std::string>> get_buffs_info() const;
		std::vector<std::vector<std::string>> get_bufftypes_info() const;
	};
}
