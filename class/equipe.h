#ifndef EQUIPE_H
#define EQUIPE_H

#include "club.h"
#include "person.h"

class Equipe {

private:
	Club* 	_club;
	int 	_nbrJoueurs;
	int 	_nbrGardiens;
	Joueur 	*_capitaine;

public:
    Equipe(Club *team, int players, int goals, Joueur *capt) :
		_club(team), _nbrJoueurs(players), _nbrGardiens(goals), _capitaine(capt) {}

    ~Equipe();
    Equipe(const Equipe& other);
    Equipe(Equipe&& other);
    Equipe& operator=(const Equipe& other);
    Equipe& operator=(Equipe&& other);

//----------------------------------------------------------------- methods for club
    Club *getClub(){
    	return _club;
    }

    void setClub(Club *team){
    	_club = team;
    }

//----------------------------------------------------------------- methods for nbrJoueurs
	int getNbrJoueur(){
		return _nbrJoueurs;
	}

	void setNbrJoueur(int nbr){
		_nbrJoueurs = nbr;
	}

//----------------------------------------------------------------- methods for nbrGardiens
	int getNbrGardiens(){
		return _nbrGardiens;
	}

	void setNbrGardiens(int nbr){
		_nbrGardiens = nbr;
	}

//----------------------------------------------------------------- methods for nbrGardiens
	Joueur *getCapitaine(){
		return _capitaine;
	}

	void setCapitaine(Joueur *capt){
		_capitaine = capt;
	}
};

#endif
