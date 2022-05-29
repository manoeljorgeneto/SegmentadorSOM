// Classe que representa os dados que alimentarão o SOM

#ifndef DADO_H_
#define DADO_H_

#include <vector>
#include <cmath>
#include <string>
#include <sstream>

#include "../Calculos/Calculos.h"

using namespace std;

class Dado {
    string rotulo; // Rótulo que marca o dado (serve para a formação de um Mapa Contextual)
	 
    vector<double>* dados; // Vetor que representa o dado
    unsigned int dimensao; // Dimensão do dado
    bool marcado; // Serve para os algoritmos SOM e do Mapa Contextual
	
public:
    Dado(unsigned int dimensao, string rotulo = ""); // Construtor
    Dado(vector<double>* dados , string rotulo = ""); // Construtor
    virtual ~Dado(); // Destrutor
	
	// Gets e sets
    string getRotulo();
    vector<double>* getDados();
    bool getMarcado();
	
    void setRotulo(string rotulo);
    void setDados(vector<double>* dados);
    void setMarcado(bool marcado);
	
    void normaliza(); // Normaliza o vetor de dados
	
    virtual string toString(); // Converte para String
};

#endif // DADO_H_
