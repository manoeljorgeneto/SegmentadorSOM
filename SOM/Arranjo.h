//======================================================================================================================
// Name        : Arranjo.h
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

/* Arranjo de neurônios bidimensional e quadrado.
 * Ou seja, com largura e altura idênticas (L*L) */

#ifndef ARRANJO_H_
#define ARRANJO_H_

#include <vector>
#include <omp.h>

#include "../Codificador/Dado.h"
#include "../SOM/Neuronio.h"

using namespace std;

class Arranjo {
protected:
    vector<Neuronio*>* neuronios; // Contêiner onde estarão os neurônios
    unsigned dimensao; // Dimensão dos vetores de pesos sinápticos do neurônios
	
    unsigned largura; // Largura (e altura também) do arranjo
    unsigned tamanho; // Tamanho do arranjo
	
    [[nodiscard]] vector<unsigned>* criaPosicao(unsigned n) const; // Cria uma posição 2D, dado um inteiro
    Neuronio* criaNeuronio(unsigned n); // Cria um neurônio na posição correta no arranjo
	
public:
    Arranjo(unsigned largura, unsigned dimensao_entrada); // Construtor
    virtual ~Arranjo(); // Destrutor
	
    // Gets e sets
    vector<Neuronio*>* getNeuronios();
    [[nodiscard]] unsigned getDimensao() const;
    [[nodiscard]] unsigned getLargura() const;
    [[nodiscard]] unsigned getTamanho() const;
    void setNeuronios(vector<Neuronio*>* neuronios);

    /* Faz a competição entre os neurônios para descobrir quem é o vencedor:
     * O vencedor é o neurônio cujo vetor de pesos sinápticos tem a menor distância em relação
     * ao vetor de dados apresentado */
    vector<Neuronio*>::iterator getVencedor(Dado* dado, bool marcar = false);
};

#endif // ARRANJO_H_
