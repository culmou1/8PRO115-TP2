#ifndef EQUIPE_H
#define EQUIPE_H

#include "person.h"
#include "club.h"

/**
 *  Un equipe est une entite qui fait parti d un club et qui contient des joueurs,
 *	des gardiens et un capitaine
 */
class Equipe {

private:
	Club* 	_club;
	int 	_nbrJoueurs;
	int 	_nbrGardiens;
	Joueur 	*_capitaine;

public:
	Equipe() {}
    Equipe(Club *team, int players, int goals, Joueur *capt) :
		_club(team), _nbrJoueurs(players), _nbrGardiens(goals), _capitaine(capt) {}
	~Equipe() {}
	Equipe(const Equipe& other) :
		_club(other._club), _nbrJoueurs(other._nbrJoueurs), _nbrGardiens(other._nbrGardiens), _capitaine(other._capitaine) {}
    Equipe& operator=(Equipe&& other) {
		_club=other._club; _nbrJoueurs=other._nbrJoueurs; _nbrGardiens=other._nbrGardiens; _capitaine=other._capitaine;
		return *this;
	}

/**
  * @params methods of club
  */
    Club *getClub(){
    	return _club;
    }

    void setClub(Club *team){
    	_club = team;
    }

/**
  * @params methods of nbrJoueurs
  */
	int getNbrJoueur(){
		return _nbrJoueurs;
	}

	void setNbrJoueur(int nbr){
		_nbrJoueurs = nbr;
	}

/**
  * @params methods of nbrGardiens
  */
	int getNbrGardiens(){
		return _nbrGardiens;
	}

	void setNbrGardiens(int nbr){
		_nbrGardiens = nbr;
	}

/**
  * @params methods of captaine
  */
	Joueur *getCapitaine(){
		return _capitaine;
	}

	void setCapitaine(Joueur *capt){
		_capitaine = capt;
	}
};

#endif
