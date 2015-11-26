#include "entraineur.h"
#include "palmares.h"

//----------------------------------------------------------------- Constructeurs
Entraineur::Entraineur() {}

Entraineur::Entraineur(std::string prenom,std::string nom, int age, std::string place) :
	Person(prenom, nom, age, ENTRAINEUR), _placeGrade(place) {}

//----------------------------------------------------------------- Destructeur
Entraineur::~Entraineur() {
	//Suppression des _titreGagne
	for (unsigned int i=0; i <_titreGagne.size(); i++) {
		delete _titreGagne[i];
	}
	_titreGagne.clear();
}

//----------------------------------------------------------------- Constructeur de recopie
Entraineur::Entraineur(const Entraineur& other) :
	Person(other), _placeGrade(other._placeGrade), _titreGagne(other._titreGagne) {}

//----------------------------------------------------------------- Operateur d'affectation
Entraineur& Entraineur::operator=(Entraineur& other) {
	Person *a, *b;
	a = this;
	b = &other;
	*a = *b; _placeGrade = other._placeGrade; _titreGagne = other._titreGagne;
	return *this;
}

//----------------------------------------------------------------- methods of placeGrade
std::string Entraineur::getPlaceGrade(){
    return _placeGrade;
}

void Entraineur::setPlaceGrade(std::string Grade){
	_placeGrade = Grade;
}

//----------------------------------------------------------------- methods of TitresGagnes
VectorPal Entraineur::getTitreGagne() {
	return _titreGagne;
}

//-----------------------------------------------------------------addTitreGagne
void Entraineur::addTitreGagne(TitreGagne* titre) {
	_titreGagne.push_back(titre);
}

//-----------------------------------------------------------------afficherTitreGagne
void Entraineur::afficherTitreGagne(){
	std::cout << std::endl <<"*******************LISTE DES TITRES DE L\'ENTRAINEUR******************* " << std::endl;
    for (unsigned int i = 0; i < _titreGagne.size();i++){
		std::cout << "Voici la Position du TitreGagne: " << i << " - "<< _titreGagne[i]->getTitre() << std::endl;
    }
}

//-----------------------------------------------------------------getNumberOfTitre
int Entraineur::getNumberOfTitre(){
    return (int)_titreGagne.size(); // Retourne le nombre de titre
}
