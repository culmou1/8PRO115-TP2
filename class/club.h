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


typedef std::vector<Palmares*>	VectorPal; // Une ensemble de vecteur de type Palmares
typedef std::vector<Contrat*> 	VectorCon; // Une ensemble de vecteur de type Contrat
typedef std::vector<Rupture*> 	VectorRup; // Une ensemble de vecteur de type Rupture
typedef std::vector<Person*>  	VectorPrs; // Une ensemble de vecteur de type Person
typedef std::vector<Joueur*>  	VectorJou; // Une ensemble de vecteur de type Joueur


// Classe Club
class Club {

private:
	std::string				_nom;
	std::string 			_histoireDuClub;
	std::string 			_couleurDuClub;
	std::string 			_adresseDuClub;
	std::string 			_villeDuClub;
	Date 					_anneeDeCreation;
	VectorJou				_effectif;
	VectorPal			 	_unPalmares;
	VectorPrs			 	_staffTechnique;
	VectorCon 				_contratsdEngagement;
	VectorRup 				_rupturesDeContrats;

public:
	Club();
    Club(std::string name, std::string history, std::string color, std::string address, std::string town, std::string year);
    ~Club();
    Club(const Club& other);
    Club& operator=(Club&& other);

//----------------------------------------------------------------- methods for _histoireDuClub
	std::string getNomDuClub();
	void setNomDuClub(std::string name);

//----------------------------------------------------------------- methods for _histoireDuClub
	std::string getHistoireDuClub();
	void setHistoireDuClub(std::string history);

//----------------------------------------------------------------- methods for _couleurDuClub
	std::string getCouleurDuClub();
	void setCouleurDuClub(std::string color);

//----------------------------------------------------------------- methods for _anneeDeCreation
	Date getAnneeDeCreation();
	void setAnneeDeCreation (Date year);

//----------------------------------------------------------------- methods for _effectif
	VectorJou* getEffectif();
	void addEffectif(Joueur *someone);
	void deleteEffectif(Joueur* someone);
	void setEffectif(VectorJou players);
	Joueur* rechercherJoueur(std::string joueur);

//----------------------------------------------------------------- methods for _unPalmares
	VectorPal* getUnPalmares();
	void addUnPalmares(Palmares *trophy);
	void setUnPalmares(VectorPal trophies);
	int getNumberOfTitre();

//----------------------------------------------------------------- methods for _villeDuClub
	std::string getVilleDuClub();
	void setVilleDuClub(std::string town);

//----------------------------------------------------------------- methods for _villeDuClub
	std::string getAdresseDuClub();
	void setAdresseDuClub(std::string address);

//----------------------------------------------------------------- methods for _staffTechnique
	VectorPrs* getStaffTechnique();
	void addStaffTechnique(Person *someone);
	void deleteStaffTechnique(Person *someone);
	void setStaffTechnique(VectorPrs staff);

//----------------------------------------------------------------- methods for _contratsdEngagement
	VectorCon* getContratdEngagement();
	void addContratdEngagement(Contrat *contrats);
	void deleteContratdEngagement(Contrat *contrats);
	void afficherContratEngagement();
	Contrat* rechercherContratdEngagement(Joueur *joueur);

//----------------------------------------------------------------- methods for _rupturesDeContrats
	VectorRup* getRupturesDeContrats();
	void addRuptureDeContrats(Rupture *ruptures);
	void deleteRupturesDeContrats(Rupture *ruptures);
	void setRupturesDeContrats(VectorRup ruptures);
	Rupture* rechercherRupturesDeContrats(Joueur* joueur);

//----------------------------------------------------------------- methods of Club
	void CreerEntraineur();

};

#endif
