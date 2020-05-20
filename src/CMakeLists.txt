cmake_minimum_required( VERSION 2.8 )

## Sources and headers
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
include_directories( ${__INCLUDE_PATH} )
include_directories( ${PROJECT_SOURCE_DIR}/engine )

## Find all source and header files to be compiled into object files
file( GLOB_RECURSE SOURCES *.cc *.hh *.cpp *.hpp *.c *.h *.inl )
file( GLOB_RECURSE ENGINE_SOURCES ${PROJECT_SOURCE_DIR}/engine/*.cpp )


## Add Libraries
add_library(glew STATIC IMPORTED)
set_property(TARGET glew PROPERTY IMPORTED_LOCATION "${__LIB_PATH}/${__GLEW_LIB_NAME}")

add_library(glfw STATIC IMPORTED)
set_property(TARGET glfw PROPERTY IMPORTED_LOCATION "${__LIB_PATH}/${__GLFW_LIB_NAME}")

add_library(imgui STATIC IMPORTED)
set_property(TARGET imgui PROPERTY IMPORTED_LOCATION "${__LIB_PATH}/libimgui.a")

add_library(stb STATIC IMPORTED)
set_property(TARGET stb PROPERTY IMPORTED_LOCATION "${__LIB_PATH}/libstb.a")

## Find Required Packages
find_package(OpenGL REQUIRED)

## C++ compiler options

### Compiler settings
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "-O2" )
set( CMAKE_CXX_STANDARD_REQUIRED ON ) #...is required...
set( CMAKE_CXX_EXTENSIONS ON ) #...with compiler extensions like gnu++11

### Set custom flags
if (OS_TARGET_ MATCHES "Windows")
    set( CMAKE_CXX_FLAGS "-Wextra -std=c++11 -pthread" ) 
endif()

if (OS_TARGET_ MATCHES "Linux")
    set( CMAKE_CXX_FLAGS "-Wextra -std=c++11 -ldl -pthread" ) 
endif()

## Source file containing the "main" function
set( MAIN_SOURCE main.cpp )
## Specify a name for the generated executable file
set( MAIN_EXE_NAME ${PROJECT_NAME_} )


## 1. Compile...
add_executable( ${MAIN_EXE_NAME} ${MAIN_SOURCE} ${SOURCES} ${ENGINE_SOURCES} )


## 2. Link...
if (OS_TARGET_ MATCHES "Windows")
    target_link_libraries( ${MAIN_EXE_NAME} glew glfw imgui ${OPENGL_gl_LIBRARY} stb )
endif()

if (OS_TARGET_ MATCHES "Linux")
    target_link_libraries( ${MAIN_EXE_NAME} glew glfw imgui ${OPENGL_gl_LIBRARY} OpenGL::GL ${CMAKE_DL_LIBS} stb )
endif()

## 3. Install...
install( TARGETS ${MAIN_EXE_NAME} )
