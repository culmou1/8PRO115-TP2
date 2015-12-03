#ifndef MATCH_H
#define MATCH_H

#include <vector>
#include "resultat.h"

class Club;
class Equipe;
class Periode;

typedef std::vector<Periode*> 	VectorPer;

/**
 *  Les matchs contiennent les 2 équipes (locaux et visiteurs) le nombre de période
 *	jouer et le résultat finale du matchs
 */
class Match {

private:
	Equipe		*_locaux;
	Equipe 		*_visiteurs;
	VectorPer	_periodesJouees;
	Resultat  	_resultatFinal;

public:
/**
* @params Constructeur par defaut
*/
	Match();
/**
* @params Constructeur avec resultat aleatoire
*/
	Match(Club *home, Club *visitor);
/**
* @params Constructeur avec resultat saisi
*/
	Match(Club *home, Club *visitor, int butL, int butV);
/**
* @params Destructeur
*/
    ~Match();
/**
* @params Constructeur de recopie
*/
    Match(const Match& other);
/**
* @params Operateur d'affectation
*/
    Match& operator=(Match&& other);

//---------------------------------------------------------------- methods for Locaux
/**
* @params Retourne l'Equipe locale
*/
    Equipe *getLocaux();
/**
* @params Modifie l'Equipe locale
*/
	void setLocaux(Equipe *home);
//---------------------------------------------------------------- methods for Visiteurs
/**
* @params Retourne l'Equipe visiteur
*/
    Equipe *getVisiteurs();
/**
* @params Modifie l'Equipe visiteur
*/
    void setVisiteurs(Equipe *stranger);

//---------------------------------------------------------------- methods for periodesJouees
/**
* @params Retourne les periodes jouees
*/
	VectorPer getPeriodes();
/**
* @params Modifie les periodes jouees
*/
	void setPeriodes(VectorPer half);
//---------------------------------------------------------------- methods for resultat
/**
* @params Retourne le resultat 
*/
	Resultat getResultat();
/**
* @params Modifie le resultat 
*/
	void setResulat(int home, int visitor);

//---------------------------------------------------------------- methods of Match
/**
* @params Calcule le resultat selon les periodes jouees
*/
	void obtenirResulatFinal();

};

#endif
