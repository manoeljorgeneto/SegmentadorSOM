// ======================================================================================================================
//  Name              :  main.cpp
//  Author           : Manoel Jorge Ribeiro Neto
//  e-mail              : manoeljorge.neto@gmail.com
//  Version          : v0.1.1-alpha
//  Copyright     : Copyright© 2022, Manoel Jorge Ribeiro Neto. All rights reserved.
//  Description : Programa SegmentadorSOM, que utiliza o algoritmo SOM de Kohonen.
//
//  This file is part of SegmentadorSOM.
//
//  SegmentadorSOM is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
//  License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later
//  version.
//
//  SegmentadorSOM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with SegmentadorSOM. If not, see
//  <https://www.gnu.org/licenses/>
// ======================================================================================================================

//
// Created by manoel on 28/06/22.
//

// Classe que faz o controle do fluxo do programa.

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>
#include <vector>
#include <string>

#include "../Calculos/Calculos.h"
#include "../Codificador/Dado.h"
#include "../SOM/Neuronio.h"
#include "../SOM/Arranjo.h"
#include "../SOM/SOM.h"
#include "../Visualizacao/MapaContextual.h"

using namespace std;

class Controlador {
    vector<string>* arg;

    unsigned int verificaArgumentos(); // Verifica os srgumentos fornecidos

    void Versao(bool verboso = false); // Exibe a versão do programa
    void Copia(); // Exibe os direitos de cópia (copyright)
    void Ajuda(); // Exibe uma tela de ajuda
    void Padrao(); // Faz a execução padrão do programa
    // TODO Implementar outros métodos, como leitura de dataset, leitura do conjunto de neurônios etc.

public:
    Controlador(vector<string>& argm); // Construtor
    virtual ~Controlador(); // Destrutor

    void executa(); // Executa o programa de acordo com os argumentos fornecidos
};

#endif // CONTROLADOR_H
