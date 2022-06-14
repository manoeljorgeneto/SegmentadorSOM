//======================================================================================================================
// Name        : Dado.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.1-alpha
// Copyright   : Copyright© 2007-2022, Manoel Jorge Ribeiro Neto. All rights reserved.
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
Dado::Dado(unsigned int dimensao, string rotulo) {
    this->dimensao = dimensao;
    this->rotulo = rotulo;
    this->marcado = false;
    this->dados = new vector<double>(this->dimensao);
}

// Construtor
Dado::Dado(vector<double>* dados , string rotulo) {
    this->dados = dados;
    this->dimensao = this->dados->size();
    this->rotulo = rotulo;
    this->marcado = false;
}

// Destrutor
Dado::~Dado() {	
    delete this->dados;
}

// Gets e sets
string Dado::getRotulo() {
    return this->rotulo;
}

vector<double>* Dado::getDados() {
    return this->dados;
}

bool Dado::getMarcado() {
    return this->marcado;
}
	
void Dado::setRotulo(string rotulo) {
    this->rotulo = rotulo;
}

void Dado::setDados(vector<double>* dados) {
    this->dados = dados;
    this->dimensao = this->dados->size();
}

void Dado::setMarcado(bool marcado) {
    this->marcado = marcado;
}

// Normaliza o vetor de dados
void Dado::normaliza() {
    Calculos::normalizaVetor(this->dados);
}

// Converte para String
string Dado::toString() {
    ostringstream str("");
	
    str << "Dado(" << this->rotulo << "): ";
    for(unsigned int i = 0; i < this->dimensao; i++)
        str << this->dados->at(i) << " ";
	
    return str.str();
}
