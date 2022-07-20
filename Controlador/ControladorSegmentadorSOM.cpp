//======================================================================================================================
// Name        : ControladorSegmentadorSOM.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     : v0.1.3-alpha
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

// Verifica os argumentos fornecidos
unsigned ControladorSegmentadorSOM::verificaArgumentos() const {
    // Treina informando o arquivo de dados
    if(this->args.size() == 3 && (this->args.at(1) == "-t" || this->args.at(1) == "--train"))
        return 4;

    // Treina informando os arquivos de dados e configurações
    if(this->args.size() == 4 && (this->args.at(1) == "-t" || this->args.at(1) == "--train"))
        return 5;

    return UINT32_MAX; // Argumento(s) não contemplado(s) pelo método
}

// Exibe uma mensagem de erro de arquivo
void ControladorSegmentadorSOM::erroArquivo() {
    string erro_arquivo;
    switch(this->lingua) {
        case PT_BR: {
            erro_arquivo = "Erro ao ler o arquivo!";
            break;
        }
        default:
            erro_arquivo = "Error reading file!";
    }

    cerr << erro_arquivo << endl;
}

// Atualiza as configurações de acordo com o arquivo de configurações
bool ControladorSegmentadorSOM::configuraArquivo(const string& arqConfigs) {
    if(arqConfigs.empty()) // Configurações padrão
        return false;

    auto* cf = ArquivoCSV_configs::obtemConfigs(arqConfigs);

    if(cf == nullptr) { // Erro ao ler o arquivo de configurações
        this->erroArquivo();
        return false;
    }

    // Atualiza
    c.cfg = arqConfigs; // Nome do arquivo de configurações

    c.largura = cf->largura; c.sigma = cf->sigma; c.tau2 = cf->tau2; c.eta = cf->eta; c.normalizados = cf->normalizados;
    c.semente = cf->semente; // Hiperparâmetros do SOM

    c.lingua = cf->lingua; this->lingua = cf->lingua; // Língua de exibição do programa

    // Parâmetros de treinamento
    c.iteracoes = cf->iteracoes; c.inicializa = cf->inicializa; c.verboso = cf->verboso;

    return true;
}

// Exibe uma tela de ajuda
void ControladorSegmentadorSOM::ajuda() {
    string uso, arqDados, trDados, arqConfigs, trDadosCfg; // Para traduções
    switch(this->lingua) {
        case PT_BR: {
            uso         = "Uso:",
            arqDados    = "<arquivo_dados>",
            trDados     = "(treina informando dados)",
            arqConfigs  = "<arquivo_configs>",
            trDadosCfg  = "(treina informando dados e configurações)";
            break;
        }
        default: {
            uso         = "Usage:",
            arqDados    = "<data_file>",
            trDados     = "(train by informing data)",
            arqConfigs  = "<configs_file>",
            trDadosCfg  = "(train by informing data and settings)";
        }
    }

    cout << uso << endl;
    cout << "   " << PROGRAMA_NOME << " [-t] | [--train] " << arqDados << " " << trDados << endl;
    cout << "   " << PROGRAMA_NOME << " [-t] | [--train] " << arqDados << " " << arqConfigs << " " << trDadosCfg
         << endl;

    Controlador::ajuda(); // Chama o método da classe mãe
}

// Faz a execução padrão do programa
void ControladorSegmentadorSOM::padrao() {
    Controlador::padrao(); // Chama o método da classe mãe

    cout << endl;

    // Criando e preparando os dados de treinamento a partir do arquivo
    auto* dados_treinamento = ArquivoCSV_dados::obtemDados(c.dados, c.normalizados);

    if(dados_treinamento == nullptr) { // Erro ao ler o arquivo de dados
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

    cout << MensagensSOM::sumario(som); // Sumário do SOM

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

// Execução informando o arquivo de dados
void ControladorSegmentadorSOM::padrao(const string& arqDados) {
    c.dados = arqDados; // Atualiza o nome do arquivo de dados
    this->padrao(); // Executa com o novo arquivo de dados
}

// Execução informando os arquivos de dados e configurações
void ControladorSegmentadorSOM::padrao(const string& arqDados, const string& arqConfigs) {
    if(!this->configuraArquivo(arqConfigs)) // Erro ao ler o arquivo de configurações
        return;

    this->padrao(arqDados); // Faz a execução com as novas configurações
}

// TODO Há outros métodos para implementar aqui

// Construtor
ControladorSegmentadorSOM::ControladorSegmentadorSOM(int argc, char** argv, const string& arqConfigs) :
    Controlador(argc, argv) {
    if(!this->configuraArquivo(arqConfigs))
        cout << "Using default settings." << endl;
}

// Executa o programa de acordo com os argumentos fornecidos
void ControladorSegmentadorSOM::executa() {
    switch(this->verificaArgumentos()) {
        case 4: { // Faz a execução, informando o arquivo de dados
            this->padrao(this->args.at(2));
            break;
        }
        case 5: { // Faz a execução, informando os arquivos de dados e configurações
            this->padrao(this->args.at(2), this->args.at(3));
            break;
        }
        default:
            Controlador::executa(); // Chama o método da classe mãe
    }
}
