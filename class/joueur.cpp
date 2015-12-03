#include <iostream>
#include <algorithm>
#include "person.h"
#include "club.h"
#include "rupture.h"
#include "contrat.h"
#include "joueur.h"

//----------------------------------------- Joueur -----------------------------------------
//------------------------------------------------------------------------------------------
//---------------------------------------------------------------- Constructeurs
Joueur::Joueur() {}

Joueur::Joueur(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance):
        Person(prenom,nom,age),_taille(taille),_poids(poids),_emplacementNaissance(emplacementNaissance) {}

Joueur::Joueur(std::string prenom,std::string nom, int age):Person(prenom,nom,age){ }

//---------------------------------------------------------------- Destructeur
Joueur::~Joueur(){
	std::cout << "CARACTERISTIQUES DU JOUEUR " << obtenirNP() << " : " << std::endl;
	std::cout << "-		AGE : " << _age << " ans" << std::endl;
	std::cout << "-		TAILLE : "<< _taille << "m" << std::endl;
	std::cout << "-		POIDS : "<< _poids << "kg" << std::endl;
}

//---------------------------------------------------------------- Constructeur de recopie
 Joueur::Joueur(const Joueur& other) :
		Person(other), _taille(other._taille), _poids(other._poids), _emplacementNaissance(other._emplacementNaissance) {}

//---------------------------------------------------------------- Operateur d'affectation
Joueur& Joueur::operator=(Joueur& other) {
	Person *a, *b;
	a = this;
	b = &other;
	*a = *b; _taille = other._taille; _poids = other._poids; _emplacementNaissance = other._emplacementNaissance;
	return *this;
}

//---------------------------------------------------------------- methods for Taille
double Joueur::getTaille(){
    return _taille;
}

void Joueur::setTaille(double grandeur){
    _taille = grandeur;
}

//---------------------------------------------------------------- methods of poids
double Joueur::getPoids(){
    return _poids;
}

void Joueur::setPoids(double grosseur){
    _poids = grosseur;
}

//---------------------------------------------------------------- methods of emplacementNaissance
std::string Joueur::getEmplacementNaissance(){
    return _emplacementNaissance;
}

void Joueur::setEmplacementNaissance(std::string birthPlace){
    _emplacementNaissance = birthPlace;
}

//-------------------------------------- Joueur_Autonome -------------------------------------
//--------------------------------------------------------------------------------------------
//---------------------------------------------------------------- Constructeurs
Joueur_Autonome::Joueur_Autonome() {}
	
Joueur_Autonome::Joueur_Autonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance):
				Joueur(prenom, nom, age, taille, poids, emplacementNaissance) {}

//---------------------------------------------------------------- Destructeur
Joueur_Autonome::~Joueur_Autonome() {}

//---------------------------------------------------------------- Constructeur de recopie
Joueur_Autonome::Joueur_Autonome(const Joueur_Autonome& other) : Joueur(other) {}

//---------------------------------------------------------------- Operateur d'affectation
Joueur_Autonome& Joueur_Autonome::operator=(Joueur_Autonome& other) {
	Joueur *a, *b;
	a = this;
	b = &other;
	*a = *b;
	return *this;
}

//-------------------------------------Joueur_NonAutonome ------------------------------------
//--------------------------------------------------------------------------------------------
//---------------------------------------------------------------- Constructeurs
Joueur_NonAutonome::Joueur_NonAutonome() {}

// Avec AnneeCumulee
Joueur_NonAutonome::Joueur_NonAutonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance,int anneecumulee):
    Joueur(prenom, nom, age, taille, poids, emplacementNaissance),_anneeCumulee(anneecumulee),_avisFavorable(false) {}

// Sans AnneeCumulee
Joueur_NonAutonome::Joueur_NonAutonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance):
    Joueur(prenom, nom, age, taille, poids, emplacementNaissance), _anneeCumulee(0),_avisFavorable(false) {}

//---------------------------------------------------------------- Destructeur
Joueur_NonAutonome::~Joueur_NonAutonome() {}

//---------------------------------------------------------------- Constructeur de recopie
Joueur_NonAutonome::Joueur_NonAutonome(const Joueur_NonAutonome& other) :
	Joueur(other), _anneeCumulee(other._anneeCumulee), _avisFavorable(other._avisFavorable) {}

//---------------------------------------------------------------- Operateur d'affectation
Joueur_NonAutonome& Joueur_NonAutonome::operator=(Joueur_NonAutonome& other) {
	Joueur *a, *b;
	a = this;
	b = &other;
	*a = *b; _anneeCumulee = other._anneeCumulee; _avisFavorable= other._avisFavorable;
	return *this;
}

//---------------------------------------------------------------- methods for AnneeCumulee
int Joueur_NonAutonome::getAnneeCumulee() {
	return _anneeCumulee;
}

void Joueur_NonAutonome::setAnneeCumulee(int annee) {
	_anneeCumulee = annee;
}

//---------------------------------------------------------------- methods for avisFavorable
bool Joueur_NonAutonome::getAvisFavorable(){
	return _avisFavorable;
}

void Joueur_NonAutonome::getAvisFavorable(bool avis) {
	_avisFavorable = avis;
}

//---------------------------------------------------------------- DemandeDeTransfert
bool Joueur_NonAutonome::DemandeDeTransfert(){
	if (_anneeCumulee >= 3){ // Retourne vrai si la joueur a joue plus de 3 ans
		_avisFavorable = true;
		return _avisFavorable;
    }
    else 
		return false;
}
