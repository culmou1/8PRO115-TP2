#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <vector>

class Rencontre;
class Club;

typedef std::vector<Rencontre*> 	VectorRen; // Une ensemble de vecteur de type Contrat

class Calendrier
{
    VectorRen _rencontres;
public:
    Calendrier();

    ~Calendrier();
    Calendrier(const Calendrier& other);
    Calendrier& operator=(Calendrier&& other);

//----------------------------------------------------------------- methods for rencontres
    VectorRen Calendrier::getAllRencontre(){
		return _rencontres;
	}

	void addRencontre(Rencontre* game);

    void AfficherRencontreForAwayClub(Club *club);

    void AfficherRencontreForHomeClub(Club *club);

    void AfficherRencontre(Club *club);
};





#endif
