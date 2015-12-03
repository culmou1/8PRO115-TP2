#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include <string>
#include "utils.h"

class Contrat;
class Palmares;
class Rupture;
class Joueur;
class PersonStaff;


typedef std::vector<Palmares*>		VectorPal; // Une ensemble de vecteur de type Palmares
typedef std::vector<Contrat*> 		VectorCon; // Une ensemble de vecteur de type Contrat
typedef std::vector<Rupture*> 		VectorRup; // Une ensemble de vecteur de type Rupture
typedef std::vector<PersonStaff*>  	VectorPrs; // Une ensemble de vecteur de type Person
typedef std::vector<Joueur*>  		VectorJou; // Une ensemble de vecteur de type Joueur


/**
 *  Le club est une entite qui reprensente les caracteristiques qu une equipe
 *	doit avoir
 * 	Par Exemple: Un nom, Un histoire, Une Couleur, etc...
 */
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
/**
* @params Constructeur par defaut
*/
	Club();
/**
* @params Constructeur
*/
    Club(std::string name, std::string history, std::string color, std::string address, std::string town, std::string year);
/**
* @params Destructeur
*/
    ~Club();
/**
* @params Constructeur de recopie
*/
    Club(const Club& other);
/**
* @params Operateur d'affectation
*/
    Club& operator=(Club&& other);

//---------------------------------------------------------------- methods for _histoireDuClub
/**
* @params Retourne le nom du club
*/
	std::string getNomDuClub();
/**
* @params Modifie le nom du club
*/
	void setNomDuClub(std::string name);

//---------------------------------------------------------------- methods for _histoireDuClub
/**
* @params Retourne le histoire du club
*/
	std::string getHistoireDuClub();
/**
* @params Modifie le hisoire du club
*/
	void setHistoireDuClub(std::string history);

//---------------------------------------------------------------- methods for _couleurDuClub
/**
* @params Retourne le couleur du club
*/
	std::string getCouleurDuClub();
/**
* @params Modifie le couleur du club
*/
	void setCouleurDuClub(std::string color);

//---------------------------------------------------------------- methods for _anneeDeCreation
/**
* @params Retourne l'annee de creation du club
*/
	Date getAnneeDeCreation();
/**
* @params Modifie l'annee de creation du club
*/
	void setAnneeDeCreation (Date year);

//---------------------------------------------------------------- methods for _effectif
/**
* @params Retourne l'effectif du club
*/
	VectorJou* getEffectif();
/**
* @params Ajoute un Joueur a l'effectif du club
*/
	void addEffectif(Joueur *someone);
/**
* @params Supprime un Joueur de l'effectif du club
*/
	void deleteEffectif(Joueur* someone);
/**
* @params Modifie l'effectif du club
*/
	void setEffectif(VectorJou players);
/**
* @params Recherche un Joueur dans l'effectif du club
*/
	Joueur* rechercherJoueur(std::string joueur);

//---------------------------------------------------------------- methods for _unPalmares
/**
* @params Retourne le palmares du club
*/
	VectorPal* getUnPalmares();
/**
* @params Ajoute un Palmares aux Palmares du club
*/
	void addUnPalmares(Palmares *trophy);
/**
* @params Modifie le palmares du club
*/
	void setUnPalmares(VectorPal trophies);
/**
* @params Retourne le nombre de Palmares du club
*/
	int getNumberOfTitre();

//---------------------------------------------------------------- methods for _villeDuClub
/**
* @params Retourne la ville du club
*/
	std::string getVilleDuClub();
/**
* @params Modifie la ville du club
*/
	void setVilleDuClub(std::string town);

//---------------------------------------------------------------- methods for _adresseDuClub
/**
* @params Retourne l'adresse du club
*/
	std::string getAdresseDuClub();
/**
* @params Modifie l'adresse du club
*/
	void setAdresseDuClub(std::string address);

//---------------------------------------------------------------- methods for _staffTechnique
/**
* @params Retourne le staff du club
*/
	VectorPrs* getStaffTechnique();
/**
* @params Ajoute une PersonStaff au staff du club
*/
	void addStaffTechnique(PersonStaff *someone);
/**
* @params Supprime une PersonStaff au staff du club
*/
	void deleteStaffTechnique(PersonStaff *someone);
/**
* @params Modifie le staff du club
*/
	void setStaffTechnique(VectorPrs staff);

//---------------------------------------------------------------- methods for _contratsdEngagement
/**
* @params Retourne les contrats d'engagements du club
*/
	VectorCon* getContratdEngagement();
/**
* @params Ajoute un Contrat aux contrats d'engagements du club
*/
	void addContratdEngagement(Contrat *contrats);
/**
* @params Supprime un Contrat aux contrats d'engagements du club
*/
	void deleteContratdEngagement(Contrat *contrats);
/**
* @params Affiche les contrats d'engagements du club
*/
	void afficherContratEngagement();
/**
* @params Recherche un Contrat dans les contrats d'engagements du club
*/
	Contrat* rechercherContratdEngagement(Joueur *joueur);

//---------------------------------------------------------------- methods for _rupturesDeContrats
/**
* @params Retourne les ruptures de contrat du club
*/
	VectorRup* getRupturesDeContrats();
/**
* @params Ajoute une Rupture aux ruptures de contrat du club
*/
	void addRuptureDeContrats(Rupture *ruptures);
/**
* @params Supprime une Rupture aux ruptures de contrat du club
*/
	void deleteRupturesDeContrats(Rupture *ruptures);
/**
* @params Modifie les ruptures de contrat du club
*/
	void setRupturesDeContrats(VectorRup ruptures);
/**
* @params Recherche une Rupture dans les ruptures de contrat du club
*/
	Rupture* rechercherRupturesDeContrats(Joueur* joueur);

//---------------------------------------------------------------- methods of Club
/**
* @params Creer un Entraineur et l'ajoute au staff du club
*/
	void CreerEntraineur();

};

#endif
