#pragma once
#include "view.hpp"

namespace view {
	class View_console : public View {
		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		View_console(model::Model* model);
		~View_console();

		// ----------- contract ------------
		virtual void print_title() override;

		virtual void output_message(const view::Message_code& message_code) override;

		virtual void output_id_and_name_objects(const std::vector<std::vector<std::string>>& object_types) 	override;
		virtual void output_rooms_info(const std::vector<std::vector<std::string>>& rooms_info)				override;
		virtual void output_walls_info(const std::vector<std::vector<std::string>>& walls_info)				override;
		virtual void output_NPCs_info(const std::vector<std::vector<std::string>>& npcs_info)				override;
		virtual void output_items_info(const std::vector<std::vector<std::string>>& items_info)				override;
		virtual void output_buffs_info(const std::vector<std::vector<std::string>>& buffs_info)				override;
	};
}
