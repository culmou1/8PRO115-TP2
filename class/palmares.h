#ifndef PALMARES_H
#define PALMARES_H

#include <string>
#include "utils.h"

class Club;

class Palmares {

protected:
    Date _date; // Date
    Titre _titre; // titre


public:
    Palmares(std::string day, Titre trophy) :
		_date(To_Date(day)), _titre(trophy) {}

	~Palmares() {}

	Palmares(const Palmares& other) : _date(other._date), _titre(other._titre) {}

    Palmares& operator=(Palmares&& other) {
		_date=other._date; _titre=other._titre;
		return *this;
	}

//----------------------------------------------------------------- methods of date
    Date getDate(){
        return _date;
    }

    void setDate(int day, int month, int year){
        _date.tm_day = day;
        _date.tm_month = month;
        _date.tm_year = year;
    }

//----------------------------------------------------------------- methods of titre
    Titre getTitre(){
        return _titre;
    }

    void setTitre(Titre choix){
		_titre = choix;
    }
};

class TitreGagne : public Palmares {

private:
    Club  *_club;

public:
    TitreGagne(Club *team, std::string day, Titre trophy) :
		_club(team), Palmares(day, trophy) {}

	~TitreGagne() { delete _club;}

    TitreGagne(const TitreGagne& other) : Palmares(other), _club(other._club) {}

    TitreGagne& operator=(TitreGagne&& other) {
		Palmares *a, *b;
		a = this;
		b = &other;
		*a = *b; _club = other._club;
		return *this;
	}
//----------------------------------------------------------------- methods of club
    Club *getClub() {
        return _club;
    }
    void setClub(Club *other){
        _club = other;
    }
};

#endif
