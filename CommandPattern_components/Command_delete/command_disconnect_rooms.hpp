#pragma once
#include "../command.hpp"
#include "../../MVC_modules/controller.hpp"
#include "../../MVC_modules/model.hpp"
#include "../../MVC_modules/view.hpp"

namespace commander {
	class Command_disconnect_rooms : public Command {
		// ============== ATTRIBUTES ==============
		controller::Controller*		_controller;
		model::Model*				_model;
		view::View*					_view;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Command_disconnect_rooms(controller::Controller* controller, model::Model* model, view::View* view);

		// ----------- contract ------------
		virtual void execute() override;
	};
}
