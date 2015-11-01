#include "club.h"
#include "iostream"

//----------------------------------------------------------------- Constructor
Club::Club(std::string history, std::string color, std::string address, std::string town, std::string year) {
	histoireDuClub = history; couleurDuClub = color; adresseDuClub = address;
	villeDuClub = town; anneeDeCreation = To_Date(year);
}

//----------------------------------------------------------------- Destructor
Club::~Club() {

}

//----------------------------------------------------------------- methods of Club
void Club::CreerJoueur(){
	std::string nom, prenom, ville, dateContrat, dateEntree; 
	int dureeContrat;
	float taille, poids, montant; 
	bool autonome(false);
	std::cout << "*******************CREATION D'UN JOUEUR*******************" << std::endl
	<< "//		Nom : "; std::cin >> nom;
	std::cout << std::endl <<  "//		Prenom : "; std::cin >> prenom;
	std::cout << std::endl << "//		Taille : "; std::cin >> taille;
	std::cout << std::endl << "//		Poids : "; std::cin >> poids;
	std::cout << std::endl << "//		Ville de Naissance : "; std::cin >> ville;
	std::cout << std::endl << "//		Autonome(Oui = 1/Non = 0) : "; std::cin >> autonome;

	if (autonome) {
		//Joueur_Autonome New(nom, prenom, taille, poids, ville);
		//effectif.push_back(New);
		//Constructor Contract
		//contratsdEngagement.push_back(NewContrat);
		
	}
	else {
		//Joueur_NonAutonome New(nom, prenom, taille, poids, ville);
		//effectif.push_back(New);
		//Constructor Contract
		//contratsdEngagement.push_back(NewContrat);
	}
}		

void Club::ModifierJoueur(){

}

void Club::SupprimerJoueur(std::string firstname, std::string lastname){
	for (int i = 0; i < effectif.size(); i++){
		if (effectif[i]->getFirstName() == firstname && effectif[i]->getLastName() == lastname){
			std::cout << "Le joueur " << effectif[i]->getFirstName() << " " << effectif[i]->getLastName() << " a été supprimé.";
			delete effectif[i];
			effectif.erase(effectif.begin()+i);
		}
	}
}

void Club::AfficherEffectif(){
	std::cout << "Liste des joueurs du club : /n";
	for (int i = 0; i < effectif.size(); i++){
		std::cout << effectif[i]->getFirstName() << " " << effectif[i]->getLastName() << ", ";
	}
}

void Club::AfficherCalendrier(){

}

void Club::TransfertJoueur(){

}

void Club::AfficherMontantTransferts(Date dateDonnee){
	std::cout << "Les montants des transferts du " << dateDonnee.To_String() << " :/n";
	for (int i = 0; i < contratsdEngagement.size(); i++){
		if(contratsdEngagement[i]->getDateDuContrat().Compare(dateDonnee))
			std::cout << "-  " << contratsdEngagement[i]->getReglement().getMontantDuTransfert() << std::endl;
	}
}
