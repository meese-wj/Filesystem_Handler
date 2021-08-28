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
    // Here the_path is assumed to be a relative directory.
    void Filesystem_Handler::initialize_filesystem( const FS::path & the_path )
    {
        fs_path = FS::absolute(the_path);
        std::cout << "\nCurrent directory: " << FS::absolute(FS::current_path()) << ".";
        std::cout << "\nInitializing filesystem at " << fs_path << ".";
        
        if ( FS::exists( fs_path ) )
        {
            std::cout << "\nFilesystem already exists. No need to create directories.\n";
            return;
        }

        std::cout << "\nFilesystem doesn't exist at the specified parent directory.";
        std::cout << "\nCreating filesystem inside " << fs_path << " recursively.\n";
        // Create directories _techinically_ won't break anything
        // if the path already exists (it doesn't do anything), but 
        // why not be verbose?
        FS::create_directories( fs_path );
    }

    // Wrapper around the filesystem version.
    void Filesystem_Handler::initialize_filesystem( const std::string & the_path_string )
    {

        initialize_filesystem( FS::path( the_path_string ) );
    }
}