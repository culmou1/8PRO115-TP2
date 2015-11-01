#ifndef RUPTURE_H
#define RUPTURE_H

#include "club.h"

class Rupture {

private:
	Joueur 			*joueurRelaxant;
	Club 			*clubContractant;
	Raison	        raisonsDuDepart;
	float 			penalite;

public:
	Rupture(Joueur *player, Club *new_club, Raison why, float money) : 
		joueurRelaxant(player), clubContractant(new_club), raisonsDuDepart(why), penalite(money) {}

    ~Rupture();
    Rupture(const Rupture& other);
    Rupture(Rupture&& other);
    Rupture& operator=(const Rupture& other);
    Rupture& operator=(Rupture&& other);

//----------------------------------------------------------------- methods for joueurRelaxant
    Joueur *getJoueurRelaxant() {
    	return joueurRelaxant;
    }

    void setJoueurRelaxant(Joueur *newbie) {
    	joueurRelaxant = newbie;
    } 

//----------------------------------------------------------------- methods for clubContractant
    Club *getClubContractant() {
    	return clubContractant;
    }

    void setClubContractant(Club *new_club) {
    	clubContractant = new_club;
    }
//----------------------------------------------------------------- methods for raisonsDuDepart
    Raison getRaisonsDuDepart() {
    	return raisonsDuDepart;
    }

    void setRaisonsDuDepart(Raison raisons) {
    	raisonsDuDepart = raisons;
    }

//----------------------------------------------------------------- methods for penalite
    float getPenalite() {
    	return penalite;
    }

    void setPenalite(float cost)  {
    	penalite = cost;
    }

};

#endif