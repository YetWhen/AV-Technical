cmake_minimum_required(VERSION 3.8)
project(nmp LANGUAGES CXX)

#set_property(TARGET main PROPERTY CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "g++")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/)
add_executable(nmp main.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# GoogleTest requires at least C++11



# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)



# enable_testing()

# add_executable(
#   nmp_test
#   nmp_test.cc
# )
# target_link_libraries(
#   nmp_test
#   gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(nmp_test) 