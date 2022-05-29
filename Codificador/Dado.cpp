#include "../Codificador/Dado.h"

// Construtor
Dado::Dado(unsigned int dimensao, string rotulo) {
    this->dimensao = dimensao;
    this->rotulo = rotulo;
    this->marcado = false;
    this->dados = new vector<double>(this->dimensao);
}

// Construtor
Dado::Dado(vector<double>* dados , string rotulo) {
    this->dados = dados;
    this->dimensao = this->dados->size();
    this->rotulo = rotulo;
    this->marcado = false;
}

// Destrutor
Dado::~Dado() {	
    delete this->dados;
}

string Dado::getRotulo() {
    return this->rotulo;
}

vector<double>* Dado::getDados() {
    return this->dados;
}

bool Dado::getMarcado() {
    return this->marcado;
}
	
void Dado::setRotulo(string rotulo) {
    this->rotulo = rotulo;
}

void Dado::setDados(vector<double>* dados) {
    this->dados = dados;
    this->dimensao = this->dados->size();
}

void Dado::setMarcado(bool marcado) {
    this->marcado = marcado;
}

void Dado::normaliza() {
    Calculos::normalizaVetor(this->dados);
}

string Dado::toString() {
    ostringstream str("");
	
    str << "Dado(" << this->rotulo << "): ";
    for(unsigned int i = 0; i < this->dimensao; i++)
        str << this->dados->at(i) << " ";
	
    return str.str();
}
