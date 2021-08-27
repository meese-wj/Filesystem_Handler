add_subdirectory(HandlerBase)

include_directories(HandlerBase)
add_executable(FilesystemHandler main.cpp)

target_link_libraries(FilesystemHandler PUBLIC filesystem_handler_base)

set(config_file "${CMAKE_BINARY_DIR}/build_config.txt")
configure_file(cmake_config.in ${config_file})
message(STATUS "CMake Configuration File: ${config_file}")