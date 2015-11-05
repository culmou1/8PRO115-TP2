#ifndef PERIODE_H
#define PERIODE_H

#include "resultat.h"

class Periode {

private:
	int 		dureePeriode;
	Resultat 	resultat;

public:
	Periode(int time, Resultat score) : dureePeriode(time), resultat(score) {}

    ~Periode();
    Periode(const Periode& other);
    Periode(Periode&& other);
    Periode& operator=(const Periode& other);
    Periode& operator=(Periode&& other);

//----------------------------------------------------------------- methods for dureePeriode
	int getDureePeriode() {
		return dureePeriode;
	}

	void setDureePeriode(int time) {
		dureePeriode = time;
	}

//----------------------------------------------------------------- methods for score
	Resultat getScore() {
		return resultat;
	}

	void setResulat(int home, int visitor) {
		resultat.setButsLocaux(home);
		resultat.setButsVisiteurs(visitor);
	}
};

#endif
