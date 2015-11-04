#include "club.h"
#include <iostream>

//----------------------------------------------------------------- Constructor
Club::Club(std::string history, std::string color, std::string address, std::string town, std::string year) {
	histoireDuClub = history; couleurDuClub = color; adresseDuClub = address;
	villeDuClub = town; anneeDeCreation = To_Date(year);

	//Ajout du club a la ligue
	_ligue->AjouterClub(this); 
}

//----------------------------------------------------------------- Destructor
Club::~Club() {

	//Suppression de l'effectif
	for (unsigned int i=0; i <effectif.size(); i++) {
		delete effectif[i];
	}
	effectif.clear();

	//Suppression du staffTechnique
	for (unsigned int i=0; i <staffTechnique.size(); i++) {
		delete staffTechnique[i];
	}
	staffTechnique.clear();

	//Suppression du Palmares
	for (unsigned int i=0; i <unPalmares.size(); i++) {
		delete unPalmares[i];
	}
	unPalmares.clear();

	//Suppression des contratsdEngagement
	for (unsigned int i=0; i <contratsdEngagement.size(); i++) {
		delete contratsdEngagement[i];
	}
	contratsdEngagement.clear();

	//Suppression des rupturesDeContrats
	for (unsigned int i=0; i <rupturesDeContrats.size(); i++) {
		delete rupturesDeContrats[i];
	}
	rupturesDeContrats.clear();

	//Suppression du Calendrier
	delete _calendrier;
}

//----------------------------------------------------------------- CreerJoueur
void Club::CreerJoueur(){
	std::string nom, prenom, ville, dateDuContrat, datedEntree, droit;
	int dureeDuContrat, age;
	double taille, poids, montant;
	bool autonome(false);

	std::cout << "*******************CREATION D'UN JOUEUR*******************" << std::endl
	<< "//		NOM : "; std::cin >> nom;
	std::cout << std::endl <<  "//		PRENOM : "; std::cin >> prenom;
	std::cout << std::endl <<  "//		AGE : "; std::cin >> age;
	std::cout << std::endl << "//		TAILLE : "; std::cin >> taille;
	std::cout << std::endl << "//		POIDS : "; std::cin >> poids;
	std::cout << std::endl << "//		VILLE DE NAISSANCE : "; std::cin >> ville;
	std::cout << std::endl << "//		AUTONOME(OUI = 1/NON = 0) : "; std::cin >> autonome;

	std::cout << "*******************LE NOUVEAU CONTRAT DU JOUEUR*******************" << std::endl;
	std::cout << std::endl << "//		DUREE DU CONTRAT : "; std::cin >> dureeDuContrat;
	std::cout << std::endl << "//		DATE D\'ENTREE DU JOUEUR : "; std::cin >> datedEntree;
	std::cout << std::endl << "//		DATE DU CONTRAT : "; std::cin >> dateDuContrat;
	std::cout << std::endl << "//		PRIX DU TRANSFERT : "; std::cin >> montant;
	std::cout << std::endl << "//		DROITS DU JOUEUR : "; std::cin >> droit;

	if (autonome) {//S'il est autonome 
		//Cree le nouveau joueur et l'ajoute a leffectif du club
		Joueur* newbie = new Joueur_Autonome(prenom, nom, age, taille, poids, ville);
		addEffectif(newbie);
		//Cree son nouveau contrat et l'ajoute aux contratsdEngagement du club
		Contrat* newContrat = new Contrat(newbie, this, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
		addContratdEngagement(newContrat);
	}
	else {
		//Cree le nouveau joueur et l'ajoute a leffectif du club
		Joueur *newbie = new Joueur_NonAutonome(prenom, nom, age, taille, poids, ville);
		addEffectif(newbie);
		//Cree son nouveau contrat et l'ajoute aux contratsdEngagement du club
		Contrat* newContrat = new Contrat(newbie, this, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
		addContratdEngagement(newContrat);
	}
}

//----------------------------------------------------------------- ModifierJoueur
void Club::ModifierJoueur(){

}

//----------------------------------------------------------------- SupprimerJoueur
void Club::SupprimerJoueur(std::string name){
	//Itere dans l'effectif du club
	for (unsigned int i = 0; i < effectif.size(); i++) 
	{
		if (effectif[i]->obtenirNP() == name) 
		{//Si le joueur est trouve
			std::cout << "Le joueur " << effectif[i]->obtenirNP() << " a été supprimé./n";
			delete effectif[i];
			effectif.erase(effectif.begin()+i);
		}
	}
}

//----------------------------------------------------------------- AfficherEffectif
void Club::AfficherEffectif(){
	std::cout << "*******************LISTE DES JOUEURS DU CLUB******************* /n";
	//Itere dans l'effectif du club
	for (unsigned int i = 0; i < effectif.size(); i++)
	{
		std::cout << effectif[i]->obtenirNP() << ", ";
	}
}

//----------------------------------------------------------------- AfficherCalendrier
void Club::AfficherCalendrier(){
	std::cout << "*******************CALENDRIER DES RENCONTRES DU CLUB******************* : /n";
	_calendrier->getAllRencontre(this);

}

//----------------------------------------------------------------- TransfertJoueur
void Club::TransfertJoueur(Joueur* joueur, Club* club){

		int dureeDuContrat;
		std::string datedEntree, dateDuContrat, droit;
		double montant;

		std::cout << "*******************LE NOUVEAU CONTRAT DU JOUEUR*******************" << std::endl;
		std::cout << std::endl << "//		DUREE DU CONTRAT : "; std::cin >> dureeDuContrat;
		std::cout << std::endl << "//		DATE D\'ENTREE DU JOUEUR : "; std::cin >> datedEntree;
		std::cout << std::endl << "//		DATE DU CONTRAT : "; std::cin >> dateDuContrat;
		std::cout << std::endl << "//		PRIX DU TRANSFERT : "; std::cin >> montant;
		std::cout << std::endl << "//		DROITS DU JOUEUR : "; std::cin >> droit;

		//Cree le nouveau contrat du joueur puis l'ajoute aux contratsdEngagement du nouveau club
		Contrat* newContrat = new Contrat(joueur, club, this, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
		club->addContratdEngagement(newContrat);

		//ajoute le joueur a l'effectif du nouveau club
		club->addEffectif(joueur);

		//supprime le joueur de l'effectif du club libere
		SupprimerJoueur(joueur->obtenirNP());
}

//----------------------------------------------------------------- AfficherMontantTransferts
void Club::AfficherMontantTransferts(std::string date){

	//Convertit en Date
	Date dateDonnee = To_Date(date);
	std::cout << "Les montants des transferts du " << dateDonnee.To_String() << " :/n";

	//Itere dans les contratsdEngagement
	for (unsigned int i = 0; i < contratsdEngagement.size(); i++)
	{
		//Si la date correspond alors il affiche
		if(contratsdEngagement[i]->getDateDuContrat().Compare(dateDonnee))
			std::cout << "-  " << contratsdEngagement[i]->getReglement()->getMontantDuTransfert() << std::endl;
	}
}
