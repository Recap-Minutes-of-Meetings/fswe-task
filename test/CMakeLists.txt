cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(calc)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test test_calculator.cpp)
target_link_libraries(test calc GTest::GTest GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

gtest_add_tests(TARGET test)

