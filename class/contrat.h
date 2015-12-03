#ifndef CONTRAT_H
#define CONTRAT_H

#include "utils.h"
#include "reglement.h"

class Joueur;
class Club;

/**
  * Classe Contrat qui instancie le contrat d'un joueur
  *@authors Gillian Chaville & Daehli Nadeau-Otis
  */
class Contrat {

private :
	Joueur 		*_joueurContractant;
 	Club 		*_clubContractant;
 	Club 		*_clubLibere;
 	int 		_dureeContrat;
 	Date 		_datedEntree;
 	Date 		_dateDuContrat;
	Reglement	_reglement;

public :
/**
* @params Construteur par defaut
*/ 
	Contrat();
/**
* @params Construteur avec club libere
*/ 
	Contrat(Joueur *joueurContractant,Club *clubContractant,Club *clubLibere, int duree,
			std::string datedEntree,std::string dateDuContrat,double montant, std::string droit);
/**
* @params Construteur sans club libere
*/ 
	Contrat(Joueur *joueurContractant,Club *clubContractant, int duree,
				std::string datedEntree,std::string dateDuContrat,double montant, std::string droit);
/**
* @params Destructeur
*/ 
	~Contrat();
/**
* @params Construteur de recopie
*/ 
    Contrat(const Contrat& other);
/**
* @params Operateur d'affectation
*/ 
    Contrat& operator=(Contrat&& other);

//---------------------------------------------------------------- methods of joueurContractant
/**
  * @params Retourne le joueur contractant
  */
    Joueur *getJoueurContractant();
/**
  * @params Modifie le joueur contractant
  */
    void setJoueurContractant(Joueur *newbie);

//---------------------------------------------------------------- methods of clubContractant
/**
  * @params Retourne le club contractant
  */
    Club *getClubContractant();
/**
  * @params Modifie le club contractant
  */
    void setClubContractant(Club *new_club);

//---------------------------------------------------------------- methods of clubLibere
/**
  * @params Retourne le club libere
  */
    Club *getClubLibere();
/**
  * @params Modifie le club libere
  */
    void setClubLibere(Club *old_club);

//---------------------------------------------------------------- methods of dureeContrat
/**
  * @params Retourne la duree du contrat
  */
    int getDureeContrat();
/**
  * @params Modifie la duree du contrat
  */
    void setDureeContrat(int duree);

//---------------------------------------------------------------- methods of datedEntree
/**
  * @params Retourne la date d'entree
  */
    Date getDatedEntree();
/**
  * @params Modifie la date d'entree
  */
    void setDatedEntree(Date entree);

//---------------------------------------------------------------- methods of dateDuContrat
/**
  * @params Retourne la date du contrat
  */
    Date getDateDuContrat();
/**
  * @params Modifie la date du contrat
  */
    void setDateDuContrat(int d_day, int m_month,int y_year);

//---------------------------------------------------------------- methods of reglement
/**
  * @params Retourne le reglement
  */
	Reglement* getReglement();
/**
  * @params Modifie le reglement
  */
	void setReglement(double montantT, std::string droit);

//---------------------------------------------------------------- methods of Contrat
/**
  * @params Retourne la date d'echeance du contrat
  */
	Date getDatedEcheance();
};



#endif
