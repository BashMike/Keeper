#include "controller.hpp"

controller::Controller::Controller(Model* model, view::View* view, Database_connector* database_connector) {
	this->_is_running	= true;

	this->_model				= model;
	this->_view					= view;
	this->_database_connector 	= database_connector;
}

controller::Controller::~Controller() {}

bool controller::Controller::is_running() const { return this->_is_running; }

void controller::Controller::set_user_name(const std::string& user_name) {
	this->_user_name = user_name;
}
