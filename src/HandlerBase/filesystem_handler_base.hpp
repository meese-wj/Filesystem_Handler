#ifndef FILESYSTEM_HANDLER_BASE
#define FILESYSTEM_HANDLER_BASE
// This is the header for the Filesystem_Handler 
// object base. It is meant to be inherited by 
// future simulations but can be used directly.


#include <string>
#include <filesystem>

namespace Filesystem_Handlers
{
    namespace FS = std::filesystem;

    class Filesystem_Handler
    {
        public:
            Filesystem_Handler();
            virtual void initialize_filesystem( const FS::path & the_path );
            virtual void initialize_filesystem( const std::string & the_path_string );
            virtual ~Filesystem_Handler();
        
        protected:
            FS::path fs_path;
    };
}

#endif // FILESYSTEM_HANDLER_BASE