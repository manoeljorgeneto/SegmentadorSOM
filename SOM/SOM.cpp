//======================================================================================================================
// Name        : SOM.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.1-alpha
// Copyright   : Copyright© 2007-2022, Manoel Jorge Ribeiro Neto. All rights reserved.
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
double SOM::calculaSigma(unsigned int tempo) {
    return this->sigma_ini * exp(-(double(tempo))/this->tau1);
}

// Calcula a taxa de aprendizado
double SOM::calculaEta(unsigned int tempo) {
    return this->eta_ini * exp(-(double(tempo))/this->tau2);
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
unsigned int SOM::geraRandInt(unsigned int m, unsigned int n) {
    std::uniform_int_distribution<> dis_ui(m, n); // distribuição uniforme (inteiros)
    unsigned int r;

    #pragma omp critical
    r = dis_ui(this->ger_mt);

    return r;
}

// Gera um vetor de pesos aleatório e normalizado
vector<double> SOM::geraVetorRand() {
    vector<double> vetor(this->dimensao_entrada);
	
    // Preenche o vetor com valores aleatórios
    //#pragma omp parallel for
    for(unsigned int i = 0; i < this->dimensao_entrada; i++)
        vetor.at(i) = this->geraRand(-1.0, 1.0); // Intervalo entre -1 e 1
	
    Calculos::normalizaVetor(&vetor); // Normaliza o vetor

    return vetor;
}

// Inicializa os neurônios do arranjo com valores aleatórios
void SOM::inicializaRand() {
    // Percorre os neurônios do arranjo, criando valores aleatórios para seus pesos
    //#pragma omp parallel for
    for(auto i = this->arranjo->getNeuronios()->begin(); i != this->arranjo->getNeuronios()->end(); i++) {
        auto aux = (*i)->getPesos();
        *aux = this->geraVetorRand(); // Gera um vetor com valores aleatórios
    }
}

// Obtém um dado ainda não marcado de forma aleatória
Dado* SOM::getDadoRand(vector<Dado*>* dados) {
    unsigned int rnd;
    Dado* d;

    do {
        rnd = this->geraRandInt(0, dados->size() - 1); // Gera um número aleatório
        d = dados->at(rnd);	// Obtém um dado
    } while(d->getMarcado() && !this->todosDadosMarcados(dados));

    if(d != NULL)
        d->setMarcado(true); // Marca o dado

    return d;
}

// Desmarca todos os dados
void SOM::desmarcaDados(vector<Dado*>* dados) {
    #pragma omp parallel for
    for(auto i = dados->begin(); i != dados->end(); i++)
        (*i)->setMarcado(false);
}

// Verifica se todos os dados foram marcados
bool SOM::todosDadosMarcados(vector<Dado*>* dados) {
    for(auto i = dados->begin(); i != dados->end(); i++)
        if ((*i)->getMarcado() == false)
            return false;
    return true;
}

// Atualiza todos os neurônios do arranjo
void SOM::atualizaNeuronios(Neuronio* vencedor, Dado* dado, double eta, double sigma) {
    // Percorre todos os neurônios e atualiza-os
    #pragma omp parallel for // Paralelizado FTW!!
    for(auto i = this->arranjo->getNeuronios()->begin(); i != this->arranjo->getNeuronios()->end(); i++)
        (*i)->atualiza(vencedor, dado, eta, sigma);
}

// Mensagens durante o algoritmo de treinamento
void SOM::Verboso(unsigned int msg, bool verboso, unsigned int iteracoes, unsigned int n_it, int64_t tempo) {
    if(!verboso)
        return;

    // Escolha das mensagens a serem exibidas
    switch(msg) {
        case 0: { // Início do sumário de treinamento
            cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl;
            cout << " - Dados de treinamento:" << endl;
            if(omp_get_num_procs() > 1)
                cout << " * Utilizando OpenMP: " << omp_get_num_procs() << " processadores" << endl;
            cout << " * Número de iterações: " << iteracoes << endl;
            break;
        }
        case 1: { // Mensagem de inicialização dos neurônios
            cout << " * Inicializando os neurônios de forma aleatória..." << endl;
            break;
        }
        case 2: { // Continuando o sumário do treinamento
            cout << endl << " * Treinando o SOM..." << endl << endl;
            break;
        }
        case 3: { // TODO Verificar melhor isso
            if( (10*(n_it + 1) % iteracoes) == 0) // A cada 10%, faz uma exibição do progresso
                cout << "    * Progresso: " << (n_it + 1) << " iterações (" << (100 * (n_it + 1) / iteracoes) << "%)" <<
                     endl;
            break;
        }
        case 4: { // Finalizando o sumário de treinamento
            cout << endl << " * Mapa gerado!" << endl;
            cout << " * Tempo decorrido: " << tempo/1000000000.0 << " segundo(s)." << endl;
            cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
            break;
        }
        default: {
            cout << "Nada para fazer..." << endl;
            cout << "O bolo é uma mentira!" << endl; // GLaDOS FTW!!
        }
    }
}

// Construtor
SOM::SOM(unsigned int largura, unsigned int dimensao_entrada, double sigma, double tau2, double eta, int semente) :
         ger_mt(semente) {
    this->sigma_ini = sigma;
    this->tau2 = tau2;
    this->eta_ini = eta;
	
    this->tau1 = tau2/log(sigma);

    this->dimensao_entrada = dimensao_entrada;
    this->arranjo = new Arranjo(largura, dimensao_entrada);
}

// Destrutor
SOM::~SOM() {
    delete this->arranjo;
}

// Faz o treinamento do SOM segundo o algoritmo incremental
void SOM::treinaSOM(vector<Dado*>* dados, unsigned int iteracoes, bool inicializa, bool verboso) {
    this->Verboso(0, verboso, iteracoes); // Começo do sumário do treinamento

    if(inicializa) { // Inicializa os neurônios do arranjo de forma aleatória
        this->Verboso(1, verboso); // Mensagem de inicialização dos neurônios
        this->inicializaRand(); // Inicializa os neurônios do arranjo com valores aleatórios
    }

    this->desmarcaDados(dados); // Desmarca todos os dados

    this->Verboso(2, verboso); // Continuando o sumário do treinamento

    auto inicio = high_resolution_clock::now(); // Início da contagem do tempo!

    // Repete até o número máximo de iterações
    for(unsigned int n_it = 0; n_it < iteracoes; n_it++) {
        double sigma = this->calculaSigma(n_it); // Calcula a largura da vizinhança
        double eta = this->calculaEta(n_it); // Calcula a taxa de aprendizado
		
        // Apresenta todos os dados de forma aleatória e atualiza os pesos sinápticos dos neurônios no arranjo
        while(!this->todosDadosMarcados(dados)) {
            auto dado = this->getDadoRand(dados); // Obtém um dado de forma aleatória
            auto vencedor = this->arranjo->getVencedor(dado); // Faz a competição
            this->atualizaNeuronios(*vencedor, dado, eta, sigma); // Atualiza os neurônios do arranjo!
        }

        this->desmarcaDados(dados); // Desmarca os dados ao final de cada iteração

        this->Verboso(3, verboso, iteracoes, n_it); // Exibição do progresso
    }

    auto fim = high_resolution_clock::now(); // Fim da contagem do tempo!
    // Cálculo do tempo passado para o aprendizado
    auto duracao = duration_cast<nanoseconds>(fim - inicio);

    // Finalizando o sumário de treinamento
    this->Verboso(4, verboso, iteracoes, 0, duracao.count());
}

// Gets e sets
double SOM::getSigmaIni() {
    return this->sigma_ini;
}

double SOM::getEtaIni(){
    return this->eta_ini;
}

double SOM::getTau1(){
    return this->tau1;
}

double SOM::getTau2(){
    return this->tau2;
}

Arranjo* SOM::getArranjo(){
    return this->arranjo;
}
	
void SOM::setSigmaIni(double sigma){
    this->sigma_ini = sigma;
}

void SOM::setEtaIni(double eta){
    this->eta_ini = eta;
}

void SOM::setTau1(double tau1){
    this->tau1 = tau1;
}

void SOM::setTau2(double tau2) {
    this->tau2 = tau2;
}

// Faz um sumário do SOM
void SOM::sumario() {
    cout << "╔═══════════════════════════════ Sumário do SOM ═══════════════════════════════╗" << endl;
    cout << " - Hiperparâmetros:" << endl;
    cout << " * Dimensão do mapa: " << this->arranjo->getLargura() << " x " << this->arranjo->getLargura() << endl;
    cout << " * Dimensão de entrada: " << this->dimensao_entrada << endl;
    cout << " * Valores (sigma, eta, tau1, tau2): " << "(" <<
        this->sigma_ini << ", " <<
        this->eta_ini << ", " <<
        this->tau1 << ", " <<
        this->tau2 << ")" << endl;
    cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
}
