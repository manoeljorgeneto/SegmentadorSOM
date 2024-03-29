//======================================================================================================================
// Name        : ArquivoCSV_dados.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.5-alpha
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

#include "../Arquivos/ArquivoCSV_dados.h"

// Cria um objeto Dado a partir de uma linha do arquivo
Dado* ArquivoCSV_dados::criaDado(const vector<string>& linha) {
    auto* v = new vector<double>; // Vetor de valores do dado

    for(unsigned i = 1; i < linha.size(); i++) // Percorre o vetor de strings, ignorando a posição 0
        v->push_back(stod(linha.at(i))); // Conversão de string para double

    // Cria um objeto Dado e retorna
    return new Dado(v, linha.at(0)); // O rótulo está na posição 0 do vetor
}

// Faz a leitura do arquivo e retorna um objeto com o conjunto de dados
ConjuntoDados* ArquivoCSV_dados::obtemDados(const string& nomeArquivo, bool normalizados) {
    auto* linhas = ArquivoCSV_dados::lerArquivo(nomeArquivo);

    if(linhas == nullptr) // O arquivo não existe
        return nullptr;

    auto* dados = new ConjuntoDados(normalizados); // Conjunto dos dados

    // Percorre o vetor de linhas
    for(const auto & linha : *linhas)
        dados->adicionaDado(ArquivoCSV_dados::criaDado(linha)); // Adiciona o dado ao conjunto

    return dados;
}
