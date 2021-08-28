#include <iostream>
#include <filesystem_handler_base.hpp>

int main(const int argc, const char * argv [])
{
    if ( argc != 2)
    {
        std::cout << "\nA path location needs to be specified.\n\n";
        return 0;
    }

    std::string the_path = std::string(argv[1]);
    std::cout << "\nHello World! I'm the Filesystem Handler\n\n";
    Filesystem_Handlers::Filesystem_Handler fs_handler = Filesystem_Handlers::Filesystem_Handler();
    fs_handler.initialize_filesystem(the_path);    
    return 0;
}