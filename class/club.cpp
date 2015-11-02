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
	std::string nom, prenom, ville, dateContrat, dateEntree, droit;
	int dureeContrat, age;
	float taille, poids, montant;
	bool autonome(false);
	std::cout << "*******************CREATION D'UN JOUEUR*******************" << std::endl
	<< "//		NOM : "; std::cin >> nom;
	std::cout << std::endl <<  "//		PRENOM : "; std::cin >> prenom;
	std::cout << std::endl <<  "//		AGE : "; std::cin >> age;
	std::cout << std::endl << "//		TAILLE : "; std::cin >> taille;
	std::cout << std::endl << "//		POIDS : "; std::cin >> poids;
	std::cout << std::endl << "//		VILLE DE NAISSANCE : "; std::cin >> ville;
	std::cout << std::endl << "//		AUTONOME(OUI = 1/NON = 0) : "; std::cin >> autonome;

	if (autonome) {
		 Joueur* newbie = new Joueur_Autonome(prenom, nom, age, taille, poids, ville);
		effectif.push_back(newbie);
		Contrat* newContrat = new Contrat(newbie, this, dureeContrat, dateEntree, dateContrat, montant, droit);
		contratsdEngagement.push_back(newContrat);
	}
	else {
		Joueur_NonAutonome *newbie = new Joueur_NonAutonome(prenom, nom, age, taille, poids, ville);
		effectif.push_back(newbie);
		Contrat* newContrat = new Contrat(newbie, this, dureeContrat, dateEntree, dateContrat, montant, droit);
		contratsdEngagement.push_back(newContrat);
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

void Club::TransfertJoueur(Contrat* leContrat){

}

void Club::AfficherMontantTransferts(Date dateDonnee){
	std::cout << "Les montants des transferts du " << dateDonnee.To_String() << " :/n";
	for (int i = 0; i < contratsdEngagement.size(); i++){
		if(contratsdEngagement[i]->getDateDuContrat().Compare(dateDonnee))
			std::cout << "-  " << contratsdEngagement[i]->getReglement()->getMontantDuTransfert() << std::endl;
	}
}
