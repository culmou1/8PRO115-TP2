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
/**
* @params Construteur par defaut
*/ 
	Equipe() {}
/**
* @params Construteur
*/ 
    Equipe(Club *team, int players, int goals, Joueur *capt) :
		_club(team), _nbrJoueurs(players), _nbrGardiens(goals), _capitaine(capt) {}
/**
* @params Destructeur
*/ 
	~Equipe() {}
/**
* @params Construteur de recopie
*/ 
	Equipe(const Equipe& other) :
		_club(other._club), _nbrJoueurs(other._nbrJoueurs), _nbrGardiens(other._nbrGardiens), _capitaine(other._capitaine) {}
/**
* @params Operateur d'affectation
*/ 
    Equipe& operator=(Equipe&& other) {
		_club=other._club; _nbrJoueurs=other._nbrJoueurs; _nbrGardiens=other._nbrGardiens; _capitaine=other._capitaine;
		return *this;
	}

//---------------------------------------------------------------- methods for club
/**
* @params Retourne le Club
*/ 
    Club *getClub(){
    	return _club;
    }
/**
* @params Modifie le Club
*/ 
    void setClub(Club *team){
    	_club = team;
    }

//---------------------------------------------------------------- methods for nbrJoueurs
/**
* @params Retourne le nombre de Joueur
*/ 
	int getNbrJoueur(){
		return _nbrJoueurs;
	}
/**
* @params Modifie le nombre de Joueur
*/ 
	void setNbrJoueur(int nbr){
		_nbrJoueurs = nbr;
	}

//---------------------------------------------------------------- methods for nbrGardiens
/**
* @params Retourne le nombre de gardiens
*/ 
	int getNbrGardiens(){
		return _nbrGardiens;
	}
/**
* @params Modifie le nombre de gardiens
*/ 
	void setNbrGardiens(int nbr){
		_nbrGardiens = nbr;
	}

//---------------------------------------------------------------- methods for capitaine
/**
* @params Retourne le captaine d'equipe
*/ 
	Joueur *getCapitaine(){
		return _capitaine;
	}
/**
* @params Modifie le captaine d'equipe
*/ 
	void setCapitaine(Joueur *capt){
		_capitaine = capt;
	}
};

#endif
