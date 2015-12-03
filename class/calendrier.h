#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <vector>

class Rencontre;
class Club;

typedef std::vector<Rencontre*> 	VectorRen; // Une ensemble de vecteur de type Contrat

/**
 *  Le calendrier contient tout les rencontres entre les Clubs
 */
class Calendrier
{
    VectorRen _rencontres;
public:
    Calendrier();
    ~Calendrier();
    Calendrier(const Calendrier& other);
    Calendrier& operator=(Calendrier&& other);

//---------------------------------------------------------------- methods for rencontres
    VectorRen *getRencontres();
	void addRencontre(Rencontre* game);

};

#endif
