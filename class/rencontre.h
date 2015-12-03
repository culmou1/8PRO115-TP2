#ifndef RENCONTRE_H
#define RENCONTRE_H

#include "utils.h"
#include "match.h"

class Calendrier;
class Club;

/**
 *  Les rencontre contiennent des matchs, la date du match et les équipes
 *	qui s'affronte
 */
class Rencontre {

private:
	Match		_match;
	Date		_dateDeRencontre;
	Club		*_locaux, *_visiteurs;

public:
	/**
	* @params Constructeur par defaut
	*/
	Rencontre();
	/**
	* @params Constructeur sans un match
	*/
	Rencontre(Club* home, Club* away, Date date);
	/**
	* @params Constructeur Avec tout les parametres
	*/
	Rencontre(Club* home, Club* away, Match* game, Date date);
	/**
	* @params Destructeur par defaut
	*/
	~Rencontre();
	/**
	* @params Constructeur de recopie
	*/
	Rencontre(const Rencontre& other);
	/**
	* @params Operateur d'affectation
	*/
    Rencontre& operator=(Rencontre&& other);

//---------------------------------------------------------------- methods for Locaux
/**
* @params Retrourne l equipe locale
*/
    Club *getLocaux();
	/**
	* @params Modifie l equipe locale
	*/
	void setLocaux(Club *home);

//---------------------------------------------------------------- methods for Visiteurs
/**
* @params Retrourne l equipe visiteur
*/
    Club *getVisiteurs();
	/**
	* @params Modifie l equipe visiteur
	*/
    void setVisiteurs(Club *stranger);

//---------------------------------------------------------------- methods for match
/**
* @params Retrourne un match
*/
	Match* getMatch();
	/**
	* @params Modifie un match
	*/
	void setMatch(Match *game);
	/**
	* @params Modifie un match entre 2 equipes
	*/
	void setMatch(Club* home, Club* away);
//---------------------------------------------------------------- methods for dateDeRencontre
/**
* @params Retrourne une date
*/
	Date getDate();
	/**
	* @params Modifie une date
	*/
	void setDate(std::string date);

//---------------------------------------------------------------- methods of Rencontre
/**
* @params Retrourne un resultats
*/
	std::string getResultat();

};

#endif
