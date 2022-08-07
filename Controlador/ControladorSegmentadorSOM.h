//======================================================================================================================
// Name        : ControladorSegmentadorSOM.h
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

#ifndef CONTROLADORSEGMENTADORSOM_H
#define CONTROLADORSEGMENTADORSOM_H

#include "../Controlador/Controlador.h"
#include "../Arquivos/ArquivoCSV_configs.h"
#include "../Arquivos/ArquivoCSV_dados.h"
#include "../Arquivos/Arquivo_Arranjo.h"
#include "../Codificador/Dado.h"
#include "../Codificador/ConjuntoDados.h"
#include "../SOM/Neuronio.h"
#include "../SOM/Arranjo.h"
#include "../SOM/SOM.h"
#include "../Visualizacao/MapaContextual.h"

/**
 * Classe que faz o controle do fluxo do programa, herdeira das características da classe Controlador.
 */
class ControladorSegmentadorSOM : public Controlador {
protected:
    configs c; // Estrutura com as configurações do programa

    [[nodiscard]] unsigned verificaArgumentos() const override; // Verifica os argumentos fornecidos

    void erroArquivo(); // Exibe uma mensagem de erro de arquivo
    // Atualiza as configurações de acordo com o arquivo de configurações
    bool configuraArquivo(const string& arqConfigs);

    void ajuda() override; // Exibe uma tela de ajuda

    void padrao() override; // Faz a execução padrão do programa
    void padrao(const string& arqDados); // Execução informando o arquivo de dados
    // Execução informando os arquivos de dados e configurações
    void padrao(const string& arqDados, const string& arqConfigs);
    // Execução informando os arquivos de dados, configurações e do arranjo a ser salvo
    void padrao(const string& arqDados, const string& arqConfigs, const string& arqArranjo);

    // Gera um mapa contextual, a partir de um conjunto de dados e de um arranjo de neurônios do SOM
    static void mapa(ConjuntoDados* dados, Arranjo* arr);
    // Gera um mapa contextual, a partir dos arquivos de dados e do arranjo de neurônios do SOM
    void mapa(const string& arqDados, const string& arqArranjo);
    // Gera um mapa contextual, informando o arquivo de dados
    void mapa(const string& arqDados);

    // TODO Implementar outros métodos, como leitura do conjunto de neurônios, saída do programa etc.

public:
    ControladorSegmentadorSOM(int argc, char** argv, const string& arqConfigs = ""); // Construtor

    void executa() override; // Executa o programa de acordo com os argumentos fornecidos
};

#endif // CONTROLADORSEGMENTADORSOM_H
