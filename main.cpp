//======================================================================================================================
// Name        : main.cpp
// Author      : Manoel Jorge Ribeiro Neto
// e-mail      : manoeljorge.neto@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Programa SegmentadorSOM, que utiliza o algoritmo SOM de Kohonen.
//======================================================================================================================

#include <iostream>
#include <vector>
#include <string>

#include "./Calculos/Calculos.h"
#include "./Codificador/Dado.h"
#include "./SOM/Neuronio.h"
#include "./SOM/Arranjo.h"
#include "./SOM/SOM.h"
#include "./Visualizacao/MapaContextual.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Lidando com argumentos
    vector<string> arg(argc);
    for (int i = 0; i < argc; i++) // Copiando os argumentos para um vetor de strings
        arg.at(i) = argv[i];
    cout << arg[0] << endl << endl; // Nome do programa

    // TODO Implementar um método de leitura de datasets
    // Criando e preparando os dados
    vector<Dado*>* v = new vector<Dado*>(20);

    vector<double>* a = new vector<double>(6);
    a->at(0) = 2; a->at(1) = 0; a->at(2) = 6; a->at(3) = 0; a->at(4) = 0; a->at(5) = 0;
    Dado* A = new Dado(a,"Pa");
    A->normaliza();
    v->at(0) = A;

    vector<double>* b = new vector<double>(6);
    b->at(0) = 1; b->at(1) = 3; b->at(2) = 3; b->at(3) = 1; b->at(4) = 1; b->at(5) = 0;
    Dado* B = new Dado(b,"Al");
    B->normaliza();
    v->at(1) = B;
	
    vector<double>* c = new vector<double>(6);
    c->at(0) = 1; c->at(1) = 4; c->at(2) = 5; c->at(3) = 0; c->at(4) = 0; c->at(5) = 1;
    Dado* C = new Dado(c,"Ma");
    C->normaliza();
    v->at(2) = C;
	
    vector<double>* d = new vector<double>(6);
    d->at(0) = 0; d->at(1) = 4; d->at(2) = 4; d->at(3) = 1; d->at(4) = 0; d->at(5) = 0;
    Dado* D = new Dado(d,"Mi");
    D->normaliza();
    v->at(3) = D;
	
    vector<double>* e = new vector<double>(6);
    e->at(0) = 1; e->at(1) = 1; e->at(2) = 4; e->at(3) = 1; e->at(4) = 0; e->at(5) = 0;
    Dado* E = new Dado(e,"Si");
    E->normaliza();
    v->at(4) = E;
	
    vector<double>* f = new vector<double>(6);
    f->at(0) = 0; f->at(1) = 1; f->at(2) = 7; f->at(3) = 0; f->at(4) = 0; f->at(5) = 0;
    Dado* F = new Dado(f,"Pe");
    F->normaliza();
    v->at(5) = F;
	
    vector<double>* g = new vector<double>(6);
    g->at(0) = 0; g->at(1) = 1; g->at(2) = 5; g->at(3) = 0; g->at(4) = 0; g->at(5) = 1;
    Dado* G = new Dado(g,"Mt");
    G->normaliza();
    v->at(6) = G;

    vector<double>* h = new vector<double>(6);
    h->at(0) = 1; h->at(1) = 2; h->at(2) = 3; h->at(3) = 1; h->at(4) = 0; h->at(5) = 0;
    Dado* H = new Dado(h,"Ad");
    H->normaliza();
    v->at(7) = H;
	
    vector<double>* i = new vector<double>(6);
    i->at(0) = 0; i->at(1) = 0; i->at(2) = 7; i->at(3) = 0; i->at(4) = 0; i->at(5) = 0;
    Dado* I = new Dado(i,"Br");
    I->normaliza();
    v->at(8) = I;
	
    vector<double>* j = new vector<double>(6);
    j->at(0) = 0; j->at(1) = 3; j->at(2) = 4; j->at(3) = 1; j->at(4) = 0; j->at(5) = 0;
    Dado* J = new Dado(j,"Jo");
    J->normaliza();
    v->at(9) = J;
	
    vector<double>* k = new vector<double>(6);
    k->at(0) = 0; k->at(1) = 0; k->at(2) = 3; k->at(3) = 1; k->at(4) = 0; k->at(5) = 0;
    Dado* K = new Dado(k,"Ti");
    K->normaliza();
    v->at(10) = K;
	
    vector<double>* l = new vector<double>(6);
    l->at(0) = 0; l->at(1) = 4; l->at(2) = 6; l->at(3) = 0; l->at(4) = 0; l->at(5) = 0;
    Dado* L = new Dado(l,"Ag");
    L->normaliza();
    v->at(11) = L;
	
    vector<double>* m = new vector<double>(6);
    m->at(0) = 1; m->at(1) = 0; m->at(2) = 5; m->at(3) = 0; m->at(4) = 0; m->at(5) = 1;
    Dado* M = new Dado(m,"Le");
    M->normaliza();
    v->at(12) = M;
	
    vector<double>* n = new vector<double>(6);
    n->at(0) = 1; n->at(1) = 3; n->at(2) = 7; n->at(3) = 0; n->at(4) = 0; n->at(5) = 0;
    Dado* N = new Dado(n,"Fr");
    N->normaliza();
    v->at(13) = N;
	
    vector<double>* o = new vector<double>(6);
    o->at(0) = 1; o->at(1) = 2; o->at(2) = 4; o->at(3) = 1; o->at(4) = 0; o->at(5) = 0;
    Dado* O = new Dado(o,"Ca");
    O->normaliza();
    v->at(14) = O;
	
    vector<double>* p = new vector<double>(6);
    p->at(0) = 0; p->at(1) = 2; p->at(2) = 4; p->at(3) = 0; p->at(4) = 0; p->at(5) = 0;
    Dado* P = new Dado(p,"He");
    P->normaliza();
    v->at(15) = P;
	
    vector<double>* q = new vector<double>(6);
    q->at(0) = 0; q->at(1) = 5; q->at(2) = 3; q->at(3) = 1; q->at(4) = 1; q->at(5) = 0;
    Dado* Q = new Dado(q,"Af");
    Q->normaliza();
    v->at(16) = Q;
	
    vector<double>* r = new vector<double>(6);
    r->at(0) = 0; r->at(1) = 3; r->at(2) = 6; r->at(3) = 0; r->at(4) = 0; r->at(5) = 0;
    Dado* R = new Dado(r,"Cr");
    R->normaliza();
    v->at(17) = R;
	
    vector<double>* s = new vector<double>(6);
    s->at(0) = 1; s->at(1) = 3; s->at(2) = 5; s->at(3) = 0; s->at(4) = 0; s->at(5) = 1;
    Dado* S = new Dado(s,"Ve");
    S->normaliza();
    v->at(18) = S;
	
    vector<double>* t = new vector<double>(6);
    t->at(0) = 1; t->at(1) = 1; t->at(2) = 7; t->at(3) = 0; t->at(4) = 0; t->at(5) = 0;
    Dado* T = new Dado(t,"Ju");
    T->normaliza();
    v->at(19) = T;

    // Exibindo os dados
    for(unsigned int i = 0; i < v->size(); i++)
        cout << v->at(i)->toString() << endl;

    cout << endl;

    // TODO Atualizar o algoritmo SOM, incluindo paralelização
    // TODO Incluir o método de aprendizado batch (verificar literatura)
    // TODO Incluir métodos para salvar e ler o SOM em disco
    // Criação do SOM, definindo os hiperparâmetros
    SOM* som = new SOM(10, 6);

    som->sumario(); // Sumário do SOM

    som->treinaSOM(v); // Treinando o SOM!

    cout << endl;

    // TODO Criação de melhores visualizações (verificar literatura)
    // Geração do mapa contextual
    MapaContextual* mapa = new MapaContextual();
    Arranjo* arr = som->getArranjo();

    // Exibindo o mapa contextual
    cout << mapa->geraMapa(v,arr) << endl;

    // Exibição dos parâmetros dos neurônios
    cout << endl;
    for(auto i = arr->getNeuronios()->begin(); i != arr->getNeuronios()->end(); i++)
        cout << (*i)->toString() << endl;
	
    return EXIT_SUCCESS;
}
