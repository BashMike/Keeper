#include "transaction_module.hpp"

model::Transaction_module::Transaction_module(Database_connector* database_connector)
	:	_database_connector(database_connector)
{}

std::string model::Transaction_module::_script_exec(const std::string& script_str) const {
	std::string result;

	PGresult* command_result = PQexec((PGconn*)this->_database_connector->connection(), script_str.c_str()); 
	result = std::string(PQresultErrorMessage(command_result));

	PQclear(command_result);

	return result;
}

std::string model::Transaction_module::create_level(const std::vector<std::string>& data) const {
	return this->_script_exec("insert into level(name, music_filepath) values(\'" + data.at(0) + "\', \'" + data.at(1) + "\');");
}

std::string model::Transaction_module::create_room(const std::vector<std::string>& data) const {
	std::string script_str = 	"with ins(roomtype_name, level_name) as ( "
								"	values (\'" + data.at(0) + "\', \'" + data.at(1) + "\') "
								") "
								"insert into room "
								"	(roomtype_id, level_id) "
								"select "
								"	roomtype.id, level.id "
								"from roomtype "
								"	join ins    on ins.roomtype_name = roomtype.name "
								"	join level  on ins.level_name = level.name;";

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::create_rooms_connection(const std::vector<std::string>& data) const {
	std::string script_str = 	"with ins(firstroom_id, secondroom_id) as ( "
								"    values "
								"        (" + data.at(0) + ", " + data.at(1) + ") "
								") "
								"insert into room_to_room "
								"    (firstroom_id, secondroom_id) "
								"select firstroom.id, secondroom.id "
								"from ins "
								"    join room       as firstroom        on firstroom.id = ins.firstroom_id "
								"    join room       as secondroom       on secondroom.id = ins.secondroom_id;";

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::create_roomtype(const std::vector<std::string>& data) const {
	return this->_script_exec("insert into roomtype(name) values(\'" + data.at(0) + "\');");
}

std::string model::Transaction_module::create_wall(const std::vector<std::string>& data) const {
	std::string script_str = "call create_wall(";
	script_str += data.at(0) + ", ";				// wall's X
	script_str += data.at(1) + ", ";				// wall's Y
	script_str += "\'" + data.at(2) + "\', ";		// room type's name
	script_str += "\'" + data.at(3) + "\', ";		// level's name
	script_str += "\'" + data.at(4) + "\', ";		// animation's file path
	script_str += data.at(5) + ");";				// wall's damage

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::create_npc(const std::vector<std::string>& data) const {
	std::string script_str = "call create_npc(";
	script_str += data.at(0) + ", ";				// NPC's x
	script_str += data.at(1) + ", ";				// NPC's y
	script_str += "\'" + data.at(2) + "\', ";		// room type's name
	script_str += "\'" + data.at(3) + "\', ";		// level's name
	script_str += "\'" + data.at(4) + "\', ";		// animation's file path
	script_str += "\'" + data.at(5) + "\', ";		// NPC's name
	script_str += "\'" + data.at(6) + "\', ";		// NPC type's name
	script_str += data.at(7) + ", ";				// NPC's health
	script_str += data.at(8) + ", ";				// NPC's speed
	script_str += data.at(9) + ");";				// NPC's damage

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::create_npctype(const std::vector<std::string>& data) const {
	return this->_script_exec("insert into npctype(name) values(\'" + data.at(0) + "\');");
}

std::string model::Transaction_module::create_item(const std::vector<std::string>& data) const {
	std::string script_str = "call create_item(";
	script_str += data.at(0) + ", ";				// item's x
	script_str += data.at(1) + ", ";				// item's y
	script_str += "\'" + data.at(2) + "\', ";		// room type's name
	script_str += "\'" + data.at(3) + "\', ";		// level's name
	script_str += "\'" + data.at(4) + "\', ";		// animation's file path
	script_str += "\'" + data.at(5) + "\', ";		// item's name
	script_str += "\'" + data.at(6) + "\', ";		// item type's name
	script_str += data.at(7) + ");";				// item's damage

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::create_itemtype(const std::vector<std::string>& data) const {
	return this->_script_exec("insert into itemtype(name) values(\'" + data.at(0) + "\');");
}

std::string model::Transaction_module::create_buff(const std::vector<std::string>& data) const {
	std::string script_str = 	"with ins(bufftype_name, effecttime_value) as ( "
								"	values (\'" + data.at(0) + "\', " + data.at(1) + ") "
								") "
								"insert into buff "
								"	(effecttime, bufftype_id) "
								"select "
								"	ins.effecttime_value, bt.id "
								"from ins "
								"	join bufftype as bt on bt.name = ins.bufftype_name;";

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::create_bufftype(const std::vector<std::string>& data) const {
	return this->_script_exec("insert into bufftype(name) values(\'" + data.at(0) + "\');");
}

std::string model::Transaction_module::delete_level(const std::vector<std::string>& data) const {
	return this->_script_exec("delete from level where id = \'" + data.at(0) + "\';");
}

std::string model::Transaction_module::delete_room(const std::vector<std::string>& data) const {
	return this->_script_exec("delete from room where id = " + data.at(0) + ";");
}

std::string model::Transaction_module::delete_rooms_connection(const std::vector<std::string>& data) const {
	std::string script_str = 	"delete from room_to_room "
								"where firstroom_id = " + data.at(0) + " and secondroom_id = " + data.at(1) + ";";

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::delete_roomtype(const std::vector<std::string>& data) const {
	return this->_script_exec("delete from roomtype where id = " + data.at(0) + ";");
}

std::string model::Transaction_module::delete_wall(const std::vector<std::string>& data) const {
	std::string script_str = 	"delete from wall where wall.gameobject_id = " + data.at(0) + "; "
								"delete from gameobject where gameobject.id = " + data.at(0) + ";";

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::delete_npc(const std::vector<std::string>& data) const {
	std::string script_str = 	"delete from npc where npc.gameobject_id = " + data.at(0) + "; "
								"delete from gameobject where gameobject.id = " + data.at(0) + ";";

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::delete_npctype(const std::vector<std::string>& data) const {
	return this->_script_exec("delete from npctype where id = " + data.at(0) + ";");
}

std::string model::Transaction_module::delete_item(const std::vector<std::string>& data) const {
	std::string script_str = 	"delete from item where item.gameobject_id = " + data.at(0) + "; "
								"delete from gameobject where gameobject.id = " + data.at(0) + ";";

	return this->_script_exec(script_str);
}

std::string model::Transaction_module::delete_itemtype(const std::vector<std::string>& data) const {
	return this->_script_exec("delete from itemtype where id = " + data.at(0) + ";");
}

std::string model::Transaction_module::delete_buff(const std::vector<std::string>& data) const {
	return this->_script_exec("delete from buff where id = " + data.at(0) + ";");
}

std::string model::Transaction_module::delete_bufftype(const std::vector<std::string>& data) const {
	return this->_script_exec("delete from bufftype where id = " + data.at(0) + ";");
}
