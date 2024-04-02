cmake_minimum_required(VERSION 3.10)

project(
    car
    VERSION 1.0
    LANGUAGES CXX)

add_library(Petroleum Petroleum.cpp Petroleum.h Vehicle.h)
add_library(Electric Electric.cpp Electric.h Vehicle.h)
add_library(Renault Renault.cpp Renault.h Petroleum)
add_library(Tesla Tesla.cpp Tesla.h Electric)
add_library(Utils Utils.cpp Utils.h Petroleum Electric)
add_executable(main main.cpp Tesla Renault Utils)
target_link_libraries(main PRIVATE Petroleum Electric Renault Tesla Utils)