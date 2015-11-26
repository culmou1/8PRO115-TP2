#ifndef RENCONTRE_H
#define RENCONTRE_H

#include "utils.h"
#include "match.h"

class Calendrier;
class Club;

class Rencontre {

private:
	Match		_match;
	Date		_dateDeRencontre;
	Club		*_locaux, *_visiteurs;

public:
	Rencontre();
	Rencontre(Club* home, Club* away, Date date);
	Rencontre(Club* home, Club* away, Match* game, Date date);
	~Rencontre();
	Rencontre(const Rencontre& other);
    Rencontre& operator=(Rencontre&& other);

//----------------------------------------------------------------- methods for Locaux
    Club *getLocaux();
	void setLocaux(Club *home);

//----------------------------------------------------------------- methods for Visiteurs
    Club *getVisiteurs();
    void setVisiteurs(Club *stranger);

//----------------------------------------------------------------- methods for match
	Match* getMatch();
	void setMatch(Match *game);
	void setMatch(Club* home, Club* away);
//----------------------------------------------------------------- methods for dateDeRencontre
	Date getDate();
	void setDate(std::string date);

//----------------------------------------------------------------- methods of Rencontre
	std::string getResultat();

};

#endif
