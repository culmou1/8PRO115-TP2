#ifndef MATCH_H
#define MATCH_H

#include "equipe.h"
#include "periode.h"

typedef std::vector<Periode*> 	VectorPer;

class Match {

private:
	Equipe		*locaux;
	Equipe 		*visiteurs;
	VectorPer	periodesJouees;
	Resultat  	resultatFinal;

public:
	Match(Equipe *home, Equipe *visitor, Resultat score) :
		locaux(home), visiteurs(visitor), resultatFinal(score) {}

    ~Match();
    Match(const Match& other);
    Match(Match&& other);
    Match& operator=(const Match& other);
    Match& operator=(Match&& other);

//----------------------------------------------------------------- methods for Locaux
    Equipe *getLocaux(){
    	return locaux;
    }

    void setLocaux(Equipe *home){
    	locaux = home;
    }

//----------------------------------------------------------------- methods for Locaux
    Equipe *getVisiteurs(){
    	return visiteurs;
    }

    void setVisiteurs(Equipe *stranger){
    	visiteurs = stranger;
    }

//----------------------------------------------------------------- methods for periodesJouees
	void getPeriodes(VectorPer &half) {
		for (int i = 0; i < periodesJouees.size(); i++) {
			half[i] = periodesJouees[i];
		}
	}

	void setPeriodes(VectorPer half) {
		periodesJouees.clear();
		for (int i = 0; i < half.size(); i++) {
			periodesJouees.push_back(half[i]);
		}
	}

//----------------------------------------------------------------- methods for resultat
	Resultat getResultat(){
		return resultatFinal;
	}

	void setResulat(int home, int visitor) {
		resultatFinal.butsLocaux = home;
		resultatFinal.butsVisiteurs= visitor;
	}

//----------------------------------------------------------------- methods of Match
	void ObtenirResulatFinal() {
		for (int i = 0; i <periodesJouees.size(); i++) {
			resultatFinal.butsLocaux += periodesJouees[i]->resultat.butsLocaux;
			resultatFinal.butsVisiteurs += periodesJouees[i]->resultat.butsVisiteurs;
		}
	}
};

#endif
