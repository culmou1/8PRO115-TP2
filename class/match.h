#ifndef MATCH_H
#define MATCH_H

#include <vector>
#include "resultat.h"

class Club;
class Equipe;
class Periode;

typedef std::vector<Periode*> 	VectorPer;

/**
  *
  */
class Match {

private:
	Equipe		*_locaux;
	Equipe 		*_visiteurs;
	VectorPer	_periodesJouees;
	Resultat  	_resultatFinal;

public:
	Match();
	Match(Club *home, Club *visitor);
	Match(Club *home, Club *visitor, int butL, int butV);
    ~Match();
    Match(const Match& other);
    Match& operator=(Match&& other);

//---------------------------------------------------------------- methods for Locaux
    Equipe *getLocaux();
	void setLocaux(Equipe *home);
//---------------------------------------------------------------- methods for Visiteurs
    Equipe *getVisiteurs();
    void setVisiteurs(Equipe *stranger);

//---------------------------------------------------------------- methods for periodesJouees
	VectorPer getPeriodes();

	void setPeriodes(VectorPer half);
//---------------------------------------------------------------- methods for resultat
	Resultat getResultat();
	void setResulat(int home, int visitor);

//---------------------------------------------------------------- methods of Match
	void obtenirResulatFinal();

};

#endif
