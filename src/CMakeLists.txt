cmake_minimum_required( VERSION 2.8 )

## Sources and headers
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../include )

## Find all source and header files to be compiled into object files
file( GLOB_RECURSE SOURCES *.cc *.hh *.cpp *.hpp *.c *.h )

## Add Libraries
# add_library(<<LibraryName>> SHARED IMPORTED)
# set_property(TARGET <<LibraryName>>  PROPERTY IMPORTED_LOCATION "/path/to/lib/")
add_library(glew STATIC IMPORTED)
set_property(TARGET glew PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../lib/glew32s.lib")

add_library(glfw STATIC IMPORTED)
set_property(TARGET glfw PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../lib/libglfw3.a")


## Find Required Packages
# find_package(<<LibraryName>> REQUIRED)
find_package(OpenGL REQUIRED)

## C++ compiler options

### Compiler settings
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "-O2" )
set( CMAKE_CXX_STANDARD_REQUIRED ON ) #...is required...
set( CMAKE_CXX_EXTENSIONS ON ) #...with compiler extensions like gnu++11

### Set custom flags
set( CMAKE_CXX_FLAGS "-Wextra -std=c++11" ) 


## Source file containing the "main" function
set( MAIN_SOURCE main.cpp )
## Specify a name for the generated executable file
set( MAIN_EXE_NAME ${PROJECT_NAME_} )


## 1. Compile...
add_executable( ${MAIN_EXE_NAME} ${MAIN_SOURCE} ${SOURCES} )


## 2. Link...
target_link_libraries( ${MAIN_EXE_NAME} glew ${OPENGL_gl_LIBRARY} glfw)
# target_link_libraries(${MAIN_EXE_NAME} <<Libraryname>> )


## 3. Install...
install( TARGETS ${MAIN_EXE_NAME} RUNTIME DESTINATION bin )
