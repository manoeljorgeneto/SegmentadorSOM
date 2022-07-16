//======================================================================================================================
// Name        : Visualizacao.cpp
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

#include "../Visualizacao/Visualizacao.h"

// Desmarca todos os neurônios
void Visualizacao::desmarcaNeuronios(Arranjo* arranjo) {
    #pragma omp parallel for
    for(auto & neuronio : *arranjo->getNeuronios())
        neuronio->setMarcado(false);
}

// Verifica se todos os neurônios estão marcados
bool Visualizacao::todosNeuroniosMarcados(Arranjo* arranjo) {
    for(auto & neuronio : *arranjo->getNeuronios())
        if(!neuronio->getMarcado())
            return false;
    return true;
}

// Construtor
Visualizacao::Visualizacao() = default;

// Destrutor
Visualizacao::~Visualizacao() = default;
