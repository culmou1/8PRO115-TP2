#ifndef RENCONTRE_H
#define RENCONTRE_H

#include "match.h"
#include "utils.h"

class Rencontre {

private:
	Match	*_match;
	Date	_dateDeRencontre;

public:
	Rencontre(Match *game, std::string date) : _match(game), _dateDeRencontre(To_Date(date)) {}

    ~Rencontre();
    Rencontre(const Rencontre& other);
    Rencontre(Rencontre&& other);
    Rencontre& operator=(const Rencontre& other);
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

	void getMatchAndGame(){
		std::cout << getDate.To_String() << " " << getMatch << std::endl
	}

//----------------------------------------------------------------- methods for Add Match

/* Ajout des matchs Entre des Équipes */

//----------------------------------------------------------------- methods for affichage

	float resultatAUneDateDonne(std::string date){
		if (lookForDate(date,_dateDeRencontre)){
			_match->getResultat();
		}
	}


};

#endif
