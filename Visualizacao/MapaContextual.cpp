//======================================================================================================================
// Name        : MapaContextual.cpp
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

#include "../Visualizacao/MapaContextual.h"

// Desmarca todos os neurônios
void MapaContextual::desmarcaNeuronios(Arranjo* arranjo) {
    #pragma omp parallel for
    for(auto & neuronio : *arranjo->getNeuronios())
        neuronio->setMarcado(false);
}

// Verifica se todos os neurônios estão marcados
bool MapaContextual::todosNeuroniosMarcados(Arranjo* arranjo) {
    for(auto & neuronio : *arranjo->getNeuronios())
        if(!neuronio->getMarcado())
            return false;
    return true;
}

// Constrói a string com o Mapa Contextual
string MapaContextual::geraStrMapa(Arranjo* arranjo) {
    ostringstream mapa("");

    // Percorre todos os neurônios e escreve os seus rótulos em mapa
    unsigned i = 0, largura = arranjo->getLargura();
    for(auto & neuronio : *arranjo->getNeuronios()) {
        if((i % largura == 0) && (i != 0))
            mapa << endl;
        mapa << neuronio->getRotulo() << "		";
        i++;
    }

    return mapa.str();
}

// Construtor
MapaContextual::MapaContextual() = default;

// Destrutor
MapaContextual::~MapaContextual() = default;

// Gera um Mapa Contextual
string MapaContextual::geraMapa(vector<Dado*>* dados, Arranjo* arranjo) {
    this->desmarcaNeuronios(arranjo); // Desmarca todos os neurônios

    // Cria o Mapa Contextual
    while(!this->todosNeuroniosMarcados(arranjo)) {
        unsigned i = 0;
        do {
            auto* d = dados->at(i);
            auto vencedor = arranjo->getVencedor(d, true); // Acha o vencedor e marca-o
            (*vencedor)->setRotulo(d->getRotulo()); // Rotula o neurônio
            i++;
        } while((i < dados->size()) && !this->todosNeuroniosMarcados(arranjo));
    }

    this->desmarcaNeuronios(arranjo); // Desmarca todos os neurônios

    return this->geraStrMapa(arranjo); // Retorna a string com o Mapa Contextual
}
