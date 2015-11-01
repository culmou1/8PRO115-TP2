#ifndef PALMARES_H
#define PALMARES_H

#include "club.h"
#include "utils.h"

class Palmares{

private:
    Date date; // Date
    Titre titre; // titre


public:
    Palmares(std::string day, Titre trophy) :
		date(To_Date(day)), titre(trophy) {}

    ~Palmares();
    Palmares(const Palmares& other);
    Palmares(Palmares&& other);
    Palmares& operator=(const Palmares& other);
    Palmares& operator=(Palmares&& other);

//----------------------------------------------------------------- methods of date
    Date getDate(){
        return date;
    }

    void setDate(int day, int month, int year){
        date.tm_day = day;
        date.tm_month = month;
        date.tm_year = year;
    }

//----------------------------------------------------------------- methods of titre
    Titre getTitre(){
        return titre;
    }

    void setTitre(Titre choix){
		titre = choix;
    }
};

class TitreGagne : public Palmares {

private:
    Club  *club;

public:
    TitreGagne(Club *team, std::string day, Titre trophy) :
		club(team), Palmares(day, trophy) {}

    ~TitreGagne();
    TitreGagne(const TitreGagne& other);
    TitreGagne(TitreGagne&& other);
    TitreGagne& operator=(const TitreGagne& other);
    TitreGagne& operator=(TitreGagne&& other);

//----------------------------------------------------------------- methods of club
    Club *getClub() {
        return club;
    }
    void setClub(Club *other){
        club = other;
    }
};

#endif
