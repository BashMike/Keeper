#pragma once
#include "Model_modules/info_module.hpp"

namespace model {
	class Model {
		// ============== ATTRIBUTES ==============
		Info_module* 	_info_module;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Model(Database_connector* database_connector);
		~Model();

		// ----------- contract ------------
		const Info_module* info_module() const;
	};
}
