#ifndef RESULTAT_H
#define RESULTAT_H

class Resultat {
	friend class Periode;
	friend class Match;

private:
	int _butsLocaux;
	int _butsVisiteurs;

public:
	Resultat(int home, int visitor) : _butsLocaux(home), _butsVisiteurs(visitor) {}

    ~Resultat();
    Resultat(const Resultat& other);
    Resultat(Resultat&& other);
    Resultat& operator=(const Resultat& other);
    Resultat& operator=(Resultat&& other);

//----------------------------------------------------------------- methods for butsLocaux
	int getButsLocaux() {
		return _butsLocaux;
	}

	void setButsLocaux(int goals) {
		_butsLocaux = goals;
	}

//----------------------------------------------------------------- methods for butsVisiteurs
	int getButsVisiteurs() {
		return _butsVisiteurs;
	}

	void setButsVisiteurs(int goals) {
		_butsVisiteurs = goals;
	}

};

#endif