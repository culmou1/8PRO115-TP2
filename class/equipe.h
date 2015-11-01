#ifndef EQUIPE_H
#define EQUIPE_H

#include "club.h"
#include "person.h"

class Equipe {
	
private:
	Club 	*club;
	int 	nbrJoueurs;
	int 	nbrGardiens;
	Joueur 	*capitaine;

public:
    Equipe(Club *team, int players, int goals, Joueur *capt) :
		club(team), nbrJoueurs(players), nbrGardiens(goals), capitaine(capt) {}

    ~Equipe();
    Equipe(const Equipe& other);
    Equipe(Equipe&& other);
    Equipe& operator=(const Equipe& other);
    Equipe& operator=(Equipe&& other);

//----------------------------------------------------------------- methods for club
    Club *getClub(){
    	return club;
    }

    void setClub(Club *team){
    	club = team;
    }

//----------------------------------------------------------------- methods for nbrJoueurs
	int getNbrJoueur(){
		return nbrJoueurs;
	}

	void setNbrJoueur(int nbr){
		nbrJoueurs = nbr;
	}

//----------------------------------------------------------------- methods for nbrGardiens
	int getNbrGardiens(){
		return nbrGardiens;
	}

	void setNbrGardiens(int nbr){
		nbrGardiens = nbr;
	}

//----------------------------------------------------------------- methods for nbrGardiens
	Joueur *getCapitaine(){
		return capitaine;
	}

	void setCapitaine(Joueur *capt){
		capitaine = capt;
	}
};

#endif