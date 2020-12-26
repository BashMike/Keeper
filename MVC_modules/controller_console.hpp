#pragma once
#include "controller.hpp"
#include "Controller_console/parser.hpp"

namespace controller {
	class Controller_console : public Controller {
		// ============== ATTRIBUTES ==============
		Parser 	_parser;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Controller_console(model::Model* model, view::View* view, Database_connector* database_connector);
		~Controller_console();

		// ----------- contract ------------
		virtual commander::Command* get_command() const override;
		virtual void quit() override;

		virtual bool connect_to_database(std::string& user_name) const override;
	};
}
