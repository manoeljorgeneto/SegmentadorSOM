//======================================================================================================================
// Name        : SOM.cpp
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

#include "../SOM/SOM.h"

// Calcula a largura da vizinhança
double SOM::calculaSigma(unsigned tempo) const {
    return this->sigma_ini * exp(-(double(tempo)) / this->tau1);
}

// Calcula a taxa de aprendizado
double SOM::calculaEta(unsigned tempo) const {
    return this->eta_ini * exp(-(double(tempo)) / this->tau2);
}

// Gera um número real aleatório no intervalo [x,y), com distribuição uniforme
double SOM::geraRand(double x, double y) {
    std::uniform_real_distribution<> dis_ur(x, y); // distribuição uniforme (reais)
    double r;

    #pragma omp critical
    r = dis_ur(this->ger_mt);

    return r;
}

// Gera um inteiro aleatório no intervalo [m,n]
unsigned SOM::geraRand(int m, int n) {
    std::uniform_int_distribution<> dis_ui(m, n); // distribuição uniforme (inteiros)
    unsigned r;

    #pragma omp critical
    r = dis_ui(this->ger_mt);

    return r;
}

// Gera um vetor de pesos aleatório para um neurônio
void SOM::geraPesosRand(Neuronio* n) {
    vector<double>* pesos = n->getPesos(); // Obtém o vetor de pesos do neurônio

    // Preenche o vetor com valores aleatórios
    for(double & p : *pesos)
        p = this->geraRand(-1.0, 1.0); // Intervalo entre -1 e 1

    if(this->normalizados)
        n->normaliza(); // Normaliza o vetor
}

// Inicializa os neurônios do arranjo com valores aleatórios
void SOM::inicializaRand() {
    // Percorre os neurônios do arranjo, criando valores aleatórios para seus pesos
    //#pragma omp parallel for
    for(auto & n : *this->arranjo->getNeuronios())
        this->geraPesosRand(n); // Gera um vetor com valores aleatórios para o neurônio
}

// Obtém um dado ainda não marcado de forma aleatória
Dado* SOM::getDadoRand(ConjuntoDados* dados) {
    unsigned rnd;
    Dado* d;

    do {
        rnd = this->geraRand(0, int(dados->getTamanho() - 1)); // Gera um número aleatório
        d = dados->getDados()->at(rnd);	// Obtém um dado
    } while(d->getMarcado() && !SOM::todosDadosMarcados(dados));

    d->setMarcado(true); // Marca o dado

    return d;
}

// Desmarca todos os dados
void SOM::desmarcaDados(ConjuntoDados* dados) {
    #pragma omp parallel for
    for(auto & dado : *(dados->getDados()))
        dado->setMarcado(false);
}

// Verifica se todos os dados foram marcados
bool SOM::todosDadosMarcados(ConjuntoDados* dados) {
    for(auto & dado : *(dados->getDados()))
        if (!dado->getMarcado())
            return false;
    return true;
}

// Atualiza todos os neurônios do arranjo
void SOM::atualizaNeuronios(Neuronio* vencedor, Dado* dado, double eta, double sigma) {
    // Percorre todos os neurônios e atualiza-os
    #pragma omp parallel for // Paralelizado FTW!!
    for(auto & n : *this->arranjo->getNeuronios())
        n->atualiza(vencedor, dado, eta, sigma);
}

// Construtor
SOM::SOM(unsigned largura, unsigned dimensao_entrada, double sigma, double tau2, double eta, bool normalizados,
         int semente, int lingua) : ger_mt(semente) {
    this->sigma_ini = sigma;
    this->tau2 = tau2;
    this->eta_ini = eta;
	
    this->tau1 = tau2/log(sigma);

    this->normalizados = normalizados;

    this->dimensao_entrada = dimensao_entrada;
    this->arranjo = new Arranjo(largura, dimensao_entrada, normalizados);

    this->lingua = lingua;
}

// Destrutor
SOM::~SOM() {
    delete this->arranjo;
}

// Faz o treinamento do SOM segundo o algoritmo incremental
void SOM::treinaSOM(ConjuntoDados* dados, unsigned iteracoes, bool inicializa, bool verb) {
    MensagensSOM::verboso(0, this, verb, iteracoes); // Começo do sumário do treinamento

    if(inicializa) { // Inicializa os neurônios do arranjo de forma aleatória
        MensagensSOM::verboso(1, this, verb); // Mensagem de inicialização dos neurônios
        this->inicializaRand(); // Inicializa os neurônios do arranjo com valores aleatórios
    }

    SOM::desmarcaDados(dados); // Desmarca todos os dados

    MensagensSOM::verboso(2, this, verb); // Continuando o sumário do treinamento

    auto inicio = high_resolution_clock::now(); // Início da contagem do tempo!

    // Repete até o número máximo de iterações
    for(unsigned n_it = 0; n_it < iteracoes; n_it++) {
        double sigma = this->calculaSigma(n_it); // Calcula a largura da vizinhança
        double eta = this->calculaEta(n_it); // Calcula a taxa de aprendizado
		
        // Apresenta todos os dados de forma aleatória e atualiza os pesos sinápticos dos neurônios no arranjo
        while(!SOM::todosDadosMarcados(dados)) {
            auto dado = this->getDadoRand(dados); // Obtém um dado de forma aleatória
            auto vencedor = this->arranjo->getVencedor(dado); // Faz a competição
            this->atualizaNeuronios(*vencedor, dado, eta, sigma); // Atualiza os neurônios do arranjo!
        }

        SOM::desmarcaDados(dados); // Desmarca os dados ao final de cada iteração

        MensagensSOM::verboso(3, this, verb, iteracoes, n_it); // Exibição do progresso
    }

    auto fim = high_resolution_clock::now(); // Fim da contagem do tempo!
    // Cálculo do tempo passado para o aprendizado
    auto duracao = duration_cast<nanoseconds>(fim - inicio);

    // Finalizando o sumário de treinamento
    MensagensSOM::verboso(4, this, verb, iteracoes, 0, duracao.count());
}

// Gets
Arranjo* SOM::getArranjo() const {
    return this->arranjo;
}

unsigned SOM::getDimensao_entrada() const {
    return this->dimensao_entrada;
}

double SOM::getSigma_ini() const {
    return this->sigma_ini;
}

double SOM::getEta_ini() const {
    return this->eta_ini;
}

double SOM::getTau1() const {
    return this->tau1;
}

double SOM::getTau2() const {
    return this->tau2;
}

int SOM::getLingua() const {
    return this->lingua;
}
