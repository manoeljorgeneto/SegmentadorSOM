//======================================================================================================================
// Name        : SOM.cpp
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
    //#pragma omp parallel for
    for(double & p : *pesos)
        p = this->geraRand(-1.0, 1.0); // Intervalo entre -1 e 1

    if(this->normalizados)
        Calculos::normalizaVetor(pesos); // Normaliza o vetor
}

// Inicializa os neurônios do arranjo com valores aleatórios
void SOM::inicializaRand() {
    // Percorre os neurônios do arranjo, criando valores aleatórios para seus pesos
    //#pragma omp parallel for
    for(auto & n : *this->arranjo->getNeuronios())
        this->geraPesosRand(n); // Gera um vetor com valores aleatórios para o neurônio
}

// Obtém um dado ainda não marcado de forma aleatória
Dado* SOM::getDadoRand(vector<Dado*>* dados) {
    unsigned rnd;
    Dado* d;

    do {
        rnd = this->geraRand(0, dados->size() - 1); // Gera um número aleatório
        d = dados->at(rnd);	// Obtém um dado
    } while(d->getMarcado() && !SOM::todosDadosMarcados(dados));

    d->setMarcado(true); // Marca o dado

    return d;
}

// Desmarca todos os dados
void SOM::desmarcaDados(vector<Dado*>* dados) {
    #pragma omp parallel for
    for(auto & dado : *dados)
        dado->setMarcado(false);
}

// Verifica se todos os dados foram marcados
bool SOM::todosDadosMarcados(vector<Dado*>* dados) {
    for(auto & dado : *dados)
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

// Mensagens durante o algoritmo de treinamento
void SOM::verboso(unsigned msg, bool verb, unsigned iteracoes, unsigned n_it, int64_t tempo) const {
    if(!verb)
        return;

    string dT, uOMP, nproc, numIt, iniNeu, trSOM, progresso, itr, mpGer, tDec, segs; // Palavras para tradução
    switch(this->lingua) {
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
        case ENG: {
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
            break;
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
        case 3: { // TODO Verificar melhor isso
            if( (10*(n_it + 1) % iteracoes) == 0) // A cada 10%, faz uma exibição do progresso
                cout << progresso << (n_it + 1) << itr << (100 * (n_it + 1) / iteracoes) << "%)" <<
                     endl;
            break;
        }
        case 4: { // Finalizando o sumário de treinamento
            cout << endl << mpGer << endl;
            cout << tDec << tempo/1000000000.0 << segs << endl;
            cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
            break;
        }
    }
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
void SOM::treinaSOM(vector<Dado*>* dados, unsigned iteracoes, bool inicializa, bool verb) {
    this->verboso(0, verb, iteracoes); // Começo do sumário do treinamento

    if(inicializa) { // Inicializa os neurônios do arranjo de forma aleatória
        this->verboso(1, verb); // Mensagem de inicialização dos neurônios
        this->inicializaRand(); // Inicializa os neurônios do arranjo com valores aleatórios
    }

    this->desmarcaDados(dados); // Desmarca todos os dados

    this->verboso(2, verb); // Continuando o sumário do treinamento

    auto inicio = high_resolution_clock::now(); // Início da contagem do tempo!

    // Repete até o número máximo de iterações
    for(unsigned n_it = 0; n_it < iteracoes; n_it++) {
        double sigma = this->calculaSigma(n_it); // Calcula a largura da vizinhança
        double eta = this->calculaEta(n_it); // Calcula a taxa de aprendizado
		
        // Apresenta todos os dados de forma aleatória e atualiza os pesos sinápticos dos neurônios no arranjo
        while(!this->todosDadosMarcados(dados)) {
            auto dado = this->getDadoRand(dados); // Obtém um dado de forma aleatória
            auto vencedor = this->arranjo->getVencedor(dado); // Faz a competição
            this->atualizaNeuronios(*vencedor, dado, eta, sigma); // Atualiza os neurônios do arranjo!
        }

        this->desmarcaDados(dados); // Desmarca os dados ao final de cada iteração

        this->verboso(3, verb, iteracoes, n_it); // Exibição do progresso
    }

    auto fim = high_resolution_clock::now(); // Fim da contagem do tempo!
    // Cálculo do tempo passado para o aprendizado
    auto duracao = duration_cast<nanoseconds>(fim - inicio);

    // Finalizando o sumário de treinamento
    this->verboso(4, verb, iteracoes, 0, duracao.count());
}

// Gets e sets
Arranjo* SOM::getArranjo() const {
    return this->arranjo;
}

double SOM::getSigmaIni() const {
    return this->sigma_ini;
}

double SOM::getEtaIni() const {
    return this->eta_ini;
}

double SOM::getTau1() const {
    return this->tau1;
}

double SOM::getTau2() const {
    return this->tau2;
}

bool SOM::getNormalizados() const {
    return this->normalizados;
}

int SOM::getLingua() const {
    return this->lingua;
}
	
void SOM::setSigmaIni(double sigma) {
    this->sigma_ini = sigma;
}

void SOM::setEtaIni(double eta) {
    this->eta_ini = eta;
}

void SOM::setTau1(double tau1) {
    this->tau1 = tau1;
}

void SOM::setTau2(double tau2) {
    this->tau2 = tau2;
}

void SOM::setLingua(int lingua) {
    this->lingua = lingua;
}

// Faz um sumário do SOM
void SOM::sumario() {
    string sumSOM, hipPar, dimMp, dimEnt, valSET1T2; // Palavras para tradução
    switch(this->lingua) {
        case PT_BR: {
            sumSOM      = "╔═══════════════════════════════ Sumário do SOM ═══════════════════════════════╗",
            hipPar      = " - Hiperparâmetros:",
            dimMp       = " * Dimensão do mapa: ",
            dimEnt      = " * Dimensão de entrada: ",
            valSET1T2   = " * Valores ";
            break;
        }
        case ENG: {
            sumSOM      = "╔════════════════════════════════ SOM summary ═════════════════════════════════╗",
            hipPar      = " - Hyperparameters:",
            dimMp       = " * Map dimension: ",
            dimEnt      = " * Input dimension: ",
            valSET1T2   = " * Values ";
            break;
        }
    }

    cout << sumSOM << endl;
    cout << hipPar << endl;
    cout << dimMp << this->arranjo->getLargura() << " x " << this->arranjo->getLargura() << endl;
    cout << dimEnt << this->dimensao_entrada << endl;
    cout << valSET1T2 << "(sigma, eta, tau1, tau2): " << "(" <<
        this->sigma_ini << ", " <<
        this->eta_ini << ", " <<
        this->tau1 << ", " <<
        this->tau2 << ")" << endl;
    cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
}
