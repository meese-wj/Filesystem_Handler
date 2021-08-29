add_library(filesystem_handler_base filesystem_handler_base.cpp)

set(install_lib_name FilesystemHandlerBase)
set(CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}/${install_lib_name}")
message(STATUS "CMake Install Location: ${CMAKE_INSTALL_PREFIX}")

# Include the installation routine
include(FilesystemHandlerInstaller.cmake)