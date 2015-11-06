#include "ligue.h"
#include "club.h"
#include "calendrier.h"
#include "person.h"
#include "rencontre.h"

//----------------------------------------------------------------- Destructeur
Ligue::~Ligue() {
	//Suppression des clubs de la Ligue
	for (unsigned int i=0; i <clubsDeLaLigue.size(); i++) {
		delete clubsDeLaLigue[i];
	}
	clubsDeLaLigue.clear();

	//Suppression du calendrier de Ligue
	for (unsigned int i=0; i <calendrierDeLaLigue.size(); i++) {
		delete calendrierDeLaLigue[i];
	}
	calendrierDeLaLigue.clear();
}

Ligue& Ligue::operator=(Ligue&& other) {
	clubsDeLaLigue=other.clubsDeLaLigue; calendrierDeLaLigue=other.calendrierDeLaLigue;
	return *this;
}

//----------------------------------------------------------------- CreerClub
void Ligue::CreerClub() {
	std::string histoireDuClub,	couleurDuClub, adresseDuClub, villeDuClub, anneeDeCreation;
	std::cout << "*******************CREATION D'UN CLUB*******************" << std::endl
	<< "//		COULEUR : "; std::cin >> couleurDuClub;
	std::cin.ignore(1);
	std::cout << std::endl <<  "//		ADDRESSE : "; getline(std::cin, adresseDuClub);
	std::cout << std::endl <<  "//		VILLE : "; std::cin >> villeDuClub;
	std::cout << std::endl << "//		DATE DE CREATION : "; std::cin >> anneeDeCreation;
	std::cin.ignore(1);
	std::cout << std::endl << "//		HISTOIRE: " ; getline(std::cin,histoireDuClub);

	Club* newClub = new Club(histoireDuClub, couleurDuClub, adresseDuClub, villeDuClub, anneeDeCreation, this);
	AjouterClub(newClub);

}

//----------------------------------------------------------------- AjouterClub
void Ligue::AjouterClub(Club* clubs) {
	clubsDeLaLigue.push_back(clubs);
	calendrierDeLaLigue.push_back(clubs->getCalendrier());
	//creer calendrier du club
}

//----------------------------------------------------------------- RechercherClub
Club* Ligue::RechercherClub(std::string couleur) {
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i]->getCouleurDuClub() == couleur)
			return clubsDeLaLigue[i];
	}
	return NULL;
}

//----------------------------------------------------------------- SupprimerClub
void Ligue::SupprimerClub(std::string couleur) {
	std::cout << std::endl << "*******************SUPPRESSION D'UN CLUB*******************" << std::endl;
	Club* aSupprimer = RechercherClub(couleur);

	if(aSupprimer != NULL) {
		for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
			if(clubsDeLaLigue[i] == aSupprimer) {
				SupprimerCalendrier(couleur);
				delete clubsDeLaLigue[i];
				clubsDeLaLigue.erase(clubsDeLaLigue.begin()+i);
			}
		}
		std::cout << "Le club " << couleur << " a ete supprime de la ligue." << std::endl;
	}
	else
		std::cerr << "Le club " << couleur << " n\'existe pas." << std::endl; 
}

//----------------------------------------------------------------- AfficherClub
void Ligue::AfficherClubs(){
	std::cout << "*******************AFFICHAGE LISTE DES CLUBS*******************" << std::endl;
	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){
		std::cout << "Voici la Position du Club: " << i << " - "<< clubsDeLaLigue[i]->getCouleurDuClub() << std::endl;
	}
}

//----------------------------------------------------------------- AjouterCalendrier
void Ligue::AjouterCalendrier(Calendrier* calendrier) {
	calendrierDeLaLigue.push_back(calendrier);
}

Calendrier* Ligue::RechercherCalendrier(std::string couleur) {
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i]->getCouleurDuClub() == couleur)
			return clubsDeLaLigue[i]->getCalendrier();
	}
	return NULL;
}

//-----------------------------------------------------------------SupprimerCalendrier
void Ligue::SupprimerCalendrier(std::string couleur) {
	std::cout << std::endl << "*******************SUPPRESSION D\'UN CALENDRIER*******************" << std::endl;
	Calendrier* aSupprimer = RechercherCalendrier(couleur);
	for (unsigned int i=0; i<calendrierDeLaLigue.size(); i++) {
		if(calendrierDeLaLigue[i] == aSupprimer) {
			delete calendrierDeLaLigue[i];
			calendrierDeLaLigue.erase(calendrierDeLaLigue.begin()+i);
		}
	}
	std::cout << "Le calendrier du club " << couleur << " a ete supprime de la ligue." << std::endl;
}

//-----------------------------------------------------------------EntraineurLePlusTitre
void Ligue::EntraineurLePlusTitre(){
	std::cout << std::endl <<"*******************L\'ENTRAINEUR LE PLUS TITRE******************* " << std::endl;
	int nbTitre = 0;
	Person *entraineurLePlusTitre = NULL;
	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){
		for(unsigned int j = 0; j < clubsDeLaLigue[i]->getStaffTechnique().size();j++){
			int currentNumber = clubsDeLaLigue[i]->getStaffTechnique()[j]->getNumberOfTitre();
			if(currentNumber > nbTitre){
				nbTitre = currentNumber;
				entraineurLePlusTitre = clubsDeLaLigue[i]->getStaffTechnique()[j];
			}
		}
	}
	std::cout << "Voici l\'entraineur le plsu titre: " << entraineurLePlusTitre->obtenirNP() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
}

//-----------------------------------------------------------------EntraineurLePlusTitre
void Ligue::ClubLePlusTitre(){
	std::cout << std::endl <<"*******************LE CLUB LE PLUS TITRE******************* " << std::endl;
	int nbTitre = 0;
	Club *clubLePlusTitre = NULL;
	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){
		int currentNumber = clubsDeLaLigue[i]->getNumberOfTitre();
		if(currentNumber > nbTitre){
			nbTitre = currentNumber;
			clubLePlusTitre = clubsDeLaLigue[i];
		}
	}
	std::cout << "Voici le club le plus titre: " << clubLePlusTitre->getCouleurDuClub() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
}
<<<<<<< HEAD
=======

//-----------------------------------------------------------------AjouterRencontre
void Ligue::AjouterRencontre(Club* home, Club* away, std::string date) {
	Rencontre* newRencontre = new Rencontre(home, away, date);
	home->getCalendrier()->addRencontre(newRencontre);
	away->getCalendrier()->addRencontre(newRencontre);
}

//----------------------------------------------------------------- AfficherRencontre
void Ligue::AfficherRencontre(Club *club){
	std::cout << std::endl << "*******************CALENDRIER DES RENCONTRES DU CLUB******************* " << std::endl;
    try
    {
		club->getCalendrier()->AfficherRencontreForHomeClub(club);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        club->getCalendrier()->AfficherRencontreForAwayClub(club);
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() <<std::endl;
    }
}
>>>>>>> b44a4983423945be435aeb0c8cda677f7ca4f82e
