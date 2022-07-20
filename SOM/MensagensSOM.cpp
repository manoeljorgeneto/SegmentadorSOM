//======================================================================================================================
// Name        : MensagensSOM.cpp
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

#include "../SOM/SOM.h"

// Construtor
MensagensSOM::MensagensSOM() = default;

// Destrutor
MensagensSOM::~MensagensSOM() = default;

// Mensagens durante o algoritmo de treinamento
void MensagensSOM::verboso(unsigned msg, const SOM* som, bool verb, unsigned iteracoes, unsigned n_it, int64_t tempo) {
    if(!verb)
        return;

    string dT, uOMP, nproc, numIt, iniNeu, trSOM, progresso, itr, mpGer, tDec, segs; // Palavras para tradução
    switch(som->getLingua()) {
        case PT_BR: {
            dT =        " - Dados de treinamento:",
            uOMP =      " * Utilizando OpenMP: ",
            nproc =     " processadores",
            numIt =     " * Número de iterações: ",
            iniNeu =    " * Inicializando os neurônios de forma aleatória...",
            trSOM =     " * Treinando o SOM...",
            progresso = "    * Progresso: ",
            itr =       " iterações (",
            mpGer =     " * Mapa gerado!",
            tDec =      " * Tempo decorrido: ",
            segs =      " segundo(s).";
            break;
        }
        default: {
            dT =        " - Training data:",
            uOMP =      " * Using OpenMP: ",
            nproc =     " processors",
            numIt =     " * Number of iterations: ",
            iniNeu =    " * Randomly initializing neurons...",
            trSOM =     " * Training SOM...",
            progresso = "    * Progress: ",
            itr =       " iterations (",
            mpGer =     " * Generated map!",
            tDec =      " * Elapsed time: ",
            segs =      " second(s).";
        }
    }

    // Escolha das mensagens a serem exibidas
    switch(msg) {
        case 0: { // Início do sumário de treinamento
            cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl;
            cout << dT << endl;
            if(omp_get_num_procs() > 1)
                cout << uOMP << omp_get_num_procs() << nproc << endl;
            cout << numIt << iteracoes << endl;
            break;
        }
        case 1: { // Mensagem de inicialização dos neurônios
            cout << iniNeu << endl;
            break;
        }
        case 2: { // Continuando o sumário do treinamento
            cout << endl << trSOM << endl << endl;
            break;
        }
        case 3: {
            if( (10*(n_it + 1) % iteracoes) == 0) // A cada 10%, faz uma exibição do progresso
                cout << progresso << (n_it + 1) << itr << (100 * (n_it + 1) / iteracoes) << "%)" <<
                     endl;
            break;
        }
        case 4: { // Finalizando o sumário de treinamento
            cout << endl << mpGer << endl;
            cout << tDec << double(tempo)/1000000000.0 << segs << endl;
            cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
            break;
        }
    }
}

// Faz um sumário do SOM
string MensagensSOM::sumario(const SOM* som) {
    ostringstream str("");

    string sumSOM, hipPar, dimMp, dimEnt, valSET1T2; // Palavras para tradução
    switch(som->getLingua()) {
        case PT_BR: {
            sumSOM      = "╔═══════════════════════════════ Sumário do SOM ═══════════════════════════════╗",
            hipPar      = " - Hiperparâmetros:",
            dimMp       = " * Dimensão do mapa: ",
            dimEnt      = " * Dimensão de entrada: ",
            valSET1T2   = " * Valores ";
            break;
        }
        default: {
            sumSOM      = "╔════════════════════════════════ SOM summary ═════════════════════════════════╗",
            hipPar      = " - Hyperparameters:",
            dimMp       = " * Map dimension: ",
            dimEnt      = " * Input dimension: ",
            valSET1T2   = " * Values ";
        }
    }

    str << sumSOM << endl;
    str << hipPar << endl;
    str << dimMp << som->getArranjo()->getLargura() << " x " << som->getArranjo()->getLargura() << endl;
    str << dimEnt << som->getDimensao_entrada() << endl;
    str << valSET1T2 << "(sigma, eta, tau1, tau2): " << "(" <<
        som->getSigma_ini() << ", " <<
        som->getEta_ini() << ", " <<
        som->getTau1() << ", " <<
        som->getTau2() << ")" << endl;
    str << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;

    return str.str();
}
