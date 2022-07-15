//======================================================================================================================
// Name        : ArquivoCSV.cpp
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

#include "../Arquivos/ArquivoCSV.h"

// Abre o arquivo no modo de leitura
fstream ArquivoCSV::abreArquivo(const string& nomeArquivo) {
    fstream arquivo; // Referência para o arquivo
    arquivo.open(nomeArquivo, ios::in); // Abre o arquivo

    return arquivo;
}

// Obtém um vetor de strings com valores delimitados, a partir de uma linha do arquivo
vector<string> ArquivoCSV::obtemLinha(fstream& arquivo) {
    vector<string> resultado; // Vetor de strings, que armazenará os valores da linha
    string linha, valor; // Variáveis auxiliares

    std::getline(arquivo, linha); // Lê uma linha do arquivo e armazena na string 'linha'
    stringstream s(linha); // Cria um fluxo de string a partir de linha, que contém os dados "brutos" (não delimitados)

    // Armazena os valores do fluxo no vetor de strings
    while(std::getline(s, valor, ',')) // Cada 'valor' é um valor da linha, já delimitado
        resultado.push_back(valor); // Adiciona o valor ao vetor

    return resultado;
}

// Construtor
ArquivoCSV::ArquivoCSV() = default;

// Destrutor
ArquivoCSV::~ArquivoCSV() = default;

// Faz a leitura do arquivo e retorna um vetor com as linhas do arquivo
// Cada linha é um vetor de strings com os valores
vector<vector<string>>* ArquivoCSV::lerArquivo(const string& nomeArquivo) {
    fstream arquivo = ArquivoCSV::abreArquivo(nomeArquivo); // Abre o arquivo

    if(!arquivo) // O arquivo não existe
        return nullptr;

    auto linhas = new vector<vector<string>>; // Vetor das linhas do arquivo

    // Percorre o arquivo, linha a linha
    do {
        vector<string> linha = ArquivoCSV::obtemLinha(arquivo); // Obtém o vetor de strings

        if(!linha.empty()) // Se o vetor conter dados, adiciona no vetor 'linhas'
            linhas->push_back(linha); // Adiciona o dado no conjunto

    } while(arquivo);

    arquivo.close(); // Fecha o arquivo

    return linhas;
}
