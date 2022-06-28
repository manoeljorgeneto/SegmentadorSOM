//======================================================================================================================
// Name        : Calculos.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.2-alpha
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

#include "../Calculos/Calculos.h"

// Construtor
Calculos::Calculos() {
	
}

// Destrutor
Calculos::~Calculos() {
	
}

// Módulo do vetor
double Calculos::calculaNorma(const vector<double> &a) {	
    double distancia = 0.0;
		
    for(unsigned int i = 0 ; i < a.size(); i++)
        distancia += pow(a.at(i), 2.0);
		
    return sqrt(distancia);
}

void Calculos::normalizaVetor(vector<double> *a) {
    // Calcula a norma do vetor
    double norma = Calculos::calculaNorma(*a);
	
    // Normaliza o vetor
    for(unsigned int i = 0; i < a->size(); i++)
        a->at(i) /= norma;
}

// Distância euclidiana
double Calculos::calculaDistancia(const vector<double> &a, const vector<double> &b) {	
    double dif, distancia = 0.0;
		
    for(unsigned int i = 0 ; i < a.size(); i++) {
        dif = a.at(i) - b.at(i);
        distancia += pow(dif, 2.0);
    }
		
    return sqrt(distancia);
}

// ********************************************************************************************************************
// Sobrecarga de operadores
// ********************************************************************************************************************

// Soma de dois vetores
vector<double> operator+ (vector<double> &a, vector<double> &b) {
    vector<double> vetorSoma(a.size());
	
    for(unsigned int i = 0; i < a.size(); i++)
        vetorSoma.at(i) = a.at(i) + b.at(i);
	
    return vetorSoma;
}

// Subtração de dois vetores
vector<double> operator- (vector<double> &a, vector<double> &b) {
    vector<double> vetorSub(a.size());
	
    for(unsigned int i = 0; i < a.size(); i++)
        vetorSub.at(i) = a.at(i) - b.at(i);
	
    return vetorSub;
}

vector<double> operator/ (vector<double> &a, double b) { // Divisão por um Real
    vector<double> vetorDiv(a.size());
	
    for(unsigned int i = 0; i < a.size(); i++)
        vetorDiv.at(i) = a.at(i)/b;
	
    return vetorDiv;
}

vector<double> operator* (vector<double> &a, double b) { // Multiplicação por um Real
    vector<double> vetorMult(a.size());

    for (unsigned int i = 0; i < a.size(); i++)
        vetorMult.at(i) = a.at(i) * b;

    return vetorMult;
}

vector<double> operator* (double a, vector<double> &b) { // Multiplicação por um Real
    return b*a;
}

double operator* (vector<double> &a, vector<double> &b) { // Produto interno
    double prodInter = 0.0;
	
    for(unsigned int i = 0; i < a.size(); i++)
        prodInter += a.at(i)*b.at(i);
	
    return prodInter;
}
