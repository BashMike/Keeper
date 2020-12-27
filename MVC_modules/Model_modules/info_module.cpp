#include "info_module.hpp"
#include <iostream>

model::Info_module::Info_module(Database_connector* database_connector)
	: _database_connector(database_connector)
{}

std::vector<std::vector<std::string>> model::Info_module::_select(const std::string& script_str) const {
	std::vector<std::vector<std::string>> result;

	PGresult* command_result = PQexec((PGconn*)this->_database_connector->connection(), script_str.c_str()); 
	for (int row=0; row<PQntuples(command_result); row++) {
		std::vector<std::string> select_row;

		for (int col=0; col<PQnfields(command_result); col++) { 
			select_row.push_back(PQgetvalue(command_result, row, col));
		}

		result.push_back(select_row);
	}

	PQclear(command_result);

	return result;
}

std::vector<std::vector<std::string>> model::Info_module::get_levels_info() const {
	return this->_select("select * from level;");
}

std::vector<std::vector<std::string>> model::Info_module::get_rooms_info() const {
	return this->_select(	"select room.id, roomtype.name, level.name from room "
							"join roomtype	on roomtype.id = room.roomtype_id "
							"join level		on level.id = room.level_id;");
}

std::vector<std::vector<std::string>> model::Info_module::get_roomtypes_info() const {
	return this->_select("select * from roomtype;");
}

std::vector<std::vector<std::string>> model::Info_module::get_walls_info() const {
	return this->_select(	"select wall.gameobject_id, gameobject.x, gameobject.y, roomtype.name, level.name, wall.damage from wall "
							"join gameobject 	on gameobject.id = wall.gameobject_id "
							"join room 			on room.id = gameobject.room_id "
							"join roomtype		on roomtype.id = room.roomtype_id "
							"join level			on level.id = room.level_id;");
}

std::vector<std::vector<std::string>> model::Info_module::get_NPCs_info() const {
	return this->_select(	"select * from npc_data;");
}

std::vector<std::vector<std::string>> model::Info_module::get_npctypes_info() const	{
	return this->_select("select * from npctype;");
}

std::vector<std::vector<std::string>> model::Info_module::get_items_info() const {
	return this->_select("select * from item_data;");
}

std::vector<std::vector<std::string>> model::Info_module::get_itemtypes_info() const {
	return this->_select("select * from itemtype;");
}

std::vector<std::vector<std::string>> model::Info_module::get_buffs_info() const {
	return this->_select(	"select buff.id, bufftype.name, buff.effecttime from buff "
							"join bufftype on bufftype.id = buff.bufftype_id;");
}

std::vector<std::vector<std::string>> model::Info_module::get_bufftypes_info() const {
	return this->_select("select * from bufftype;");
}
