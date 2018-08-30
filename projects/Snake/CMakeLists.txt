# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(Snake)

#set the C++ standard to be used
set (CMAKE_CXX_STANDARD 11)

# Bring the headers into the project
include_directories(include)

## set source files
# set (SOURCES main.cpp)
file(GLOB SOURCES "src/*.cpp")

## If you want to link SFML statically
if (NOT APPLE)
  set(SFML_STATIC_LIBRARIES TRUE)
endif(NOT APPLE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio system window REQUIRED)

# Add source to this project's executable.
add_executable (Snake ${SOURCES})

# Copy Media files to build location
file(COPY "media/" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/media)

target_link_libraries(Snake sfml-graphics sfml-audio sfml-system sfml-window)

# TODO: Add tests and install targets if needed.
