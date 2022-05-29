cmake_minimum_required(VERSION 3.22)
project(SegmentadorSOM)

set(CMAKE_CXX_STANDARD 17)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")

add_executable(
        SegmentadorSOM
        main.cpp
        Calculos/Calculos.cpp
        Codificador/Dado.cpp
        SOM/Arranjo.cpp
        SOM/Neuronio.cpp
        SOM/SOM.cpp
        Visualizacao/MapaContextual.cpp
        Calculos/Calculos.h
        Codificador/Dado.h
        SOM/Arranjo.h
        SOM/Neuronio.h
        SOM/SOM.h
        Visualizacao/MapaContextual.h
        )
