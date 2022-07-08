# Makefile SegmentadorSOM

all: SegmentadorSOM
	@echo "Compilação do SegmentadorSOM finalizada!"

SegmentadorSOM: main.o ControladorSegmentadorSOM.o Controlador.o Calculos.o Dado.o Neuronio.o Arranjo.o SOM.o MapaContextual.o Visualizacao.o
	g++ -fopenmp main.o ControladorSegmentadorSOM.o Controlador.o Calculos.o Dado.o Neuronio.o Arranjo.o SOM.o MapaContextual.o Visualizacao.o -o SegmentadorSOM

main.o: main.cpp ./Controlador/ControladorSegmentadorSOM.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic main.cpp -o main.o

ControladorSegmentadorSOM.o: ./Controlador/ControladorSegmentadorSOM.cpp ./Controlador/ControladorSegmentadorSOM.h ./Controlador/Controlador.h ./Codificador/Dado.h ./SOM/Neuronio.h ./SOM/Arranjo.h ./SOM/SOM.h ./Visualizacao/MapaContextual.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Controlador/ControladorSegmentadorSOM.cpp -o ControladorSegmentadorSOM.o

Controlador.o: ./Controlador/Controlador.cpp ./Controlador/Controlador.h versao.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Controlador/Controlador.cpp -o Controlador.o

Calculos.o: ./Calculos/Calculos.cpp ./Calculos/Calculos.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Calculos/Calculos.cpp -o Calculos.o

Dado.o: ./Codificador/Dado.cpp ./Codificador/Dado.h ./Calculos/Calculos.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Codificador/Dado.cpp -o Dado.o

Neuronio.o: ./SOM/Neuronio.cpp ./SOM/Neuronio.h ./Calculos/Calculos.h ./Codificador/Dado.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/Neuronio.cpp -o Neuronio.o

Arranjo.o: ./SOM/Arranjo.cpp ./SOM/Arranjo.h ./Codificador/Dado.h ./SOM/Neuronio.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/Arranjo.cpp -o Arranjo.o

SOM.o: ./SOM/SOM.cpp ./SOM/SOM.h versao.h ./Calculos/Calculos.h ./Codificador/Dado.h ./SOM/Neuronio.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/SOM.cpp -o SOM.o

MapaContextual.o: ./Visualizacao/MapaContextual.cpp ./Visualizacao/MapaContextual.h ./Visualizacao/Visualizacao.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Visualizacao/MapaContextual.cpp -o MapaContextual.o

Visualizacao.o: ./Visualizacao/Visualizacao.cpp ./Visualizacao/Visualizacao.h ./Codificador/Dado.h ./SOM/Neuronio.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Visualizacao/Visualizacao.cpp -o Visualizacao.o

tidy:
	rm -f *.o

clean:
	rm -f *.o ./SegmentadorSOM

# Comando completo
# g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic main.cpp ./Controlador/ControladorSegmentadorSOM.cpp ./Controlador/Controlador.cpp ./Calculos/Calculos.cpp ./Codificador/Dado.cpp ./SOM/Neuronio.cpp ./SOM/Arranjo.cpp ./SOM/SOM.cpp ./Visualizacao/MapaContextual.cpp ./Visualizacao/Visualizacao.cpp -o SegmentadorSOM
