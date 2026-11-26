cmake_minimum_required(VERSION 3.30)

project("Unit test with google test" LANGUAGES CXX)

option(WARNINGS_AS_ERROR "Treat warnings as errors" ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(settings)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)