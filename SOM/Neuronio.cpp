#include "../SOM/Neuronio.h"

// Construtor
Neuronio::Neuronio(unsigned int dim_entrada, vector<unsigned int>* posicao, string rotulo) {
	this->posicao = posicao;
	this->pesos = new vector<double>(dim_entrada);
	
	this->dim_entrada = dim_entrada;
	this->dim_saida = this->posicao->size();
	
	this->rotulo = rotulo;
	this->marcado = false;
}

// Construtor
Neuronio::Neuronio(vector<double> *pesos, vector<unsigned int>* posicao, string rotulo) {	
	this->pesos = pesos;
	this->posicao = posicao;
		
	this->dim_entrada = this->pesos->size();
	this->dim_saida = this->posicao->size();
	
	this->rotulo = rotulo;
	this->marcado = false;
}

// Destrutor
Neuronio::~Neuronio() {	
	delete this->pesos;
	delete this->posicao;		
}

unsigned int Neuronio::getDim() {
	return this->dim_entrada;
}

vector<double>* Neuronio::getPesos() {
	return this->pesos;	
}

vector<unsigned int>* Neuronio::getPosicao(){
	return this->posicao;
}

string Neuronio::getRotulo() {
	return this->rotulo;
}

bool Neuronio::getMarcado() {
	return this->marcado;
}

void Neuronio::setPesos(vector<double>* pesos) {
	this->pesos = pesos;
	this->dim_entrada = this->pesos->size(); 
}

void Neuronio::setRotulo(string rotulo) {
	this->rotulo = rotulo;
}

void Neuronio::setMarcado(bool marcado) {
	this->marcado = marcado;
}

double Neuronio::getDistancia(const vector<double> &vetor) {
	return Calculos::calculaDistancia(vetor, *this->pesos);
}

void Neuronio::normaliza() {
	Calculos::normalizaVetor(this->pesos);
}

double Neuronio::calculaDistanciaEspacial(Neuronio* n) {	
	// Converte os vetores de inteiro para double
	vector<double> this_pos(this->dim_saida);
	for(unsigned int i = 0; i < this->posicao->size(); i++) {		
		this_pos.at(i) = double(this->posicao->at(i));
	}
	
	vector<double> n_pos(this->dim_saida);;
	for(unsigned int i = 0; i < n->getPosicao()->size(); i++)
		n_pos.at(i) = (double)n->getPosicao()->at(i);

	return Calculos::calculaDistancia(n_pos,this_pos);
}

double Neuronio::calculaVizinhanca(Neuronio* n,	double sigma) {
	return exp(-pow((this)->calculaDistanciaEspacial(n),2)/(2*pow(sigma,2)));
}

/* Faz a equação:
 * w(n+1) = w(n) + eta(n)*h(i(x),n)*[x - w(n)]
 * E depois normaliza o vetor de pesos sinápticos */
void Neuronio::atualiza(Neuronio* vencedor, Dado* dado,	double eta, double sigma) {	
	double h = this->calculaVizinhanca(vencedor,sigma); // Acha o nível de vizinhança
	double plasticidade = eta*h; // Define o quão será atualizado o neurônio
	
	// Acha a subtração x - w
	vector<double> dif = *(dado->getDados()) - *(this->pesos);
	
	// Multiplica pela plasticidade
	dif = plasticidade * dif;
	
	// Altera os pesos do neurônio
	*(this->pesos) =  *(this->pesos) + dif; 

	// Normaliza o vetor de pesos do neurônio
	this->normaliza(); 
}

string Neuronio::toString() {
	ostringstream str("");
	
	str << "Neuronio pos(" << this->posicao->at(0) << "," <<
		this->posicao->at(1) << "): ";
	for(unsigned int i = 0; i < this->dim_entrada; i++) {
		str << this->pesos->at(i) << " ";
	}
	
	return str.str();
}
