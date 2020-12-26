#pragma once
#include "model.hpp"
#include "view.hpp"
#include "database_connector.hpp"
#include "../CommandPattern_components/command.hpp"

namespace controller {
	class Controller {
		// ============== ATTRIBUTES ==============
	protected:
		bool 					_is_running;

		std::string 			_user_name;

		model::Model*			_model;
		view::View*				_view;
		Database_connector*		_database_connector;

	public:
		bool is_running() const;

		// ============== OPERATIONS ==============
		// ----------- creating ------------
		Controller(model::Model* model, view::View* view, Database_connector* database_connector);
		virtual ~Controller();

		// ----------- contract ------------
		virtual commander::Command* get_command() const = 0;
		virtual void quit() = 0;

		virtual bool connect_to_database(std::string& user_name) const = 0;

		// ---------- additional -----------
		void set_user_name(const std::string& user_name);
	};
}
