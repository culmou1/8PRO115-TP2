#ifndef LIGUE_H
#define LIGUE_H
 
#include <vector>
#include <string>
#include "utils.h"

class Club;
class Calendrier;

typedef std::vector<Club*>			VectorClub;
typedef std::vector<Calendrier*>	VectorCal;

class Ligue {

private:
	VectorClub		clubsDeLaLigue;
	VectorCal		calendrierDeLaLigue;

public:
	Ligue();

    ~Ligue();
    Ligue(const Ligue& other);
    Ligue(Ligue&& other);
    Ligue& operator=(const Ligue& other);
    Ligue& operator=(Ligue&& other);

//----------------------------------------------------------------- methods for clubsDeLaLigue
	VectorClub getClubsDeLaLigue() {
		return clubsDeLaLigue;
	}

	void	AjouterClub(Club* clubs);
	Club*	RechercherClub(std::string couleur);
	void	SupprimerClub(std::string couleur);

//----------------------------------------------------------------- methods for calendrierDeLaLigue
	VectorCal getCalendrierDeLaLigue() {
		return calendrierDeLaLigue;
	}

	void AjouterCalendrier(Calendrier* calendrier);
	void SupprimerCalendrier(Club* club);
};


#endif