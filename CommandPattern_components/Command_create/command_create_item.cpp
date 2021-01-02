#include "command_create_item.hpp"

commander::Command_create_item::Command_create_item(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_item::execute() {
	std::vector<std::string> item_data = this->_controller->read_item_data();

	if (!item_data.empty()) {
		view::Message_code result_message = this->_model->transaction_module()->create_item(item_data);

		if (result_message != view::NO_MESSAGE) {
			this->_view->output_message(result_message);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
