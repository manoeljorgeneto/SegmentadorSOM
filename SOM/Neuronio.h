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

#ifndef NEURONIO_H_
#define NEURONIO_H_

#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <sstream>

#include "../Calculos/Calculos.h"
#include "../Codificador/Dado.h"

using namespace std;

/**
 * Classe Neurônio, que é a base do algoritmo SOM de Kohonen.
 */
class Neuronio {
protected:
    vector<double>* pesos; // Vetor de pesos sinápticos
    vector<unsigned>* posicao; // Vetor da posição do neurônio no arranjo
	
    unsigned dim_entrada; // Dimensão de entrada dos dados
    unsigned dim_saida; // Dimensão do arranjo onde o neurônio está localizado
	
    string rotulo; // Servem para o Mapa Contextual
    bool marcado;

    bool normalizado; // Define se o neurônio sempre normalizará seus pesos ou não

    void normaliza(); // Normaliza seus pesos sinápticos

    // Retorna a distância espacial entre o neurônio e outro no arranjo de neurônios
    virtual double calculaDistanciaEspacial(Neuronio* n);

    // Calcula a função de vizinhança do neurônio, dado um vencedor
    virtual double calculaVizinhanca(Neuronio* n, double sigma);
	
public:
    // Construtor (criando um novo neurônio)
    Neuronio(unsigned dim_entrada, vector<unsigned>* posicao, string rotulo = "", bool normalizado = true);
    // Construtor (criando um novo neurônio, definindo o vetor de pesos sinápticos)
    Neuronio(vector<double>* pesos, vector<unsigned>* posicao, string rotulo = "", bool normalizado = true);
    virtual ~Neuronio(); // Destrutor

    // Calcula a distância euclidiana entre os pesos sinápticos do neurônio e o vetor de valores de um dado
    virtual double getDistancia(Dado* d);

    /**
     * Faz a equação:
     * w(n + 1) = w(n) + eta(n) * h(i(x), n) * [x - w(n)]
     * E depois normaliza o vetor de pesos sinápticos, caso esteja marcado para tal operação.
     */
    virtual void atualiza(Neuronio* vencedor, Dado* dado, double eta, double sigma);

    // Gets e sets
    vector<double>* getPesos();
    vector<unsigned>* getPosicao();
    string getRotulo();
    [[nodiscard]] bool getMarcado() const;
    [[nodiscard]] bool getNormalizado() const;

    void setRotulo(string rotulo);
    void setMarcado(bool marcado);

    virtual string toString(); // Converte para string
};

#endif // NEURONIO_H_
