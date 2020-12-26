#include "model.hpp"

model::Model::Model(Database_connector* database_connector) {
	this->_info_module = new model::Info_module(database_connector);
}

model::Model::~Model() {
	delete this->_info_module;
}

const model::Info_module* model::Model::info_module() const { return this->_info_module; }
