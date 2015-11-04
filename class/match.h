#ifndef MATCH_H
#define MATCH_H


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
	void getPeriodes(VectorPer &half) {
		for (int i = 0; i < _periodesJouees.size(); i++) {
			half[i] = _periodesJouees[i];
		}
	}

	void setPeriodes(VectorPer half) {
		_periodesJouees.clear();
		for (int i = 0; i < half.size(); i++) {
			_periodesJouees.push_back(half[i]);
		}
	}

//----------------------------------------------------------------- methods for resultat
	Resultat getResultat(){
		return _resultatFinal;
	}

	void setResulat(int home, int visitor) {
		_resultatFinal.butsLocaux = home;
		_resultatFinal.butsVisiteurs= visitor;
	}

//----------------------------------------------------------------- methods of Match
	void obtenirResulatFinal() {
		for (int i = 0; i <_periodesJouees.size(); i++) {
			_resultatFinal.butsLocaux += _periodesJouees[i]->resultat.butsLocaux;
			_resultatFinal.butsVisiteurs += _periodesJouees[i]->resultat.butsVisiteurs;
		}
	}
//----------------------------------------------------------------- methods of Teams

	Equipe getLocalAndAway(){
		return

	}

};

#endif
