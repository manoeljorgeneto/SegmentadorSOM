// Classe para efetuar cálculos diversos entre vetores de doubles

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include <vector>
#include <cmath>

using namespace std;

vector<double> operator+ (vector<double> &a, vector<double> &b); // Soma de vetores
vector<double> operator- (vector<double> &a, vector<double> &b); // Subtração de vetores
vector<double> operator/ (vector<double> &a, double b); // Divisão por um Real
vector<double> operator* (vector<double> &a, double b); // Multiplicação por um Real
vector<double> operator* (double a, vector<double> &b); // Multiplicação por um Real
double operator* (vector<double> &a, vector<double> &b); // Produto interno

class Calculos {
	
public:
    Calculos(); // Construtor
    virtual ~Calculos(); // Destrutor

    static double calculaNorma(const vector<double> &a); // Módulo do vetor
    static void normalizaVetor(vector<double> *a); // Normaliza o vetor (deixando-o com norma igual a 1)
    static double calculaDistancia(const vector<double> &a, const vector<double> &b); // Distância euclidiana
};

#endif // CALCULOS_H_
