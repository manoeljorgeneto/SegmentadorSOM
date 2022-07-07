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
    auto* dados = new vector<Dado*>(20); // Vetor onde os dados serão armazenados

    v = new vector<double>(6); *v = {2, 0, 6, 0, 0, 0};
    d = new Dado(v, "Pa"); d->normaliza();
    dados->at(0) = d;

    v = new vector<double>(6); *v = {1, 3, 3, 1, 1, 0};
    d = new Dado(v, "Al"); d->normaliza();
    dados->at(1) = d;

    v = new vector<double>(6); *v = {1, 4, 5, 0, 0, 1};
    d = new Dado(v, "Ma"); d->normaliza();
    dados->at(2) = d;

    v = new vector<double>(6); *v = {0, 4, 4, 1, 0, 0};
    d = new Dado(v, "Mi"); d->normaliza();
    dados->at(3) = d;

    v = new vector<double>(6); *v = {1, 1, 4, 1, 0, 0};
    d = new Dado(v, "Si"); d->normaliza();
    dados->at(4) = d;

    v = new vector<double>(6); *v = {0, 1, 7, 0, 0, 0};
    d = new Dado(v, "Pe"); d->normaliza();
    dados->at(5) = d;

    v = new vector<double>(6); *v = {0, 1, 5, 0, 0, 1};
    d = new Dado(v, "Mt"); d->normaliza();
    dados->at(6) = d;

    v = new vector<double>(6); *v = {1, 2, 3, 1, 0, 0};
    d = new Dado(v, "Ad"); d->normaliza();
    dados->at(7) = d;

    v = new vector<double>(6); *v = {0, 0, 7, 0, 0, 0};
    d = new Dado(v, "Br"); d->normaliza();
    dados->at(8) = d;

    v = new vector<double>(6); *v = {0, 3, 4, 1, 0, 0};
    d = new Dado(v, "Jo"); d->normaliza();
    dados->at(9) = d;

    v = new vector<double>(6); *v = {0, 0, 3, 1, 0, 0};
    d = new Dado(v, "Ti"); d->normaliza();
    dados->at(10) = d;

    v = new vector<double>(6); *v = {0, 4, 6, 0, 0, 0};
    d = new Dado(v, "Ag"); d->normaliza();
    dados->at(11) = d;

    v = new vector<double>(6); *v = {1, 0, 5, 0, 0, 1};
    d = new Dado(v, "Le"); d->normaliza();
    dados->at(12) = d;

    v = new vector<double>(6); *v = {1, 3, 7, 0, 0, 0};
    d = new Dado(v, "Fr"); d->normaliza();
    dados->at(13) = d;

    v = new vector<double>(6); *v = {1, 2, 4, 1, 0, 0};
    d = new Dado(v, "Ca"); d->normaliza();
    dados->at(14) = d;

    v = new vector<double>(6); *v = {0, 2, 4, 0, 0, 0};
    d = new Dado(v, "He"); d->normaliza();
    dados->at(15) = d;

    v = new vector<double>(6); *v = {0, 5, 3, 1, 1, 0};
    d = new Dado(v, "Af"); d->normaliza();
    dados->at(16) = d;

    v = new vector<double>(6); *v = {0, 3, 6, 0, 0, 0};
    d = new Dado(v, "Cr"); d->normaliza();
    dados->at(17) = d;

    v = new vector<double>(6); *v = {1, 3, 5, 0, 0, 1};
    d = new Dado(v, "Ve"); d->normaliza();
    dados->at(18) = d;

    v = new vector<double>(6); *v = {1, 1, 7, 0, 0, 0};
    d = new Dado(v, "Ju"); d->normaliza();
    dados->at(19) = d;

    // Exibindo os dados
    for(const auto & dado : *dados)
        cout << dado->toString() << endl;

    cout << endl;

    // TODO Atualizar o algoritmo SOM, incluindo paralelização
    // TODO Incluir o método de aprendizado batch (verificar literatura)
    // TODO Incluir métodos para salvar e ler o SOM em disco
    // Criação do SOM, definindo os hiperparâmetros
    SOM* som = new SOM(10, 6);

    som->sumario(); // Sumário do SOM

    som->treinaSOM(dados); // Treinando o SOM!

    cout << endl;

    Arranjo* arr = som->getArranjo(); // Arranjo treinado pelo SOM

    // TODO Criação de melhores visualizações (verificar literatura)
    // Geração e exibição do mapa contextual
    auto* mapa = new MapaContextual();
    cout << mapa->geraMapa(dados, arr) << endl;

    // Exibição dos parâmetros dos neurônios
    cout << endl;
    for(const auto & neuronio : *arr->getNeuronios())
        cout << neuronio->toString() << endl;
}

// TODO Há outros métodos para implementar aqui

// Construtor
ControladorSegmentadorSOM::ControladorSegmentadorSOM(int argc, char** argv, int lingua) :
    Controlador(argc, argv, lingua) {}
