//======================================================================================================================
// Name        : Neuronio.cpp
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

#include "../SOM/Neuronio.h"

// Retorna a distância espacial entre o neurônio e outro no arranjo de neurônios
double Neuronio::calculaDistanciaEspacial(Neuronio* n) {
    // Vetores auxiliares, que servirão para a conversão de inteiro para double
    vector<double> this_pos(this->dim_saida), n_pos(this->dim_saida);

    // Converte os vetores de posição de inteiro para double
    for(unsigned i = 0; i < this->posicao->size(); i++) // Posição do neurônio
        this_pos.at(i) = double(this->posicao->at(i));

    for(unsigned i = 0; i < n->getPosicao()->size(); i++) // Posição do outro neurônio
        n_pos.at(i) = (double)n->getPosicao()->at(i);

    return Calculos::calculaDistancia(this_pos, n_pos);
}

// Calcula a função de vizinhança do neurônio, dado um vencedor
double Neuronio::calculaVizinhanca(Neuronio* n, double sigma) {
    return exp(-pow(this->calculaDistanciaEspacial(n), 2.0) / (2.0 * pow(sigma, 2.0)));
}

// Construtor (criando um novo neurônio)
Neuronio::Neuronio(unsigned dim_entrada, vector<unsigned>* posicao, string rotulo, bool normalizado) {
    this->pesos = new vector<double>(dim_entrada);
    this->posicao = posicao;

    this->dim_entrada = dim_entrada;
    this->dim_saida = this->posicao->size();

    this->rotulo = std::move(rotulo);
    this->marcado = false;

    this->normalizado = normalizado;
}

// Construtor (criando um novo neurônio, definindo o vetor de pesos sinápticos)
Neuronio::Neuronio(vector<double>* pesos, vector<unsigned>* posicao, string rotulo, bool normalizado) {
    this->pesos = pesos;
    this->posicao = posicao;

    this->dim_entrada = this->pesos->size();
    this->dim_saida = this->posicao->size();

    this->rotulo = std::move(rotulo);
    this->marcado = false;

    this->normalizado = normalizado;

    if(this->normalizado) // Normaliza o vetor de pesos do neurônio
        this->normaliza();
}

// Destrutor
Neuronio::~Neuronio() {	
    delete this->pesos;
    delete this->posicao;
}

// Normaliza seus pesos sinápticos
void Neuronio::normaliza() {
    Calculos::normalizaVetor(this->pesos);
}

// Calcula a distância euclidiana entre os pesos sinápticos do neurônio e o vetor de valores de um dado
double Neuronio::getDistancia(Dado* d) {
    return Calculos::calculaDistancia(*this->pesos, *d->getDados());
}

/**
 * Faz a equação:
 * w(n + 1) = w(n) + eta(n) * h(i(x), n) * [x - w(n)]
 * E depois normaliza o vetor de pesos sinápticos, caso esteja marcado para tal operação.
 */
void Neuronio::atualiza(Neuronio* vencedor, Dado* dado,	double eta, double sigma) {
    double h = this->calculaVizinhanca(vencedor, sigma); // Acha o nível de vizinhança: h(i(x), n)
    double plasticidade = eta * h; // Define o quão será atualizado o neurônio: eta(n) * h(i(x), n)

    // Acha a subtração [x - w(n)]
    vector<double> dif = *dado->getDados() - *this->pesos;

    // Multiplica pela plasticidade: eta(n) * h(i(x), n) * [x - w(n)]
    dif = plasticidade * dif;

    // Altera os pesos do neurônio: w(n + 1) = w(n) + eta(n) * h(i(x), n) * [x - w(n)]
    *this->pesos = *this->pesos + dif;

    if(this->normalizado) // Normaliza o vetor de pesos do neurônio
        this->normaliza();
}

// Gets e sets
vector<double>* Neuronio::getPesos() {
    return this->pesos;
}

vector<unsigned>* Neuronio::getPosicao() {
    return this->posicao;
}

string Neuronio::getRotulo() {
    return this->rotulo;
}

bool Neuronio::getMarcado() const {
    return this->marcado;
}

bool Neuronio::getNormalizado() const {
    return this->normalizado;
}

void Neuronio::setRotulo(string rotulo) {
    this->rotulo = std::move(rotulo);
}

void Neuronio::setMarcado(bool marcado) {
    this->marcado = marcado;
}

// Converte para string
string Neuronio::toString() {
    ostringstream str("");

    str << "Neuronio pos(" << this->posicao->at(0) << "," << this->posicao->at(1) << "): ";
    for(unsigned i = 0; i < this->dim_entrada; i++)
        str << this->pesos->at(i) << " ";

    return str.str();
}
