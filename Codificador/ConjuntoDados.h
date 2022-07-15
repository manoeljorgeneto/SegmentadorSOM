//======================================================================================================================
// Name        : ConjuntoDados.h
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

#ifndef CONJUNTODADOS_H
#define CONJUNTODADOS_H

#include <vector>
#include <sstream>

#include "../Codificador/Dado.h"

using namespace std;

/**
 * Classe que armazena um conjunto de dados.
 */
class ConjuntoDados {
protected:
    unsigned tamanho{}; // Tamanho do conjunto de dados
    unsigned dimensao{}; // Dimensão dos vetores de dados

    bool normalizados; // Define se os dados terão seus valores normalizados

    vector<Dado*>* dados; // Contêiner onde estarão os dados

public:
    explicit ConjuntoDados(bool normalizados = true); // Construtor
    virtual ~ConjuntoDados(); // Destrutor

    void adicionaDado(Dado* d); // Adiciona um dado ao conjunto

    // Gets
    [[nodiscard]] unsigned getTamanho() const;
    [[nodiscard]] unsigned getDimensao() const;
    [[nodiscard]] bool getNormalizados() const;
    vector<Dado*>* getDados();

    virtual string toString(); // Retorna uma string com os dados armazenados
};

#endif // CONJUNTODADOS_H
