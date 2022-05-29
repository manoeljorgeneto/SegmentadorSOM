# Makefile SegmentadorSOM

all: SegmentadorSOM

SegmentadorSOM: main.o Calculos.o Dado.o Arranjo.o Neuronio.o SOM.o MapaContextual.o
	g++ main.o Calculos.o Dado.o Arranjo.o Neuronio.o SOM.o MapaContextual.o -o SegmentadorSOM

main.o: main.cpp ./Calculos/Calculos.h ./Codificador/Dado.h ./SOM/Neuronio.h ./SOM/Arranjo.h ./SOM/SOM.h ./Visualizacao/MapaContextual.h
	g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic -g main.cpp -o main.o

Calculos.o: ./Calculos/Calculos.cpp ./Calculos/Calculos.h
	g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic -g ./Calculos/Calculos.cpp -o Calculos.o
	
Dado.o: ./Codificador/Dado.cpp ./Codificador/Dado.h ./Calculos/Calculos.h
	g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic -g ./Codificador/Dado.cpp -o Dado.o
	
Neuronio.o: ./SOM/Neuronio.cpp ./SOM/Neuronio.h ./Calculos/Calculos.h ./Codificador/Dado.h
	g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic -g ./SOM/Neuronio.cpp -o Neuronio.o

Arranjo.o: ./SOM/Arranjo.cpp ./SOM/Arranjo.h ./Codificador/Dado.h ./SOM/Neuronio.h
	g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic -g ./SOM/Arranjo.cpp -o Arranjo.o

SOM.o: ./SOM/SOM.cpp ./SOM/SOM.h ./Calculos/Calculos.h ./Codificador/Dado.h ./SOM/Neuronio.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic -g ./SOM/SOM.cpp -o SOM.o

MapaContextual.o: ./Visualizacao/MapaContextual.cpp ./Visualizacao/MapaContextual.h ./Codificador/Dado.h ./SOM/Neuronio.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic -g ./Visualizacao/MapaContextual/MapaContextual.cpp -o MapaContextual.o
 
# Comando completo
# g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -g main.cpp ./Calculos/Calculos.cpp ./Codificador/Dado.cpp ./SOM/Arranjo.cpp ./SOM/Neuronio.cpp ./SOM/SOM.cpp ./Visualizacao/MapaContextual.cpp ./Calculos/Calculos.h ./Codificador/Dado.h ./SOM/Arranjo.h ./SOM/Neuronio.h ./SOM/SOM.h ./Visualizacao/MapaContextual.h -o SegmentadorSOM