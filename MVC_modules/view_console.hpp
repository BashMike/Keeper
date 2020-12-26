#pragma once
#include "view.hpp"

namespace view {
	class View_console : public View {
		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		View_console(Model* model);
		~View_console();

		// ----------- contract ------------
		virtual void print_title() override;
		virtual void output_message(const view::Message_code& message_code) override;
	};
}
