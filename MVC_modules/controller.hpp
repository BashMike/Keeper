#pragma once
#include <vector>
#include <string>

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

		virtual bool connect_to_database(std::string& user_name) const 		= 0;

		virtual std::vector<std::string> read_level_data() const			= 0;
		virtual std::vector<std::string> read_room_data() const				= 0;
		virtual std::vector<std::string> read_roomtype_data() const			= 0;
		virtual std::vector<std::string> read_wall_data() const				= 0;
		virtual std::vector<std::string> read_npc_data() const				= 0;
		virtual std::vector<std::string> read_npctype_data() const			= 0;
		virtual std::vector<std::string> read_item_data() const				= 0;
		virtual std::vector<std::string> read_itemtype_data() const			= 0;
		virtual std::vector<std::string> read_buff_data() const				= 0;
		virtual std::vector<std::string> read_bufftype_data() const			= 0;
		virtual std::vector<std::string> read_rooms_data() const			= 0;

		virtual std::vector<std::string> read_level_define_data() const 	= 0;
		virtual std::vector<std::string> read_room_define_data() const 		= 0;
		virtual std::vector<std::string> read_roomtype_define_data() const 	= 0;
		virtual std::vector<std::string> read_wall_define_data() const 		= 0;
		virtual std::vector<std::string> read_npc_define_data() const 		= 0;
		virtual std::vector<std::string> read_npctype_define_data() const 	= 0;
		virtual std::vector<std::string> read_item_define_data() const 		= 0;
		virtual std::vector<std::string> read_itemtype_define_data() const 	= 0;
		virtual std::vector<std::string> read_buff_define_data() const 		= 0;
		virtual std::vector<std::string> read_bufftype_define_data() const 	= 0;

		// ---------- additional -----------
		void set_user_name(const std::string& user_name);
	};
}
