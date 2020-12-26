#pragma once
#include <vector>
#include <string>

#include "../../CommandPattern_components/command.hpp"
#include "../model.hpp"
#include "../view.hpp"

namespace controller {
	class Controller_console;
	class Parser {
		// ============== ATTRIBUTES ==============
		controller::Controller_console*		_controller_console;
		Model* 								_model;
		view::View* 						_view;

		// ============== OPERATIONS ==============
		std::vector<std::string> split_command_str(const std::string& command_str) const;
		commander::Command* define_command_by_words(const std::vector<std::string>& command_words) const;

	public:
		// ----------- creating ------------
		Parser(controller::Controller_console* controller_console, Model* model, view::View* view);

		// ----------- contract ------------
		commander::Command* parse(const std::string& command_str) const;
	};
}
