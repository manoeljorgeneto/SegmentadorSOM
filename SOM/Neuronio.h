//======================================================================================================================
// Name        : Neuronio.h
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

// Classe Neurônio, que é a base do algoritmo SOM de Kohonen

#ifndef NEURONIO_H_
#define NEURONIO_H_

#include <vector>
#include <cmath>
#include <string>
#include <sstream>

#include "../Calculos/Calculos.h"
#include "../Codificador/Dado.h"

using namespace std;

class Neuronio {
protected:
    vector<double>* pesos; // Vetor de pesos sinápticos
    vector<unsigned>* posicao; // Vetor da posiçãoo do neurônio no arranjo
	
    unsigned dim_entrada; // Dimensão de entrada
    unsigned dim_saida; // Dimensão de saída
	
    string rotulo; // Servem para o Mapa Contextual
    bool marcado;
	
public:
    Neuronio(unsigned dim_entrada, vector<unsigned>* posicao, string rotulo = ""); // Construtor
    Neuronio(vector<double> *pesos, vector<unsigned>* posicao, string rotulo = ""); // Construtor
    virtual ~Neuronio(); // Destrutor
	
    // Gets e sets
    unsigned getDim(); // Dimensão de entrada
    vector<double>* getPesos();
    vector<unsigned>* getPosicao(); // Posição do neurônio no arranjo
    string getRotulo();
    bool getMarcado();
	
    void setPesos(vector<double>* pesos);
    void setRotulo(string rotulo);
    void setMarcado(bool marcado);

    virtual double getDistancia(const vector<double> &vetor); // Distância euclidiana
    void normaliza(); // Normaliza seus pesos sinápticos

    virtual double calculaDistanciaEspacial(Neuronio* n); // Retorna a distância espacial entre dois neurônios

    // Calcula a função de vizinhança do neurônio, dado um vencedor
    virtual double calculaVizinhanca(Neuronio* n, double sigma);

    /* Faz a equação:
     * w(n+1) = w(n) + eta(n)*h(i(x),n)*[x - w(n)]
     * E depois normaliza o vetor de pesos sinápticos */
    virtual void atualiza(Neuronio* vencedor, Dado* dado, double eta, double sigma);

    virtual string toString(); // Converte para String
};

#endif // NEURONIO_H_
