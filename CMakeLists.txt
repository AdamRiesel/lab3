cmake_minimum_required(VERSION 3.10) # Ensures CMake version is recent enough

set(CMAKE_CXX_FLAGS "-Wall") # Show warnings

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY # Destination for generated executable
${CMAKE_SOURCE_DIR}/ 
)

include_directories( # Where are the header files
"include"
)

project(My2BitComp) # Name of this project
add_executable( My2BitComp 
                src/gate.cpp
                src/main.cpp
                src/person.cpp
                src/wire.cpp
                src/soft_circuit.cpp
                ) # Create an executable "hello