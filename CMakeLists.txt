cmake_minimum_required( VERSION 2.8 )

## Load CMAKE configuration from environment variables
set( CMAKE_MODULE_PATH $ENV{CMAKE_MODULE_PATH} )
set( CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH} )

## Set global variables
#set(<<name>> "<<value>>")
set ( PROJECT_NAME_ "twom" )

## Specify a project name
project( ${PROJECT_NAME_} )
                       
## Set the build type
if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE "Release" 
       CACHE STRING "Build configuration 'Release' or 'Debug'."
       FORCE )
endif()

## Install the executable to <install_directory>/bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

## Install libraries (if any) to <install_directory>/bin
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


## Set global definitions to be used in c++
# add_definitions(-DTEST_DEFINITION="Hello I am a global value in cmake")
add_definitions(-DGLEW_STATIC)
add_definitions(-D__CYGWIN__)

## Link Subdirectory 
add_subdirectory(${PROJECT_SOURCE_DIR}/src bin)
