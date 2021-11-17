cmake_minimum_required(VERSION 3.1)

project(FantasyWar)

include_directories(dependencies/fmt-8.0.1/include src)

# Setting up directories with source files
aux_source_directory(src SRC_FOLDER)

add_compile_options(-Wall -DFMT_HEADER_ONLY)

add_executable(${PROJECT_NAME} ${SRC_FOLDER})
