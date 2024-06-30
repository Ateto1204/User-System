cmake_minimum_required(VERSION 3.10)
project(UserTest)

set(CMAKE_CXX_STANDARD 17)

# Include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add source file
add_executable(app main.cpp test.cpp user.cpp user_repository.cpp user_service.cpp)

# Link to library of Google Test
target_link_libraries(app ${GTEST_LIBRARIES} pthread)