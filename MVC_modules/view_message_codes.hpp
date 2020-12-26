#pragma once

namespace view {
	enum Message_code {
		MSG_HELLO,								// message when entering the program
		MSG_EXIT,								// message when exiting from the program
		MSG_DB_ACCESS,							// message when accessing the database

		ERR_DB_CONNECTION						// error in database connection
	};
}
