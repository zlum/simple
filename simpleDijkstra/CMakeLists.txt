project(simpleDijkstra)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -lstdc++ -lm -Wall -Wextra -Wpedantic")

add_executable(main main.cpp)
