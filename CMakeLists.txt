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
					MVC_modules/Model_modules/transaction_module.cpp

					MVC_modules/view.cpp
					MVC_modules/view_console.cpp

					MVC_modules/controller.cpp
					MVC_modules/controller_console.cpp
					MVC_modules/Controller_console/parser.cpp

					CommandPattern_components/command.cpp
					CommandPattern_components/command_quit.cpp

					CommandPattern_components/Command_show/command_show_levels.cpp
					CommandPattern_components/Command_show/command_show_rooms.cpp
					CommandPattern_components/Command_show/command_show_roomtypes.cpp
					CommandPattern_components/Command_show/command_show_walls.cpp
					CommandPattern_components/Command_show/command_show_npcs.cpp
					CommandPattern_components/Command_show/command_show_npctypes.cpp
					CommandPattern_components/Command_show/command_show_items.cpp
					CommandPattern_components/Command_show/command_show_itemtypes.cpp
					CommandPattern_components/Command_show/command_show_buffs.cpp
					CommandPattern_components/Command_show/command_show_bufftypes.cpp

					CommandPattern_components/Command_create/command_create_level.cpp
					CommandPattern_components/Command_create/command_create_room.cpp
					CommandPattern_components/Command_create/command_create_roomtype.cpp
					CommandPattern_components/Command_create/command_create_wall.cpp
					CommandPattern_components/Command_create/command_create_npc.cpp
					CommandPattern_components/Command_create/command_create_npctype.cpp
					CommandPattern_components/Command_create/command_create_item.cpp
					CommandPattern_components/Command_create/command_create_itemtype.cpp
					CommandPattern_components/Command_create/command_create_buff.cpp
					CommandPattern_components/Command_create/command_create_bufftype.cpp
					CommandPattern_components/Command_create/command_connect_rooms.cpp

					CommandPattern_components/Command_delete/command_delete_level.cpp
					CommandPattern_components/Command_delete/command_delete_room.cpp
					CommandPattern_components/Command_delete/command_delete_roomtype.cpp
					CommandPattern_components/Command_delete/command_delete_wall.cpp
					CommandPattern_components/Command_delete/command_delete_npc.cpp
					CommandPattern_components/Command_delete/command_delete_npctype.cpp
					CommandPattern_components/Command_delete/command_delete_item.cpp
					CommandPattern_components/Command_delete/command_delete_itemtype.cpp
					CommandPattern_components/Command_delete/command_delete_buff.cpp
					CommandPattern_components/Command_delete/command_delete_bufftype.cpp
					CommandPattern_components/Command_delete/command_disconnect_rooms.cpp
				)

find_package(PostgreSQL REQUIRED)

target_include_directories(keeper PRIVATE ${PostgreSQL_INCLUDE_DIRS})
target_link_libraries(keeper PRIVATE ${PostgreSQL_LIBRARIES})
