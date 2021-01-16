#pragma once
#include "../command.hpp"
#include "../../MVC_modules/model.hpp"
#include "../../MVC_modules/view.hpp"

namespace commander {
	class Command_analytics_strongest_item : public Command {
		// ============== ATTRIBUTES ==============
		model::Model*				_model;
		view::View*					_view;

		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Command_analytics_strongest_item(model::Model* model, view::View* view);

		// ----------- contract ------------
		virtual void execute() override;
	};
}
