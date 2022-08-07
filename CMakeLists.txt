cmake_minimum_required(VERSION 3.22)
project(SegmentadorSOM)

set(CMAKE_CXX_STANDARD 17)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

# Boost!
# https://stackoverflow.com/questions/41244132/add-library-to-cmake-project
find_package(Boost COMPONENTS date_time system serialization thread program_options filesystem unit_test_framework regex chrono REQUIRED)

if(NOT Boost_FOUND)
        message(FATAL_ERROR "Cannot find Boost!")
endif(NOT Boost_FOUND)

message(STATUS "Boost found")

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(
        SegmentadorSOM
        main.cpp
        versao.h
        Arquivos/Arquivo.cpp Arquivos/Arquivo.h
        Arquivos/Arquivo_Arranjo.cpp Arquivos/Arquivo_Arranjo.h
        Arquivos/ArquivoCSV.cpp Arquivos/ArquivoCSV.h
        Arquivos/ArquivoCSV_configs.cpp Arquivos/ArquivoCSV_configs.h
        Arquivos/ArquivoCSV_dados.cpp Arquivos/ArquivoCSV_dados.h
        Calculos/Calculos.cpp Calculos/Calculos.h
        Codificador/Dado.cpp Codificador/Dado.h
        Codificador/ConjuntoDados.cpp Codificador/ConjuntoDados.h
        Controlador/Controlador.cpp Controlador/Controlador.h
        Controlador/ControladorSegmentadorSOM.cpp Controlador/ControladorSegmentadorSOM.h
        SOM/Arranjo.cpp SOM/Arranjo.h
        SOM/Neuronio.cpp SOM/Neuronio.h
        SOM/SOM.cpp SOM/MensagensSOM.cpp SOM/SOM.h
        Visualizacao/MapaContextual.cpp Visualizacao/MapaContextual.h
        Visualizacao/Visualizacao.cpp Visualizacao/Visualizacao.h
        )

target_link_libraries(SegmentadorSOM ${Boost_LIBRARIES})
