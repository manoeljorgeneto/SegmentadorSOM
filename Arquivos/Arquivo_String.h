//======================================================================================================================
// Name        : Arquivo_String.h
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

#ifndef ARQUIVO_STRING_H
#define ARQUIVO_STRING_H

#include <cassert>
#include <sstream>

#include "../Arquivos/Arquivo.h"

/**
 * Classe para a leitura e escrita de uma string em arquivo, herdeira da classe Arquivo.
 */
class Arquivo_String : public Arquivo {
protected:

public:
    // Obtém a string a partir do arquivo
    static string* obtemString(const string& nomeArquivo);

    // Grava a string no arquivo
    static void gravaString(const string& s, const string& nomeArquivo);
};

#endif // ARQUIVO_STRING_H
