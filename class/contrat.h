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
	Contrat();
	Contrat(Joueur *joueurContractant,Club *clubContractant,Club *clubLibere, int duree,
			std::string datedEntree,std::string dateDuContrat,double montant, std::string droit);
	Contrat(Joueur *joueurContractant,Club *clubContractant, int duree,
				std::string datedEntree,std::string dateDuContrat,double montant, std::string droit);
	~Contrat();
    Contrat(const Contrat& other);
    Contrat& operator=(Contrat&& other);

/**
  *  @params methods for joueurContractant
  */
    Joueur *getJoueurContractant();
    void setJoueurContractant(Joueur *newbie);

/**
  *  @params methods for clubContractant
  */
    Club *getClubContractant();

    void setClubContractant(Club *new_club);

/**
  *  @params methods for clubLibere
  */
    Club *getClubLibere();

    void setClubLibere(Club *old_club);

/**
  *  @params methods for dureeContrat
  */
    int getDureeContrat();
    void setDureeContrat(int duree);

/**
  *  @params methods for datedEntree
  */
    Date getDatedEntree();

    void setDatedEntree(Date entree);

/**
  *  @params methods for dateDuContrat
  */
    Date getDateDuContrat();
    void setDateDuContrat(int d_day, int m_month,int y_year);

/**
  * @params methods of reglement
  */
	Reglement* getReglement();
	void setReglement(double montantT, std::string droit);

	Date getDatedEcheance();
};



#endif
