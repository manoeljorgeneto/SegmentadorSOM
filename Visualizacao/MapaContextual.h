/* Mapa Contextual, visto na Seção 3.4.2
 * Serve como ferramenta para auxiliar a leitura do SOM */

#ifndef MAPACONTEXTUAL_H_
#define MAPACONTEXTUAL_H_

#include <vector>
#include <string>
#include <sstream>

#include "../Codificador/Dado.h"
#include "../SOM/Neuronio.h"
#include "../SOM/Arranjo.h"

using namespace std;

class MapaContextual {
    void desmarcaNeuronios(vector<Neuronio*>* neuronios); // Desmarca todos os neurônios
    bool todosNeuroniosMarcados(vector<Neuronio*>* neuronios); // Verifica se todos os neurônios estão marcados
	
public:
    MapaContextual(); // Construtor
    virtual ~MapaContextual(); // Destrutor

    virtual string geraMapa(vector<Dado*>* dados, Arranjo* arranjo); // Gera um Mapa Contextual
};

#endif // MAPACONTEXTUAL_H_
