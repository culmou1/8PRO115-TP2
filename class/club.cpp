#include "club.h"
#include "iostream"

//----------------------------------------------------------------- Constructor
Club::Club(std::string history, std::string color, std::string address, std::string town, std::string year) {
	histoireDuClub = history; couleurDuClub = color; adresseDuClub = address;
	villeDuClub = town; anneeDeCreation = To_Date(year);
	allClub.push_back(this); // Faire la liste the Tout le Club
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

void Club::TransfertJoueur(Joueur* joueur){
	Contrat *leContrat; int contratID;

	//Retrouver le contrat du joueur
	for (unsigned int i=0; i < contratsdEngagement.size(); i++) {
		if(contratsdEngagement[i]->getJoueurContratant() == joueur) {
			leContrat = contratsdEngagement[i];
			contratID = i;
		}
	}

	if (leContrat != NULL) { //Si le joueur avait déjà un contrat
		int dureeDuContrat;
		std::string datedEntree, dateDuContrat, choisirClub, droit;
		float montant;

		std::cout << "*******************LE NOUVEAU CONTRAT DU JOUEUR*******************" << std::endl;
		std::cout << std::endl << "//		DUREE DU CONTRAT : "; std::cin >> dureeDuContrat;
		std::cout << std::endl << "//		DATE D\'ENTREE DU JOUEUR : "; std::cin >> datedEntree;
		std::cout << std::endl << "//		DATE DU CONTRAT : "; std::cin >> dateDuContrat;
		std::cout << std::endl << "//		PRIX DU TRANSFERT : "; std::cin >> montant;
		std::cout << std::endl << "//		DROITS DU JOUEUR : "; std::cin >> droit;
		std::cout << std::endl << "//		CHOISIR NOUVELLE EQUIPE : ";  std::cin >> choisirClub;

		// Creer nouveau contrat puis l'ajoute a contratsdEngagement du nouveau club
		Club *newClub;
		//newClub = Ligue->getClub(choisirClub(couleur));
		Contrat* newContrat = new Contrat(joueur, newClub, this, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
		newClub->contratsdEngagement.push_back(newContrat);

		//ajoute le joueur a effectif du nouveau club
		newClub->effectif.push_back(joueur);

		// Supprime le contrat du vector du club libéré
		delete contratsdEngagement[contratID];
		contratsdEngagement.erase(contratsdEngagement.begin() + contratID);

		//supprime le joueur de leffectif du club libere
		for (unsigned int i=0; i < effectif.size(); i++) {
			if(effectif[i] == joueur) {
				delete effectif[i];
				effectif.erase(effectif.begin() + i);
			}
		}
	}
	else
		std::cout << "Le contrat du joueur " << joueur->obtenirNP() << " n'existe pas." << std::endl;
}

void Club::AfficherMontantTransferts(Date dateDonnee){
	std::cout << "Les montants des transferts du " << dateDonnee.To_String() << " :/n";
	for (int i = 0; i < contratsdEngagement.size(); i++){
		if(contratsdEngagement[i]->getDateDuContrat().Compare(dateDonnee))
			std::cout << "-  " << contratsdEngagement[i]->getReglement()->getMontantDuTransfert() << std::endl;
	}
}
