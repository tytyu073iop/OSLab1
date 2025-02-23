# CMakeList.txt: проект CMake для Creator; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required(VERSION 3.29)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (Main "Main.cpp" )
set_property(TARGET Main PROPERTY CXX_STANDARD 20)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
