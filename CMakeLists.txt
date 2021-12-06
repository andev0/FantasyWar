cmake_minimum_required(VERSION 3.1)

project(FantasyWar)

include_directories(dependencies/fmt-8.0.1/include src)

# Setting up directories with source files
aux_source_directory(src SRC_FOLDER)
aux_source_directory(src/Base SRC_BASE_FOLDER)
aux_source_directory(src/UserInterface SRC_UI_FOLDER)
aux_source_directory(src/UserInterface/Linux SRC_LINUX_UI_FOLDER)
aux_source_directory(src/UserInterface/Windows SRC_WINDOWS_UI_FOLDER)
aux_source_directory(src/UserInterface/Telegram SRC_TELEGRAM_UI_FOLDER)

add_compile_options(-Wall -DFMT_HEADER_ONLY)

    message("Building for Linux")
    add_compile_options(-DLINUX)

add_executable(${PROJECT_NAME} ${SRC_FOLDER} ${SRC_BASE_FOLDER} ${SRC_UI_FOLDER} ${SRC_LINUX_UI_FOLDER} ${SRC_WINDOWS_UI_FOLDER} ${SRC_TELEGRAM_UI_FOLDER})
