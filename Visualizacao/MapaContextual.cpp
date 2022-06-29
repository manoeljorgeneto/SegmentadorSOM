//======================================================================================================================
// Name        : main.cpp
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
void MapaContextual::desmarcaNeuronios(vector<Neuronio*>* neuronios) {
    #pragma omp parallel for
    for(vector<Neuronio*>::iterator i = neuronios->begin(); i != neuronios->end(); i++)
        (*i)->setMarcado(false);
}

// Verifica se todos os neurônios estão marcados
bool MapaContextual::todosNeuroniosMarcados(vector<Neuronio*>* neuronios) {
    for(vector<Neuronio*>::iterator i = neuronios->begin(); i != neuronios->end(); i++)
        if((*i)->getMarcado() == false)
            return false;
    return true;
}

// Construtor
MapaContextual::MapaContextual() {

}

// Destrutor
MapaContextual::~MapaContextual() {

}

// Gera um Mapa Contextual
string MapaContextual::geraMapa(vector<Dado*>* dados, Arranjo* arranjo) {	
    Dado* d;
    vector<Neuronio*>::iterator n; // Guardará o vencedor

    // Desmarca todos os neurônios
    this->desmarcaNeuronios(arranjo->getNeuronios());

    // Cria o Mapa Contextual
    unsigned int i = 0;
    while(!this->todosNeuroniosMarcados(arranjo->getNeuronios())) {
        while((i < dados->size()) && !this->todosNeuroniosMarcados(arranjo->getNeuronios())) {
            d = dados->at(i);
            n = arranjo->getVencedor(d,true); // Acha o vencedor e marca-o
            (*n)->setRotulo(d->getRotulo()); // Rotula o neurônio
            i++;
        }
        i = 0;
    }

    this->desmarcaNeuronios(arranjo->getNeuronios());

    // Constrói a string com o Mapa Contextual
    ostringstream mapa("") ;
    i = 0;
    unsigned int largura = arranjo->getLargura();

    // Percorre todos os neurônios e escreve os seus rótulos em mapa
    for(n = arranjo->getNeuronios()->begin(); n != arranjo->getNeuronios()->end(); n++, i++) {
        if((i % largura == 0) && (i != 0))
            mapa << endl;
        mapa << (*n)->getRotulo() << "		";
    }

    return mapa.str();
}
