# Makefile SegmentadorSOM

all: SegmentadorSOM
	@echo "Compilação do SegmentadorSOM finalizada!"

SegmentadorSOM: main.o Arquivo.o Arquivo_Arranjo.o ArquivoCSV.o ArquivoCSV_configs.o ArquivoCSV_dados.o Calculos.o Dado.o ConjuntoDados.o Controlador.o ControladorSegmentadorSOM.o Arranjo.o Neuronio.o SOM.o MensagensSOM.o MapaContextual.o Visualizacao.o
	g++ -fopenmp main.o Arquivo.o Arquivo_Arranjo.o ArquivoCSV.o ArquivoCSV_configs.o ArquivoCSV_dados.o Calculos.o Dado.o ConjuntoDados.o Controlador.o ControladorSegmentadorSOM.o Arranjo.o Neuronio.o SOM.o MensagensSOM.o MapaContextual.o Visualizacao.o -lboost_serialization -lboost_system -o SegmentadorSOM

main.o: main.cpp ./Controlador/ControladorSegmentadorSOM.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic main.cpp -o main.o

Arquivo.o: ./Arquivos/Arquivo.cpp ./Arquivos/Arquivo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Arquivos/Arquivo.cpp -o Arquivo.o

Arquivo_Arranjo.o: ./Arquivos/Arquivo_Arranjo.cpp ./Arquivos/Arquivo_Arranjo.h ./Arquivos/Arquivo.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Arquivos/Arquivo_Arranjo.cpp -o Arquivo_Arranjo.o

ArquivoCSV.o: ./Arquivos/ArquivoCSV.cpp ./Arquivos/ArquivoCSV.h ./Arquivos/Arquivo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Arquivos/ArquivoCSV.cpp -o ArquivoCSV.o

ArquivoCSV_configs.o: ./Arquivos/ArquivoCSV_configs.cpp ./Arquivos/ArquivoCSV_configs.h ./versao.h ./Arquivos/ArquivoCSV.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Arquivos/ArquivoCSV_configs.cpp -o ArquivoCSV_configs.o

ArquivoCSV_dados.o: ./Arquivos/ArquivoCSV_dados.cpp ./Arquivos/ArquivoCSV_dados.h ./Arquivos/ArquivoCSV.h ./Codificador/Dado.h ./Codificador/ConjuntoDados.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Arquivos/ArquivoCSV_dados.cpp -o ArquivoCSV_dados.o

Calculos.o: ./Calculos/Calculos.cpp ./Calculos/Calculos.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Calculos/Calculos.cpp -o Calculos.o

Dado.o: ./Codificador/Dado.cpp ./Codificador/Dado.h ./Calculos/Calculos.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Codificador/Dado.cpp -o Dado.o

ConjuntoDados.o: ./Codificador/ConjuntoDados.cpp ./Codificador/ConjuntoDados.h ./Codificador/Dado.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Codificador/ConjuntoDados.cpp -o ConjuntoDados.o

Controlador.o: ./Controlador/Controlador.cpp ./Controlador/Controlador.h versao.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Controlador/Controlador.cpp -o Controlador.o

ControladorSegmentadorSOM.o: ./Controlador/ControladorSegmentadorSOM.cpp ./Controlador/ControladorSegmentadorSOM.h ./Controlador/Controlador.h ./Arquivos/ArquivoCSV_configs.h ./Arquivos/ArquivoCSV_dados.h ./Codificador/Dado.h ./Codificador/ConjuntoDados.h ./SOM/Neuronio.h ./SOM/Arranjo.h ./SOM/SOM.h ./Visualizacao/MapaContextual.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Controlador/ControladorSegmentadorSOM.cpp -o ControladorSegmentadorSOM.o

Arranjo.o: ./SOM/Arranjo.cpp ./SOM/Arranjo.h ./Codificador/Dado.h ./SOM/Neuronio.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/Arranjo.cpp -o Arranjo.o

Neuronio.o: ./SOM/Neuronio.cpp ./SOM/Neuronio.h ./Calculos/Calculos.h ./Codificador/Dado.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/Neuronio.cpp -o Neuronio.o

SOM.o: ./SOM/SOM.cpp ./SOM/MensagensSOM.cpp ./SOM/SOM.h versao.h ./Calculos/Calculos.h ./Codificador/Dado.h ./Codificador/ConjuntoDados.h ./SOM/Neuronio.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/SOM.cpp -o SOM.o

MensagensSOM.o: ./SOM/MensagensSOM.cpp ./SOM/SOM.h versao.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./SOM/MensagensSOM.cpp -o MensagensSOM.o

MapaContextual.o: ./Visualizacao/MapaContextual.cpp ./Visualizacao/MapaContextual.h ./Visualizacao/Visualizacao.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Visualizacao/MapaContextual.cpp -o MapaContextual.o

Visualizacao.o: ./Visualizacao/Visualizacao.cpp ./Visualizacao/Visualizacao.h ./Codificador/Dado.h ./Codificador/ConjuntoDados.h ./SOM/Neuronio.h ./SOM/Arranjo.h
	g++ -std=c++17 -fopenmp -O3 -c -Wall -Wextra -pedantic ./Visualizacao/Visualizacao.cpp -o Visualizacao.o

tidy:
	rm -f *.o

clean:
	rm -f *.o ./SegmentadorSOM

# Comando completo
# g++ -std=c++17 -fopenmp -O3 -Wall -Wextra -pedantic main.cpp ./Arquivos/*.cpp ./Calculos/*.cpp ./Codificador/*.cpp ./Controlador/*.cpp ./SOM/*.cpp ./Visualizacao/*.cpp -lboost_serialization -lboost_system -o SegmentadorSOM
