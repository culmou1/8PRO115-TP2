#ifndef PERIODE_H
#define PERIODE_H

#include "resultat.h"

/**
 *  La classe Periode contient la duree de la pediode et les resultats des 2 équipes
 */
class Periode {

private:
	int 		dureePeriode;
	Resultat 	resultat;

public:
	Periode() {}
	Periode(int time, Resultat score) : dureePeriode(time), resultat(score) {}
    ~Periode();
	Periode(const Periode& other) : dureePeriode(other.dureePeriode), resultat(other.resultat) {}
    Periode& operator=(Periode&& other) {
		dureePeriode=other.dureePeriode, resultat=other.resultat;
		return *this;
	}

//---------------------------------------------------------------- methods for dureePeriode
	int getDureePeriode() {
		return dureePeriode;
	}

	void setDureePeriode(int time) {
		dureePeriode = time;
	}

//---------------------------------------------------------------- methods for score
	Resultat getScore() {
		return resultat;
	}

	void setResulat(int home, int visitor) {
		resultat.setButsLocaux(home);
		resultat.setButsVisiteurs(visitor);
	}
};

#endif
