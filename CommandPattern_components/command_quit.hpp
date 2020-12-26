#pragma once
#include "../MVC_modules/controller.hpp"

namespace commander {
	class Command_quit : public Command {
		// ============== ATTRIBUTES ==============
		controller::Controller* _controller;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Command_quit(controller::Controller* controller);

		// ----------- contract ------------
		virtual void execute() override;
	};
}
