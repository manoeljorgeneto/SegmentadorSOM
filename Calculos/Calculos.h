//======================================================================================================================
// Name        : Calculos.h
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

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include <vector>
#include <cmath>

using namespace std;

/**
 * Sobrecarga de operadores.
 */
vector<double> operator+(const vector<double>& a, const vector<double>& b); // Soma de vetores
vector<double> operator-(const vector<double>& a, const vector<double>& b); // Subtração de vetores
vector<double> operator*(const vector<double>& a, double b); // Multiplicação por um Real
vector<double> operator*(double a, const vector<double>& b); // Multiplicação por um Real
vector<double> operator/(const vector<double>& a, double b); // Divisão por um Real
double operator*(const vector<double>& a, const vector<double>& b); // Produto interno

/**
 * Classe para efetuar cálculos diversos entre vetores de doubles.
 */
class Calculos {
	
public:
    Calculos(); // Construtor
    virtual ~Calculos(); // Destrutor

    static double calculaNorma(const vector<double>& a); // Módulo do vetor: ||a|| = √(a * a)
    static void normalizaVetor(vector<double>* a); // Normaliza o vetor (deixando-o com norma igual a 1)
    static double calculaDistancia(const vector<double>& a, const vector<double>& b); // Distância euclidiana
};

#endif // CALCULOS_H_
