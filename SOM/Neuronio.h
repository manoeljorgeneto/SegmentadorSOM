// Classe Neurônio, que é a base do algoritmo SOM de Kohonen

#ifndef NEURONIO_H_
#define NEURONIO_H_

#include <vector>
#include <cmath>
#include <string>
#include <sstream>

#include "../Calculos/Calculos.h"
#include "../Codificador/Dado.h"

using namespace std;

class Neuronio {
	
	vector<double>* pesos; // Vetor de pesos sinápticos
	vector<unsigned int>* posicao; // Vetor da posiçãoo do neurônio no arranjo
	
	unsigned int dim_entrada; // Dimensão de entrada
	unsigned int dim_saida; // Dimensão de saída
	
	string rotulo; // Servem para o Mapa Contextual
	bool marcado;
	
public:

	Neuronio(unsigned int dim_entrada, vector<unsigned int>* posicao, string rotulo = ""); // Construtor
	Neuronio(vector<double> *pesos, vector<unsigned int>* posicao, string rotulo = ""); // Construtor
	virtual ~Neuronio(); // Destrutor
	
	// Gets e sets
	unsigned int getDim(); // Dimensão de entrada
	vector<double>* getPesos();	
	vector<unsigned int>* getPosicao(); // Posição do neurônio no arranjo
	string getRotulo();
	bool getMarcado();
	
	void setPesos(vector<double>* pesos);
	void setRotulo(string rotulo);
	void setMarcado(bool marcado);

	double getDistancia(const vector<double> &vetor); // Distância euclidiana
	void normaliza(); // Normaliza seus pesos sinápticos

	double calculaDistanciaEspacial(Neuronio* n); // Retorna a distância espacial entre dois neurônios

	double calculaVizinhanca(Neuronio* n, double sigma); // Calcula a função de vizinhança do neurônio, dado um vencedor
	
	/* Atualiza o neurônio, segundo o algoritmo da Seção 3.2.3
	 * E depois normaliza o vetor de pesos */
	void atualiza(Neuronio* vencedor, Dado* dado, double eta, double sigma);
	
	virtual string toString(); // Converte para String
};

#endif // NEURONIO_H_
