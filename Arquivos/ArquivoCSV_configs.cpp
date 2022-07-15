//======================================================================================================================
// Name        : ArquivoCSV_configs.cpp
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

#include "../Arquivos/ArquivoCSV_configs.h"

// Faz a leitura do arquivo e retorna uma estrutura com as configurações do programa
configs* ArquivoCSV_configs::obtemConfigs(const string& nomeArquivo) {
    auto* linhas = ArquivoCSV_configs::lerArquivo(nomeArquivo);

    if(linhas == nullptr) // O arquivo não existe
        return nullptr;

    auto* c = new configs; // Cria a estrutura para as configurações

    // Preenche com as configurações
    c->largura =        stoul((linhas->at(0)).at(1));
    c->sigma =          stod((linhas->at(1)).at(1));
    c->tau2 =           stod((linhas->at(2)).at(1));
    c->eta =            stod((linhas->at(3)).at(1));
    c->normalizados =   stoi((linhas->at(4)).at(1));
    c->semente =        stoi((linhas->at(5)).at(1));
    c->lingua =         stoi((linhas->at(6)).at(1));
    c->iteracoes =      stoul((linhas->at(7)).at(1));
    c->inicializa =     stoi((linhas->at(8)).at(1));
    c->verboso =        stoi((linhas->at(9)).at(1));

    return c;
}
