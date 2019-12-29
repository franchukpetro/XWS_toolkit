cmake_minimum_required(VERSION 3.10)
project(XWS_toolkit)

set(CMAKE_CXX_STANDARD 11)

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})

add_executable(example1 example1.cpp
               include/window.h src/window.cpp
               include/button.h src/button.cpp
               include/text_box.h src/text_box.cpp )
target_link_libraries(example1 ${X11_LIBRARIES})