# Convenient Filesystem Handler

This repo holds a C++ library for an object that controls the `std::filesystem` functionality. The main idea here is that for future codes, all filesystem calls are to be encapsulated by a separate set of functions and members. It can be inherited by simulations and modified if necessary in child classes.

The requirement for this library is that its compiled under the `ISO C++17 2017` standard which is the first standard that includes the STL filesystem (not including  experimental libraries).

## Installation Instructions with CMake

Use the following lines of code to install a cloned version of this repo:

```bash
cd <FilesystemHandler parent>
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=<FilesystemHandler Installation Location> ..
cmake --build .
cmake --install .
```

Then this library can be implemented with `find_package(FilesystemHandler)` when the installation location is added to the `PATH`, or by configuring CMake with `-DCMAKE_PREFIX_PATH=<FilesystemHandler Installation Location>`. 