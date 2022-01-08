cmake_minimum_required(VERSION 3.1)

project(FantasyWar)

include_directories(dependencies/fmt/include src)

# Setting up directories with source files
aux_source_directory(src SRC_FOLDER)
aux_source_directory(src/Base SRC_BASE_FOLDER)
aux_source_directory(src/UserInterface SRC_UI_FOLDER)
aux_source_directory(src/UserInterface/CLI SRC_UI_CLI_FOLDER)
aux_source_directory(src/UserInterface/Telegram SRC_UI_TELEGRAM_FOLDER)
aux_source_directory(src/UserInterface/TextFormatting SRC_UI_TEXTFORMATTING_FOLDER)
aux_source_directory(src/UserInterface/TextFormatting/Tags SRC_UI_TEXTFORMATTING_TAGS_FOLDER)
aux_source_directory(src/UserInterface/TextFormatting/Formatters SRC_UI_TEXTFORMATTING_FORMATTERS_FOLDER)

add_compile_options(-Wall -DFMT_HEADER_ONLY)

set(targetPlatform Linux CACHE STRING "Target platform for building.")
set_property(CACHE targetPlatform PROPERTY STRINGS "Linux" "Windows" "Telegram")

message("Building for " ${targetPlatform})

if (targetPlatform STREQUAL Linux)
    add_compile_options(-DLINUX)
elseif(targetPlatform STREQUAL Windows)
    add_compile_options(-DWINDOWS)
elseif(targetPlatform STREQUAL Telegram)
    add_compile_options(-DTELEGRAM)
else()
    message("[Warning] Unknown target platform: " ${targetPlatform})
endif()

add_executable(${PROJECT_NAME} ${SRC_FOLDER}
                               ${SRC_BASE_FOLDER}
                               ${SRC_UI_FOLDER}
                               ${SRC_UI_CLI_FOLDER}
                               ${SRC_UI_TELEGRAM_FOLDER}
                               ${SRC_UI_TEXTFORMATTING_FOLDER}
                               ${SRC_UI_TEXTFORMATTING_TAGS_FOLDER}
                               ${SRC_UI_TEXTFORMATTING_FORMATTERS_FOLDER})

target_precompile_headers(${PROJECT_NAME} PRIVATE "src/precompiled.h")
