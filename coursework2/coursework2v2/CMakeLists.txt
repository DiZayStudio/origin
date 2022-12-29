cmake_minimum_required(VERSION 3.10)

project(RacingSimulator)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set (SOURCES
LibraryTransport/race.cpp
LibraryTransport/Transport.cpp
LibraryTransport/Boots.cpp
LibraryTransport/Broom.cpp
LibraryTransport/Camel.cpp
LibraryTransport/Centaur.cpp
LibraryTransport/Eagle.cpp
LibraryTransport/FastCamel.cpp
LibraryTransport/FlyingCarpet.cpp
)

set (HEADERS
LibraryTransport/race.h
LibraryTransport/Transport.h
LibraryTransport/Boots.h
LibraryTransport/Broom.h
LibraryTransport/Camel.h
LibraryTransport/Centaur.h
LibraryTransport/Eagle.h
LibraryTransport/FastCamel.h
LibraryTransport/FlyingCarpet.h
)

add_library(LibraryTransport SHARED ${HEADERS} ${SOURCES})

add_executable(SimulatorExe coursework2.cpp)

target_link_libraries(SimulatorExe LibraryTransport)
