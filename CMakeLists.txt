# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.30)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("OSLab1")

# Включите подпроекты.
add_subdirectory ("src/Creator")
add_subdirectory ("src/Reporter")
add_subdirectory ("src/Main")

# sets install default path to current repository
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}")
set(BIN_PATH bin)

install(TARGETS Creator Reporter Main DESTINATION ${BIN_PATH}) # P.S. install dir do not work