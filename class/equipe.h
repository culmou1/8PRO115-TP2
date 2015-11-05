#ifndef EQUIPE_H
#define EQUIPE_H

#include "person.h"
#include "club.h"

class Equipe {

private:
	Club* 	_club;
	int 	_nbrJoueurs;
	int 	_nbrGardiens;
	Joueur 	*_capitaine;

public:
    Equipe(Club *team, int players, int goals, Joueur *capt) :
		_club(team), _nbrJoueurs(players), _nbrGardiens(goals), _capitaine(capt) {}

	~Equipe() {delete _club; delete _capitaine;}

	Equipe(const Equipe& other) : 
		_club(other._club), _nbrJoueurs(other._nbrJoueurs), _nbrGardiens(other._nbrGardiens), _capitaine(other._capitaine) {}

    Equipe& operator=(Equipe&& other) {
		_club=other._club; _nbrJoueurs=other._nbrJoueurs; _nbrGardiens=other._nbrGardiens; _capitaine=other._capitaine;
		return *this;
	}

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
