//======================================================================================================================
// Name        : Visualizacao.h
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

#ifndef VISUALIZACAO_H
#define VISUALIZACAO_H

#include <vector>
#include <omp.h>

#include "../Codificador/Dado.h"
#include "../Codificador/ConjuntoDados.h"
#include "../SOM/Neuronio.h"
#include "../SOM/Arranjo.h"

using namespace std;

/**
 * Classe que serve como super classe para diferentes formas de visualização do SOM.
 */
class Visualizacao {
protected:
    static void desmarcaNeuronios(Arranjo* arranjo); // Desmarca todos os neurônios do arranjo
    static bool todosNeuroniosMarcados(Arranjo* arranjo); // Verifica se todos os neurônios do arranjo estão marcados

public:
    Visualizacao(); // Construtor
    virtual ~Visualizacao(); // Destrutor
};

#endif // VISUALIZACAO_H
