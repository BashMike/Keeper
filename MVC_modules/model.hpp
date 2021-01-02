#pragma once
#include "Model_modules/info_module.hpp"
#include "Model_modules/transaction_module.hpp"

namespace model {
	class Model {
		// ============== ATTRIBUTES ==============
		Info_module* 			_info_module;
		Transaction_module* 	_transaction_module;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Model(Database_connector* database_connector);
		~Model();

		// ----------- contract ------------
		const Info_module* info_module() const;
		const Transaction_module* transaction_module() const;
	};
}
