#include "command_create_level.hpp"

commander::Command_create_level::Command_create_level(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_level::execute() {
	std::vector<std::string> level_data = this->_controller->read_level_data();

	if (!level_data.empty()) {
		std::string result_message = this->_model->transaction_module()->create_level(level_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
