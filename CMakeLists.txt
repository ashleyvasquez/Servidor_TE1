cmake_minimum_required(VERSION 3.15)
project(T_Extraclase_IS2020)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lcurl")
set(SOURCE_FILES main.cpp)

find_package(Qt5Widgets REQUIRED)
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package(Qt5Sql REQUIRED)

add_executable(T_Extraclase_IS2020 main.cpp Servidor.cpp Servidor.h Grafo.cpp Grafo.h Window.cpp Window.h)

target_link_libraries(T_Extraclase_IS2020 Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql )
qt5_use_modules( T_Extraclase_IS2020 Core Widgets Gui )
