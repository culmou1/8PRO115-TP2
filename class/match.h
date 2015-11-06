#ifndef MATCH_H
#define MATCH_H

#include <vector>
#include <string>
#include "resultat.h"

class Equipe;
class Periode;

typedef std::vector<Periode*> 	VectorPer;

class Match {

private:
	Equipe		*_locaux;
	Equipe 		*_visiteurs;
	VectorPer	_periodesJouees;
	Resultat  	_resultatFinal;

public:
	Match(Equipe *home, Equipe *visitor);
	Match(Equipe *home, Equipe *visitor, int butL, int butV);

    ~Match();
    Match(const Match& other);
    Match& operator=(Match&& other);

//----------------------------------------------------------------- methods for Locaux
    Equipe *getLocaux(){
    	return _locaux;
    }

//----------------------------------------------------------------- methods for Visiteurs
    Equipe *getVisiteurs(){
    	return _visiteurs;
    }

    void setVisiteurs(Equipe *stranger){
    	_visiteurs = stranger;
    }

//----------------------------------------------------------------- methods for periodesJouees
	void getPeriodes(VectorPer &half) {
		for (unsigned int i = 0; i < _periodesJouees.size(); i++) {
			half[i] = _periodesJouees[i];
		}
	}

	void setPeriodes(VectorPer half) {
		_periodesJouees.clear();
		for (unsigned int i = 0; i < half.size(); i++) {
			_periodesJouees.push_back(half[i]);
		}
	}

//----------------------------------------------------------------- methods for resultat
	Resultat getResultat(){
		return _resultatFinal;
	}

	void setResulat(int home, int visitor);

//----------------------------------------------------------------- methods of Match
	std::string getCouleurClub(Equipe* team);
	void obtenirResulatFinal();

};

#endif
