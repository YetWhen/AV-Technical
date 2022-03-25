cmake_minimum_required(VERSION 3.8)
project(nmp LANGUAGES CXX)

#set_property(TARGET main PROPERTY CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_COMPILER "g++")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/)
add_executable(nmp main.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# GoogleTest requires at least C++11

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(nmp_test nmp_test.cpp)
target_link_libraries(nmp_test gtest_main)
add_test(NAME nmp_test COMMAND nmp_test)
