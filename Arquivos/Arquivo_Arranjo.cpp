//======================================================================================================================
// Name        : Arquivo_Arranjo.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.3-alpha
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

#include "../Arquivos/Arquivo_Arranjo.h"

// Obtém o arranjo a partir do arquivo
Arranjo* Arquivo_Arranjo::obtemArranjo(const string& nomeArquivo) {
    ifstream arquivo = Arquivo_Arranjo::abreArquivo(nomeArquivo); // Abre o arquivo
    assert(arquivo.good()); // Testa o arquivo

    auto* arr = new Arranjo; // Cria um objeto Arranjo

    boost::archive::binary_iarchive ia(arquivo);
    ia >> *arr; // Faz a cópia do arranjo do arquivo para o objeto

    arquivo.close(); // Fecha o arquivo

    return arr;
}

// Grava o arranjo no arquivo
void Arquivo_Arranjo::gravaArranjo(const Arranjo* arr, const string& nomeArquivo) {
    ofstream arquivo = Arquivo_Arranjo::criaArquivo(nomeArquivo); // Cria o arquivo
    assert(arquivo.good()); // Testa o arquivo

    boost::archive::binary_oarchive oa(arquivo);
    oa << *arr; // Faz a cópia do objeto para o arquivo

    arquivo.close(); // Fecha o arquivo
}
