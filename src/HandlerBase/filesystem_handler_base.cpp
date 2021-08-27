// This is the implementation file for 
// the Filesystem_Handler base class.

#include "filesystem_handler_base.hpp"

namespace Filesystem_Handlers
{
    Filesystem_Handler::Filesystem_Handler() : fs_path()
    {
        // intentionally empty
    }

    Filesystem_Handler::~Filesystem_Handler()
    {
        // intentionally empty
    }

    // Create the_path recursively if it doesn't already exist.
    void Filesystem_Handler::initialize_filesystem( const FS::path & the_path )
    {

    }

    // Wrapper around the filesystem version.
    void Filesystem_Handler::initialize_filesystem( const std::string & the_path_string )
    {

        initialize_filesystem( FS::path( the_path_string ) );
    }
}