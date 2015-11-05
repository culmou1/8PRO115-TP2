#ifndef LIGUE_H
#define LIGUE_H

#include <vector>
#include <string>

class Club;
class Calendrier;

typedef std::vector<Club*>			VectorClub;
typedef std::vector<Calendrier*>	VectorCal;

class Ligue {

private:
	VectorClub		clubsDeLaLigue;
	VectorCal		calendrierDeLaLigue;

public:
	Ligue() {}

    ~Ligue();

	Ligue(const Ligue& other) : clubsDeLaLigue(other.clubsDeLaLigue), calendrierDeLaLigue(other.calendrierDeLaLigue) {}

    Ligue& operator=(Ligue&& other) {
		clubsDeLaLigue=other.clubsDeLaLigue; calendrierDeLaLigue=other.calendrierDeLaLigue;
		return *this;
	}

//----------------------------------------------------------------- methods for clubsDeLaLigue
	VectorClub getClubsDeLaLigue() {
		return clubsDeLaLigue;
	}

//----------------------------------------------------------------- methods for calendrierDeLaLigue
	VectorCal getCalendrierDeLaLigue() {
		return calendrierDeLaLigue;
	}

//----------------------------------------------------------------- methods of Ligue
	void	CreerClub();
	void	AjouterClub(Club* clubs);
	Club*	RechercherClub(std::string couleur);
	void	SupprimerClub(std::string couleur);
	void	AfficherClubs();

	void	EntraineurLePlusTitre();
	void	ClubLePlusTitre();

	void AjouterCalendrier(Calendrier* calendrier);
	void SupprimerCalendrier(Club* club);
};


#endif
