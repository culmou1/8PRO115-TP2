#ifdef CONTRAT_H
#define CONTRAT_H

#include "club.h"
#include "utils.h"

class Contract {

private :
	Joueur 	*_joueurContractant;
 	Club 	*_clubContractant;
 	Club 	*_clubLibere;
 	int 	_dureeContrat;
 	Date 	_datedEntree;
 	Date 	_dateDuContrat;
 	float 	_seuilTransfert;

public :
	Contract(Joueur *joueurContractant,Club *clubContractant,Club *clubLibere, int dureeContrat,
				std::string datedEntree,std::string dateDuContrat,float seuilTransfert):
					_joueurContractant(joueurContractant),_clubContractant(clubContractant), _clubLibere(clubLibere),_dureeContrat(duree),
					_datedEntree(To_Date(datedEntree)),_dateDuContrat(To_Date(dateDuContrat)),_seuilTransfert(seuilTransfert){
					}
	// Constructeur lorsque le Joueur n'a pas d'ancienne Équipe. Nous Donnons un Pointeur Null au Club libere.
	// Pas Besoin d'envoyer un Pointeur NUll. Il va le faire automatiquement

	Contract(Joueur *joueurContractant,Club *clubContractant, int dureeContrat,
				std::string datedEntree,std::string dateDuContrat,float seuilTransfert):
					_joueurContractant(joueurContractant),_clubContractant(clubContractant), _clubLibere(NULL),_dureeContrat(duree),
					_datedEntree(To_Date(datedEntree)),_dateDuContrat(To_Date(dateDuContrat)),_seuilTransfert(seuilTransfert){
					}
    ~Contract();
    Contract(const Contract& other) = default;
    Contract(Contract&& other) = default;
    Contract& operator=(const Contract& other) = default;
    Contract& operator=(Contract&& other) = default;

//----------------------------------------------------------------- methods for joueurContractant
    Joueur getJoueurContractant() {
    	return _joueurContractant;
    }

    void setJoueurContractant(Joueur *newbie) {
    	_joueurContractant = newbie;
    }

//----------------------------------------------------------------- methods for clubContractant
    Club getClubContractant() {
    	return _clubContractant;
    }

    void setClubContractant(Club *new_club) {
    	_clubContractant = new_club;
    }

//----------------------------------------------------------------- methods for clubLibere
    Club getClubLibere() {
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

    void setDateDuContrat(int d_day, int m_month,int y_year) {
		_dateDuContrat.tm_day = d_day;
		_dateDuContrat.tm_month = m_month;
		_dateDuContrat.tm_year = m_year;
    }

//----------------------------------------------------------------- methods of Contract
    float getSeuilTransfert(){
		return _seuilTransfert;
	}
    float setSeuilTransfert(float seuilTransfert){
		 _seuilTransfert = seuilTransfert;
	}
};



class Rupture {

private :
	Joueur 			*_joueurRelaxant;
	Club 			*_clubContractant;
	std::string 	_raisonsDuDepart;
	float 			_penalite;

public :
	Rupture(Joueur *joueurRelaxant,Club *clubContractant,std::string raisonsDuDepart,float penalite):
		_joueurRelaxant(joueurRelaxant),_clubContractant(clubContractant)_raisonsDuDepart(raisonsDuDepart),_penalite(penalite){};

    ~Rupture();
    Rupture(const Rupture& other) = default;
    Rupture(Rupture&& other) = default;
    Rupture& operator=(const Rupture& other) = default;
    Rupture& operator=(Rupture&& other) = default;

//----------------------------------------------------------------- methods for _joueurRelaxant
    Joueur getJoueurRelaxant() {
    	return *_joueurRelaxant;
    }

    void setJoueurRelaxant(Joueur *newbie) {
    	_joueurRelaxant = newbie;
    }

//----------------------------------------------------------------- methods for _clubContractant
    Club getClubContractant() {
    	return _clubContractant;
    }

    void setClubContractant(Club *new_club) {
    	_clubContractant = new_club;
    }
//----------------------------------------------------------------- methods for _raisonsDuDepart
    std::string getRaisonsDuDepart() {
    	return _raisonsDuDepart;
    }

    void setRaisonsDuDepart(std::string raisons) {
    	_raisonsDuDepart = raisons;
    }

//----------------------------------------------------------------- methods for _penalite
    float getPenalite() {
    	return _penalite;
    }

    void setPenalite(float cost)  {
    	_penalite = cost;
    }

};


#endif
