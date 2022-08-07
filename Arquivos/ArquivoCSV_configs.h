//======================================================================================================================
// Name        : ArquivoCSV_configs.h
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

#ifndef ARQUIVOCSV_CONFIGS_H
#define ARQUIVOCSV_CONFIGS_H

#include "../versao.h"
#include "../Arquivos/ArquivoCSV.h"

/**
 * Estrutura auxiliar, para armazenar as configurações do programa.
 * Os valores padrão são fornecidos.
 */
struct configs {
    string dados = "teste.csv"; // Nome do arquivo de dados
    string cfg = "configs.csv"; // Nome do arquivo de configurações
    string arr = "arr.dat";     // Nome do arquivo para salvar o arranjo de neurônios
    unsigned largura = 10;      // Largura do arranjo de neurônios
    double sigma = 2.5;         // Parâmetro sigma
    double tau2 = 1000.0;       // Parâmetro tau2
    double eta = 0.1;           // Parâmetro eta
    bool normalizados = true;   // Define se vetores dos dados e neurônios serão normalizados
    int semente = 1000;         // Para o gerador de números aleatórios
    int lingua = ENG;           // Língua do programa (PT-BR ou ENG)
    unsigned iteracoes = 10000; // Quantidade de iterações do algoritmo de treinamento
    bool inicializa = true;     // Define se inicializa os neurônios de forma aleatória
    bool verboso = true;        // Define se haverá mensagens durante o algoritmo de treinamento
};

/**
 * Classe ArquivoCSV_configs, herdeira da classe ArquivoCSV.
 * O objetivo da classe é ler um arquivo com as configurações do programa, que serão tratadas pela classe
 * ControladorSegmentadorSOM.
 */
class ArquivoCSV_configs : public ArquivoCSV {
protected:

public:
    // Faz a leitura do arquivo e retorna uma estrutura com as configurações do programa
    static configs* obtemConfigs(const string& nomeArquivo);
};

#endif // ARQUIVOCSV_CONFIGS_H
