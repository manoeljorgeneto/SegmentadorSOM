//======================================================================================================================
// Name        : Controlador.h
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.4-alpha
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

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>
#include <vector>
#include <string>

#include "../versao.h"

using namespace std;

/**
 * Classe que faz o controle do fluxo do programa.
 */
class Controlador {
protected:
    vector<string> args; // Argumentos
    int lingua; // Língua utilizada

    [[nodiscard]] virtual unsigned verificaArgumentos() const; // Verifica os argumentos fornecidos
    [[nodiscard]] virtual unsigned verificaArgumentos_Expandido() const; // Para argumentos complexos
    void listaArgumentos(); // Lista os argumentos fornecidos
    void argumentoInvalido() const; // Exibe uma mensagem de argumento inválido

    static void versao(bool verboso = true); // Exibe a versão do programa
    virtual void ajuda(); // Exibe uma tela de ajuda
    
    virtual void padrao(); // Faz a execução padrão do programa

public:
    Controlador(int argc, char** argv, int lingua = ENG); // Construtor
    virtual ~Controlador() = default; // Destrutor

    virtual void executa(); // Executa o programa de acordo com os argumentos fornecidos
};

#endif // CONTROLADOR_H
