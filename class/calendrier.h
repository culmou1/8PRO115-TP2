#ifndef CALENDRIER_H
#define CALENDRIER_H
#include <stdexcept>
#include <vector>

class Rencontre;
class Club;

typedef std::vector<Rencontre*> 	VectorRen; // Une ensemble de vecteur de type Contrat

class Calendrier
{
    VectorRen _rencontre;
public:
    Calendrier();

    ~Calendrier();
    Calendrier(const Calendrier& other);
    Calendrier(Calendrier&& other);
    Calendrier& operator=(const Calendrier& other);
    Calendrier& operator=(Calendrier&& other);

    VectorRen getAllRencontre();

	void addRencontre(Rencontre* game);

    void getAllRencontreForAwayClub(Club *club);

    void getAllRencontreForHomeClub(Club *club);

    void getAllRencontre(Club *club);
};





#endif
