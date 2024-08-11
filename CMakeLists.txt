cmake_minimum_required(VERSION 3.20)

project(Cobweb)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(SessionManager ${SOURCES})
