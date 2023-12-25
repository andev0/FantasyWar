cmake_minimum_required(VERSION 3.5)

project(FantasyWar)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

aux_source_directory(src SRC_DIR)
aux_source_directory(src/UserInterface SRC_USERINTERFACE_DIR)
aux_source_directory(src/UserInterface/MenuItems SRC_MENUITEMS_DIR)
aux_source_directory(src/UserInterface/Menus SRC_MENUS_DIR)
aux_source_directory(src/Game SRC_GAME_DIR)

add_compile_options(-Wall)

message(${CMAKE_BUILD_TYPE} " build mode is set.")

add_executable(${PROJECT_NAME} ${SRC_DIR}
                               ${SRC_USERINTERFACE_DIR}
                               ${SRC_MENUITEMS_DIR}
                               ${SRC_MENUS_DIR}
                               ${SRC_GAME_DIR})
