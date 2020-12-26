#pragma once
#include <libpq-fe.h>
#include <string>

class Database_connector {
	// ============== ATTRIBUTES ==============
	PGconn*		_connection;

	// ============== OPERATIONS ==============
public:
	// ----------- creating ------------
	Database_connector();
	~Database_connector();

	// ----------- contract ------------
	bool connect(const std::string& user_name, const std::string& user_password);
	void disconnect();

	int getNPChealth();
};
