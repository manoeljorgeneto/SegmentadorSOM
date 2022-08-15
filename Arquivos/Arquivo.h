//======================================================================================================================
// Name        : Arquivo.h
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

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
#include <string>

using namespace std;

/**
 * Classe para a manipulação de arquivos.
 */
class Arquivo {
protected:
    // Abre o arquivo
    static ifstream abreArquivo(const string& nomeArquivo);

    // Cria um novo arquivo
    static ofstream criaArquivo(const string& nomeArquivo);

public:
    Arquivo() = default; // Construtor
    virtual ~Arquivo() = default; // Destrutor
};

#endif // ARQUIVO_H
