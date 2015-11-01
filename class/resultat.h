#ifndef RESULTAT_H
#define RESULTAT_H

class Resultat {
	friend class Periode;
	friend class Match;

private:
	int butsLocaux;
	int butsVisiteurs;

public:
	Resultat(int home, int visitor) : butsLocaux(home), butsVisiteurs(visitor) {}

    ~Resultat();
    Resultat(const Resultat& other);
    Resultat(Resultat&& other);
    Resultat& operator=(const Resultat& other);
    Resultat& operator=(Resultat&& other);

//----------------------------------------------------------------- methods for butsLocaux
	int getButsLocaux() {
		return butsLocaux;
	}

	void setButsLocaux(int goals) {
		butsLocaux = goals;
	}

//----------------------------------------------------------------- methods for butsVisiteurs
	int getButsVisiteurs() {
		return butsVisiteurs;
	}

	void setButsVisiteurs(int goals) {
		butsVisiteurs = goals;
	}

};

#endif