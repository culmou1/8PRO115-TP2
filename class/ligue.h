#ifndef LIGUE_H
#define LIGUE_H

#include <vector>
#include <string>
#include "calendrier.h"

class Club;
class Rencontre;

typedef std::vector<Club*>			VectorClub;
typedef std::vector<Rencontre*>		VectorRen;

/**
  * Classe Singleton Ligue contenant l'ensemble des instances de Club et une instance de Calendrier
  * @authors Gillian Chaville & Daehli Nadeau-Otis
  */
class Ligue {

private:
	VectorClub		_clubs;
	Calendrier*		_calendrier;
	static Ligue*	instance;

public:
/**
* @params Retourne l'unique instance de Ligue
*/
	static Ligue* getInstance();
/**
* @params Constructeur par defaut
*/
	Ligue();
/**
* @params Destructeur
*/
    ~Ligue();
/**
* @params Construteur de recopie
*/
	Ligue(const Ligue& other);
/**
* @params LOperateur d'affectation
*/
    Ligue& operator=(Ligue&& other);

//---------------------------------------------------------------- methods for _clubs
/**
* @params Retourne la liste des Clubs de la ligue
*/
	VectorClub* getClubs();
/**
* @params Ajoute un Club a la liste des clubs de la ligue
*/
	void	addClub(Club* clubs);
/**
* @params Recherche un Club dans la liste des clubs de la ligue
*/
	Club*	rechercherClub(std::string nom);

//---------------------------------------------------------------- methods for _calendrier
/**
* @params Retourne le Calendrier de la ligue
*/
	VectorRen *getCalendrier();
/**
* @params Ajoute une Rencontre au Calendrier de la ligue
*/
	void addCalendrier(Rencontre* match);
/**
* @params Recherche le Calendrier d'un Club de la ligue
*/
	Calendrier* rechercherCalendrier(std::string nom);
/**
* @params Recherche une Rencontre dans le Calendrier de la ligue
*/
	Rencontre* rechercherRencontre(std::string clubLocal, std::string clubInvite, std::string date);

};


#endif
