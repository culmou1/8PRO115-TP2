#include "rencontre.h"
#include "club.h"
#include "match.h"
#include "utils.h"

//---------------------------------------------------------------- Constructeurs
Rencontre::Rencontre() {}

Rencontre::Rencontre(Club* home, Club* away, Date date) : _locaux(home), _visiteurs(away), _dateDeRencontre(date) {
	setMatch(home,away);
}

Rencontre::Rencontre(Club* home, Club* away, Match* game, Date date) : _locaux(home), _visiteurs(away), _dateDeRencontre(date) {
	setMatch(game);
}

//---------------------------------------------------------------- Destructeur
Rencontre::~Rencontre() {}

//---------------------------------------------------------------- Constructeur de recopie
Rencontre::Rencontre(const Rencontre& other) :
	_match(other._match), _dateDeRencontre(other._dateDeRencontre), _locaux(other._locaux), _visiteurs(other._visiteurs) {}

//---------------------------------------------------------------- Operateur d'affectation
Rencontre& Rencontre::operator=(Rencontre&& other) {
	_match=other._match; _dateDeRencontre=other._dateDeRencontre; _locaux=other._locaux; _visiteurs=other._visiteurs;
	return *this;
}

//---------------------------------------------------------------- methods for Locaux
Club* Rencontre::getLocaux(){
    return _locaux;
}

void Rencontre::setLocaux(Club *home){
    _locaux = home;
}


//---------------------------------------------------------------- methods for Visiteurs
Club* Rencontre::getVisiteurs(){
    return _visiteurs;
}

void Rencontre::setVisiteurs(Club *stranger){
    _visiteurs = stranger;
}


//---------------------------------------------------------------- methods for match
Match* Rencontre::getMatch() {
	return &_match;
}

void Rencontre::setMatch(Match *game){
	_match = *game;
}

void Rencontre::setMatch(Club* home, Club* away){
	Match* temp = new Match(home, away);
	_match = *temp;
}

//---------------------------------------------------------------- methods for dateDeRencontre
Date Rencontre::getDate(){
	return _dateDeRencontre;
}

void Rencontre::setDate(std::string date){
	_dateDeRencontre = To_Date(date);
}

//---------------------------------------------------------------- methods of Rencontre
std::string Rencontre::getResultat()  {
	return std::to_string(_match.getResultat().getButsLocaux()) +" - "+ std::to_string(_match.getResultat().getButsVisiteurs());
}