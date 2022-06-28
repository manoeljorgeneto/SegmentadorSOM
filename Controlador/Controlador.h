//======================================================================================================================
// Name        : Controlador.h
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.2-alpha
// Copyright   : Copyright© 2007-2022, Manoel Jorge Ribeiro Neto. All rights reserved.
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

// Classe que faz o controle do fluxo do programa.

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>
#include <vector>
#include <string>

#include "../versao.h"
#include "../Calculos/Calculos.h"
#include "../Codificador/Dado.h"
#include "../SOM/Neuronio.h"
#include "../SOM/Arranjo.h"
#include "../SOM/SOM.h"
#include "../Visualizacao/MapaContextual.h"

using namespace std;

class Controlador {
    vector<string> args;
    int lingua; // Língua utilizada

    unsigned int verificaArgumentos(); // Verifica os argumentos fornecidos
    void listaArgumentos(); // Lista os argumentos fornecidos

    void Versao(bool verboso = true); // Exibe a versão do programa
    void Ajuda(); // Exibe uma tela de ajuda
    void Padrao(); // Faz a execução padrão do programa
    //TODO Implementar outros métodos, como leitura de dataset, leitura do conjunto de neurônios etc.

public:
    Controlador(int argc, char** argv, int lingua = ENG); // Construtor
    virtual ~Controlador(); // Destrutor

    void executa(); // Executa o programa de acordo com os argumentos fornecidos

    // Get e sets
    vector<string> getArgs() const;
    int getLingua() const;

    void setArgs(const vector<string> &args);
    void setLingua(int lingua);
};

#endif // CONTROLADOR_H
