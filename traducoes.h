//======================================================================================================================
// Name        : traducoes.h
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.4-alpha
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

#ifndef TRADUCOES_H
#define TRADUCOES_H

#include <string>

// English
namespace EN {
//======================================================================================================================
    // Mensagens Classe Controlador

    // Método Controlador::argumentoInvalido()
    static std::string argIn   = "Invalid argument(s)!";
    static std::string exec    = "Run \"";
    static std::string ajud    = "for help.";

    // Método Controlador::ajuda()
    static std::string verPr   = "(program version, simple)";
    static std::string verPrVb = "(program version, verbose)";
    static std::string exAj    = "(display this help)";
    static std::string cake    = "(to win a cake)";
    static std::string nArg    = " <no argument> ";
    static std::string exPdr   = "(do default execution)";
//======================================================================================================================
    //Mensagens Classe ControladorSegmentadorSOM

    // Método ControladorSegmentadorSOM::erroArquivo()
    static std::string erro_arquivo = "Error reading file!";

    // Método ControladorSegmentadorSOM::ajuda()
    static std::string uso         = "Usage:";
    static std::string arqDados    = "<data_file>";
    static std::string arqConfigs  = "<configs_file>";
    static std::string arqArr      = "<array_file>";
    static std::string trDados     = "(train by informing data)";
    static std::string trDadosCfg  = "(train by informing data and settings)";
    static std::string svArr       = "(saves the trained array to the specified file)";
    static std::string grMapa      = "(generates a contextual map, informing data)";
    static std::string grMapa2     = "(generates a contextual map, informing data and the trained array)";
//======================================================================================================================
    // Mensagens Classe MensagensSOM

    // Método MensagensSOM::verboso()
    static std::string dT =        " - Training data:";
    static std::string uOMP =      " * Using OpenMP: ";
    static std::string nproc =     " processors";
    static std::string numIt =     " * Number of iterations: ";
    static std::string iniNeu =    " * Randomly initializing neurons...";
    static std::string trSOM =     " * Training SOM...";
    static std::string progresso = "    * Progress: ";
    static std::string itr =       " iterations (";
    static std::string mpGer =     " * Generated map!";
    static std::string tDec =      " * Elapsed time: ";
    static std::string segs =      " second(s).";

    // Método MensagensSOM::sumario()
    static std::string sumSOM      = "╔════════════════════════════════ SOM summary ═════════════════════════════════╗";
    static std::string hipPar      = " - Hyperparameters:";
    static std::string dimMp       = " * Map dimension: ";
    static std::string dimEnt      = " * Input dimension: ";
    static std::string valSET1T2   = " * Values ";
//======================================================================================================================
}

// PT_BR
namespace PTB {
//======================================================================================================================
    // Mensagens Classe Controlador

    // Método Controlador::argumentoInvalido()
    static std::string argIn   = "Argumento(s) inválido(s)!";
    static std::string exec    = "Execute \"";
    static std::string ajud    = "para ajuda.";

    // Método Controlador::ajuda()
    static std::string verPr   = "(versão do programa, simples)";
    static std::string verPrVb = "(versão do programa, verbosa)";
    static std::string exAj    = "(exibe esta ajuda)";
    static std::string cake    = "(para ganhar um bolo)";
    static std::string nArg    = " <sem argumento> ";
    static std::string exPdr   = "(faz a execução padrão)";
//======================================================================================================================
    //Mensagens Classe ControladorSegmentadorSOM

    // Método ControladorSegmentadorSOM::erroArquivo()
    static std::string erro_arquivo = "Erro ao ler o arquivo!";

    // Método ControladorSegmentadorSOM::ajuda()
    static std::string uso         = "Uso:";
    static std::string arqDados    = "<arquivo_dados>";
    static std::string arqConfigs  = "<arquivo_configs>";
    static std::string arqArr      = "<arquivo_arranjo>";
    static std::string trDados     = "(treina informando dados)";
    static std::string trDadosCfg  = "(treina informando dados e configurações)";
    static std::string svArr       = "(salva o arranjo treinado no arquivo especificado)";
    static std::string grMapa      = "(gera um mapa contextual, informando dados)";
    static std::string grMapa2     = "(gera um mapa contextual, informando dados e o arranjo treinado)";
//======================================================================================================================
    // Mensagens Classe MensagensSOM

    // Método MensagensSOM::verboso()
    static std::string dT =        " - Dados de treinamento:";
    static std::string uOMP =      " * Utilizando OpenMP: ";
    static std::string nproc =     " processadores";
    static std::string numIt =     " * Número de iterações: ";
    static std::string iniNeu =    " * Inicializando os neurônios de forma aleatória...";
    static std::string trSOM =     " * Treinando o SOM...";
    static std::string progresso = "    * Progresso: ";
    static std::string itr =       " iterações (";
    static std::string mpGer =     " * Mapa gerado!";
    static std::string tDec =      " * Tempo decorrido: ";
    static std::string segs =      " segundo(s).";

    // Método MensagensSOM::sumario()
    static std::string sumSOM      = "╔═══════════════════════════════ Sumário do SOM ═══════════════════════════════╗";
    static std::string hipPar      = " - Hiperparâmetros:";
    static std::string dimMp       = " * Dimensão do mapa: ";
    static std::string dimEnt      = " * Dimensão de entrada: ";
    static std::string valSET1T2   = " * Valores ";
//======================================================================================================================
}

#endif // TRADUCOES_H
