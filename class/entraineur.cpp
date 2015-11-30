#include "entraineur.h"
#include "palmares.h"

//----------------------------------------------------------------- Constructeurs
Entraineur::Entraineur() {}

Entraineur::Entraineur(std::string prenom,std::string nom, int age, std::string place) :
	PersonStaff(prenom, nom, age, ENTRAINEUR), _placeGrade(place) {}

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
	PersonStaff(other), _placeGrade(other._placeGrade), _titreGagne(other._titreGagne) {}

//----------------------------------------------------------------- Operateur d'affectation
Entraineur& Entraineur::operator=(Entraineur& other) {
	PersonStaff *a, *b;
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

//----------------------------------------------------------------- Constructeurs
Joueur_Entraineur::Joueur_Entraineur() {}

Joueur_Entraineur::Joueur_Entraineur(std::string prenom,std::string nom, int age, double taille, 
									 double poids,std::string emplacementNaissance, std::string place) :
	Entraineur(prenom, nom, age, place), Joueur(prenom, nom, age, taille, poids, emplacementNaissance) {}

//----------------------------------------------------------------- Destructeur
Joueur_Entraineur::~Joueur_Entraineur() {}

//----------------------------------------------------------------- Constructeur de recopie
Joueur_Entraineur::Joueur_Entraineur(const Joueur_Entraineur& other) :
	Entraineur(other), Joueur(other) {}

//----------------------------------------------------------------- Operateur d'affectation
Joueur_Entraineur& Joueur_Entraineur::operator=(Joueur_Entraineur& other) {
	/*Entraineur a, *b; Joueur *c, *d;
	a = this;
	b = &other;
	*a = *b;*/
	return *this;
}
