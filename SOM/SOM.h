//======================================================================================================================
// Name        : SOM.h
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

#ifndef SOM_H_
#define SOM_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <random>
#include <chrono>
#include <omp.h>

#include "../traducoes.h"
#include "../versao.h"
#include "../Calculos/Calculos.h"
#include "../Codificador/Dado.h"
#include "../Codificador/ConjuntoDados.h"
#include "../SOM/Neuronio.h"
#include "../SOM/Arranjo.h"

using namespace std;
using namespace std::chrono;

/**
 * Classe que implementa o algoritmo SOM de Kohonen. O algoritmo utilizado é o incremental.
 */
class SOM {
protected:
    Arranjo* arranjo; // Arranjo de neurônios

    unsigned dimensao_entrada; // Dimensão de entrada

    double sigma_ini, eta_ini; // Valores iniciais dos parâmetros sigma e eta
    double tau1, tau2; // Valores das constantes temporais

    bool normalizados; // Define se os neurônios terão seus pesos normalizados

    // Para geração de números aleatórios
    std::mt19937 ger_mt; // gerador mersenne_twister

    int lingua; // Língua utilizada nas mensagens, tratadas pela classe auxiliar 'MensagensSOM'

    [[nodiscard]] double calculaSigma(unsigned tempo) const; // Calcula a largura da vizinhança
    [[nodiscard]] double calculaEta(unsigned tempo) const; // Calcula a taxa de aprendizado

    double geraRand(double x, double y); // Gera um número real aleatório no intervalo [x,y), com distribuição uniforme
    unsigned geraRand(int m, int n); // Gera um inteiro aleatório no intervalo [m,n]

    void geraPesosRand(Neuronio* n); // Gera um vetor de pesos aleatório para um neurônio
    void inicializaRand(); // Inicializa os neurônios do arranjo com valores aleatórios
    Dado* getDadoRand(ConjuntoDados* dados); // Obtém um dado ainda não marcado de forma aleatória
	
    static void desmarcaDados(ConjuntoDados* dados); // Desmarca todos os dados
    static bool todosDadosMarcados(ConjuntoDados* dados); // Verifica se todos os dados foram marcados

    // Atualiza todos os neurônios do arranjo
    void atualizaNeuronios(Neuronio* vencedor, Dado* dado, double eta, double sigma);

public:
    SOM(unsigned largura, unsigned dimensao_entrada, double sigma = 2.5, double tau2 = 1000.0, double eta = 0.1,
        bool normalizados = true, int semente = 1000, int lingua = ENG); // Construtor
    virtual ~SOM(); // Destrutor

    // Faz o treinamento do SOM segundo o algoritmo incremental
    void treinaSOM(ConjuntoDados* dados, unsigned iteracoes = 10000, bool inicializa = true, bool verboso = true);
	
    // Gets
    [[nodiscard]] Arranjo* getArranjo() const;
    [[nodiscard]] unsigned getDimensao_entrada() const;
    [[nodiscard]] double getSigma_ini() const;
    [[nodiscard]] double getEta_ini() const;
    [[nodiscard]] double getTau1() const;
    [[nodiscard]] double getTau2() const;
    [[nodiscard]] int getLingua() const;
};

/**
 * Classe auxiliar, para a geração de mensagens do SOM.
 */
class MensagensSOM {
protected:

public:
    MensagensSOM() = default; // Construtor
    virtual ~MensagensSOM() = default; // Destrutor

    // Mensagens durante o algoritmo de treinamento
    static void verboso(unsigned msg, const SOM* som, bool verb = true, unsigned iteracoes = 0, unsigned n_it = 0,
                        int64_t tempo = 0);

    // Faz um sumário do SOM
    static string sumario(const SOM* som);
};

#endif // SOM_H_
