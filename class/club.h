#ifdef CLUB_H
#define CLUB_H

#include string
#include vector
#include "person.h"
#include "palmares.h"
#include "contract.h"

typedef std::vector<Contract> 	VectorCon;
typedef std::vector<Rupture> 	VectorRup;
typedef std::vector <Person*>  	VectorPrs;
// Classe Club
class Club {

private:
	std::string 			histoireDuClub;
	std::string 			couleurDuClub;
	Date 					anneeDeCreation;
	VectorPrs				*effectif;
	VectorPal			 	*unPalmares;
	std::string 			villeDuClub;
	VectorPrs			 	*staffTechnique;
	VectorCon 				*contratsdEngagement;
	VectorRup 				*rupturesDeContrats;
	Calendrier 				calendrier;

public:
    Club();

    ~Club();
    Club(const Club& other) = default;
    Club(Club&& other) = default;
    Club& operator=(const Club& other) = default;
    Club& operator=(Club&& other) = default;

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
		for (int i = 0; i < effectif->size(); i++) {
			players[i] = effectif[i];
		}
	}

	void setEffectif(VectorPrs *players) {
		effectif->clear();
		for (int i = 0; i < players->size(); i++) {
			effectif->push_back(players[i]);
		}
	}

//----------------------------------------------------------------- methods for unPalmares
	void getUnPalmares(VectorPal &trophies) {
		for (int i = 0; i < unPalmares->size(); i++) {
			trophies[i] = unPalmares[i];
		}
	}

	void setUnPalmares(VectorPal *trophies) {
		unPalmares->clear();
		for (int i = 0; i < trophies->size(); i++) {
			unPalmares->push_back(trophies[i]);
		}
	}

//----------------------------------------------------------------- methods for VilleDuClub
	std::string getVilleDuClub() {
		return villeDuClub;
	}

	void setVilleDuClub(std::string town) {
		villeDuClub = town;
	}

//----------------------------------------------------------------- methods for StaffTechnique
	void getStaffTechnique(VectorPrs &staff) {
		for (int i = 0; i < staffTechnique->size(); i++) {
			staff[i] = staffTechnique[i];
		}
	}

	void setStaffTechnique(VectorPrs *staff) {
		staffTechnique->clear();
		for (int i = 0; i < staff->size(); i++) {
			staffTechnique->push_back(staff[i]);
		}
	}

//----------------------------------------------------------------- methods for ContratsdEngagement
	void getContratsdEngagement(VectorCon &contrats) {
		for (int i = 0; i < contratsdEngagement->size(); i++) {
			contrats[i] = contratsdEngagement[i];
		}
	}

	void setContratsdEngagement(VectorCon *contrats) {
		contratsdEngagement->clear();
		for (int i = 0; i < contrats->size(); i++) {
			contratsdEngagement->push_back(contrats[i]);
		}
	}

//----------------------------------------------------------------- methods for RupturesDeContrats
	void getRupturesDeContrats(VectorRup &ruptures) {
		for (int i = 0; i < rupturesDeContrats.size(); i++) {
			ruptures[i] = rupturesDeContrats[i];
		}
	}

	void setRupturesDeContrats(VectorRup *ruptures) {
		rupturesDeContrats->clear();
		for (int i = 0; i < ruptures->size(); i++) {
			rupturesDeContrats->push_back(ruptures[i]);
		}
	}

//----------------------------------------------------------------- methods for Calendrier
	Calendrier getCalendrier() {
		return calendrier;
	}

	void setCalendrier(Calendrier schedul) {
		calendrier = schedul;
	}

//----------------------------------------------------------------- methods of Club
    void CreerJoueur();
    void ModifierJoueur();
    void SupprimerJoueur();
    void AfficherJoueurs();
    void TransfertJoueur();

};

#endif
