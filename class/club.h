#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include "ligue.h"
#include "person.h"
#include "palmares.h"
#include "contrat.h"
#include "calendrier.h"

#include "rupture.h"
#include "utils.h"

typedef std::vector<Palmares*>	VectorPal; // Une ensemble de vecteur de type Palmares
typedef std::vector<Contrat*> 	VectorCon; // Une ensemble de vecteur de type Contrat
typedef std::vector<Rupture*> 	VectorRup; // Une ensemble de vecteur de type Rupture
typedef std::vector<Person*>  	VectorPrs; // Une ensemble de vecteur de type Person
typedef std::vector<Club*>  	VectorEqui; // Une ensemble de vecteur de type Person


// Classe Club
class Club {
friend class Calendrier;

private:
	std::string 			histoireDuClub;
	std::string 			couleurDuClub;
	std::string 			adresseDuClub;
	std::string 			villeDuClub;
	Date 					anneeDeCreation;
	VectorPrs				effectif;
	VectorPal			 	unPalmares;
	VectorPrs			 	staffTechnique;
	VectorCon 				contratsdEngagement;
	VectorRup 				rupturesDeContrats;
	static VectorEqui		allClub;

public:
    Club(std::string history, std::string color, std::string address, std::string town, std::string year);

    ~Club();
    Club(const Club& other);
    Club(Club&& other);
    Club& operator=(const Club& other);
    Club& operator=(Club&& other);

//----------------------------------------------------------------- methods for HistoireDuClub
	std::string getHistoireDuClub() {
		return histoireDuClub;
	}

	void setHistoireDuClub(std::string history) {
		histoireDuClub = history;
	}

//----------------------------------------------------------------- methods for CouleurDuClub
	std::string getCouleurDuClub() {
		return couleurDuClub;
	}

	void setCouleurDuClub(std::string color) {
		couleurDuClub = color;
	}

//----------------------------------------------------------------- methods for AnneeDeCreation
	Date getAnneeDeCreation() {
		return anneeDeCreation;
	}

	void setAnneeDeCreation (Date year) {
		anneeDeCreation = year;
	}

//----------------------------------------------------------------- methods for Effectif
	void getEffectif(VectorPrs &players) {
		for (int i = 0; i < this.effectif.size(); i++) {
			players[i] = effectif[i];
			std::cout << players[i].getLastName << " "<< players[i].getFirstName << endl;
		}
	}

	void setEffectif(VectorPrs players) {
		effectif.clear();
		for (int i = 0; i < players.size(); i++) {
			effectif.push_back(players[i]);
		}
	}

//----------------------------------------------------------------- methods for unPalmares
	void getUnPalmares(VectorPal &trophies) {
		for (int i = 0; i < unPalmares.size(); i++) {
			trophies[i] = unPalmares[i];
		}
	}

	void setUnPalmares(VectorPal trophies) {
		unPalmares.clear();
		for (int i = 0; i < trophies.size(); i++) {
			unPalmares.push_back(trophies[i]);
		}
	}

//----------------------------------------------------------------- methods for VilleDuClub
	std::string getVilleDuClub() {
		return villeDuClub;
	}

	void setVilleDuClub(std::string town) {
		villeDuClub = town;
	}

//----------------------------------------------------------------- methods for VilleDuClub
	std::string getAdresseDuClub() {
		return adresseDuClub;
	}

	void setAdresseDuClub(std::string address) {
		adresseDuClub = address;
	}

//----------------------------------------------------------------- methods for StaffTechnique
	void getStaffTechnique(VectorPrs &staff) {
		for (int i = 0; i < staffTechnique.size(); i++) {
			staff[i] = staffTechnique[i];
		}
	}

	void setStaffTechnique(VectorPrs staff) {
		staffTechnique.clear();
		for (int i = 0; i < staff.size(); i++) {
			staffTechnique.push_back(staff[i]);
		}
	}

//----------------------------------------------------------------- methods for ContratsdEngagement
	VectorCon getContratsdEngagement(VectorCon &contrats) {
		return contratsdEngagement;
	}

	void addContratsdEngagement(Contrat *contrats) {
		contratsdEngagement.push_back(contrats);
	}

	void deleteContratsdEngagement(Contrat *contrats){
		for (unsigned int i = 0; i< contratsdEngagement.size();i++){
			if (contratsdEngagement[i]== contrats){
				delete contratsdEngagement[i];
				contratsdEngagement.erase(contratsdEngagement.begin()+i);
			}
		}
	}
	// transfert Joueur envoyer le contrat

	bool lookUpContratdEngagement(Joueur *joueur, Contrat* contrat){
		for(unsigned int i = 0; i < contratsdEngagement.size();i++){
			if (contratsdEngagement[i]->getJoueurContractant() == joueur){
				contrat = contratsdEngagement[i];
			}
		}
	}

//----------------------------------------------------------------- methods for RupturesDeContrats
	VectorRup getRupturesDeContrats() {
		return rupturesDeContrats;
	}

	void addRupturesDeContrats(Rupture *ruptures) {
		rupturesDeContrats.push_back(ruptures);
	}

	void deleteRupturesDeContrats(Rupture *ruptures){
		for (unsigned int i = 0; i< rupturesDeContrats.size();i++){
			if (rupturesDeContrats[i]== ruptures){
				delete rupturesDeContrats[i];
				rupturesDeContrats.erase(rupturesDeContrats.begin()+i);
			}
		}
	}

	void setRupturesDeContrats(VectorRup ruptures) {
		rupturesDeContrats.clear();
		for (int i = 0; i < ruptures.size(); i++) {
			rupturesDeContrats.push_back(ruptures[i]);
		}
	}

//----------------------------------------------------------------- methods for getAllClub

	Club getAllClub(){
		for (int i = 0; i < VectorEqui.size();i++){
			std::cout << "Voici la Position du Club: " << i << " - "<< allClub[i]->getCouleurDuClub() << std::endl;
		}
	}

	Club selectClub(int j){
		for(int i = 0; i < allClub.size();i++){
			if (allClub[j]==allClub[i]){
				return *allClub[i];
			}
			else {
				std::cout << "Le Club selectionne n\'existe pas" << std::endl;
			}
		}
	}

//-----------------------------------------------------------------

	void getAllContratEngagement(){
		for (int i = 0; i < contratsdEngagement.size();i++){
			std::cout << "Voici la Position du Club: " << i << " - " << contratsdEngagement[i] << std::endl;
		}
	}

//-----------------------------------------------------------------

	void montantEncaisseDepuisUneDate(std::string date){

		float sommeTotal;

		for (int i = 0;i< contratsdEngagement.size();i++){
			if (contratsdEngagement[i]->lookForEcheance(date)){
				sommeTotal += contratsdEngagement->getSeuilTransfert();
			}

			else continue;
		}
		return sommeTotal;
	}


/*----------------------------------------------------------------- methods for Calendrier
	Calendrier getCalendrier() {
		return calendrier;
	}

	void setCalendrier(Calendrier schedul) {
		calendrier = schedul;
	}*/

//----------------------------------------------------------------- methods of Club
    void CreerJoueur();
    void ModifierJoueur();
    void SupprimerJoueur(std::string name);
    void AfficherEffectif();

    void AfficherCalendrier();

    void TransfertJoueur(Joueur* joueur, Club* club);
	void AfficherMontantTransferts(std::string date);

};

#endif
