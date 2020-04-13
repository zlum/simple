project(simpleQtTCP-client)

find_package(Qt5 COMPONENTS Core Gui Network Widgets Xml REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(LIBS
    Qt5::Core
    Qt5::Gui
    Qt5::Network
    Qt5::Widgets
    Qt5::Xml
)

add_executable(${PROJECT_NAME} main.cpp client.cpp client.h)

target_link_libraries(${PROJECT_NAME}
    ${LIBS}
)
