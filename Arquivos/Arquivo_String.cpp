//======================================================================================================================
// Name        : Arquivo_String.cpp
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

#include "../Arquivos/Arquivo_String.h"

// Obtém a string a partir do arquivo
string* Arquivo_String::obtemString(const string& nomeArquivo) {
    ifstream arquivo = Arquivo_String::abreArquivo(nomeArquivo); // Abre o arquivo

    if(!arquivo) // O arquivo não existe
        return nullptr;

    stringstream buffer; // Cria um fluxo de string
    buffer << arquivo.rdbuf(); // Copia o conteúdo do arquivo para o buffer

    auto* s = new string;
    *s = buffer.str(); // Armazena o conteúdo do buffer na string

    arquivo.close(); // Fecha o arquivo

    return s;
}

// Grava a string no arquivo
void Arquivo_String::gravaString(const string& s, const string& nomeArquivo) {
    ofstream arquivo = Arquivo_String::criaArquivo(nomeArquivo); // Cria o arquivo
    assert(arquivo.good()); // Testa o arquivo

    arquivo << s; // Grava a string no arquivo

    arquivo.close(); // Fecha o arquivo
}
