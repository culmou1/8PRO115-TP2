#include "club.h"
#include "person.h"
#include "joueur.h"
#include "entraineur.h"
#include "contrat.h"
#include "rupture.h"
#include "palmares.h"
#include "reglement.h"
#include <iostream>
#include <string>

//----------------------------------------------------------------- Constructeur
Club::Club(std::string name, std::string history, std::string color, std::string address, std::string town, std::string year) {
	_nom = name; _histoireDuClub = history; _couleurDuClub = color;
	_adresseDuClub = address;_villeDuClub = town; _anneeDeCreation = To_Date(year);
}

//----------------------------------------------------------------- Destructeur
Club::~Club() {
	std::cout << "CARACTERISTIQUES DU CLUB " << _nom << " : " << std::endl;
	std::cout << "-		COULEUR : " << _couleurDuClub << std::endl;
	std::cout << "-		HISTOIRE : " << _histoireDuClub << std::endl;
	std::cout << "-		ANNEE DE CREATION : "<< _anneeDeCreation << std::endl;
	std::cout << "-		ADDRESSE : "<< _adresseDuClub << ", " << _villeDuClub << std::endl;
	std::cout << "-		NOMBRE DE TITRE(S) GAGNE(S) : "<< _unPalmares.size() << std::endl;
	std::cout << "-		TAILLE DE L\'_effectif : "<< _effectif.size() << std::endl;
	std::cout << "-		TAILLE DU STAFF TECHNIQUE : "<< _staffTechnique.size() << std::endl;

	//Suppression de l'_effectif
	for (unsigned int i=0; i <_effectif.size(); i++) {
		delete _effectif[i];
	}
	_effectif.clear();

	//Suppression du _staffTechnique
	for (unsigned int i=0; i <_staffTechnique.size(); i++) {
		delete _staffTechnique[i];
	}
	_staffTechnique.clear();

	//Suppression du Palmares
	for (unsigned int i=0; i <_unPalmares.size(); i++) {
		delete _unPalmares[i];
	}
	_unPalmares.clear();

	//Suppression des _contratsdEngagement
	for (unsigned int i=0; i <_contratsdEngagement.size(); i++) {
		delete _contratsdEngagement[i];
	}
	_contratsdEngagement.clear();

	//Suppression des _rupturesDeContrats
	for (unsigned int i=0; i <_rupturesDeContrats.size(); i++) {
		delete _rupturesDeContrats[i];
	}
	_rupturesDeContrats.clear();
}

//----------------------------------------------------------------- Constructeur de recopie
Club::Club(const Club& other) : _nom(other._nom), _histoireDuClub(other._histoireDuClub), _couleurDuClub(other._couleurDuClub), _adresseDuClub(other._adresseDuClub),
	_villeDuClub(other._villeDuClub), _anneeDeCreation(other._anneeDeCreation), _effectif(other._effectif), _staffTechnique(other._staffTechnique),
	_unPalmares(other._unPalmares), _contratsdEngagement(other._contratsdEngagement), _rupturesDeContrats(other._rupturesDeContrats) {}

//----------------------------------------------------------------- Operateur d'affectation
Club& Club::operator=(Club&& other) {
	_nom = other._nom; _villeDuClub=other._villeDuClub; _anneeDeCreation=other._anneeDeCreation; _effectif=other._effectif; _staffTechnique=other._staffTechnique;
	_unPalmares=other._unPalmares; _contratsdEngagement=other._contratsdEngagement; _rupturesDeContrats=other._rupturesDeContrats;
	return *this;
}

//----------------------------------------------------------------- CreerEntraineur
void Club::CreerEntraineur(){
	std::string nom, prenom, placeGrade;
	int age;

	std::cout << std::endl << "*******************CREATION D'UN ENTRAINEUR*******************" << std::endl
	<< "//		NOM : "; std::cin >> nom;
	std::cout << std::endl <<  "//		PRENOM : "; std::cin >> prenom;
	std::cout << std::endl <<  "//		AGE : "; std::cin >> age;
	std::cout << std::endl << "//		LIEU D\'OBTENTION DU GRADE : "; std::cin >> placeGrade;

	//Cree le nouveau entrainer et l'ajoute au staff du club
	Person* trainer = new Entraineur(prenom, nom, age, placeGrade);
	addStaffTechnique(trainer);
	std::cout << "L\'entraineur " << trainer->obtenirNP() << " a ete cree et ajoute au staff du club " << _nom << "." << std::endl;
}

//----------------------------------------------------------------- methods for _nomDuClub
std::string Club::getNomDuClub() {
	return _nom;
}

void Club::setNomDuClub(std::string name) {
	_nom = name;
}

//----------------------------------------------------------------- methods for _histoireDuClub
std::string Club::getHistoireDuClub() {
	return _histoireDuClub;
}

void Club::setHistoireDuClub(std::string history) {
	_histoireDuClub = history;
}


//----------------------------------------------------------------- methods for _couleurDuClub
std::string Club::getCouleurDuClub() {
	return _couleurDuClub;
}

void Club::setCouleurDuClub(std::string color) {
	_couleurDuClub = color;
}

//----------------------------------------------------------------- methods for _villeDuClub
std::string Club::getVilleDuClub() {
	return _villeDuClub;
}

void Club::setVilleDuClub(std::string town) {
	_villeDuClub = town;
}

//----------------------------------------------------------------- methods for _villeDuClub
std::string Club::getAdresseDuClub() {
	return _adresseDuClub;
}

void Club::setAdresseDuClub(std::string address) {
	_adresseDuClub = address;
}

//----------------------------------------------------------------- methods for _anneeDeCreation
Date Club::getAnneeDeCreation() {
	return _anneeDeCreation;
}

void Club::setAnneeDeCreation (Date year) {
	_anneeDeCreation = year;
}

//----------------------------------------------------------------- methods for _effectif

VectorJou* Club::getEffectif() {
	return &_effectif;
}

void Club::addEffectif(Joueur *someone) {
	_effectif.push_back(someone);
}

void Club::deleteEffectif(Joueur *someone){
	for (unsigned int i = 0; i< _effectif.size();i++){
		if (_effectif[i]== someone){
			delete _effectif[i];
			_effectif.erase(_effectif.begin()+i);
		}
	}
}

void Club::setEffectif(VectorJou players) {
	_effectif.clear();
	for (unsigned int i = 0; i < players.size(); i++) {
		_effectif.push_back(players[i]);
	}
}

Joueur* Club::rechercherJoueur(std::string joueur){
	for(unsigned int i = 0; i < _effectif.size();i++){
		if (_effectif[i]->obtenirNP() == joueur)
			return _effectif[i];
	}
	return NULL;
}

//----------------------------------------------------------------- methods for _unPalmares
VectorPal* Club::getUnPalmares() {
	return &_unPalmares;
}

void Club::addUnPalmares(Palmares *trophy) {
	_unPalmares.push_back(trophy);
}

void Club::setUnPalmares(VectorPal trophies) {
	_unPalmares.clear();
	for (unsigned int i = 0; i < trophies.size(); i++) {
		_unPalmares.push_back(trophies[i]);
	}
}

int Club::getNumberOfTitre() {
	return (int)_unPalmares.size();
}

//----------------------------------------------------------------- methods for _staffTechnique
VectorPrs* Club::getStaffTechnique() {
		return &_staffTechnique;
	}

void Club::addStaffTechnique(Person *someone) {
	_staffTechnique.push_back(someone);
}

void Club::deleteStaffTechnique(Person *someone){
	for (unsigned int i = 0; i< _staffTechnique.size();i++){
		if (_staffTechnique[i]== someone){
			delete _staffTechnique[i];
			_staffTechnique.erase(_staffTechnique.begin()+i);
		}
	}
}

void Club::setStaffTechnique(VectorPrs staff) {
	_staffTechnique.clear();
	for (unsigned int i = 0; i < staff.size(); i++) {
		_staffTechnique.push_back(staff[i]);
	}
}

//----------------------------------------------------------------- methods for _contratsdEngagement
VectorCon* Club::getContratdEngagement() {
		return &_contratsdEngagement;
	}

void Club::addContratdEngagement(Contrat *contrats) {
	_contratsdEngagement.push_back(contrats);
}

void Club::deleteContratdEngagement(Contrat *contrats){
	for (unsigned int i = 0; i< _contratsdEngagement.size();i++){
		if (_contratsdEngagement[i]== contrats){
			delete _contratsdEngagement[i];
			_contratsdEngagement.erase(_contratsdEngagement.begin()+i);
		}
	}
}

void Club::afficherContratEngagement(){
	std::cout << std::endl << "*******************LISTE DES CONTRATS DU CLUB******************* " << std::endl;
	for (unsigned int i = 0; i < _contratsdEngagement.size();i++){
		std::cout << "Voici la Position du Contrat: " << i << " - " << _contratsdEngagement[i]->getJoueurContractant()->obtenirNP()
			<< " to " << _contratsdEngagement[i]->getClubContractant()->getNomDuClub() << std::endl;
	}
}

Contrat* Club::rechercherContratdEngagement(Joueur *joueur){
	for(unsigned int i = 0; i < _contratsdEngagement.size();i++){
		if (_contratsdEngagement[i]->getJoueurContractant() == joueur)
			return _contratsdEngagement[i];
	}
	return NULL;
}

//----------------------------------------------------------------- methods for _rupturesDeContrats
VectorRup* Club::getRupturesDeContrats() {
		return &_rupturesDeContrats;
	}

void Club::addRuptureDeContrats(Rupture *ruptures) {
	_rupturesDeContrats.push_back(ruptures);
}

void Club::deleteRupturesDeContrats(Rupture *ruptures){
	for (unsigned int i = 0; i< _rupturesDeContrats.size();i++){
		if (_rupturesDeContrats[i]== ruptures){
			delete _rupturesDeContrats[i];
			_rupturesDeContrats.erase(_rupturesDeContrats.begin()+i);
		}
	}
}

void Club::setRupturesDeContrats(VectorRup ruptures) {
	_rupturesDeContrats.clear();
	for (unsigned int i = 0; i < ruptures.size(); i++) {
		_rupturesDeContrats.push_back(ruptures[i]);
	}
}

Rupture* Club::rechercherRupturesDeContrats(Joueur *joueur){
	for(unsigned int i = 0; i < _rupturesDeContrats.size();i++){
		if (_rupturesDeContrats[i]->getJoueurRelaxant() == joueur)
			return _rupturesDeContrats[i];
	}
	return NULL;
}
