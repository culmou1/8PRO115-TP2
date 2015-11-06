#ifndef CONTRAT_H
#define CONTRAT_H

#include "utils.h"
#include "reglement.h"

class Joueur;
class Club;

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
	Contrat(Joueur *joueurContractant,Club *clubContractant,Club *clubLibere, int duree,
			std::string datedEntree,std::string dateDuContrat,double montant, std::string droit);

	// Constructeur lorsque le Joueur n'a pas d'ancienne Équipe. Nous Donnons un Pointeur Null au Club libere.
	// Pas Besoin d'envoyer un Pointeur NUll. Il va le faire automatiquement
	Contrat(Joueur *joueurContractant,Club *clubContractant, int duree,
				std::string datedEntree,std::string dateDuContrat,double montant, std::string droit);

	~Contrat();
    Contrat(const Contrat& other);
    Contrat& operator=(Contrat&& other);
//----------------------------------------------------------------- methods for joueurContractant
    Joueur *getJoueurContractant() {
    	return _joueurContractant;
    }

    void setJoueurContractant(Joueur *newbie) {
    	_joueurContractant = newbie;
    }

//----------------------------------------------------------------- methods for clubContractant
    Club *getClubContractant() {
    	return _clubContractant;
    }

    void setClubContractant(Club *new_club) {
    	_clubContractant = new_club;
    }

//----------------------------------------------------------------- methods for clubLibere
    Club *getClubLibere() {
    	return _clubLibere;
    }

    void setClubLibere(Club *old_club) {
    	_clubLibere = old_club;
    }

//----------------------------------------------------------------- methods for dureeContrat
    int getDureeContrat() {
    	return _dureeContrat;
    }

    void setDureeContrat(int duree) {
    	_dureeContrat = duree;
    }

//----------------------------------------------------------------- methods for datedEntree
    Date getDatedEntree() {
    	return _datedEntree;
    }

    void setDatedEntree(Date entree) {
    	_datedEntree = entree;
    }

//----------------------------------------------------------------- methods for dateDuContrat
    Date getDateDuContrat() {
    	return _dateDuContrat;
    }

    void setDateDuContrat(int d_day, int m_month,int y_year);

//----------------------------------------------------------------- methods of reglement
	Reglement getReglement() {
		return _reglement;
	}

	void setReglement(double montantT, std::string droit);
<<<<<<< HEAD


};

//----------------------------------------------------------------- methods of Date

=======

//----------------------------------------------------------------- methods for Contrat 
	//Calcule la date d'echeance du Contrat
	Date getDatedEncheance() {
		Date echeance; echeance.Create(_dateDuContrat.tm_day, _dateDuContrat.tm_month, _dateDuContrat.tm_year+_dureeContrat);
		return echeance;
	}

	//Compare si la date donnee est plus recente que la date d'echeance
	bool lookForEcheance(std::string date) {
		return getDatedEncheance() <= To_Date(date); //Vrai si cest ok 
	}
};

>>>>>>> b44a4983423945be435aeb0c8cda677f7ca4f82e



#endif
