//======================================================================================================================
// Name        : Dado.h
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

// Classe que representa os dados que alimentarão o SOM

#ifndef DADO_H_
#define DADO_H_

#include <vector>
#include <string>
#include <cmath>
#include <sstream>

#include "../Calculos/Calculos.h"

using namespace std;

class Dado {
protected:
    string rotulo; // Rótulo que marca o dado (serve para a formação de um Mapa Contextual)
	 
    vector<double>* dados; // Vetor que representa o dado
    unsigned dimensao; // Dimensão do dado
    bool marcado; // Serve para os algoritmos SOM e do Mapa Contextual
	
public:
    Dado(unsigned dimensao, string rotulo = ""); // Construtor
    Dado(vector<double>* dados , string rotulo = ""); // Construtor
    virtual ~Dado(); // Destrutor

    // Gets e sets
    string getRotulo();
    vector<double>* getDados();
    bool getMarcado();

    void setRotulo(string rotulo);
    void setDados(vector<double>* dados);
    void setMarcado(bool marcado);

    void normaliza(); // Normaliza o vetor de dados

    virtual string toString(); // Converte para String
};

#endif // DADO_H_
