cmake_minimum_required(VERSION 3.1)

project(FantasyWar)

include_directories(src)

aux_source_directory(src SRC_DIR)
aux_source_directory(src/UserInterface SRC_USERINTERFACE_DIR)
aux_source_directory(src/UserInterface/MenuItems SRC_MENUITEMS_DIR)
aux_source_directory(src/UserInterface/Menus SRC_MENUS_DIR)

add_compile_options(-Wall --std=c++17)

set(BUILD_MODE Release CACHE STRING "Build mode for the project.")
set_property(CACHE BUILD_MODE PROPERTY STRINGS "Release" "Debug")

message(${BUILD_MODE} " build mode is set.")

if (BUILD_MODE STREQUAL Release)
    add_compile_options(-O2)
elseif(BUILD_MODE STREQUAL Debug)
    add_compile_options(-O0 -g)
else()
    message(FATAL_ERROR "Unknown build mode: " ${BUILD_MODE})
endif()

add_executable(${PROJECT_NAME} ${SRC_DIR}
                               ${SRC_USERINTERFACE_DIR}
                               ${SRC_MENUITEMS_DIR}
                               ${SRC_MENUS_DIR})
