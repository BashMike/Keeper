#pragma once
#include "../database_connector.hpp" 

#include <vector>
#include <string>

namespace model {
	class Info_module {
		// ============== ATTRIBUTES ==============
		Database_connector* 	_database_connector;

		// ============== OPERATIONS ==============
		// ----------- creating ------------
	public:
		Info_module(Database_connector* database_connector);

		// ----------- contract ------------
		std::vector<std::string> get_npctypes_info() const;
	};
}
