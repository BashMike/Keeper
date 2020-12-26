#include "info_module.hpp"

model::Info_module::Info_module(Database_connector* database_connector)
	: _database_connector(database_connector)
{}

std::vector<std::string> model::Info_module::get_npctypes_info() const {
	std::vector<std::string> result;

	PGresult* command_result = PQexec((PGconn*)this->_database_connector->connection(), "select * from npctype;");

	for (int row=0; row<PQntuples(command_result); row++) {
		result.push_back(PQgetvalue(command_result, row, 1));
	}

	PQclear(command_result);

	return result;
}
