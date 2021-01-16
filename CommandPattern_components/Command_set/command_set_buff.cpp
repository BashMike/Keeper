#include "command_set_buff.hpp"

commander::Command_set_buff::Command_set_buff(controller::Controller* controller, model::Model* model, view::View* view)
	:	_controller(controller),
		_model(model),
		_view(view)
{}

void commander::Command_set_buff::execute() {
	std::vector<std::string> buff_data = this->_controller->read_buff_change_parameter_data();

	if (!buff_data.empty()) {
		if (buff_data.at(0) != "help") {
			std::string result_message = this->_model->transaction_module()->set_buff(buff_data);

			if (result_message == "") 	{ this->_view->output_message(view::MSG_QUERY_SUCCESS); }
			else 						{ this->_view->output_message_str(result_message); }
		}
		else {
			std::vector<std::string> parameters_info(buff_data.begin()+1, buff_data.end());
			this->_view->output_changeable_parameters(parameters_info);
		}
	}
	else {
		this->_view->output_message(view::ERR_INVALID_ARGUMENT);
	}
}
