cmake_minimum_required(VERSION 3.8)
project(algorithm_cpp C CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)
find_library(BOOSTTEST_LIBRARY NAMES boost_unit_test_framework)
find_library(BOOSTPO_LIBRARY NAMES boost_program_options)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(class1)
