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
    Rencontre& operator=(Rencontre&& other);

//----------------------------------------------------------------- methods for match
	Match* getMatch() {
		return _match;
	}

	void setMatch(Match *game){
		_match = game;
	}

//----------------------------------------------------------------- methods for dateDeRencontre
	Date getDate(){
		return _dateDeRencontre;
	}

	void setDate(int day, int month, int year){
		_dateDeRencontre.tm_day = day;
		_dateDeRencontre.tm_month = month;
		_dateDeRencontre.tm_year = year;
	}

	void getMatchAndGame();

//----------------------------------------------------------------- methods for Add Match

/* Ajout des matchs Entre des Équipes */

//----------------------------------------------------------------- methods for affichage

	//double resultatAUneDateDonne(std::string date);s


};

#endif
