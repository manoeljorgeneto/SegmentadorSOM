/* Classe que implementa o algoritmo SOM de Kohonen.
 * O algoritmo utilizado é o incremental */

#ifndef SOM_H_
#define SOM_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
#include <chrono>
#include <omp.h>

#include "../Calculos/Calculos.h"
#include "../Codificador/Dado.h"
#include "../SOM/Neuronio.h"
#include "../SOM/Arranjo.h"

using namespace std;
using namespace std::chrono;

class SOM {
    Arranjo* arranjo; // Arranjo de neurônios

    unsigned int dimensao_entrada; // Dimensão de entrada

    double sigma_ini, eta_ini; // Valores iniciais dos parâmetros sigma e eta
    double tau1, tau2; // Valores das constantes temporais

    // Para geração de números aleatórios
    std::mt19937 ger_mt; // gerador mersenne_twister

    double calculaSigma(unsigned int tempo); // Calcula a largura da vizinhança
    double calculaEta(unsigned int tempo); // Calcula a taxa de aprendizado

    double geraRand(double x = 1.0); // Gera um número real aleatório no intervalo [0,x), com distribuição uniforme
    unsigned int geraRandInt(unsigned int n = 1); // Gera um inteiro aleatório no intervalo [0,n]

    vector<double> geraVetorRand(); // Gera um vetor de pesos aleatório
    void inicializaRand(); // Inicializa os neurônios do arranjo com valores aleatórios
    Dado* getDadoRand(vector<Dado*>* dados); // Obtém um dado ainda não marcado
	
    void desmarcaDados(vector<Dado*>* dados); // Desmarca todos os dados
    bool todosDadosMarcados(vector<Dado*>* dados); // Verifica se todos os dados foram marcados

    // Atualiza todos os neurônios do arranjo
    void atualizaNeuronios(Neuronio* vencedor, Dado* dado, double eta, double sigma);

    // Mensagens durante o algoritmo de treinamento
    virtual void Verboso(unsigned int msg, bool verboso = true, unsigned int iteracoes = 0, unsigned int n_it = 0,
                 int64_t tempo = 0);

public:
    // Construtor
    SOM(unsigned int largura, unsigned int dimensao_entrada, double sigma = 2.5, double tau2 = 1000.0, double eta = 0.1,
        int semente = 1000);
    virtual ~SOM(); // Destrutor

    // Faz o treinamento do SOM segundo o algoritmo incremental
    virtual void treinaSOM(vector<Dado*>* dados, unsigned int iteracoes = 10000, bool inicializa = true,
                           bool verboso = true);
	
	// Gets e sets
    double getSigmaIni();
    double getEtaIni();
    double getTau1();
    double getTau2();
    Arranjo* getArranjo();
	
    void setSigmaIni(double sigma);
    void setEtaIni(double eta);
    void setTau1(double tau1);
    void setTau2(double tau2);

    virtual void sumario(); // Faz um sumário do SOM
};

#endif // SOM_H_
