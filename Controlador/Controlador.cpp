// ======================================================================================================================
//  Name              :  main.cpp
//  Author           : Manoel Jorge Ribeiro Neto
//  e-mail              : manoeljorge.neto@gmail.com
//  Version          : v0.1.1-alpha
//  Copyright     : Copyright© 2022, Manoel Jorge Ribeiro Neto. All rights reserved.
//  Description : Programa SegmentadorSOM, que utiliza o algoritmo SOM de Kohonen.
//
//  This file is part of SegmentadorSOM.
//
//  SegmentadorSOM is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
//  License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later
//  version.
//
//  SegmentadorSOM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with SegmentadorSOM. If not, see
//  <https://www.gnu.org/licenses/>
// ======================================================================================================================

//
// Created by manoel on 28/06/22.
//

#include "../Controlador/Controlador.h"

// Exibe a versão do programa
void Controlador::Versao(bool verboso ) {
    if(verboso) {
        cout << "SegmentadorSOM, versão: " << VERSAO << endl;
        cout << "Copyright© 2007-2022, Manoel Jorge Ribeiro Neto <manoeljorge.neto@gmail.com>" << endl;
        cout << "Licensed under GNU GPL version 3 or later <https://www.gnu.org/licenses/>" << endl;
        cout << "This program comes with ABSOLUTELY NO WARRANTY." << endl;
        cout << "This is free software, and you are welcome to redistribute it under certain conditions; see the file COPYING for details."
             << endl;
    } else
        cout << VERSAO << endl;
}

// Construtor
Controlador::Controlador(vector<string>& argm) {
    this->arg = &argm;
}

// Destrutor
Controlador::~Controlador() {

}

// Executa o programa de acordo com os argumentos fornecidos
void Controlador::executa() {
    cout << this->arg->at(0) << endl; // Nome do programa
    this->Versao(true);
}
