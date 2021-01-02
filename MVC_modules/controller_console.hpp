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

		virtual std::vector<std::string> read_level_data() const 		override;
		virtual std::vector<std::string> read_room_data() const 		override;
		virtual std::vector<std::string> read_rooms_data() const 		override;
		virtual std::vector<std::string> read_roomtype_data() const 	override;
		virtual std::vector<std::string> read_wall_data() const 		override;
		virtual std::vector<std::string> read_npc_data() const 			override;
		virtual std::vector<std::string> read_npctype_data() const 		override;
		virtual std::vector<std::string> read_item_data() const 		override;
		virtual std::vector<std::string> read_itemtype_data() const 	override;
		virtual std::vector<std::string> read_buff_data() const 		override;
		virtual std::vector<std::string> read_bufftype_data() const 	override;
	};
}
