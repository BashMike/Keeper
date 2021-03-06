#include "command_create_item.hpp"

commander::Command_create_item::Command_create_item(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_item::execute() {
	std::vector<std::string> item_data = this->_controller->read_item_data();

	if (!item_data.empty()) {
		std::string result_message = this->_model->transaction_module()->create_item(item_data);

		if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
		else 						{ this->_view->output_message_str(result_message); }
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
