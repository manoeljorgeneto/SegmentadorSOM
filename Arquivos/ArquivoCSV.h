//======================================================================================================================
// Name        : ArquivoCSV.h
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

#ifndef ARQUIVOCSV_H
#define ARQUIVOCSV_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "../Codificador/Dado.h"
#include "../Codificador/ConjuntoDados.h"

using namespace std;

/**
 * Classe para a leitura de arquivos CSV, formatados da seguinte forma:
 * \<rótulo\>, \<dado_1\>, \<dado_2\>, ..., \<dado_n\>\n
 *
 * Exemplo:\n
 * Ma, 1, 4, 5, 0, 0, 1\n
 * Mi, 0, 4, 4, 1, 0, 0\n
 */
class ArquivoCSV {
protected:
    // Obtém um vetor de strings com valores delimitados a partir de uma linha do arquivo
    static vector<string> obtemLinha(fstream& arquivo);

    // Cria um objeto Dado a partir de uma linha do arquivo
    static Dado* criaDado(const vector<string>& linha);

public:
    ArquivoCSV(); // Construtor
    ~ArquivoCSV(); // Destrutor

    // Faz a leitura do arquivo e retorna um objeto com o conjunto de dados
    static ConjuntoDados* lerArquivo(const string& nomeArquivo);
};

#endif // ARQUIVOCSV_H
