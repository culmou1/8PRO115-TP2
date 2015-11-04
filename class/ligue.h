#ifndef LIGUE_H
#define LIGUE_H
 
#include <vector>
#include <string>
#include "club.h"
#include "calendrier.h"
#include "utils.h"

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

	void AjouterClub(Club* clubs) {
		clubsDeLaLigue.push_back(clubs);
		//creer calendrier du club
	}

	Club* RechercherClub(std::string couleur) {
		for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
			if(clubsDeLaLigue[i]->getCouleurDuClub() == couleur)
				return clubsDeLaLigue[i];
		}
		return NULL;
	}

	void SupprimerClub(std::string couleur) {
		for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
			if(clubsDeLaLigue[i]->getCouleurDuClub() == couleur) {
				delete clubsDeLaLigue[i];
				clubsDeLaLigue.erase(clubsDeLaLigue.begin()+i);
				SupprimerCalendrier(clubsDeLaLigue[i]);
			}
		}
	}

//----------------------------------------------------------------- methods for calendrierDeLaLigue
	VectorCal getCalendrierDeLaLigue() {
		return calendrierDeLaLigue;
	}

	void AjouterCalendrier(Calendrier* calendrier) {
		calendrierDeLaLigue.push_back(calendrier);
	}

	void SupprimerCalendrier(Club* club) {
		for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
			if(clubsDeLaLigue[i] == club) {
				delete clubsDeLaLigue[i]->getCalendrier();
			}
		}
	}
};


#endif