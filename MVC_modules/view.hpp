#pragma once
#include <vector>
#include <string>

#include "model.hpp"
#include "view_message_codes.hpp"

namespace view {
	class View {
		// ============== ATTRIBUTES ==============
		model::Model* _model;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		View(model::Model* model);
		virtual ~View();

		// ----------- contract ------------
		virtual void print_title() = 0;

		virtual void output_message(const view::Message_code& message_code) = 0;
		
		virtual void output_id_and_name_objects(const std::vector<std::vector<std::string>>& object_types) 	= 0;
		virtual void output_rooms_info(const std::vector<std::vector<std::string>>& rooms_info)				= 0;
		virtual void output_walls_info(const std::vector<std::vector<std::string>>& walls_info)				= 0;
		virtual void output_NPCs_info(const std::vector<std::vector<std::string>>& npcs_info)				= 0;
		virtual void output_items_info(const std::vector<std::vector<std::string>>& items_info)				= 0;
		virtual void output_buffs_info(const std::vector<std::vector<std::string>>& buffs_info)				= 0;
	};
}
