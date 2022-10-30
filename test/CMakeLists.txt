cmake_minimum_required(VERSION 3.5)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(cpp-gtest-dev)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(sample1 test_calculator.cpp)
target_link_libraries(sample1 testcpp GTest::GTest GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

# Google Testの各テストケースごとにCTestのテストを作成する
gtest_add_tests(TARGET sample1)

