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
/**
* @params Constructeur par defaut
*/
    Calendrier();
/**
* @params Destructeur
*/
    ~Calendrier();
/**
* @params Constructeur de recopie
*/
    Calendrier(const Calendrier& other);
/**
* @params Operateur d'affectation
*/
    Calendrier& operator=(Calendrier&& other);

//---------------------------------------------------------------- methods for rencontres
/**
* @params Retourne les Rencontre du calendrier
*/
    VectorRen *getRencontres();
/**
* @params Ajoute une Rencontre au calendrier
*/
	void addRencontre(Rencontre* game);

};

#endif
