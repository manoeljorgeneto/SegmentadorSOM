//======================================================================================================================
// Name        : ArquivoCSV.h
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

#ifndef ARQUIVOCSV_H
#define ARQUIVOCSV_H

#include <vector>
#include <sstream>

#include "../Arquivos/Arquivo.h"

using namespace std;

/**
 * Classe para a leitura de arquivos CSV, herdeira da classe Arquivo.
 */
class ArquivoCSV : public Arquivo {
protected:
    // Obtém um vetor de strings com valores delimitados, a partir de uma linha do arquivo
    static vector<string> obtemLinha(ifstream& arquivo);

public:
    // Faz a leitura do arquivo e retorna um vetor com as linhas do arquivo
    // Cada linha é um vetor de strings com os valores
    static vector<vector<string>>* lerArquivo(const string& nomeArquivo);
};

#endif // ARQUIVOCSV_H
