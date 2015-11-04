#ifndef MATCH_H
#define MATCH_H

class Rencontre;
class Periode;
class Match;
class Equipe;

typedef std::vector<Periode*> 	VectorPer;

class Match {

private:
	Equipe		*_locaux;
	Equipe 		*_visiteurs;
	VectorPer	_periodesJouees;
	Resultat  	_resultatFinal;

public:
	Match(Equipe *home, Equipe *visitor, Resultat score);

    ~Match();
    Match(const Match& other);
    Match(Match&& other);
    Match& operator=(const Match& other);
    Match& operator=(Match&& other);

//----------------------------------------------------------------- methods for Locaux
    Equipe *getLocaux();

//----------------------------------------------------------------- methods for Locaux
    Equipe *getVisiteurs();

    void setVisiteurs(Equipe *stranger);

//----------------------------------------------------------------- methods for periodesJouees
	VectorPer getPeriodes();

	void setPeriodes(VectorPer half);
//----------------------------------------------------------------- methods for resultat
	Resultat getResultat();

	void setResulat(int home, int visitor);
//----------------------------------------------------------------- methods of Match
	void obtenirResulatFinal();
//----------------------------------------------------------------- methods of Teams

	Equipe getLocalAndAway();

};

#endif
