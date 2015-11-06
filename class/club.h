#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include <string>
#include "utils.h"
class Contrat;
class Palmares;
class Rupture;
class Joueur;
class Person;
class Calendrier;
class Ligue;


typedef std::vector<Palmares*>	VectorPal; // Une ensemble de vecteur de type Palmares
typedef std::vector<Contrat*> 	VectorCon; // Une ensemble de vecteur de type Contrat
typedef std::vector<Rupture*> 	VectorRup; // Une ensemble de vecteur de type Rupture
typedef std::vector<Person*>  	VectorPrs; // Une ensemble de vecteur de type Person
typedef std::vector<Joueur*>  	VectorJou; // Une ensemble de vecteur de type Joueur


// Classe Club
class Club {

private:
	std::string 			histoireDuClub;
	std::string 			couleurDuClub;
	std::string 			adresseDuClub;
	std::string 			villeDuClub;
	Date 					anneeDeCreation;
	VectorJou				effectif;
	VectorPal			 	unPalmares;
	VectorPrs			 	staffTechnique;
	VectorCon 				contratsdEngagement;
	VectorRup 				rupturesDeContrats;
	Calendrier*				_calendrier;
	Ligue*					_ligue;


public:
    Club(std::string history, std::string color, std::string address, std::string town, std::string year, Ligue* league);

    ~Club();
    Club(const Club& other);
    Club& operator=(Club&& other);

//----------------------------------------------------------------- methods for HistoireDuClub
	std::string getHistoireDuClub();
	void setHistoireDuClub(std::string history);

//----------------------------------------------------------------- methods for CouleurDuClub
	std::string getCouleurDuClub();
	void setCouleurDuClub(std::string color);

//----------------------------------------------------------------- methods for AnneeDeCreation
	Date getAnneeDeCreation();
	void setAnneeDeCreation (Date year);

//----------------------------------------------------------------- methods for Effectif

	VectorJou getEffectif();
	void addEffectif(Joueur *someone);
	void setEffectif(VectorJou players);
	Joueur* rechercherJoueur(std::string joueur);

//----------------------------------------------------------------- methods for unPalmares
	VectorPal getUnPalmares();

	void addUnPalmares(Palmares *trophy);

	void setUnPalmares(VectorPal trophies);
	
	int getNumberOfTitre();

//----------------------------------------------------------------- methods for VilleDuClub
	std::string getVilleDuClub();
	void setVilleDuClub(std::string town);

//----------------------------------------------------------------- methods for VilleDuClub
	std::string getAdresseDuClub();
	void setAdresseDuClub(std::string address);

//----------------------------------------------------------------- methods for StaffTechnique
	VectorPrs getStaffTechnique() {
		return staffTechnique;
	}

	void addStaffTechnique(Person *someone);

	void deleteStaffTechnique(Person *someone);

	void setStaffTechnique(VectorPrs staff);

//----------------------------------------------------------------- methods for ContratsdEngagement
	VectorCon getContratsdEngagement(VectorCon &contrats) {
		return contratsdEngagement;
	}

	void addContratdEngagement(Contrat *contrats);

	void deleteContratdEngagement(Contrat *contrats);

	void afficherContratEngagement();

	Contrat* rechercherContratdEngagement(Joueur *joueur);

//----------------------------------------------------------------- methods for RupturesDeContrats
	VectorRup getRupturesDeContrats() {
		return rupturesDeContrats;
	}

	void addRuptureDeContrats(Rupture *ruptures);

	void deleteRupturesDeContrats(Rupture *ruptures);

	void setRupturesDeContrats(VectorRup ruptures);

	Rupture* rechercherRupturesDeContrats(Joueur* joueur);

//----------------------------------------------------------------- methods for Montant
	void montantEncaisseDepuisUneDate(std::string date);


//----------------------------------------------------------------- methods for calendrier
	Calendrier* getCalendrier() {
		return _calendrier;
	}

	void setCalendrier(Calendrier* schedul) {
		_calendrier = schedul;
	}
//----------------------------------------------------------------- methods for ligue
	Ligue* getLigue() {
		return _ligue;
	}

//----------------------------------------------------------------- methods of Club
    void CreerJoueur();
    void ModifierJoueur(std::string joueur);
    void SupprimerJoueur(std::string name);
    void AfficherEffectif();

	void CreerEntraineur();
	void AfficherStaff();

	void TransfertJoueur(std::string joueur, Club* club);
	void AfficherMontantTransferts(std::string date);

};

#endif
