#pragma once
#include "../command.hpp"
#include "../../MVC_modules/controller.hpp"
#include "../../MVC_modules/view.hpp"

namespace commander {
	class Command_show_npcs : public Command {
		// ============== ATTRIBUTES ==============
		model::Model* 	_model;
		view::View*		_view;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Command_show_npcs(model::Model* controller, view::View* view);

		// ----------- contract ------------
		virtual void execute() override;
	};
}
