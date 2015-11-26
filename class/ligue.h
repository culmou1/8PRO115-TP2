#ifndef LIGUE_H
#define LIGUE_H

#include <vector>
#include <string>
#include "calendrier.h"

class Club;
class Rencontre;

typedef std::vector<Club*>			VectorClub;
typedef std::vector<Rencontre*>		VectorRen;

class Ligue {

private:
	VectorClub		_clubs;
	Calendrier*		_calendrier;
	static Ligue*	instance;

public:
	static Ligue* getInstance();
	Ligue();

    ~Ligue();
	Ligue(const Ligue& other);
    Ligue& operator=(Ligue&& other);

//----------------------------------------------------------------- methods for _clubs
	VectorClub* getClubs();
	void	addClub(Club* clubs);
	Club*	rechercherClub(std::string nom);

//----------------------------------------------------------------- methods for _calendrier
	VectorRen *getCalendrier();
	void addCalendrier(Rencontre* match);
	Calendrier* rechercherCalendrier(std::string nom);
	Rencontre* rechercherRencontre(std::string clubLocal, std::string clubInvite, std::string date);

};


#endif
