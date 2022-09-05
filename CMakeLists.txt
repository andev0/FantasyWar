cmake_minimum_required(VERSION 3.1)

project(FantasyWar)

include_directories(src)

aux_source_directory(src SRC_DIR)
aux_source_directory(src/MenuItems SRC_MENUITEMS_DIR)
aux_source_directory(src/Menus SRC_MENUS_DIR)
aux_source_directory(src/UserInterface SRC_USERINTERFACE_DIR)

add_compile_options(-Wall)

add_executable(${PROJECT_NAME} ${SRC_DIR}
                               ${SRC_MENUITEMS_DIR}
                               ${SRC_MENUS_DIR}
                               ${SRC_USERINTERFACE_DIR})
