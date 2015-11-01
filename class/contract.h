#ifndef CONTRAT_H
#define CONTRAT_H

#include "club.h"
#include "utils.h"
#include "reglement.h"

class Contract {

private:
	Joueur 	    *joueurContractant;
 	Club 	    *clubContractant;
 	Club 	    *clubLibere;
 	int 	    dureeContrat;
 	Date 	    datedEntree;
 	Date 	    dateDuContrat;
 	Reglement	reglement;

public:
	Contract(Joueur *player, Club *new_club, Club *old_club, int time, std::string enter, std::string day, Reglement rule) :
		joueurContractant(player), clubContractant(new_club), clubLibere(old_club), dureeContrat(time), 
		datedEntree(To_Date(enter)), dateDuContrat(To_Date(day)), reglement(rule) {}

    ~Contract();
    Contract(const Contract& other);
    Contract(Contract&& other);
    Contract& operator=(const Contract& other);
    Contract& operator=(Contract&& other);

//----------------------------------------------------------------- methods for joueurContractant
    Joueur *getJoueurContractant() {
    	return joueurContractant;
    }

    void setJoueurContractant(Joueur *newbie) {
    	joueurContractant = newbie;
    }

//----------------------------------------------------------------- methods for clubContractant
    Club *getClubContractant() {
    	return clubContractant;
    }

    void setClubContractant(Club *new_club) {
    	clubContractant = new_club;
    }

//----------------------------------------------------------------- methods for clubLibere
    Club *getClubLibere() {
    	return clubLibere;
    }

    void setClubLibere(Club *old_club) {
    	clubLibere = old_club;
    }

//----------------------------------------------------------------- methods for dureeContrat
    int getDureeContrat() {
    	return dureeContrat;
    }

    void setDureeContrat(int duree) {
    	dureeContrat = duree;
    }

//----------------------------------------------------------------- methods for datedEntree
    Date getDatedEntree() {
    	return datedEntree;
    }

    void setDatedEntree(int day, int month, int year){
        datedEntree.tm_day = day;
        datedEntree.tm_month = month;
        datedEntree.tm_year = year;
    }

//----------------------------------------------------------------- methods for dateDuContrat
    Date getDateDuContrat() {
    	return dateDuContrat;
    }

    void setDateDuContrat(int day, int month, int year){
        dateDuContrat.tm_day = day;
        dateDuContrat.tm_month = month;
        dateDuContrat.tm_year = year;
    }

//----------------------------------------------------------------- methods for reglement
	Reglement getReglement(){
		return reglement;
	}


	void setReglement(Reglement other){
		reglement = other;
	}

private:
	Joueur 			joueurRelaxant;
	Club 			clubContractant;
	std::string 	raisonsDuDepart;
	float 			penalite;

public:
	Rupture();

    ~Rupture();
    Rupture(const Rupture& other) = default;
    Rupture(Rupture&& other) = default;
    Rupture& operator=(const Rupture& other) = default;
    Rupture& operator=(Rupture&& other) = default;

//----------------------------------------------------------------- methods for joueurRelaxant
    Joueur getJoueurRelaxant() {
    	return joueurRelaxant;
    }

    void setJoueurRelaxant(Joueur newbie) {
    	joueurRelaxant = newbie;
    }

//----------------------------------------------------------------- methods for clubContractant
    Club getClubContractant() {
    	return clubContractant;
    }

    void setClubContractant(Club new_club) {
    	clubContractant = new_club;
    }
//----------------------------------------------------------------- methods for raisonsDuDepart
    std::string getRaisonsDuDepart() {
    	return raisonsDuDepart;
    }

    void setRaisonsDuDepart(std::string raisons) {
    	raisonsDuDepart = raisons;
    }

//----------------------------------------------------------------- methods for penalite
    float getPenalite() {
    	return penalite;
    }

    void setPenalite(float cost)  {
    	penalite = cost;
    }

//----------------------------------------------------------------- methods of Contract
    void updateSeuilTransfert();
    
};


#endif
