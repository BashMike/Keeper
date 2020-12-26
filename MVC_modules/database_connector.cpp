#include "database_connector.hpp"

Database_connector::Database_connector() {}
Database_connector::~Database_connector() {}

bool Database_connector::connect(const std::string& user_name, const std::string& user_password) {
	bool success = true;

	std::string connection_info = "user = " + user_name + " password = " + user_password + " dbname = Dungeon";

	this->_connection = PQconnectdb(connection_info.c_str());

	if (PQstatus(this->_connection) != CONNECTION_OK) {
		this->disconnect();
		success = false;
	}

	return success;
}

void Database_connector::disconnect() {
	PQfinish(this->_connection);
}

const PGconn* Database_connector::connection() const { return this->_connection; }
