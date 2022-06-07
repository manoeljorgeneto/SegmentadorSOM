//======================================================================================================================
// Name        : Arranjo.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.1-alpha
// Copyright   : Copyright© 2007-2022 Manoel Jorge Ribeiro Neto
// Description : Programa SegmentadorSOM, que utiliza o algoritmo SOM de Kohonen.
//
// This file is part of SegmentadorSOM.
//
// SegmentadorSOM is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// SegmentadorSOM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with SegmentadorSOM. If not, see
// <https://www.gnu.org/licenses/>
//======================================================================================================================

#include "../SOM/Arranjo.h"

vector<unsigned int>* Arranjo::criaPosicao(unsigned int n) {
    unsigned int pos_x = n % this->largura; // Cálculo das posições
    unsigned int pos_y = n / this->largura;
	
    vector<unsigned int>* pos = new vector<unsigned int>(2);
    pos->at(0) = pos_x; pos->at(1) = pos_y;
	
    return pos;
}
 
Neuronio* Arranjo::criaNeuronio(unsigned int n) {			 
    return new Neuronio(this->dimensao,this->criaPosicao(n));
}

// Construtor
Arranjo::Arranjo(unsigned int largura, unsigned int dimensao_entrada) {
    this->largura = largura;
    this->tamanho = largura*largura; // Pois é um arranjo quadrado
    this->dimensao = dimensao_entrada;
		
    this->neuronios = new vector<Neuronio*>(this->tamanho); // Cria o vetor de neurônios
	
	// Criação dos neurônios
    #pragma omp parallel for
    for(unsigned int i = 0; i < this->tamanho; i++)
        this->neuronios->at(i) = this->criaNeuronio(i);
}

// Destrutor
Arranjo::~Arranjo() {
    delete this->neuronios;
}

// Gets e sets
vector<Neuronio*>* Arranjo::getNeuronios() {
    return this->neuronios;
}

unsigned int Arranjo::getDimensao() {
    return this->dimensao;
}

unsigned int Arranjo::getLargura() {
    return this->largura;
}

unsigned int Arranjo::getTamanho() {
    return this->tamanho;
}

void Arranjo::setNeuronios(vector<Neuronio*>* neuronios) {
    this->neuronios = neuronios;
}

/* Faz a competição entre os neurônios para descobrir quem é o vencedor:
 * O vencedor é o neurônio cujo vetor de pesos sinápticos tem a menor distância em relação
 * ao vetor de dados apresentado */
vector<Neuronio*>::iterator Arranjo::getVencedor(Dado* dado, bool marcar) {
    vector<Neuronio*>::iterator vencedor = this->neuronios->begin(); // Obtém o primeiro neurônio e guarda em vencedor
    double menor_distancia = (*vencedor)->getDistancia(*(dado->getDados())); // Calcula a distância
	
	// Percorre os neurônios para descobrir qual tem menor distância
    //#pragma omp parallel for
    for(vector<Neuronio*>::iterator aux = this->neuronios->begin(); aux != this->neuronios->end(); aux++)
        if(((*aux)->getDistancia(*(dado)->getDados()) < menor_distancia && !(*aux)->getMarcado()) ||
            (*vencedor)->getMarcado()) {
            vencedor = aux;
            menor_distancia = (*vencedor)->getDistancia(*(dado)->getDados());
        }
	
    if(marcar) // Tem utilidade no Mapa Contextual
        (*vencedor)->setMarcado(true);

    return vencedor;
}
