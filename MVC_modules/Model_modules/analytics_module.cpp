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
