//======================================================================================================================
// Name        : Controlador.cpp
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

#include "../Controlador/Controlador.h"

// Verifica os argumentos fornecidos
unsigned Controlador::verificaArgumentos() const {
    if(this->args.size() == 1) // Tem apenas o caminho do programa, faz a execuçao padrão
        return 0;

    if(this->args.size() > 2) // Argumento complexo, requer um melhor tratamento
        return this->verificaArgumentos_Expandido();

    // Versão do programa (simples)
    if(this->args.at(1) == "-v" || this->args.at(1) == "--version")
        return 1;

    // Versão do programa (verbosa)
    if(this->args.at(1) == "-V" || this->args.at(1) == "--Version")
        return 2;

    // Tela de ajuda
    if(this->args.at(1) == "-h" || this->args.at(1) == "--help" || this->args.at(1) == "-H" ||
       this->args.at(1) == "--Help")
        return 3;

    // The cake is a lie!
    if(this->args.at(1) == "-c" || this->args.at(1) == "--cake")
        return (UINT32_MAX - 1);

    return UINT32_MAX; // Argumento inválido
}

// Para argumentos complexos
unsigned Controlador::verificaArgumentos_Expandido() const {
    return UINT32_MAX; // O programa ainda não lida com argumentos complexos
}

// Lista os argumentos fornecidos
void Controlador::listaArgumentos() {
    for(const auto& s : this->args)
        cout << s << endl;
}

// Exibe uma mensagem de argumento inválido
void Controlador::argumentoInvalido() {
    string argIn, exec, ajud; // Para tradução
    switch(this->lingua) {
        case PT_BR: {
            argIn   = "Argumento(s) inválido(s)!",
            exec    = "Execute \"",
            ajud    = "para ajuda.";
            break;
        }
        case ENG: {
            argIn   = "Invalid argument(s)!",
            exec    = "Run \"",
            ajud    = "for help.";
            break;
        }
    }

    cout << argIn << endl;
    cout << exec << PROGRAMA_NOME << " -h\" " << ajud << endl;
}

// Exibe a versão do programa
void Controlador::Versao(bool verboso) {
    if(!verboso) {
        cout << VERSAO << endl;
        return;
    }

    cout << PROGRAMA_NOME << ", version: " << VERSAO << endl;
    cout << "Copyright © "<< COPYRIGHT_ANOS << " " << AUTOR << " <" << AUTOR_EMAIL << ">" << endl;
    cout << "Licensed under " << LICENCA << " version " << LICENCA_VERSAO << " or later <" << LICENCA_SITE << ">"
         << endl;
    cout << "This program comes with ABSOLUTELY NO WARRANTY." << endl;
    cout << "This is free software, and you are welcome to redistribute it under certain conditions; "
         << "see the file " << LICENCA_ARQUIVO << " for details." << endl;
}

// Exibe uma tela de ajuda
void Controlador::Ajuda() {
    string uso, verPr, verPrVb, exAj, cake, nArg, exPdr; // Para traduções
    switch(this->lingua) {
        case PT_BR: {
            uso     = "Uso:",
            verPr   = "(versão do programa, simples)",
            verPrVb = "(versão do programa, verbosa)",
            exAj    = "(exibe esta ajuda)",
            cake    = "(para ganhar um bolo)",
            nArg    = " <sem argumento> ",
            exPdr   = "(faz a execução padrão)";
            break;
        }
        case ENG: {
            uso     = "Usage:",
            verPr   = "(program version, simple)",
            verPrVb = "(program version, verbose)",
            exAj    = "(display this help)",
            cake    = "(to win a cake)",
            nArg    = " <no argument> ",
            exPdr   = "(do default execution)";
            break;
        }
    }

    cout << uso << endl;
    cout << "   " << PROGRAMA_NOME << " [-v] | [--version] " << verPr << endl;
    cout << "   " << PROGRAMA_NOME << " [-V] | [--Version] " << verPrVb << endl;
    cout << "   " << PROGRAMA_NOME << " [-h] | [-H] | [--help] | [--Help] " << exAj << endl;
    cout << "   " << PROGRAMA_NOME << " [-c] | [--cake] " << cake << endl;
    cout << "   " << PROGRAMA_NOME << nArg << exPdr << endl;
}

// Faz a execução padrão do programa
void Controlador::Padrao() {
    this->listaArgumentos();
    this->Versao();
}

// Construtor
Controlador::Controlador(int argc, char** argv, int lingua) :
    args(argv, argv + argc) { // Lidando com argumentos
    this->lingua = lingua;
}

// Destrutor
Controlador::~Controlador() {}

// Executa o programa de acordo com os argumentos fornecidos
void Controlador::executa() {
    switch(this->verificaArgumentos()) {
        case 0: { // Faz a execução padrão
            this->Padrao();
            break;
        }
        case 1: { // Versão do programa (simples)
            this->Versao(false);
            break;
        }
        case 2: { // Versão do programa (verbosa)
            this->Versao();
            break;
        }
        case 3: { // Ajuda
            this->Ajuda();
            break;
        }
        case (UINT32_MAX - 1): { // O bolo é uma mentira!
            cout << "The cake is a lie :P !" << endl; // GLaDOS FTW!!
            break;
        }
        default: // Argumento inválido
            this->argumentoInvalido();
    }
}

// Gets e sets
vector<string> Controlador::getArgs() const {
    return this->args;
}

int Controlador::getLingua() const {
    return this->lingua;
}

void Controlador::setArgs(const vector<string> &args) {
    this->args = args;
}

void Controlador::setLingua(int lingua) {
    this->lingua = lingua;
}
