This project shows how to make CMake config files for client applications using
a modern CMake approach.

The goal is to make things as simple as possible for the client.  Users
shouldn't have to do anything more than add the appropriate
`target_link_libraries(...)` command to their CMakeLists.txt to have all the
required compiler flags, includes and libraries added automatically by CMake.

Furthermore this example shows how to make a relocatable CMake package (the
installation folder can be moved and other than building the client with the
updated library install path, no changes are necessary).

The library should be usable both when installed or directly included in
another CMake project.  To achieve this, an ALIAS such as `pont::pont` must be
added in the library's CMakeLists.txt file.  Client apps should only use the
namespace qualified target regardless of if they use it installed or embedded.


# Build and exectution instructions

## Build the lib
```
cd lib
mkdir build && cd $_
# You can choose to activate OpenMP or not.  To test the transitive
# dependencies, it needs to be activated
cmake .. -DCMAKE_INSTALL_PREFIX=../install -DWITH_OPENMP=TRUE && make install
```

## Build the client app

From the root of the project:
```
cd client
mkdir build && cd $_
cmake .. -Dpont_ROOT=../../lib/install && make
```

## Running the client
In the client's build folder:
```
./client
```