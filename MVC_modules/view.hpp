#pragma once
#include "model.hpp"
#include "view_message_codes.hpp"

namespace view {
	class View {
		// ============== ATTRIBUTES ==============
		Model* _model;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		View(Model* model);
		virtual ~View();

		// ----------- contract ------------
		virtual void print_title() = 0;
		virtual void output_message(const view::Message_code& message_code) = 0;
	};
}
