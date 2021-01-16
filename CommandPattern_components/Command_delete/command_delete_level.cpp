#include "command_delete_level.hpp"

commander::Command_delete_level::Command_delete_level(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_delete_level::execute() {
	std::vector<std::string> level_data = this->_controller->read_object_define_data();

	if (!level_data.empty()) {
		std::string result_message = this->_model->transaction_module()->delete_level(level_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
