//======================================================================================================================
// Name        : Arranjo.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.2-alpha
// Copyright   : Copyright © 2007-2022 Manoel Jorge Ribeiro Neto <manoeljorge.neto@gmail.com>
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

// Cria uma posição 2D, dado um inteiro
vector<unsigned>* Arranjo::criaPosicao2D(unsigned n) const {
    unsigned pos_x = n % this->largura; // Cálculo das posições
    unsigned pos_y = n / this->altura;

    auto* pos = new vector<unsigned>(2);
    pos->at(0) = pos_x, pos->at(1) = pos_y;

    return pos;
}

// Cria um neurônio na posição correta no arranjo
Neuronio* Arranjo::criaNeuronio(unsigned n) {
    return new Neuronio(this->dimensao, this->criaPosicao2D(n), "", this->normalizados);
}

// Construtor
Arranjo::Arranjo(unsigned largura, unsigned dimensao_entrada, bool normalizados) {
    this->largura = largura;
    this->altura = largura; // Pois é um arranjo quadrado
    this->tamanho = this->largura * this->altura;

    this->normalizados = normalizados;

    this->dimensao = dimensao_entrada;
    this->neuronios = new vector<Neuronio*>(this->tamanho); // Cria o vetor de neurônios

    // Preenche o vetor dos neurônios
    #pragma omp parallel for
    for(unsigned i = 0; i < this->tamanho; i++)
        this->neuronios->at(i) = this->criaNeuronio(i);
}

// Destrutor
Arranjo::~Arranjo() {
    delete this->neuronios;
}

/**
 * Faz a competição entre os neurônios para descobrir quem é o vencedor:
 * O vencedor é o neurônio cujo vetor de pesos sinápticos tem a menor distância em relação
 * ao vetor de dados apresentado.
 */
vector<Neuronio*>::iterator Arranjo::getVencedor(Dado* dado, bool marcar) {
    auto vencedor = this->neuronios->begin(); // Obtém o primeiro neurônio e guarda em vencedor
    double menor_distancia = (*vencedor)->getDistancia(dado); // Calcula a distância

    // Percorre os neurônios para descobrir qual tem menor distância
    for(auto aux = this->neuronios->begin(); aux != this->neuronios->end(); aux++)
        if( ((*aux)->getDistancia(dado) < menor_distancia && !(*aux)->getMarcado()) || (*vencedor)->getMarcado() ) {
            vencedor = aux;
            menor_distancia = (*vencedor)->getDistancia(dado);
        }

    if(marcar) // Tem utilidade no Mapa Contextual
        (*vencedor)->setMarcado(true);

    return vencedor;
}

// Gets
unsigned Arranjo::getLargura() const {
    return this->largura;
}

unsigned Arranjo::getAltura() const {
    return this->altura;
}

unsigned Arranjo::getTamanho() const {
    return this->tamanho;
}

bool Arranjo::getNormalizados() const {
    return this->normalizados;
}

unsigned Arranjo::getDimensao() const {
    return this->dimensao;
}

vector<Neuronio*>* Arranjo::getNeuronios() {
    return this->neuronios;
}

// Retorna uma string exibindo os parâmetros dos neurônios
string Arranjo::toString() {
    ostringstream str("");

    for(const auto & neuronio : *(this->neuronios))
        str << neuronio->toString() << endl;

    return str.str();
}
