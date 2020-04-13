set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall -Wextra -pedantic")

# fPIC for libs
if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif(NOT WIN32)

# Enable debug build by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

# Enable json for cppcheck and other cool stuff
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    # CPPCHECK USAGE:
    # cppcheck --project=compile_commands.json \
    # --enable=all --inconclusive --std=c++11 2>err.txt
endif(CMAKE_BUILD_TYPE MATCHES Debug)

add_executable(main
    main.cpp
    cyclecaller.cpp
    cyclecaller.h
#    controllablesleep.cpp
#    controllablesleep.h
)

target_link_libraries(main
    pthread
)
