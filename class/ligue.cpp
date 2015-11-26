#include "ligue.h"
#include "club.h"
#include "calendrier.h"
#include "person.h"
#include "rencontre.h"

//----------------------------------------------------------------- Constructeur
Ligue::Ligue() {
	_calendrier = new Calendrier;
}

//----------------------------------------------------------------- Destructeur
// Singleton
Ligne* Ligne::instance=NULL;
Ligue::~Ligue() {
	//Suppression des clubs de la Ligue
	for (unsigned int i=0; i <_clubs.size(); i++) {
		delete _clubs[i];
	}
	_clubs.clear();

	//Suppression du calendrier de Ligue
	delete _calendrier;
}
// SingleTon
Ligue* Ligne::getInstance() {
	if(instance == NUll){
		instance = new Ligne;
	}
	return instance;
}

//----------------------------------------------------------------- Constructeur de recopie
Ligue::Ligue(const Ligue& other) : _clubs(other._clubs), _calendrier(other._calendrier) {}

//----------------------------------------------------------------- Operateur d'affectation
Ligue& Ligue::operator=(Ligue&& other) {
	_clubs=other._clubs; _calendrier=other._calendrier;
	return *this;
}

//----------------------------------------------------------------- methods for _clubs
VectorClub* Ligue::getClubs() {
	return &_clubs;
}

//----------------------------------------------------------------- methods for _calendrier
VectorRen* Ligue::getCalendrier() {
	return _calendrier->getRencontres();
}

//----------------------------------------------------------------- addClub
void Ligue::addClub(Club* clubs) {
	//Ajoute un club et son calendrier a la ligue
	_clubs.push_back(clubs);
}

//----------------------------------------------------------------- rechercherClub
Club* Ligue::rechercherClub(std::string nom) {
	for (unsigned int i=0; i<_clubs.size(); i++) {
		if(_clubs[i]->getNomDuClub() == nom)
			return _clubs[i];
	}
	return NULL;
}

//----------------------------------------------------------------- addCalendrier
void Ligue::addCalendrier(Rencontre* match) {
	_calendrier->addRencontre(match);
}

Calendrier* Ligue::rechercherCalendrier(std::string nom) {
	Calendrier* pCalendrier = new Calendrier;

	for (unsigned int i=0; i<getCalendrier()->size(); i++) {
			if(getCalendrier()->at(i)->getLocaux()->getNomDuClub() == nom ||
				getCalendrier()->at(i)->getVisiteurs()->getNomDuClub() == nom)
				pCalendrier->addRencontre(getCalendrier()->at(i));
		}
	return pCalendrier;
}

Rencontre* Ligue::rechercherRencontre(std::string clubLocal, std::string clubInvite, std::string date) {
	for (unsigned int i=0; i<getCalendrier()->size(); i++) {
		if(getCalendrier()->at(i)->getDate() == To_Date(date)) {
			if (getCalendrier()->at(i)->getLocaux()->getNomDuClub() == clubLocal ||
				getCalendrier()->at(i)->getVisiteurs()->getNomDuClub() == clubLocal) {
				if (getCalendrier()->at(i)->getLocaux()->getNomDuClub() == clubInvite ||
					getCalendrier()->at(i)->getVisiteurs()->getNomDuClub() == clubInvite) {
						return getCalendrier()->at(i);
				}
			}
		}
	}
	return NULL;
}



<<<<<<< HEAD
 //----------------------------------------------------------------- AfficherResultat
 void Ligue::AfficherResultat(std::string nom, std::string date) {
 	Club* club = RechercherClub(nom);

 	std::cout << std::endl << "*******************RESULTAT DU MATCH DU " << date << "******************* " << std::endl;

 	if(club != NULL) {// Si le club existe
 		if(club->getCalendrier() != NULL) {// Si le calendrier est pas vide
 			club->getCalendrier()->AfficherResultat(club, date);
 		}
 		else
 			std::cerr << "Le calendrier du club " << nom << " n\'existe pas." << std::endl;
 	}
 	else
 			std::cerr << "Le club " << nom << " n\'existe pas." << std::endl;
 }
=======

>>>>>>> f5fdf0059ab5df9a10899e1707f5179dab8d57e5
