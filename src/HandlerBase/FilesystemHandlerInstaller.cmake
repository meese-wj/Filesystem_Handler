message(STATUS "Opening installation settings.")
# Load GNU variables to use:
#   * CMAKE_INSTALL_LIBDIR
#   * CMAKE_INSTALL_BINDIR
#   * CMAKE_INSTALL_INCLUDEDIR
include(GNUInstallDirs)

set(cmake_config_in   ${CMAKE_CURRENT_SOURCE_DIR}/${install_lib_name}Config.cmake.in)
set(cmake_config_out  ${CMAKE_CURRENT_BINARY_DIR}/${install_lib_name}Config.cmake)
set(cmake_version_out ${CMAKE_CURRENT_BINARY_DIR}/${install_lib_name}ConfigVersion.cmake)
set(cmake_install_file ${install_lib_name}Targets.cmake)
set(cmake_install_dest ${CMAKE_INSTALL_LIBDIR}/cmake/${install_lib_name})

target_include_directories(filesystem_handler_base PUBLIC 
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

install(TARGETS filesystem_handler_base
        EXPORT ${install_lib_name}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES filesystem_handler_base.hpp 
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT ${install_lib_name}
        FILE ${cmake_install_file}
        NAMESPACE "${install_lib_name}::"
        DESTINATION ${cmake_install_dest})

# Add config helpers for 
# configure_package_config_file()
include(CMakePackageConfigHelpers)

configure_package_config_file(${cmake_config_in}
                              ${cmake_config_out}
                              INSTALL_DESTINATION 
                              ${cmake_install_dest})


install(FILES 
        ${cmake_config_out}
        ${cmake_version_out}
        DESTINATION 
        ${cmake_install_dest})

# Create a Package Version
set(version 1.0)

set_property(TARGET filesystem_handler_base 
             PROPERTY VERSION ${version})
set_property(TARGET filesystem_handler_base SOVERSION 1)               
set_property(TARGET filesystem_handler_base 
             PROPERTY INTERFACE_filesystem_handler_base_MAJOR_VERSION 1)               
set_property(TARGET filesystem_handler_base 
             APPEND PROPERTY 
             COMPATIBLE_INTERFACE_STRING filesystem_handler_base_MAJOR_VERSION)        


write_basic_version_file(${cmake_version_out}
                         VERSION ${version}
                         COMPATIBILITY AnyNewerVersion)
             