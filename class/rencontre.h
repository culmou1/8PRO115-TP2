#ifndef RENCONTRE_H
#define RENCONTRE_H

#include "utils.h"

class Match;
class Calendrier;

class Rencontre {

private:
	Match		*_match;
	Date		_dateDeRencontre;
	Calendrier	*_calendrier;

public:
	Rencontre(Match *game, std::string date);

    ~Rencontre();
    Rencontre(const Rencontre& other);
    Rencontre(Rencontre&& other);
    Rencontre& operator=(const Rencontre& other);
    Rencontre& operator=(Rencontre&& other);

//----------------------------------------------------------------- methods for match
    Match* getMatch();

    void setMatch(Match *game);

//----------------------------------------------------------------- methods for dateDeRencontre
    Date getDate();

	void setDate(int day, int month, int year);

	void getMatchAndGame();

//----------------------------------------------------------------- methods for Add Match

/* Ajout des matchs Entre des Équipes */

//----------------------------------------------------------------- methods for affichage

	double resultatAUneDateDonne(std::string date);


};

#endif
