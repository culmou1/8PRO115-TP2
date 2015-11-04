#ifndef MATCH_H
#define MATCH_H

#include "equipe.h"
#include "periode.h"

typedef std::vector<Periode*> 	VectorPer;

class Match {

private:
	Equipe		*_locaux;
	Equipe 		*_visiteurs;
	VectorPer	_periodesJouees;
	Resultat  	_resultatFinal;

public:
	Match(Equipe *home, Equipe *visitor, Resultat score) :
		_locaux(home), _visiteurs(visitor), _resultatFinal(score) {}

    ~Match();
    Match(const Match& other);
    Match(Match&& other);
    Match& operator=(const Match& other);
    Match& operator=(Match&& other);

//----------------------------------------------------------------- methods for Locaux
    Equipe *getLocaux(){
    	return _locaux;
    }

//----------------------------------------------------------------- methods for Locaux
    Equipe *getVisiteurs(){
    	return _visiteurs;
    }

    void setVisiteurs(Equipe *stranger){
    	_visiteurs = stranger;
    }

//----------------------------------------------------------------- methods for periodesJouees
	VectorPer getPeriodes() {
		return _periodesJouees;
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

	void setResulat(int home, int visitor) {
		_resultatFinal.setButsLocaux(home);
		_resultatFinal.setButsVisiteurs(visitor);
	}

//----------------------------------------------------------------- methods of Match
	void obtenirResulatFinal() {
		int home, visitor;
		for (unsigned int i = 0; i <_periodesJouees.size(); i++) {
			home += _periodesJouees[i]->getScore().getButsLocaux();
			visitor += _periodesJouees[i]->getScore().getButsVisiteurs();
		}
		setResulat(home, visitor);
	}
//----------------------------------------------------------------- methods of Teams

	Equipe getLocalAndAway(){

	}

};

#endif
