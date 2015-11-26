#include "calendrier.h"

//----------------------------------------------------------------- Constructeur
Calendrier::Calendrier(){}

//----------------------------------------------------------------- Destructeur
Calendrier::~Calendrier(){
	//Supprime les rencontres du calendrier
	for(unsigned int i=0; i<_rencontres.size(); i++) {
		delete _rencontres[i];
	}
	_rencontres.clear();
}

//----------------------------------------------------------------- Constructeur de recopie
Calendrier::Calendrier(const Calendrier& other) : _rencontres(other._rencontres) {}

//----------------------------------------------------------------- Operateur d'affectation
Calendrier& Calendrier::operator=(Calendrier&& other) {
	_rencontres=other._rencontres;
	return *this;
}

//----------------------------------------------------------------- addRencontre
void Calendrier::addRencontre(Rencontre* game) {
    _rencontres.push_back(game);
}

//----------------------------------------------------------------- methods for rencontres
VectorRen* Calendrier::getRencontres(){
    return &_rencontres;
}
