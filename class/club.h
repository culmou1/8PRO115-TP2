#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include "utils.h"
#include "person.h"
class Palmares;
class Contract;
class Rupture;
class Person;
class Club;
typedef std::vector<Palmares*>	VectorPal; // Une ensemble de vecteur de type Palmares
typedef std::vector<Contract*> 	VectorCon; // Une ensemble de vecteur de type Contract
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
	VectorCon 				contractsdEngagement;
	VectorRup 				rupturesDeContracts;
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
		for (int i = 0; i < effectif.size(); i++) {
			players[i] = effectif[i];
			std::cout << players[i].getLastName << " "<< players[i].getFirstName << std::endl;
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

//----------------------------------------------------------------- methods for ContractsdEngagement
	VectorCon getContractsdEngagement(VectorCon &contracts) {
		return contractsdEngagement;
	}

	void addContractsdEngagement(Contract *contracts) {
		contractsdEngagement.push_back(contracts);
	}

	void deleteContractsdEngagement(Contract *contracts){
		for (unsigned int i = 0; i< contractsdEngagement.size();i++){
			if (contractsdEngagement[i]== contracts){
				delete contractsdEngagement[i];
				contractsdEngagement.erase(contractsdEngagement.begin()+i);
			}
		}
	}
	// transfert Joueur envoyer le contract

	bool lookUpContractdEngagement(Joueur *joueur, Contract* contract){
		for(unsigned int i = 0; i < contractsdEngagement.size();i++){
			if (contractsdEngagement[i]->getJoueurContractant() == joueur){
				contract = contractsdEngagement[i];
			}
		}
	}

//----------------------------------------------------------------- methods for RupturesDeContracts
	VectorRup getRupturesDeContracts() {
		return rupturesDeContracts;
	}

	void addRupturesDeContracts(Rupture *ruptures) {
		rupturesDeContracts.push_back(ruptures);
	}

	void deleteRupturesDeContracts(Rupture *ruptures){
		for (unsigned int i = 0; i< rupturesDeContracts.size();i++){
			if (rupturesDeContracts[i]== ruptures){
				delete rupturesDeContracts[i];
				rupturesDeContracts.erase(rupturesDeContracts.begin()+i);
			}
		}
	}

	void setRupturesDeContracts(VectorRup ruptures) {
		rupturesDeContracts.clear();
		for (int i = 0; i < ruptures.size(); i++) {
			rupturesDeContracts.push_back(ruptures[i]);
		}
	}

//----------------------------------------------------------------- methods for getAllClub

	Club getAllClub(){
		for (int i = 0; i < allClub.size();i++){
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

	void getEntraineurLePlusTitre(){
		int nbTitre = 0;
		Entraineur *entraineurLePlusTitre;
		for (int i = 0; i < allClub.size();i++){
			for(int j = 0; j < allClub[i]->staffTechnique.size();i++){
				if(allClub[i]->staffTechnique[j]->getNumberOfTitre() > nbTitre){
					nbTitre = allClub[i]->staffTechnique[j]->getNumberOfTitre();
					entraineurLePlusTitre = allClub[i]->staffTechnique[j]
				}
			}
		}
		std::cout << "Voici l\'entraineur: " << entraineurLePlusTitre->getFirstName() << "il a gagner " << nbTitre << " titre" <<std::endl;
	}

//-----------------------------------------------------------------

	void getAllContractEngagement(){
		for (int i = 0; i < contractsdEngagement.size();i++){
			std::cout << "Voici la Position du Club: " << i << " - " << contractsdEngagement[i] << std::endl;
		}
	}

//-----------------------------------------------------------------

	void montantEncaisseDepuisUneDate(std::string date){

		float sommeTotal;

		for (int i = 0;i< contractsdEngagement.size();i++){
			if (contractsdEngagement[i]->lookForEcheance(date)){
				sommeTotal += contractsdEngagement->getSeuilTransfert();
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
