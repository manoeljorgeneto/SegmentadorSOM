//======================================================================================================================
// Name        : ControladorSegmentadorSOM.cpp
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

#include "../Controlador/ControladorSegmentadorSOM.h"

// Verifica os argumentos fornecidos
unsigned ControladorSegmentadorSOM::verificaArgumentos() const {
    // Treina informando o arquivo de dados
    if(this->args.size() == 3 && (this->args.at(1) == "-t" || this->args.at(1) == "--train"))
        return 4;

    // Treina informando os arquivos de dados e configurações
    if(this->args.size() == 4 && (this->args.at(1) == "-t" || this->args.at(1) == "--train"))
        return 5;

    // Treina informando os arquivos de dados, configurações e do arranjo a ser salvo
    if(this->args.size() == 5 && (this->args.at(1) == "-t" || this->args.at(1) == "--train"))
        return 6;

    // Semelhante ao caso 6, informando também o mapa contextual a ser salvo
    if(this->args.size() == 6 && (this->args.at(1) == "-t" || this->args.at(1) == "--train"))
        return 7;

    // Gera um mapa contextual, informando o arquivo de dados
    if(this->args.size() == 3 && (this->args.at(1) == "-m" || this->args.at(1) == "--map"))
        return 8;

    // Gera um mapa contextual, a partir dos arquivos de dados e do arranjo de neurônios do SOM
    if(this->args.size() == 4 && (this->args.at(1) == "-m" || this->args.at(1) == "--map"))
        return 9;

    // Semelhante ao caso 9, informando também o mapa contextual a ser salvo
    if(this->args.size() == 5 && (this->args.at(1) == "-m" || this->args.at(1) == "--map"))
        return 10;

    return UINT32_MAX; // Argumento(s) não contemplado(s) pelo método
}

// Exibe uma mensagem de erro de arquivo
void ControladorSegmentadorSOM::erroArquivo() {
    switch(this->lingua) {
        case PT_BR: {
            cerr << PTB::erro_arquivo << endl;
            break;
        }
        default:
            cerr << EN::erro_arquivo << endl;
    }
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
    // Para traduções
    string uso, arqDados, arqConfigs, arqArr, arqMapa, trSOM1, trSOM2, trSOM3, trSOM4, grMapa1, grMapa2, grMapa3;
    switch(this->lingua) {
        case PT_BR: {
            uso = PTB::uso,
            arqDados = PTB::arqDados, arqConfigs = PTB::arqConfigs, arqArr = PTB::arqArr, arqMapa = PTB::arqMapa,
            trSOM1 = PTB::trSOM1, trSOM2 = PTB::trSOM2, trSOM3 = PTB::trSOM3, trSOM4 = PTB::trSOM4,
            grMapa1 = PTB::grMapa1, grMapa2 = PTB::grMapa2, grMapa3 = PTB::grMapa3;
            break;
        }
        default: {
            uso = EN::uso,
            arqDados = EN::arqDados, arqConfigs = EN::arqConfigs, arqArr = EN::arqArr, arqMapa = EN::arqMapa,
            trSOM1 = EN::trSOM1, trSOM2 = EN::trSOM2, trSOM3 = EN::trSOM3, trSOM4 = EN::trSOM4,
            grMapa1 = EN::grMapa1, grMapa2 = EN::grMapa2, grMapa3 = EN::grMapa3;
        }
    }

    cout << uso << endl;
    cout << "   " << PROGRAMA_NOME << " [-t|--train] " << arqDados << " " << trSOM1 << endl;
    cout << "   " << PROGRAMA_NOME << " [-t|--train] " << arqDados << " " << arqConfigs << " " << trSOM2 << endl;
    cout << "   " << PROGRAMA_NOME << " [-t|--train] " << arqDados << " " << arqConfigs << " " << arqArr << " "
         << trSOM3 << endl;
    cout << "   " << PROGRAMA_NOME << " [-t|--train] " << arqDados << " " << arqConfigs << " " << arqArr << " "
         << arqMapa << " " << trSOM4 << endl;
    cout << "   " << PROGRAMA_NOME << " [-m|--map] " << arqDados << " " << grMapa1 << endl;
    cout << "   " << PROGRAMA_NOME << " [-m|--map] " << arqDados << " " << arqArr << " " << grMapa2 << endl;
    cout << "   " << PROGRAMA_NOME << " [-m|--map] " << arqDados << " " << arqArr << " " << arqMapa << " " << grMapa3
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

    //TODO Atualizar o algoritmo SOM, incluindo paralelização e otimizações
    //TODO Incluir o método de aprendizado batch (verificar literatura)

    // Criação do SOM, definindo os hiperparâmetros
    auto* som = new SOM(c.largura, dados_treinamento->getDimensao(), c.sigma, c.tau2, c.eta, c.normalizados, c.semente,
                        this->lingua);

    cout << MensagensSOM::sumario(som); // Sumário do SOM

    som->treinaSOM(dados_treinamento, c.iteracoes, c.inicializa, c.verboso); // Treinando o SOM!

    auto* arr = som->getArranjo(); // Arranjo treinado pelo SOM

    Arquivo_Arranjo::gravaArranjo(arr, c.arr); // Grava o arranjo no arquivo

    cout << endl;

    //TODO Criação de métodos para trabalhar com os arquivos gerados
    //TODO Criação de melhores visualizações (verificar literatura)
    //TODO Adicionar métodos para exportar os dados que possibilitem criar visualizações

    ControladorSegmentadorSOM::mapa(dados_treinamento, arr); // Gera, grava e exibe o mapa contextual
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

// Execução informando os arquivos de dados e configurações; além do arranjo e mapa contextual a serem salvos
void ControladorSegmentadorSOM::padrao(const string& arqDados, const string& arqConfigs, const string& arqArranjo,
                                       const string& arqMapa) {
    c.arr = arqArranjo; // Define o nome do arquivo para salvar o arranjo de neurônios

    if(!arqMapa.empty())
        c.mapa = arqMapa; // Define o nome do arquivo para salvar o mapa contextual

    this->padrao(arqDados, arqConfigs);
}

// Gera um mapa contextual, a partir de um conjunto de dados e de um arranjo de neurônios do SOM
void ControladorSegmentadorSOM::mapa(ConjuntoDados* dados, Arranjo* arr, bool grava, bool exibe) const {
    // Geração e exibição do mapa contextual
    auto* mapa = new MapaContextual();
    string ms = mapa->geraMapa(dados, arr);

    if(grava) // Grava o mapa contextual no arquivo
        Arquivo_String::gravaString(ms, c.mapa);

    if(exibe) {
        cout << ms << endl << endl; // Exibe o mapa contextual
        cout << arr->toString(); // Exibição dos parâmetros dos neurônios no arranjo
    }
}

// Gera um mapa contextual, a partir dos arquivos de dados e do arranjo de neurônios do SOM
void ControladorSegmentadorSOM::mapa(const string& arqDados, const string& arqArranjo, bool grava, bool exibe,
                                     const string& arqMapa) {
    Controlador::padrao(); // Chama o método da classe mãe
    cout << endl;

    // Criando e preparando os dados a partir do arquivo
    auto* dados = ArquivoCSV_dados::obtemDados(arqDados, c.normalizados);

    if(dados == nullptr) { // Erro ao ler o arquivo de dados
        this->erroArquivo();
        return;
    }

    // Faz a leitura do arquivo do arranjo de neurônios
    auto* arr = Arquivo_Arranjo::obtemArranjo(arqArranjo);

    if(!arqMapa.empty())
        c.mapa = arqMapa; // Define o nome do arquivo para salvar o mapa contextual

    ControladorSegmentadorSOM::mapa(dados, arr, grava, exibe); // Gera e exibe o mapa contextual
}

// Gera um mapa contextual, informando o arquivo de dados
void ControladorSegmentadorSOM::mapa(const string& arqDados, bool grava, bool exibe) {
    this->mapa(arqDados, c.arr, grava, exibe); // Usa o arranjo no arquivo padrão
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
        case 4: { // Treina informando o arquivo de dados
            this->padrao(this->args.at(2));
            break;
        }
        case 5: { // Treina informando os arquivos de dados e configurações
            this->padrao(this->args.at(2), this->args.at(3));
            break;
        }
        case 6: { // Treina informando os arquivos de dados, configurações e do arranjo a ser salvo
            this->padrao(this->args.at(2), this->args.at(3), this->args.at(4));
            break;
        }
        case 7: { // Semelhante ao caso 6, informando também o mapa contextual a ser salvo
            this->padrao(this->args.at(2), this->args.at(3), this->args.at(4), this->args.at(5));
            break;
        }
        case 8: { // Gera um mapa contextual, informando o arquivo de dados
            this->mapa(this->args.at(2));
            break;
        }
        case 9: { // Gera um mapa contextual, a partir dos arquivos de dados e do arranjo de neurônios do SOM
            this->mapa(this->args.at(2), this->args.at(3));
            break;
        }
        case 10: { // Semelhante ao caso 9, informando também o mapa contextual a ser salvo
            this->mapa(this->args.at(2), this->args.at(3), true, true, this->args.at(4));
            break;
        }
        default:
            Controlador::executa(); // Chama o método da classe mãe
    }
}
