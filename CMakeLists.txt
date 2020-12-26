cmake_minimum_required(VERSION 3.13)
project(keeper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3")

add_executable(keeper
					main.cpp
					additional.cpp
					
					MVC_modules/app.cpp
					MVC_modules/database_connector.cpp

					MVC_modules/model.cpp
					MVC_modules/Model_modules/info_module.cpp

					MVC_modules/view.cpp
					MVC_modules/view_console.cpp

					MVC_modules/controller.cpp
					MVC_modules/controller_console.cpp
					MVC_modules/Controller_console/parser.cpp

					CommandPattern_components/command.cpp
					CommandPattern_components/command_quit.cpp
					CommandPattern_components/Command_show/command_show_npctypes.cpp
				)

find_package(PostgreSQL REQUIRED)

target_include_directories(keeper PRIVATE ${PostgreSQL_INCLUDE_DIRS})
target_link_libraries(keeper PRIVATE ${PostgreSQL_LIBRARIES})
