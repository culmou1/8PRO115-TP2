#include "ligue.h"
#include "club.h"
#include "calendrier.h"

//----------------------------------------------------------------- AjouterClub
void Ligue::AjouterClub(Club* clubs) {
	clubsDeLaLigue.push_back(clubs);
	//creer calendrier du club
}

//----------------------------------------------------------------- RechercherClub
Club* Ligue::RechercherClub(std::string couleur) {
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i]->getCouleurDuClub() == couleur)
			return clubsDeLaLigue[i];
	}
	return NULL;
}

//----------------------------------------------------------------- SupprimerClub
void Ligue::SupprimerClub(std::string couleur) {
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i]->getCouleurDuClub() == couleur) {
			delete clubsDeLaLigue[i];
			clubsDeLaLigue.erase(clubsDeLaLigue.begin()+i);
			SupprimerCalendrier(clubsDeLaLigue[i]);
		}
	}
}

//----------------------------------------------------------------- AjouterCalendrier
void Ligue::AjouterCalendrier(Calendrier* calendrier) {
	calendrierDeLaLigue.push_back(calendrier);
}

//-----------------------------------------------------------------SupprimerCalendrier
void Ligue::SupprimerCalendrier(Club* club) {
	for (unsigned int i=0; i<clubsDeLaLigue.size(); i++) {
		if(clubsDeLaLigue[i] == club) {
			delete clubsDeLaLigue[i]->getCalendrier();
		}
	}
}