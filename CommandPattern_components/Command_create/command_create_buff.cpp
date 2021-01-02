#include "command_create_buff.hpp"

commander::Command_create_buff::Command_create_buff(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_create_buff::execute() {
	std::vector<std::string> buff_data = this->_controller->read_buff_data();

	if (!buff_data.empty()) {
		view::Message_code result_message = this->_model->transaction_module()->create_buff(buff_data);

		if (result_message != view::NO_MESSAGE) {
			this->_view->output_message(result_message);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
