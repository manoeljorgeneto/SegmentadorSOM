/* Arranjo de neurônios bidimensional e quadrado.
 * Ou seja, com largura e altura idênticas (L*L) */

#ifndef ARRANJO_H_
#define ARRANJO_H_

#include <vector>

#include "../Codificador/Dado.h"
#include "../SOM/Neuronio.h"

using namespace std;

class Arranjo {
	vector<Neuronio*>* neuronios; // Contêiner onde estarão os neurônios
	unsigned int dimensao; // Dimensão dos vetores de pesos sinápticos do neurônios
	
	unsigned int largura; // Largura (e altura também) do arranjo
	unsigned int tamanho; // Tamanho do arranjo
	
	vector<unsigned int>* criaPosicao(unsigned int n); // Cria uma posição 2D, dado um inteiro
	Neuronio* criaNeuronio(unsigned int n); // Cria um neurônio na posição correta no arranjo
	
public:
	Arranjo(unsigned int largura, unsigned int dimensao_entrada); // Construtor
	virtual ~Arranjo(); // Destrutor
	
	// Gets e sets
	vector<Neuronio*>* getNeuronios();
	unsigned int getDimensao();
	unsigned int getLargura();
	unsigned int getTamanho();
	void setNeuronios(vector<Neuronio*>* neuronios);

	// Retorna o iterador para o neurônio vencedor
	vector<Neuronio*>::iterator getVencedor(Dado* dado, bool marcar = false);
};

#endif // ARRANJO_H_
