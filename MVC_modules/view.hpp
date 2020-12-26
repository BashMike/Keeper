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

		virtual void output_text(const std::vector<std::string>& text) = 0;
		virtual void output_message(const view::Message_code& message_code) = 0;
	};
}
