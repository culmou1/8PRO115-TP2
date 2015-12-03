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
/**
* @params Constructeur par defaut
*/
	Periode() {}
/**
* @params Constructeur
*/
	Periode(int time, Resultat score) : dureePeriode(time), resultat(score) {}
/**
* @params Destructeur
*/
    ~Periode();
/**
* @params Constructeur de recopie
*/
	Periode(const Periode& other) : dureePeriode(other.dureePeriode), resultat(other.resultat) {}
/**
* @params Operateur d'affectation
*/
    Periode& operator=(Periode&& other) {
		dureePeriode=other.dureePeriode, resultat=other.resultat;
		return *this;
	}

//---------------------------------------------------------------- methods for dureePeriode
/**
* @params Retourne la duree de la periode
*/
	int getDureePeriode() {
		return dureePeriode;
	}
/**
* @params Modifie la duree de la periode
*/
	void setDureePeriode(int time) {
		dureePeriode = time;
	}

//---------------------------------------------------------------- methods for score
/**
* @params Retourne le score de la periode
*/
	Resultat getScore() {
		return resultat;
	}
/**
* @params Modifie le score de la periode
*/
	void setResulat(int home, int visitor) {
		resultat.setButsLocaux(home);
		resultat.setButsVisiteurs(visitor);
	}
};

#endif
