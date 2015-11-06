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

	//Cree le nouveau club et l'ajoute aux clubs de la ligue
	Club* newClub = new Club(histoireDuClub, couleurDuClub, adresseDuClub, villeDuClub, anneeDeCreation, this);
	AjouterClub(newClub);

}

//----------------------------------------------------------------- AjouterClub
void Ligue::AjouterClub(Club* clubs) {
	//ajoute un club et son calendrier a la ligue
	clubsDeLaLigue.push_back(clubs);
	calendrierDeLaLigue.push_back(clubs->getCalendrier());
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
	Club* aSupprimer = RechercherClub(couleur);

	std::cout << std::endl << "*******************SUPPRESSION D'UN CLUB*******************" << std::endl;

	if(aSupprimer != NULL) {// Si le club existe
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

//----------------------------------------------------------------- AfficherClubs
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
	Calendrier* aSupprimer = RechercherCalendrier(couleur);

	std::cout << std::endl << "*******************SUPPRESSION D\'UN CALENDRIER*******************" << std::endl;

	if(aSupprimer != NULL) {// Si le calendrier existe
		for (unsigned int i=0; i<calendrierDeLaLigue.size(); i++) {
			if(calendrierDeLaLigue[i] == aSupprimer) {
				delete calendrierDeLaLigue[i];
				calendrierDeLaLigue.erase(calendrierDeLaLigue.begin()+i);
			}
		}
		std::cout << "Le calendrier du club " << couleur << " a ete supprime de la ligue." << std::endl;
	}
	else 
		std::cerr << "Le club " << couleur << " n\'existe pas." << std::endl; 
}

//-----------------------------------------------------------------EntraineurLePlusTitre
void Ligue::EntraineurLePlusTitre(){
	int nbTitre = 0;
	Person *entraineurLePlusTitre;

	std::cout << std::endl <<"*******************L\'ENTRAINEUR LE PLUS TITRE******************* " << std::endl;
	
	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){//Itere dans les clubs de la ligue
		for(unsigned int j = 0; j < clubsDeLaLigue[i]->getStaffTechnique().size();j++){//Itere dans le staff d'un club
			int currentNumber = clubsDeLaLigue[i]->getStaffTechnique()[j]->getNumberOfTitre();
			if(currentNumber > nbTitre){// Si le nombre de titre de l'entraineur du club est plus grand
				nbTitre = currentNumber;
				entraineurLePlusTitre = clubsDeLaLigue[i]->getStaffTechnique()[j];
			}
		}
	}
	std::cout << "Voici l\'entraineur le plsu titre: " << entraineurLePlusTitre->obtenirNP() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
}

//-----------------------------------------------------------------ClubLePlusTitre
void Ligue::ClubLePlusTitre(){
	int nbTitre = 0;
	Club *clubLePlusTitre;

	std::cout << std::endl <<"*******************LE CLUB LE PLUS TITRE******************* " << std::endl;

	for (unsigned int i = 0; i < clubsDeLaLigue.size();i++){//Itere dans les clubs de la ligue
		int currentNumber = clubsDeLaLigue[i]->getNumberOfTitre();
		if(currentNumber > nbTitre){// Si le nombre de titre du club est plus grand
			nbTitre = currentNumber;
			clubLePlusTitre = clubsDeLaLigue[i];
		}
	}
	std::cout << "Voici le club le plus titre: " << clubLePlusTitre->getCouleurDuClub() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
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

//----------------------------------------------------------------- AfficherResultat
void Ligue::AfficherResultat(std::string couleur, std::string date) {
	Club* club = RechercherClub(couleur);

	std::cout << std::endl << "*******************RESULTAT DU MATCH DU " << date << "******************* " << std::endl;

	if(club != NULL) {// Si le club existe
		if(club->getCalendrier()->getAllRencontre().empty() != NULL) {// Si le calendrier est pas vide
			club->getCalendrier()->AfficherResultat(club, date);
		}
		else 
			std::cerr << "Le calendrier du club " << couleur << " n\'existe pas." << std::endl; 
	}
	else 
			std::cerr << "Le club " << couleur << " n\'existe pas." << std::endl; 
}