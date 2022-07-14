//======================================================================================================================
// Name        : ControladorSegmentadorSOM.cpp
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

#include "../Controlador/ControladorSegmentadorSOM.h"

// Faz a execução padrão do programa
void ControladorSegmentadorSOM::padrao() {

    Controlador::padrao(); // Chama o método da classe mãe

    cout << endl;

    // TODO Implementar um método de leitura de datasets

    // Criando e preparando os dados
    vector<double>* v; // Ponteiro para um vetor com os valores dos dados
    Dado* d; // Ponteiro para um objeto Dado
    auto* dados_treinamento = new ConjuntoDados(); // Conjunto dos dados de treinamento

    v = new vector<double>(6); *v = {2, 0, 6, 0, 0, 0};
    d = new Dado(v, "Pa");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 3, 3, 1, 1, 0};
    d = new Dado(v, "Al");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 4, 5, 0, 0, 1};
    d = new Dado(v, "Ma");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 4, 4, 1, 0, 0};
    d = new Dado(v, "Mi");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 1, 4, 1, 0, 0};
    d = new Dado(v, "Si");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 1, 7, 0, 0, 0};
    d = new Dado(v, "Pe");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 1, 5, 0, 0, 1};
    d = new Dado(v, "Mt");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 2, 3, 1, 0, 0};
    d = new Dado(v, "Ad");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 0, 7, 0, 0, 0};
    d = new Dado(v, "Br");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 3, 4, 1, 0, 0};
    d = new Dado(v, "Jo");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 0, 3, 1, 0, 0};
    d = new Dado(v, "Ti");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 4, 6, 0, 0, 0};
    d = new Dado(v, "Ag");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 0, 5, 0, 0, 1};
    d = new Dado(v, "Le");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 3, 7, 0, 0, 0};
    d = new Dado(v, "Fr");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 2, 4, 1, 0, 0};
    d = new Dado(v, "Ca");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 2, 4, 0, 0, 0};
    d = new Dado(v, "He");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 5, 3, 1, 1, 0};
    d = new Dado(v, "Af");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {0, 3, 6, 0, 0, 0};
    d = new Dado(v, "Cr");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 3, 5, 0, 0, 1};
    d = new Dado(v, "Ve");
    dados_treinamento->adicionaDado(d);

    v = new vector<double>(6); *v = {1, 1, 7, 0, 0, 0};
    d = new Dado(v, "Ju");
    dados_treinamento->adicionaDado(d);

    // Exibindo os dados de treinamento
    cout << dados_treinamento->toString() << endl;

    // TODO Atualizar o algoritmo SOM, incluindo paralelização e otimizações
    // TODO Incluir o método de aprendizado batch (verificar literatura)
    // TODO Incluir métodos para salvar e ler o SOM em disco

    // Criação do SOM, definindo os hiperparâmetros
    auto* som = new SOM(10, dados_treinamento->getDimensao());

    cout << som->sumario(); // Sumário do SOM

    som->treinaSOM(dados_treinamento); // Treinando o SOM!

    auto* arr = som->getArranjo(); // Arranjo treinado pelo SOM

    // TODO Criação de melhores visualizações (verificar literatura)

    cout << endl;

    // Geração e exibição do mapa contextual
    auto* mapa = new MapaContextual();
    cout << mapa->geraMapa(dados_treinamento, arr) << endl << endl;

    // Exibição dos parâmetros dos neurônios no arranjo
    cout << arr->toString();
}

// TODO Há outros métodos para implementar aqui

// Construtor
ControladorSegmentadorSOM::ControladorSegmentadorSOM(int argc, char** argv, int lingua) :
    Controlador(argc, argv, lingua) {}
