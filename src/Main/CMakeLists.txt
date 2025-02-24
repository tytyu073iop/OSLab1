# CMakeList.txt: проект CMake для Creator; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required(VERSION 3.29)

project(Main)

#kolhoz
set(BIN_PATH bin)
# Добавьте источник в исполняемый файл этого проекта.
configure_file(ProgramPaths.h.in ProgramPaths.h)

add_executable (Main "Main.cpp" )
set_property(TARGET Main PROPERTY CXX_STANDARD 20)

target_include_directories(Main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
