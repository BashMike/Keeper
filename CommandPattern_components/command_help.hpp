#pragma once
#include "../CommandPattern_components/command.hpp"
#include "../MVC_modules/view.hpp"

namespace commander {
	class Command_help : public Command {
		// ============== ATTRIBUTES ==============
		view::View* _view;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Command_help(view::View* view);

		// ----------- contract ------------
		virtual void execute() override;
	};
}
