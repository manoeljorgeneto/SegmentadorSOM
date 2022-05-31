#include "../Visualizacao/MapaContextual.h"

// Desmarca todos os neurônios
void MapaContextual::desmarcaNeuronios(vector<Neuronio*>* neuronios) {
    #pragma omp parallel for
    for(vector<Neuronio*>::iterator i = neuronios->begin(); i != neuronios->end(); i++)
        (*i)->setMarcado(false);
}

// Verifica se todos os neurônios estão marcados
bool MapaContextual::todosNeuroniosMarcados(vector<Neuronio*>* neuronios) {
    for(vector<Neuronio*>::iterator i = neuronios->begin(); i != neuronios->end(); i++)
        if((*i)->getMarcado() == false)
            return false;
    return true;
}

// Construtor
MapaContextual::MapaContextual() {

}

// Destrutor
MapaContextual::~MapaContextual() {

}

// Gera um Mapa Contextual
string MapaContextual::geraMapa(vector<Dado*>* dados, Arranjo* arranjo) {	
    Dado* d;
    vector<Neuronio*>::iterator n; // Guardará o vencedor
	
	// Desmarca todos os neurônios
    this->desmarcaNeuronios(arranjo->getNeuronios());
	
	// Cria o Mapa Contextual
    unsigned int i = 0;
    while(!this->todosNeuroniosMarcados(arranjo->getNeuronios())) {
        while((i < dados->size()) && !this->todosNeuroniosMarcados(arranjo->getNeuronios())) {
            d = dados->at(i);
            n = arranjo->getVencedor(d,true); // Acha o vencedor e marca-o
            (*n)->setRotulo(d->getRotulo()); // Rotula o neurônio
            i++;
        }
        i = 0;
    }

    this->desmarcaNeuronios(arranjo->getNeuronios());
	
    // Constrói a string com o Mapa Contextual
    ostringstream mapa("") ;
    i = 0;
    unsigned int largura = arranjo->getLargura();
	
    // Percorre todos os neurônios e escreve os seus rótulos em mapa
    for(n = arranjo->getNeuronios()->begin(); n != arranjo->getNeuronios()->end(); n++, i++) {
        if((i % largura == 0) && (i / largura != 0))
			mapa << endl;

        mapa << (*n)->getRotulo() << "		";
	}

    return mapa.str();
}
