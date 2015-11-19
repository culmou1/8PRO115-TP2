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

//----------------------------------------------------------------- AjouterClub
void Ligue::AjouterClub(Club* clubs) {
	//Ajoute un club et son calendrier a la ligue
	clubsDeLaLigue.push_back(clubs);
	calendrierDeLaLigue.push_back(clubs->getCalendrier());
}

//----------------------------------------------------------------- RechercherClub
Club* Ligue::RechercherClub(std::string nom) {
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i]->getNomDuClub() == nom)
			return clubsDeLaLigue[i];
	}
	return NULL;
}


//----------------------------------------------------------------- AfficherClub
void Ligue::AfficherClubs(){
	std::cout << "*******************AFFICHAGE LISTE DES CLUBS*******************" << std::endl;
	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){
		std::cout << "Voici la Position du Club: " << i << " - "<< clubsDeLaLigue[i]->getNomDuClub() << std::endl;
	}
}

//----------------------------------------------------------------- AjouterCalendrier
void Ligue::AjouterCalendrier(Calendrier* calendrier) {
	calendrierDeLaLigue.push_back(calendrier);
}

Calendrier* Ligue::RechercherCalendrier(std::string nom) {
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i]->getNomDuClub() == nom)
			return clubsDeLaLigue[i]->getCalendrier();
	}
	return NULL;
}

//-----------------------------------------------------------------SupprimerCalendrier
void Ligue::SupprimerCalendrier(std::string nom) {
	Calendrier* aSupprimer = RechercherCalendrier(nom);

	std::cout << std::endl << "*******************SUPPRESSION D\'UN CALENDRIER*******************" << std::endl;
	if(aSupprimer != NULL) {//Si le calendrier existe
		for (unsigned int i=0; i<calendrierDeLaLigue.size(); i++) {
			if(calendrierDeLaLigue[i] == aSupprimer) {
				delete calendrierDeLaLigue[i];
				calendrierDeLaLigue.erase(calendrierDeLaLigue.begin()+i);
			}
		}
		std::cout << "Le calendrier du club " << nom << " a ete supprime de la ligue." << std::endl;
	}
	else
		std::cerr << "Le club " << nom << " n\'existe pas." << std::endl;
}

//-----------------------------------------------------------------EntraineurLePlusTitre
void Ligue::EntraineurLePlusTitre(){

	int nbTitre = 0;
	Person *entraineurLePlusTitre = NULL;

	std::cout << std::endl <<"*******************L\'ENTRAINEUR LE PLUS TITRE******************* " << std::endl;

	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){//Itere dans les clubs de la ligue
		for(unsigned int j = 0; j < clubsDeLaLigue[i]->getStaffTechnique().size();j++){//Itere dans le staff du club
			int currentNumber = clubsDeLaLigue[i]->getStaffTechnique()[j]->getNumberOfTitre();
			if(currentNumber > nbTitre){// si le nb de titre est plus est grand
				nbTitre = currentNumber;
				entraineurLePlusTitre = clubsDeLaLigue[i]->getStaffTechnique()[j];
			}
		}
	}
	std::cout << "Voici l\'entraineur le plsu titre: " << entraineurLePlusTitre->obtenirNP() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
}

//-----------------------------------------------------------------EntraineurLePlusTitre
void Ligue::ClubLePlusTitre(){

	int nbTitre = 0;
	Club *clubLePlusTitre = NULL;

	std::cout << std::endl <<"*******************LE CLUB LE PLUS TITRE******************* " << std::endl;

	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){//Itere dans les clubs de la ligue
		int currentNumber = clubsDeLaLigue[i]->getNumberOfTitre();
		if(currentNumber > nbTitre){// si le nb de titre est plus est grand
			nbTitre = currentNumber;
			clubLePlusTitre = clubsDeLaLigue[i];
		}
	}
	std::cout << "Voici le club le plus titre: " << clubLePlusTitre->getNomDuClub() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
}

//-----------------------------------------------------------------AjouterRencontre
void Ligue::AjouterRencontre(Club* home, Club* away, std::string date) {
	Rencontre* newRencontre = new Rencontre(home, away, date);
	home->getCalendrier()->addRencontre(newRencontre);
	away->getCalendrier()->addRencontre(newRencontre);
}

//----------------------------------------------------------------- AfficherRencontre
void Ligue::AfficherRencontre(Club *club){
	std::cout << std::endl << "*******************CALENDRIER DES RENCONTRES DU CLUB******************* " << std::endl;
    try // Fait la fonction
    {
		club->getCalendrier()->AfficherRencontreForHomeClub(club);
    }
    catch (const std::exception &e) // Si une Erreur est survenu
    {
        std::cerr << e.what() << std::endl; // Description de l'erreur
    }
    try // Fait la fonction
    {
        club->getCalendrier()->AfficherRencontreForAwayClub(club);
    }
    catch (const std::exception & e) // Si une erreur survient
    {
        std::cerr << e.what() <<std::endl; // Description de l'erreur
    }
}

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
