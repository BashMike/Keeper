#pragma once

namespace view {
	enum Message_code {
		NO_MESSAGE,								// NULL message

		MSG_HELLO,								// message when entering the program
		MSG_EXIT,								// message when exiting from the program
		MSG_DB_ACCESS,							// message when accessing the database
		MSG_QUERY_SUCCESS,						// message when successing the query executing

		ERR_DB_CONNECTION,						// error in database connection
		ERR_DB_INSERT,							// error in database insert command 
		ERR_INVALID_ARGUMENT,					// error in type of input argument for database's query
		ERR_UKNOWN_PARAMETER_TO_SET				// error in unknown parameter that is given by user to set
	};
}
