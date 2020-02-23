cmake_minimum_required(VERSION 3.15)
project(T_Extraclase_IS2020)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(T_Extraclase_IS2020 main.cpp Servidor.cpp Servidor.h Grafo.cpp Grafo.h)