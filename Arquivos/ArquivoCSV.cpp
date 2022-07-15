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

// Obtém um vetor de strings com valores delimitados a partir de uma linha do arquivo
vector<string> ArquivoCSV::obtemLinha(fstream& arquivo) {
    vector<string> resultado; // Vetor de strings, que armazenará os valores da linha
    string linha, celula; // Variáveis auxiliares

    std::getline(arquivo, linha); // Lê uma linha do arquivo e armazena na string 'linha'
    stringstream s(linha); // Cria um fluxo de string a partir de linha, que contém os dados "brutos" (não delimitados)

    // Armazena os valores da string linha no vetor de strings
    while(std::getline(s, celula, ',')) // Cada 'celula' é um valor da linha, já delimitado
        resultado.push_back(celula); // Adiciona o valor no vetor

    return resultado;
}

// Cria um objeto Dado a partir de uma linha do arquivo
Dado* ArquivoCSV::criaDado(const vector<string>& linha) {
    auto* v = new vector<double>; // Vetor de valores do dado

    for(unsigned i = 1; i < linha.size(); i++) // Percorre o vetor de strings, ignorando a posição 0
        v->push_back(stod(linha.at(i))); // Conversão de string para double

    // Cria um objeto Dado e retorna
    return new Dado(v, linha.at(0)); // O rótulo está na posição 0 do vetor
}

// Construtor
ArquivoCSV::ArquivoCSV() = default;

// Destrutor
ArquivoCSV::~ArquivoCSV() = default;

// Faz a leitura do arquivo e retorna um objeto com o conjunto de dados
ConjuntoDados* ArquivoCSV::lerArquivo(const string& nomeArquivo) {
    fstream arquivo; // Referência para o arquivo
    arquivo.open(nomeArquivo, ios::in); // Abre o arquivo

    if(!arquivo) // O arquivo não existe
        return nullptr;

    auto* dados = new ConjuntoDados(); // Conjunto dos dados

    // Percorre o arquivo, linha a linha
    do {
        vector<string> linha = ArquivoCSV::obtemLinha(arquivo); // Obtém o vetor de strings

        if(!linha.empty()) // Se o vetor conter dados, cria um novo objeto do tipo Dado e armazena-o no conjunto
            dados->adicionaDado(ArquivoCSV::criaDado(linha)); // Adiciona o dado no conjunto

    } while(arquivo);

    arquivo.close(); // Fecha o arquivo

    return dados;
}
