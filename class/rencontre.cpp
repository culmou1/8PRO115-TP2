#include "rencontre.h"
#include "calendrier.h"
#include "match.h"


Rencontre::Rencontre(Match *game, std::string date) : _match(game), _dateDeRencontre(To_Date(date))
{
    _calendrier->addRencontre(this);
}

Rencontre::~Rencontre(){}


//----------------------------------------------------------------- methods for match
Match* Rencontre::getMatch() {
    return _match;
}

void Rencontre::setMatch(Match *game){
    _match = game;
}

//----------------------------------------------------------------- methods for dateDeRencontre
Date Rencontre::getDate(){
    return _dateDeRencontre;
}

void Rencontre::setDate(int day, int month, int year){
    _dateDeRencontre.tm_day = day;
    _dateDeRencontre.tm_month = month;
    _dateDeRencontre.tm_year = year;
}

void Rencontre::getMatchAndGame(){
    std::cout << _dateDeRencontre.To_String() << "/ " << _match->getLocaux()->getCouleur() << " vs. "
        << _match->getVisiteurs()->getCouleur() << std::endl;
}

//----------------------------------------------------------------- methods for Add Match

/* Ajout des matchs Entre des Équipes */

//----------------------------------------------------------------- methods for affichage

double Rencontre::resultatAUneDateDonne(std::string date){
    if (lookForDate(date,_dateDeRencontre)){
        _match->getResultat();
    }
}
