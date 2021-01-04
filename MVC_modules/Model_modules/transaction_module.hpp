#pragma once
#include "../database_connector.hpp" 

#include <vector>
#include <string>

#include "../view_message_codes.hpp"

namespace model {
	class Transaction_module {
		// ============== ATTRIBUTES ==============
		Database_connector* 	_database_connector;

		// ============== OPERATIONS ==============
		// ----------- creating ------------
	public:
		Transaction_module(Database_connector* database_connector);

		// ----------- contract ------------
	private:
		std::string _script_exec(const std::string& script_str) const;

	public:
		std::string create_level(const std::vector<std::string>& data) const;
		std::string create_room(const std::vector<std::string>& data) const;
		std::string create_rooms_connection(const std::vector<std::string>& data) const;
		std::string create_roomtype(const std::vector<std::string>& data) const;
		std::string create_wall(const std::vector<std::string>& data) const;
		std::string create_npc(const std::vector<std::string>& data) const;
		std::string create_npctype(const std::vector<std::string>& data) const;
		std::string create_item(const std::vector<std::string>& data) const;
		std::string create_itemtype(const std::vector<std::string>& data) const;
		std::string create_buff(const std::vector<std::string>& data) const;
		std::string create_bufftype(const std::vector<std::string>& data) const;

		std::string delete_level(const std::vector<std::string>& data) const;
		std::string delete_room(const std::vector<std::string>& data) const;
		std::string delete_rooms_connection(const std::vector<std::string>& data) const;
		std::string delete_roomtype(const std::vector<std::string>& data) const;
		std::string delete_wall(const std::vector<std::string>& data) const;
		std::string delete_npc(const std::vector<std::string>& data) const;
		std::string delete_npctype(const std::vector<std::string>& data) const;
		std::string delete_item(const std::vector<std::string>& data) const;
		std::string delete_itemtype(const std::vector<std::string>& data) const;
		std::string delete_buff(const std::vector<std::string>& data) const;
		std::string delete_bufftype(const std::vector<std::string>& data) const;
	};
}
