cmake_minimum_required(VERSION 3.14)
project(MyProject)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(my_tests test.cpp)
target_link_libraries(my_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(my_tests)
