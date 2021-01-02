#include "command_create_itemtype.hpp"

commander::Command_create_itemtype::Command_create_itemtype(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_itemtype::execute() {
	std::vector<std::string> itemtype_data = this->_controller->read_itemtype_data();

	if (!itemtype_data.empty()) {
		view::Message_code result_message = this->_model->transaction_module()->create_itemtype(itemtype_data);

		if (result_message != view::NO_MESSAGE) {
			this->_view->output_message(result_message);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
