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
	_ligue = league;
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
	_calendrier->AfficherRencontre(this);

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

VectorPrs Club::getEffectif() {
	return effectif;
}

void Club::addEffectif(Joueur *someone) {
	effectif.push_back(someone);


}

void Club::setEffectif(VectorPrs players) {
	effectif.clear();
	for (unsigned int i = 0; i < players.size(); i++) {
		effectif.push_back(players[i]);
	}
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
	for (unsigned int i = 0; i < contratsdEngagement.size();i++){
		std::cout << "Voici la Position du Club: " << i << " - " << contratsdEngagement[i] << std::endl;
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

//-----------------------------------------------------------------montantEncaisseDepuisUneDate
/*
void Club::montantEncaisseDepuisUneDate(std::string date){
	double sommeTotal = 0;
	for (unsigned int i = 0;i< contratsdEngagement.size();i++){
		if (contratsdEngagement[i]->getDateDuContrat() <= To_Date(date)){
			sommeTotal += contratsdEngagement[i]->getReglement().getMontantDuTransfert();
		}
	}
	std::cout << "Le montant encaisse depuis le " << date << " est de : " << sommeTotal << "$." << std::endl;
}
*/
