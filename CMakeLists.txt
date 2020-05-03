cmake_minimum_required(VERSION 3.10)

project(2048 VERSION 0.2)

include_directories(2048Game/include)

file(GLOB SOURCES "2048Game/src/*.cpp")

add_executable(game ${SOURCES})