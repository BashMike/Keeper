#pragma once

namespace model {
	class Analytics_module {
		// ============== ATTRIBUTES ==============
		Database_connector* 	_database_connector;

		// ============== OPERATIONS ==============
		// ----------- creating ------------
	public:
		Analytics_module(Database_connector* database_connector);

		// ----------- contract ------------
	private:
		std::vector<std::vector<std::string>> _script_exec(const std::string& script_str) const;

	public:
	};
}
