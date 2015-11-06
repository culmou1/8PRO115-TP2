#include "club.h"
#include "person.h"
#include "contrat.h"
#include "calendrier.h"
#include "ligue.h"
#include "rencontre.h"
#include "rupture.h"
#include "palmares.h"
#include "reglement.h"
#include <iostream>
#include <string>

//----------------------------------------------------------------- Constructor
Club::Club(std::string history, std::string color, std::string address, std::string town, std::string year, Ligue* league) {
	histoireDuClub = history; couleurDuClub = color; adresseDuClub = address;
	villeDuClub = town; anneeDeCreation = To_Date(year);

	//Ajout du club a la ligue
	_ligue = league; _calendrier = new Calendrier();
}

//----------------------------------------------------------------- Destructor
Club::~Club() {
	std::cout << "CARACTERISTIQUES DU CLUB " << couleurDuClub << " : " << std::endl;
	std::cout << "-		HISTOIRE : " << histoireDuClub << std::endl;
	std::cout << "-		ANNEE DE CREATION : "<< anneeDeCreation.To_String() << std::endl;
	std::cout << "-		ADDRESSE : "<< adresseDuClub << ", " << villeDuClub << std::endl;
	std::cout << "-		NOMBRE DE TITRE(S) GAGNE(S) : "<< unPalmares.size() << std::endl;
	std::cout << "-		TAILLE DE L\'EFFECTIF : "<< effectif.size() << std::endl;
	std::cout << "-		TAILLE DU STAFF TECHNIQUE : "<< staffTechnique.size() << std::endl;

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
}

//----------------------------------------------------------------- CreerJoueur
void Club::CreerJoueur(){
	std::string nom, prenom, ville, dateDuContrat, datedEntree, droit;
	int dureeDuContrat, age;
	double taille, poids, montant;
	bool autonome(false);

	std::cout << std::endl << "*******************CREATION D'UN JOUEUR*******************" << std::endl
	<< "//		NOM : "; std::cin >> nom;
	std::cout << std::endl <<  "//		PRENOM : "; std::cin >> prenom;
	std::cout << std::endl <<  "//		AGE : "; std::cin >> age;
	std::cout << std::endl << "//		TAILLE : "; std::cin >> taille;
	std::cout << std::endl << "//		POIDS : "; std::cin >> poids;
	std::cout << std::endl << "//		VILLE DE NAISSANCE : "; std::cin >> ville;
	std::cout << std::endl << "//		AUTONOME(OUI = 1/NON = 0) : "; std::cin >> autonome;

	std::cout << std::endl <<  "*******************LE NOUVEAU CONTRAT DU JOUEUR*******************" << std::endl;
	std::cout << std::endl << "//		DUREE DU CONTRAT : "; std::cin >> dureeDuContrat;
	std::cout << std::endl << "//		DATE D\'ENTREE DU JOUEUR : "; std::cin >> datedEntree;
	std::cout << std::endl << "//		DATE DU CONTRAT : "; std::cin >> dateDuContrat;
	std::cout << std::endl << "//		PRIX DU TRANSFERT : "; std::cin >> montant;
	std::cout << std::endl << "//		DROITS DU JOUEUR : "; std::cin >> droit;

	Joueur* newbie;
	if (autonome) {//S'il est autonome
		//Cree le nouveau joueur et l'ajoute a leffectif du club
		 newbie = new Joueur_Autonome(prenom, nom, age, taille, poids, ville);
		addEffectif(newbie);
		//Cree son nouveau contrat et l'ajoute aux contratsdEngagement du club
		Contrat* newContrat = new Contrat(newbie, this, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
		addContratdEngagement(newContrat);
	}
	else {
		//Cree le nouveau joueur et l'ajoute a leffectif du club
		newbie = new Joueur_NonAutonome(prenom, nom, age, taille, poids, ville);
		addEffectif(newbie);
		//Cree son nouveau contrat et l'ajoute aux contratsdEngagement du club
		Contrat* newContrat = new Contrat(newbie, this, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
		addContratdEngagement(newContrat);
	}
	std::cout << "Le joueur " << newbie->obtenirNP() << " a ete cree et ajoute a l'effectif du club " << couleurDuClub << "." << std::endl;
}

//----------------------------------------------------------------- ModifierJoueur
void Club::ModifierJoueur(std::string joueur){

	Joueur* aModifier = rechercherJoueur(joueur);

	int age;
	double taille, poids;
	bool autonome(false);

	if(aModifier != NULL) {
		std::cout << std::endl << "*******************MODIFICATION D'UN JOUEUR*******************" << std::endl;
		std::cout << std::endl <<  "//		AGE : "; std::cin >> age;
		std::cout << std::endl << "//		TAILLE : "; std::cin >> taille;
		std::cout << std::endl << "//		POIDS : "; std::cin >> poids;

		aModifier->setAge(age); aModifier->setTaille(taille); aModifier->setPoids(poids);
		std::cout << "Le joueur " << joueur << " a ete modifie." << std::endl;
	}
	else
		std::cerr << "Le joueur " << joueur << " n\'existe pas." << std::endl;

}

//----------------------------------------------------------------- SupprimerJoueur
void Club::SupprimerJoueur(std::string name){

	std::cout << std::endl << "*******************SUPPRESSION D'UN JOUEUR*******************" << std::endl;
	Person* aSupprimer = rechercherJoueur(name);
	if(aSupprimer != NULL) {
		//Itere dans l'effectif du club
		for (unsigned int i = 0; i < effectif.size(); i++)
		{
			if (aSupprimer == effectif[i])
			{//Si le joueur est trouve
				delete effectif[i];
				effectif.erase(effectif.begin()+i);
			}
		}
		std::cout << "Le joueur " << name << " a ete supprime de l'effectif du club " << couleurDuClub << "." << std::endl;
	}
	else
		std::cerr << "Le joueur " << name << " n\'existe pas." << std::endl;
}

//----------------------------------------------------------------- CreerJoueur
void Club::CreerEntraineur(){
	std::string nom, prenom, placeGrade;
	int age;

	std::cout << std::endl << "*******************CREATION D'UN ENTRAINEUR*******************" << std::endl
	<< "//		NOM : "; std::cin >> nom;
	std::cout << std::endl <<  "//		PRENOM : "; std::cin >> prenom;
	std::cout << std::endl <<  "//		AGE : "; std::cin >> age;
	std::cout << std::endl << "//		LIEU D\'OBTENTION DU GRADE : "; std::cin >> placeGrade;

	Person* trainer = new Entraineur(prenom, nom, age, placeGrade);
	addStaffTechnique(trainer);
	std::cout << "L\'entraineur " << trainer->obtenirNP() << " a ete cree et ajoute au staff du club " << couleurDuClub << "." << std::endl;
}

//----------------------------------------------------------------- AfficherEffectif
void Club::AfficherEffectif(){
	std::cout << std::endl << "*******************LISTE DES JOUEURS DU CLUB******************* " << std::endl;
	//Itere dans l'effectif du club
	for (unsigned int i = 0; i < effectif.size(); i++)
	{
		std::cout << effectif[i]->obtenirNP() << ", ";
	}
}

//----------------------------------------------------------------- AfficherStaff
void Club::AfficherStaff(){
	std::cout << std::endl << "*******************LISTE DU STAFF DU CLUB******************* " << std::endl;
	//Itere dans l'effectif du club
	for (unsigned int i = 0; i < staffTechnique.size(); i++)
	{
		std::cerr << staffTechnique[i]->obtenirNP() << ", ";
	}
}

//----------------------------------------------------------------- TransfertJoueur
void Club::TransfertJoueur(std::string joueur, Club* club){

		Joueur* aTransferer = rechercherJoueur(joueur);
		if (aTransferer != NULL) {
			Contrat* newContrat = rechercherContratdEngagement(aTransferer);
			int dureeDuContrat;
			std::string datedEntree, dateDuContrat, droit;
			double montant;

			std::cout << std::endl << "*******************TRANSFERT DU JOUEUR*******************" << std::endl;
			std::cout << std::endl << "//		DUREE DU CONTRAT : "; std::cin >> dureeDuContrat;
			std::cout << std::endl << "//		DATE D\'ENTREE DU JOUEUR : "; std::cin >> datedEntree;
			std::cout << std::endl << "//		DATE DU CONTRAT : "; std::cin >> dateDuContrat;
			std::cout << std::endl << "//		PRIX DU TRANSFERT : "; std::cin >> montant;
			std::cout << std::endl << "//		DROITS DU JOUEUR : "; std::cin >> droit;

			if(newContrat->lookForEcheance(dateDuContrat) || rechercherRupturesDeContrats(aTransferer) != NULL) {
				//if (montant <= newContrat->getReglement().getSeuilDeTransert()) {
					//Cree le nouveau contrat du joueur puis l'ajoute aux contratsdEngagement du nouveau club
					newContrat = new Contrat(aTransferer, club, this, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
					club->addContratdEngagement(newContrat);

					//ajoute le joueur a l'effectif du nouveau club
					club->addEffectif(aTransferer);

					//supprime le joueur de l'effectif du club libere
					SupprimerJoueur(joueur);
				//}
					std::cout << "Le joueur " << joueur << " a ete transfere du club " << couleurDuClub
										<< " au club " << club->getCouleurDuClub() << "." << std::endl;
			}
			else
				std::cout << "Creation du nouveau contrat impossible (voir date d'echeance, existence de rupture ou seuil de transfert)." << std::endl;
		}
		else
			std::cerr << "Le joueur " << joueur << " n\'existe pas." << std::endl;
}

//----------------------------------------------------------------- AfficherMontantTransferts
void Club::AfficherMontantTransferts(std::string date){
	std::cout << std::endl << "******************* MONTANTS ENCAISSES DEPUIS LE " << date << " ******************* " << std::endl;
	//Convertit en Date
	Date dateDonnee = To_Date(date);
	std::cout << std::endl << "Les montants des transferts par le club " << couleurDuClub << " sont :" << std::endl;

	//Itere dans les contratsdEngagement
	for (unsigned int i = 0; i < contratsdEngagement.size(); i++)
	{
		//Si la date correspond alors il affiche
		if(contratsdEngagement[i]->getDateDuContrat() <= dateDonnee)
			std::cout << "-  " << contratsdEngagement[i]->getReglement().getMontantDuTransfert() << std::endl;
	}
}

//----------------------------------------------------------------- methods for HistoireDuClub
std::string Club::getHistoireDuClub() {
	return histoireDuClub;
}

void Club::setHistoireDuClub(std::string history) {
	histoireDuClub = history;
}


//----------------------------------------------------------------- methods for CouleurDuClub
std::string Club::getCouleurDuClub() {
	return couleurDuClub;
}

void Club::setCouleurDuClub(std::string color) {
	couleurDuClub = color;
}

//----------------------------------------------------------------- methods for AnneeDeCreation
Date Club::getAnneeDeCreation() {
	return anneeDeCreation;
}

void Club::setAnneeDeCreation (Date year) {
	anneeDeCreation = year;
}

//----------------------------------------------------------------- methods for Effectif

VectorJou Club::getEffectif() {
	return effectif;
}

void Club::addEffectif(Joueur *someone) {
	effectif.push_back(someone);
}

void Club::setEffectif(VectorJou players) {
	effectif.clear();
	for (unsigned int i = 0; i < players.size(); i++) {
		effectif.push_back(players[i]);
	}
}

Joueur* Club::rechercherJoueur(std::string joueur){
	for(unsigned int i = 0; i < effectif.size();i++){
		if (effectif[i]->obtenirNP() == joueur)
			return effectif[i];
	}
	return NULL;
}

//----------------------------------------------------------------- methods for unPalmares
VectorPal Club::getUnPalmares() {
	return unPalmares;
}

void Club::addUnPalmares(Palmares *trophy) {
	unPalmares.push_back(trophy);
}

void Club::setUnPalmares(VectorPal trophies) {
	unPalmares.clear();
	for (unsigned int i = 0; i < trophies.size(); i++) {
		unPalmares.push_back(trophies[i]);
	}
}

int Club::getNumberOfTitre() {
	return (int)unPalmares.size();
}

//----------------------------------------------------------------- methods for VilleDuClub
std::string Club::getVilleDuClub() {
	return villeDuClub;
}

void Club::setVilleDuClub(std::string town) {
	villeDuClub = town;
}

//----------------------------------------------------------------- methods for VilleDuClub
std::string Club::getAdresseDuClub() {
	return adresseDuClub;
}

void Club::setAdresseDuClub(std::string address) {
	adresseDuClub = address;
}

//----------------------------------------------------------------- methods for StaffTechnique
void Club::addStaffTechnique(Person *someone) {
	staffTechnique.push_back(someone);
}

void Club::deleteStaffTechnique(Person *someone){
	for (unsigned int i = 0; i< staffTechnique.size();i++){
		if (staffTechnique[i]== someone){
			delete staffTechnique[i];
			staffTechnique.erase(staffTechnique.begin()+i);
		}
	}
}

void Club::setStaffTechnique(VectorPrs staff) {
	staffTechnique.clear();
	for (unsigned int i = 0; i < staff.size(); i++) {
		staffTechnique.push_back(staff[i]);
	}
}

//----------------------------------------------------------------- methods for ContratsdEngagement
void Club::addContratdEngagement(Contrat *contrats) {
	contratsdEngagement.push_back(contrats);
}

void Club::deleteContratdEngagement(Contrat *contrats){
	for (unsigned int i = 0; i< contratsdEngagement.size();i++){
		if (contratsdEngagement[i]== contrats){
			delete contratsdEngagement[i];
			contratsdEngagement.erase(contratsdEngagement.begin()+i);
		}
	}
}

void Club::afficherContratEngagement(){
	std::cout << std::endl << "*******************LISTE DES CONTRATS DU CLUB******************* " << std::endl;
	for (unsigned int i = 0; i < contratsdEngagement.size();i++){
		std::cout << "Voici la Position du Contrat: " << i << " - " << contratsdEngagement[i]->getJoueurContractant()->obtenirNP()
			<< " to " << contratsdEngagement[i]->getClubContractant()->getCouleurDuClub() << std::endl;
	}
}

Contrat* Club::rechercherContratdEngagement(Joueur *joueur){
	for(unsigned int i = 0; i < contratsdEngagement.size();i++){
		if (contratsdEngagement[i]->getJoueurContractant() == joueur)
			return contratsdEngagement[i];
	}
	return NULL;
}

//----------------------------------------------------------------- methods for RupturesDeContrats
void Club::addRuptureDeContrats(Rupture *ruptures) {
	rupturesDeContrats.push_back(ruptures);
}

void Club::deleteRupturesDeContrats(Rupture *ruptures){
	for (unsigned int i = 0; i< rupturesDeContrats.size();i++){
		if (rupturesDeContrats[i]== ruptures){
			delete rupturesDeContrats[i];
			rupturesDeContrats.erase(rupturesDeContrats.begin()+i);
		}
	}
}

void Club::setRupturesDeContrats(VectorRup ruptures) {
	rupturesDeContrats.clear();
	for (unsigned int i = 0; i < ruptures.size(); i++) {
		rupturesDeContrats.push_back(ruptures[i]);
	}
}

Rupture* Club::rechercherRupturesDeContrats(Joueur *joueur){
	for(unsigned int i = 0; i < rupturesDeContrats.size();i++){
		if (rupturesDeContrats[i]->getJoueurRelaxant() == joueur)
			return rupturesDeContrats[i];
	}
	return NULL;
}

//-----------------------------------------------------------------montantEncaisseDepuisUneDate

void Club::montantEncaisseDepuisUneDate(std::string date){
	double sommeTotal = 0;

	std::cout << std::endl << "******************* MONTANT ENCAISSE DEPUIS LE " << date << " ******************* " << std::endl;
	for (unsigned int i = 0;i< contratsdEngagement.size();i++){
		if (contratsdEngagement[i]->getDateDuContrat() <= To_Date(date)){
			sommeTotal += contratsdEngagement[i]->getReglement().getMontantDuTransfert();
		}
	}
	std::cout << "Le montant encaisse par le club " << couleurDuClub << " est de : " << sommeTotal << "$." << std::endl;
}
