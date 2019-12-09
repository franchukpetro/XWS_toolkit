cmake_minimum_required(VERSION 3.10)
project(XWS_toolkit)

set(CMAKE_CXX_STANDARD 11)

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})

add_executable(hello hello.cpp )
target_link_libraries(hello ${X11_LIBRARIES})