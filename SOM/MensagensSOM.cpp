//======================================================================================================================
// Name        : MensagensSOM.cpp
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

#include "../SOM/SOM.h"

// Mensagens durante o algoritmo de treinamento
void MensagensSOM::verboso(unsigned msg, const SOM* som, bool verb, unsigned iteracoes, unsigned n_it, int64_t tempo) {
    if(!verb)
        return;

    string dT, uOMP, nproc, numIt, iniNeu, trSOM, progresso, itr, mpGer, tDec, segs; // Palavras para tradução
    switch(som->getLingua()) {
        case PT_BR: {
            dT =        PTB::dT,
            uOMP =      PTB::uOMP,
            nproc =     PTB::nproc,
            numIt =     PTB::numIt,
            iniNeu =    PTB::iniNeu,
            trSOM =     PTB::trSOM,
            progresso = PTB::progresso,
            itr =       PTB::itr,
            mpGer =     PTB::mpGer,
            tDec =      PTB::tDec,
            segs =      PTB::segs;
            break;
        }
        default: {
            dT =        EN::dT,
            uOMP =      EN::uOMP,
            nproc =     EN::nproc,
            numIt =     EN::numIt,
            iniNeu =    EN::iniNeu,
            trSOM =     EN::trSOM,
            progresso = EN::progresso,
            itr =       EN::itr,
            mpGer =     EN::mpGer,
            tDec =      EN::tDec,
            segs =      EN::segs;
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
            sumSOM      = PTB::sumSOM,
            hipPar      = PTB::hipPar,
            dimMp       = PTB::dimMp,
            dimEnt      = PTB::dimEnt,
            valSET1T2   = PTB::valSET1T2;
            break;
        }
        default: {
            sumSOM      = EN::sumSOM,
            hipPar      = EN::hipPar,
            dimMp       = EN::dimMp,
            dimEnt      = EN::dimEnt,
            valSET1T2   = EN::valSET1T2;
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
