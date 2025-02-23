# CMakeList.txt: проект CMake для Creator; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required(VERSION 3.29)

include(CTest)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Creator "Creator.cpp" )
set_property(TARGET Creator PROPERTY CXX_STANDARD 20)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
