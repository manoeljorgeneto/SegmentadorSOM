//======================================================================================================================
// Name        : ControladorSegmentadorSOM.h
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

#ifndef CONTROLADORSEGMENTADORSOM_H
#define CONTROLADORSEGMENTADORSOM_H

#include "../Controlador/Controlador.h"
#include "../Codificador/Dado.h"
#include "../SOM/Neuronio.h"
#include "../SOM/Arranjo.h"
#include "../SOM/SOM.h"
#include "../Visualizacao/MapaContextual.h"

/**
 * Classe que faz o controle do fluxo do programa, herdeira das características da classe Controlador.
 */
class ControladorSegmentadorSOM : public Controlador {
protected:
    void padrao() override; // Faz a execução padrão do programa

    // TODO Implementar outros métodos, como leitura de dataset, leitura do conjunto de neurônios etc.
    // TODO Implementar um método para leitura de configurações

public:
    ControladorSegmentadorSOM(int argc, char** argv, int lingua = ENG); // Construtor
};

#endif // CONTROLADORSEGMENTADORSOM_H
