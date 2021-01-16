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
		virtual void print_title() 	override;
		virtual void print_help() 	override;

		virtual void output_message_str(const std::string& message_str) 	override;	
		virtual void output_message(const view::Message_code& message_code) override;

		virtual void output_object_types(const std::vector<std::vector<std::string>>& object_types)			override;
		virtual void output_levels_info(const std::vector<std::vector<std::string>>& levels_info)			override;
		virtual void output_rooms_info(const std::vector<std::vector<std::string>>& rooms_info)				override;
		virtual void output_walls_info(const std::vector<std::vector<std::string>>& walls_info)				override;
		virtual void output_NPCs_info(const std::vector<std::vector<std::string>>& npcs_info)				override;
		virtual void output_items_info(const std::vector<std::vector<std::string>>& items_info)				override;
		virtual void output_buffs_info(const std::vector<std::vector<std::string>>& buffs_info)				override;

		virtual void output_level_map(const std::vector<std::vector<std::string>>& level_map_info)			override;
		virtual void output_room_objects(const std::vector<std::vector<std::string>>& room_objects_info)	override;

		virtual void output_changeable_parameters(const std::vector<std::string>& params_dictionary)		override;
	};
}
