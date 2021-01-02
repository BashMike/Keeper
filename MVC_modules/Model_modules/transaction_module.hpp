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
		view::Message_code _insert(const std::string& script_str) const;

	public:
		view::Message_code create_level(const std::vector<std::string>& data) const;
		view::Message_code create_room(const std::vector<std::string>& data) const;
		view::Message_code create_rooms_connection(const std::vector<std::string>& data) const;
		view::Message_code create_roomtype(const std::vector<std::string>& data) const;
		view::Message_code create_wall(const std::vector<std::string>& data) const;

		view::Message_code create_npc(const std::vector<std::string>& data) const;
		view::Message_code create_npctype(const std::vector<std::string>& data) const;
		view::Message_code create_item(const std::vector<std::string>& data) const;
		view::Message_code create_itemtype(const std::vector<std::string>& data) const;

		view::Message_code create_buff(const std::vector<std::string>& data) const;
		view::Message_code create_bufftype(const std::vector<std::string>& data) const;
	};
}
