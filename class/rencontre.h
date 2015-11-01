#ifndef RENCONTRE_H
#define RENCONTRE_H

#include "match.h"
#include "utils.h"

class Rencontre {

private: 
	Match	*match;
	Date	dateDeRencontre;

public:
	Rencontre(Match *game, std::string date) : match(game), dateDeRencontre(To_Date(date)) {}

    ~Rencontre();
    Rencontre(const Rencontre& other);
    Rencontre(Rencontre&& other);
    Rencontre& operator=(const Rencontre& other);
    Rencontre& operator=(Rencontre&& other);

//----------------------------------------------------------------- methods for match
    Match* getMatch() {
    	return match;
    }

    void setMatch(Match *game){
    	match = game;
    }

//----------------------------------------------------------------- methods for dateDeRencontre
    Date getDate(){
    	return dateDeRencontre;
    }

	void setDate(int day, int month, int year){
	    dateDeRencontre.tm_day = day;
	    dateDeRencontre.tm_month = month;
	    dateDeRencontre.tm_year = year;
	}

};

#endif
