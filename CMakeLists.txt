cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall)

project(INI_Reader_CPlusPlus VERSION 1.0.0 DESCRIPTION "Basic C++ INI Reader")

message("Using compiler : ${CMAKE_CXX_COMPILER_ID}")
message("Version : ${CMAKE_CXX_COMPILER_VERSION}")

find_package(GTest REQUIRED)
add_subdirectory(IniReader)

add_executable(App main.cpp)
target_link_libraries(App PRIVATE ini_reader)

add_executable(TestAppRunner testRunner.cpp)
target_link_libraries(TestAppRunner PRIVATE ${GTEST_LIBRARIES} ini_reader)