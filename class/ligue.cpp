#include "ligue.h"
#include "club.h"
#include "calendrier.h"
#include "person.h"

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

//----------------------------------------------------------------- CreerClub
void Ligue::CreerClub() {
	std::string histoireDuClub,	couleurDuClub, adresseDuClub, villeDuClub, anneeDeCreation;
	std::cout << "*******************CREATION D'UN CLUB*******************" << std::endl
	<< "//		COULEUR : "; std::cin >> couleurDuClub;
	std::cin.ignore(1);
	std::cout << std::endl <<  "//		ADDRESSE : "; getline(std::cin, adresseDuClub);
	std::cout << std::endl <<  "//		VILLE : "; std::cin >> villeDuClub;
	std::cin.ignore(1);
	std::cout << std::endl << "//		DATE DE CREATION : "; getline(std::cin,anneeDeCreation);
	std::cout << std::endl << "//		HISTOIRE: "; std::cin >> histoireDuClub;

	Club* newClub = new Club(histoireDuClub, couleurDuClub, adresseDuClub, villeDuClub, anneeDeCreation, this);
	AjouterClub(newClub);
}

//----------------------------------------------------------------- AjouterClub
void Ligue::AjouterClub(Club* clubs) {
	clubsDeLaLigue.push_back(clubs);
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
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i]->getCouleurDuClub() == couleur) {
			delete clubsDeLaLigue[i];
			clubsDeLaLigue.erase(clubsDeLaLigue.begin()+i);
			SupprimerCalendrier(clubsDeLaLigue[i]);
		}
	}
}

//----------------------------------------------------------------- AfficherClub
void Ligue::AfficherClubs(){
	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){
		std::cout << "Voici la Position du Club: " << i << " - "<< clubsDeLaLigue[i]->getCouleurDuClub() << std::endl;
	}
}

//----------------------------------------------------------------- AjouterCalendrier
void Ligue::AjouterCalendrier(Calendrier* calendrier) {
	calendrierDeLaLigue.push_back(calendrier);
}

//-----------------------------------------------------------------SupprimerCalendrier
void Ligue::SupprimerCalendrier(Club* club) {
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i] == club) {
			delete clubsDeLaLigue[i]->getCalendrier();
		}
	}
}

//-----------------------------------------------------------------EntraineurLePlusTitre
void Ligue::EntraineurLePlusTitre(){
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
	std::cout << "Voici l\'entraineur: " << entraineurLePlusTitre->obtenirNP() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
}