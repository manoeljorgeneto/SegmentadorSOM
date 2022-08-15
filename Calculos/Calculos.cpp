//======================================================================================================================
// Name        : Calculos.cpp
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

#include "../Calculos/Calculos.h"

// Soma de dois vetores
vector<double> operator+(const vector<double>& a, const vector<double>& b) {
    vector<double> vetorSoma(a.size());

    for(unsigned i = 0; i < a.size(); i++)
        vetorSoma.at(i) = a.at(i) + b.at(i);

    return vetorSoma;
}

// Subtração de dois vetores
vector<double> operator-(const vector<double>& a, const vector<double>& b) {
    vector<double> vetorSub(a.size());

    for(unsigned i = 0; i < a.size(); i++)
        vetorSub.at(i) = a.at(i) - b.at(i);

    return vetorSub;
}

vector<double> operator*(const vector<double>& a, double b) { // Multiplicação por um Real
    vector<double> vetorMult(a.size());

    for (unsigned i = 0; i < a.size(); i++)
        vetorMult.at(i) = a.at(i) * b;

    return vetorMult;
}

vector<double> operator*(double a, const vector<double>& b) { // Multiplicação por um Real
    return b*a;
}

vector<double> operator/(const vector<double>& a, double b) { // Divisão por um Real
    return a*(1.0/b);
}

double operator*(const vector<double>& a, const vector<double>& b) { // Produto interno
    double prodInter = 0.0;

    for(unsigned i = 0; i < a.size(); i++)
        prodInter += a.at(i)*b.at(i);

    return prodInter;
}

// Módulo do vetor: ||a|| = √(a * a)
double Calculos::calculaNorma(const vector<double>& a) {
    return sqrt(a * a);
}

// Normaliza o vetor (deixando-o com norma igual a 1)
void Calculos::normalizaVetor(vector<double>* a) {
    double norma = Calculos::calculaNorma(*a); // Calcula a norma do vetor

    if(norma != 0.0) // Para evitar divisão por zero
        *a = *a / norma;
}

// Distância euclidiana
double Calculos::calculaDistancia(const vector<double>& a, const vector<double>& b) {
    double distancia = 0.0;

    for(unsigned i = 0 ; i < a.size(); i++)
        distancia += pow((a.at(i) - b.at(i)), 2.0);

    return sqrt(distancia);
}
