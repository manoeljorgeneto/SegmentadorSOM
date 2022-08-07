//======================================================================================================================
// Name        : Arquivo_Arranjo.h
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

#ifndef ARQUIVO_ARRANJO_H
#define ARQUIVO_ARRANJO_H

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include "../Arquivos/Arquivo.h"
#include "../SOM/Arranjo.h"

using namespace boost::archive;

/**
 * Classe para a leitura e escrita do arranjo de neurônios em arquivo, herdeira da classe Arquivo.
 */
class Arquivo_Arranjo : public Arquivo {
protected:

public:
    // Obtém o arranjo a partir do arquivo
    static Arranjo* obtemArranjo(const string& nomeArquivo);

    // Grava o arranjo no arquivo
    static void gravaArranjo(const Arranjo* arr, const string& nomeArquivo);
};

#endif // ARQUIVO_ARRANJO_H
