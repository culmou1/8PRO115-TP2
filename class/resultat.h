#ifndef RESULTAT_H
#define RESULTAT_H

class Resultat {

private:
	int _butsLocaux;
	int _butsVisiteurs;

public:
	Resultat(int home, int visitor) : _butsLocaux(home), _butsVisiteurs(visitor) {}

	~Resultat() {}

	Resultat(const Resultat& other) : _butsLocaux(other._butsLocaux), _butsVisiteurs(other._butsVisiteurs) {}

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
