#include "analytics_module.hpp"
#include <iostream>

model::Analytics_module::Analytics_module(Database_connector* database_connector)
	: _database_connector(database_connector)
{}

std::vector<std::vector<std::string>> model::Analytics_module::_script_exec(const std::string& script_str) const {
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

std::vector<std::vector<std::string>> model::Analytics_module::analytics_strongest_npc(const std::vector<std::string>& room_info) const {
	std::string script_str = 	"select * from npc_data "
								"join (select id, (npc_health*0.3 + npc_speed*0.2 + npc_dmg*0.5) as power_coef from npc_data) "
								"	as npc_power 	on npc_power.id = npc_data.id "
								"join roomtype 		on roomtype.name = npc_data.roomtype_name "
								"join level 		on level.name = npc_data.level_name "
								"join room 			on room.roomtype_id = roomtype.id and room.level_id = level.id and room.id = " + room_info.at(0) + " "
								"order by npc_power.power_coef desc "
								"limit 1;";

	std::vector<std::vector<std::string>> npc_info = this->_script_exec(script_str);
	std::vector<std::vector<std::string>> npc_buff_resist_info = this->_script_exec("select npc_id, bufftype.name from npc_to_buff join bufftype on bufftype.id = npc_to_buff.bufftype_id;");

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

std::vector<std::vector<std::string>> model::Analytics_module::analytics_strongest_item() const {
	std::string script_str = 	"select * from item_data "
								"order by item_data.item_damage desc "
								"limit 1;";

	return this->_script_exec(script_str);
}
