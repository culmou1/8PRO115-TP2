#include <iostream>
#include <string>
#include <algorithm>
#include "person.h"
#include "club.h"
#include "rupture.h"
#include "contrat.h"
#include "palmares.h"
#include "ligue.h"

//----------------------------------------------------------------- Constructeur de Joueur
Joueur::~Joueur(){
	std::cout << "CARACTERISTIQUES DU JOUEUR " << obtenirNP() << " : " << std::endl;
	std::cout << "-		AGE : " << _age << " ans" << std::endl;
	std::cout << "-		TAILLE : "<< _taille << "m" << std::endl;
	std::cout << "-		POIDS : "<< _poids << "kg" << std::endl;
}

//----------------------------------------------------------------- obtenirNP
std::string Person::obtenirNP() {
	return _prenom+" "+_nom;
}

//----------------------------------------------------------------- RompreSonContrat
void Joueur_Autonome::RompreSonContrat(Contrat* leContrat){
	std::string raisonDuDepart, choisirClub;
    double penalite;

	std::cout << std::endl << "*******************ROMPRE LE CONTRAT DU JOUEUR*******************" << std::endl;

	//Creation de la rupture
	if(leContrat != NULL)
	{
        std::cout << std::endl <<  "//		RAISON DU DEPART : "; getline(std::cin,raisonDuDepart);
        std::cout << std::endl <<  "//		PENALITE DE DEPART : "; std::cin >> penalite;
		std::cout << std::endl << "//		CHOISIR NOUVELLE EQUIPE (ecrire en minuscule): ";  std::cin >> choisirClub; //choix de la couleur du Club

		Club *newClub = leContrat->getClubContractant()->getLigue()->RechercherClub(choisirClub);

        // Construction de la rupture
		Rupture* newRupture = new Rupture(this,newClub,raisonDuDepart,penalite);
		leContrat->getClubContractant()->addRuptureDeContrats(newRupture);
		std::cout << "Le joueur " << obtenirNP() << " a rompu son contrat." << std::endl;

		//Creation du nouveau contrat du joueur
		leContrat->getClubContractant()->TransfertJoueur(obtenirNP(), newClub);

	}
    else
	{
		std::cout << "Le joueur " << obtenirNP() << " n'a pas de contrat." << std::endl;
    }
}
//----------------------------------------------------------------- DemandeDeTransfert
bool Joueur_NonAutonome::DemandeDeTransfert(){
		if (_anneeCumulee >= 3){ // Retourne vrai si la joueur a joué plus de 3 ans
			_avisFavorable = true;
			return _avisFavorable;
        }
        else return false;
    }

//----------------------------------------------------------------- RompreSonContrat
void Joueur_NonAutonome::RompreSonContrat(Contrat* leContrat){
	std::string raisonDuDepart, choisirClub;
    double penalite;
	std::cout << std::endl << "*******************ROMPRE LE CONTRAT DU JOUEUR*******************" << std::endl;
	if(DemandeDeTransfert()){ //Verifie l'avis Favorable en fonction des annees cumulees
		//Creation de la rupture
		if(leContrat != NULL)
		{
			std::cout << std::endl <<  "//		RAISON DU DEPART : "; getline(std::cin,raisonDuDepart);
			std::cout << std::endl <<  "//		PENALITE DE DEPART : "; std::cin >> penalite;
			std::cout << std::endl << "//		CHOISIR NOUVELLE EQUIPE (ecrire en minuscule): ";  std::cin >> choisirClub;//choix de la couleur du Club

			Club *newClub = leContrat->getClubContractant()->getLigue()->RechercherClub(choisirClub);

			// Construction de la rupture
			Rupture* newRupture = new Rupture(this,newClub,raisonDuDepart,penalite);
			leContrat->getClubContractant()->addRuptureDeContrats(newRupture);
			std::cout << "Le joueur " << obtenirNP() << " a rompu son contrat." << std::endl;

			//Creation du nouveau contrat du joueur
			leContrat->getClubContractant()->TransfertJoueur(this->obtenirNP(), newClub);

		}
		else
		{
			std::cout << "Le joueur " << obtenirNP() << " n'a pas de contrat." << std::endl;
		}
	}
	else
		std::cout << "Le joueur " << obtenirNP() << " n'a pas d'avis favorable." << std::endl;
}

//-----------------------------------------------------------------addTitreGagne
void Entraineur::addTitreGagne(TitreGagne* titre) {
	_titreGagne.push_back(titre);
}

//-----------------------------------------------------------------afficherTitreGagne
void Entraineur::afficherTitreGagne(){
	std::cout << std::endl <<"*******************LISTE DES TITRES DE L\'ENTRAINEUR******************* " << std::endl;
    for (unsigned int i = 0; i < _titreGagne.size();i++){
		std::cout << "Voici la Position du TitreGagne: " << i << " - "<< getTextForTitre(_titreGagne[i]->getTitre()) << std::endl;
    }
}

//-----------------------------------------------------------------selectTitreGagne
Palmares* Entraineur::selectTitreGagne(int j){
    for(unsigned int i = 0; i < _titreGagne.size();i++){ //
        if (_titreGagne[j]==_titreGagne[i])
            return _titreGagne[i];
    }
	std::cout << "Le Titre selectionne n\'existe pas" << std::endl;
	return NULL;
}

//-----------------------------------------------------------------getNumberOfTitre
int Entraineur::getNumberOfTitre(){
    return (int)_titreGagne.size(); // Retourne le nombre de titre
}

//-----------------------------------------------------------------deleteTitreGagne
void Entraineur::deleteTitreGagne(std::string date) {

	Date currentDate = To_Date(date);
	for(unsigned int i=0; i<_titreGagne.size(); i++) {// Regarde la grandeur 
		if (_titreGagne[i]->getDate() == currentDate) {
			delete _titreGagne[i];
			_titreGagne.erase(_titreGagne.begin()+i);
		}
	}
}
