# CMakeList.txt: ������ CMake ��� Creator; �������� �������� ��� � �����������,
# ������� ����� ������ ��� ����������� �������.
#
cmake_minimum_required(VERSION 3.29)

project(Main)

#kolhoz
set(BIN_PATH bin)
# �������� �������� � ����������� ���� ����� �������.
configure_file(ProgramPaths.h.in ProgramPaths.h)

add_executable (Main "Main.cpp" )
set_property(TARGET Main PROPERTY CXX_STANDARD 20)

target_include_directories(Main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# TODO: �������� ����� � ������� �������, ���� ��� ����������.
