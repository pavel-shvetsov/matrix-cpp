project(matrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(matrix main.cpp mat.hpp mat.cpp mat.cpp mat.hpp main.cpp)