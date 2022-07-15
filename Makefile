# Makefile SegmentadorSOM

all: SegmentadorSOM
	@echo "Compilação do SegmentadorSOM finalizada!"

SegmentadorSOM: main.o ArquivoCSV.o Calculos.o Dado.o ConjuntoDados.o Controlador.o ControladorSegmentadorSOM.o Arranjo.o Neuronio.o SOM.o MapaContextual.o Visualizacao.o
	g++ -fopenmp main.o ArquivoCSV.o Calculos.o Dado.o ConjuntoDados.o Controlador.o ControladorSegmentadorSOM.o Arranjo.o Neuronio.o SOM.o MapaContextual.o Visualizacao.o -o SegmentadorSOM

main.o: main.cpp ./Controlador/ControladorSegmentadorSOM.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic main.cpp -o main.o

ArquivoCSV.o: ./Arquivos/ArquivoCSV.cpp ./Arquivos/ArquivoCSV.h ./Codificador/Dado.h ./Codificador/ConjuntoDados.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Arquivos/ArquivoCSV.cpp -o ArquivoCSV.o

Calculos.o: ./Calculos/Calculos.cpp ./Calculos/Calculos.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Calculos/Calculos.cpp -o Calculos.o

Dado.o: ./Codificador/Dado.cpp ./Codificador/Dado.h ./Calculos/Calculos.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Codificador/Dado.cpp -o Dado.o

ConjuntoDados.o: ./Codificador/ConjuntoDados.cpp ./Codificador/ConjuntoDados.h ./Codificador/Dado.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Codificador/ConjuntoDados.cpp -o ConjuntoDados.o

Controlador.o: ./Controlador/Controlador.cpp ./Controlador/Controlador.h versao.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Controlador/Controlador.cpp -o Controlador.o

ControladorSegmentadorSOM.o: ./Controlador/ControladorSegmentadorSOM.cpp ./Controlador/ControladorSegmentadorSOM.h ./Controlador/Controlador.h ./Arquivos/ArquivoCSV.h ./Codificador/Dado.h ./Codificador/ConjuntoDados.h ./SOM/Neuronio.h ./SOM/Arranjo.h ./SOM/SOM.h ./Visualizacao/MapaContextual.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Controlador/ControladorSegmentadorSOM.cpp -o ControladorSegmentadorSOM.o

Arranjo.o: ./SOM/Arranjo.cpp ./SOM/Arranjo.h ./Codificador/Dado.h ./SOM/Neuronio.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/Arranjo.cpp -o Arranjo.o

Neuronio.o: ./SOM/Neuronio.cpp ./SOM/Neuronio.h ./Calculos/Calculos.h ./Codificador/Dado.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/Neuronio.cpp -o Neuronio.o

SOM.o: ./SOM/SOM.cpp ./SOM/SOM.h versao.h ./Calculos/Calculos.h ./Codificador/Dado.h ./Codificador/ConjuntoDados.h ./SOM/Neuronio.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/SOM.cpp -o SOM.o

MapaContextual.o: ./Visualizacao/MapaContextual.cpp ./Visualizacao/MapaContextual.h ./Visualizacao/Visualizacao.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Visualizacao/MapaContextual.cpp -o MapaContextual.o

Visualizacao.o: ./Visualizacao/Visualizacao.cpp ./Visualizacao/Visualizacao.h ./Codificador/Dado.h ./Codificador/ConjuntoDados.h ./SOM/Neuronio.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Visualizacao/Visualizacao.cpp -o Visualizacao.o

tidy:
	rm -f *.o

clean:
	rm -f *.o ./SegmentadorSOM

# Comando completo
# g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic main.cpp ./Arquivos/ArquivoCSV.cpp ./Calculos/Calculos.cpp ./Codificador/Dado.cpp ./Codificador/ConjuntoDados.cpp ./Controlador/Controlador.cpp ./Controlador/ControladorSegmentadorSOM.cpp ./SOM/Arranjo.cpp ./SOM/Neuronio.cpp ./SOM/SOM.cpp ./Visualizacao/MapaContextual.cpp ./Visualizacao/Visualizacao.cpp -o SegmentadorSOM
