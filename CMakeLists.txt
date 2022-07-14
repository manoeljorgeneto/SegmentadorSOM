cmake_minimum_required(VERSION 3.22)
project(SegmentadorSOM)

set(CMAKE_CXX_STANDARD 17)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(
        SegmentadorSOM
        main.cpp
        versao.h
        Controlador/Controlador.cpp Controlador/Controlador.h
        Controlador/ControladorSegmentadorSOM.cpp Controlador/ControladorSegmentadorSOM.h
        Calculos/Calculos.cpp Calculos/Calculos.h
        Codificador/Dado.cpp Codificador/Dado.h
        Codificador/ConjuntoDados.cpp Codificador/ConjuntoDados.h
        SOM/Arranjo.cpp SOM/Arranjo.h
        SOM/Neuronio.cpp SOM/Neuronio.h
        SOM/SOM.cpp SOM/SOM.h
        Visualizacao/Visualizacao.cpp Visualizacao/Visualizacao.h
        Visualizacao/MapaContextual.cpp Visualizacao/MapaContextual.h
        )
