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
	return this->_select(	"select room.id, roomtype.name, level.name "
							"from room "
							"	 join roomtype	on roomtype.id = room.roomtype_id "
							"	 join level		on level.id = room.level_id;");
}

std::vector<std::vector<std::string>> model::Info_module::get_roomtypes_info() const {
	return this->_select("select * from roomtype;");
}

std::vector<std::vector<std::string>> model::Info_module::get_walls_info() const {
	return this->_select(	"select wall.gameobject_id, gameobject.x, gameobject.y, roomtype.name, level.name, wall.damage, gameobject.animation_filepath from wall "
							"join gameobject 	on gameobject.id = wall.gameobject_id "
							"join room 			on room.id = gameobject.room_id "
							"join roomtype		on roomtype.id = room.roomtype_id "
							"join level			on level.id = room.level_id;");
}

std::vector<std::vector<std::string>> model::Info_module::get_NPCs_info() const {
	std::vector<std::vector<std::string>> npc_info = this->_select("select * from npc_data;");
	std::vector<std::vector<std::string>> npc_buff_resist_info = this->_select("select npc_id, bufftype.name from npc_to_buff join bufftype on bufftype.id = npc_to_buff.bufftype_id;");

	for (int i=1; i<=npc_info.size(); i+=2) {
		npc_info.insert(npc_info.begin()+i, std::vector<std::string>());
	}

	for (int i=0; i<npc_info.size(); i+=2) {
		for (const auto& buff_resist : npc_buff_resist_info) {
			if (buff_resist.at(0) == npc_info.at(i).at(0)) {
				npc_info.at(i+1).push_back(buff_resist.at(1));
			}
		}
	}

	return npc_info;
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

std::vector<std::vector<std::string>> model::Info_module::get_level_map(const std::vector<std::string>& level_info) const {
	std::string script_str = 	"select room.id, roomtype.name, level.name "
								"from room "
								"	join roomtype 	on roomtype.id = room.roomtype_id "
								"	join level 		on level.id = room.level_id and level.id = " + level_info.at(0) + ";";
	std::vector<std::vector<std::string>> result = this->_select(script_str);

	script_str = 	"select room.id, roomtype.name, level.name "
					"from room "
					"	join roomtype 	on roomtype.id = room.roomtype_id "
					"	join level 		on level.id = room.level_id; "
					""
					"select firstroom.id, firstroomtype.name, firstlevel.name, secondroom.id, secondroomtype.name, secondlevel.name "
					"from room_to_room "
					"    join room as firstroom      		on firstroom.id = room_to_room.firstroom_id "
					"	 join roomtype as firstroomtype		on firstroomtype.id = firstroom.roomtype_id "
					"    join level as firstlevel			on firstlevel.id = firstroom.level_id "
					"    join room as secondroom			on secondroom.id = room_to_room.secondroom_id "
					"	 join roomtype as secondroomtype	on secondroomtype.id = secondroom.roomtype_id "
					"    join level as secondlevel			on secondlevel.id = secondroom.level_id "
					"where firstlevel.id = " + level_info.at(0) + " and secondlevel.id = " + level_info.at(0) + "; ";
	std::vector<std::vector<std::string>> result_add = this->_select(script_str);

	result.insert(result.end(), result_add.begin(), result_add.end());

	return result;
}

std::vector<std::vector<std::string>> model::Info_module::get_room_objects(const std::vector<std::string>& room_info) const {
	std::string script_str = 	"with ins(npc_type, item_type, wall_type, wall_name) as ( "
								"    values (1, 2, 3, '_wall') "
								") "
								"select ins.npc_type, gameobject.id, gameobject.x, gameobject.y, npc.name, npctype.name, npc.damage "
								"from room "
								"    join gameobject                     on gameobject.room_id = room.id "
								"    join npc                            on npc.gameobject_id = gameobject.id "
								"	 join npctype						 on npctype.id = npc.npctype_id "
								"    join ins                            on true "
								"where room.id = " + room_info.at(0) + " "
								"union select ins.item_type, gameobject.id, gameobject.x, gameobject.y, item.name, itemtype.name, item.damage "
								"from room "
								"    join gameobject                     on gameobject.room_id = room.id "
								"    join item                           on item.gameobject_id = gameobject.id "
								"	 join itemtype						 on itemtype.id = item.itemtype_id "
								"    join ins                            on true "
								"where room.id = " + room_info.at(0) + " "
								"union select ins.wall_type, gameobject.id, gameobject.x, gameobject.y, ins.wall_name, ins.wall_name, wall.damage "
								"from room "
								"    join gameobject                     on gameobject.room_id = room.id "
								"    join wall                           on wall.gameobject_id = gameobject.id "
								"    join ins                            on true "
								"where room.id = " + room_info.at(0) + ";";

	return this->_select(script_str);
}
