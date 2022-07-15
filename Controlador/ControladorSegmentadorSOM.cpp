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

    // Criando e preparando os dados de treinamento a partir do arquivo
    auto* dados_treinamento = ArquivoCSV_dados::obtemDados(c.dados, c.normalizados);

    if(dados_treinamento == nullptr) { // Erro ao ler o arquivo
        this->erroArquivo();
        return;
    }

    // Exibindo os dados de treinamento
    cout << dados_treinamento->toString() << endl;

    //TODO Incluir métodos para salvar e ler o SOM em disco
    //TODO Atualizar o algoritmo SOM, incluindo paralelização e otimizações
    //TODO Incluir o método de aprendizado batch (verificar literatura)

    // Criação do SOM, definindo os hiperparâmetros
    auto* som = new SOM(c.largura, dados_treinamento->getDimensao(), c.sigma, c.tau2, c.eta, c.normalizados, c.semente,
                        this->lingua);

    cout << som->sumario(); // Sumário do SOM

    som->treinaSOM(dados_treinamento, c.iteracoes, c.inicializa, c.verboso); // Treinando o SOM!

    auto* arr = som->getArranjo(); // Arranjo treinado pelo SOM

    //TODO Criação de melhores visualizações (verificar literatura)

    cout << endl;

    // Geração e exibição do mapa contextual
    auto* mapa = new MapaContextual();
    cout << mapa->geraMapa(dados_treinamento, arr) << endl << endl;

    // Exibição dos parâmetros dos neurônios no arranjo
    cout << arr->toString();
}

// TODO Há outros métodos para implementar aqui

// Construtor
ControladorSegmentadorSOM::ControladorSegmentadorSOM(int argc, char** argv) : Controlador(argc, argv) {
    // Atualiza as configurações de acordo com o arquivo de configurações
    auto* cf = ArquivoCSV_configs::obtemConfigs(c.cfg);

    if(cf == nullptr) { // Erro ao ler o arquivo
        this->erroArquivo();
        cout << "Using default configs." << endl;
    } else { // Atualiza
        c.largura = cf->largura; c.sigma = cf->sigma; c.tau2 = cf->tau2; c.eta = cf->eta;
        c.normalizados = cf->normalizados; c.semente = cf->semente;
        c.lingua = cf->lingua; this->lingua = cf->lingua;
        c.iteracoes = cf->iteracoes; c.inicializa = cf->inicializa; c.verboso = cf->verboso;
    }
}
