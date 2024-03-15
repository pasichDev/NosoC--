cmake_minimum_required(VERSION 3.23)
project(NosoCpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Botan REQUIRED)

add_subdirectory(src)
