add_executable(main simpleClass.hpp main.cpp)
add_subdirectory(hackerLib hackerLib)

target_link_libraries(main hackerLib)
