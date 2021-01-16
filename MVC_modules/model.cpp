#include "model.hpp"

model::Model::Model(Database_connector* database_connector) {
	this->_info_module = new model::Info_module(database_connector);
	this->_transaction_module = new model::Transaction_module(database_connector);
	this->_analytics_module = new model::Analytics_module(database_connector);
}

model::Model::~Model() {
	delete this->_info_module;
	delete this->_transaction_module;
}

const model::Info_module* model::Model::info_module() const 				{ return this->_info_module; }
const model::Transaction_module* model::Model::transaction_module() const 	{ return this->_transaction_module; }
const model::Analytics_module* model::Model::analytics_module() const 		{ return this->_analytics_module; }
