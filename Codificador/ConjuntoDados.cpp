//======================================================================================================================
// Name        : ConjuntoDados.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.5-alpha
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

#include "ConjuntoDados.h"

// Construtor
ConjuntoDados::ConjuntoDados(bool normalizados) {
    this->normalizados = normalizados;
    this->dados = new vector<Dado*>; // Cria o vetor de dados
}

// Destrutor
ConjuntoDados::~ConjuntoDados() {
    delete this->dados;
}

// Adiciona um dado ao conjunto
void ConjuntoDados::adicionaDado(Dado* d) {
    if(this->dados->empty())
        this->dimensao = d->getDimensao(); // Define a dimensão dos dados armazenados

    if(this->normalizados)
        d->normaliza(); // Normaliza o dado

    this->dados->push_back(d); // Adiciona
    this->tamanho = this->dados->size(); // Atualiza o tamanho do conjunto
}

// Gets
unsigned ConjuntoDados::getTamanho() const {
    return this->tamanho;
}

unsigned ConjuntoDados::getDimensao() const {
    return this->dimensao;
}

bool ConjuntoDados::getNormalizados() const {
    return this->normalizados;
}

vector<Dado*>* ConjuntoDados::getDados() {
    return this->dados;
}

// Retorna uma string com os dados armazenados
string ConjuntoDados::toString() {
    ostringstream str("");

    for(const auto & dado : *(this->dados))
        str << dado->toString() << endl;

    return str.str();
}
