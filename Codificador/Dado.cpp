//======================================================================================================================
// Name        : Dado.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.3-alpha
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

#include "../Codificador/Dado.h"

// Construtor
Dado::Dado(unsigned dimensao, string rotulo) {
    this->dimensao = dimensao;
    this->rotulo = std::move(rotulo);
    this->marcado = false;
    this->dados = new vector<double>(this->dimensao);
}

// Construtor
Dado::Dado(vector<double>* dados , string rotulo) {
    this->dados = dados;
    this->dimensao = this->dados->size();
    this->rotulo = std::move(rotulo);
    this->marcado = false;
}

// Destrutor
Dado::~Dado() {	
    delete this->dados;
}

// Normaliza o vetor de dados
void Dado::normaliza() {
    Calculos::normalizaVetor(this->dados);
}

// Gets e sets
string Dado::getRotulo() {
    return this->rotulo;
}

vector<double>* Dado::getDados() {
    return this->dados;
}

unsigned Dado::getDimensao() const {
    return this->dimensao;
}

bool Dado::getMarcado() const {
    return this->marcado;
}

void Dado::setMarcado(bool marcado) {
    this->marcado = marcado;
}

// Converte para string
string Dado::toString() {
    ostringstream str("");

    str << "Dado(" << this->rotulo << "): ";
    for(unsigned i = 0; i < this->dimensao; i++)
        str << this->dados->at(i) << " ";

    return str.str();
}
