
#ifndef RUPTURE_H
#define RUPTURE_H

class Joueur;
class Club;

/**
 *  Rupture, contient un Joueur qui rompte sont contrat
 *	Le club qui obtient le joueur
 *	Une raison de départ en string
 *	Une somme d'argent
 */
class Rupture {

private:
	Joueur 			*_joueurRelaxant;
	Club 			*_clubContractant;
	std::string	    _raisonsDuDepart;
	double 			_penalite;

public:
	/**
	* @params Constructeur par defaut
	*/
	Rupture() {}
	/**
	* @params Constructeur Avec tout les parametres
	*/

	Rupture(Joueur *player, Club *new_club, std::string why, double money) :
		_joueurRelaxant(player), _clubContractant(new_club), _raisonsDuDepart(why), _penalite(money) {}

	/**
	* @params Destructeur par defaut
	*/
	~Rupture() {}

	/**
	* @params Constructeur de recopie
	*/

    Rupture(const Rupture& other) :
		_joueurRelaxant(other._joueurRelaxant), _clubContractant(other._clubContractant), _raisonsDuDepart(other._raisonsDuDepart), _penalite(other._penalite) {}
	/**
	* @params Operateur d'affectation
	*/
    Rupture& operator=(Rupture&& other) {
		_joueurRelaxant=other._joueurRelaxant; _clubContractant=other._clubContractant; _raisonsDuDepart=other._raisonsDuDepart; _penalite=other._penalite;
		return *this;
	}

//---------------------------------------------------------------- methods for joueurRelaxant
	/**
	* @params Retrourne le Joueur Relaxant
	*/
    Joueur* getJoueurRelaxant() {
    	return _joueurRelaxant;
    }
	/**
	* @params Modifie le Joueur Relaxant
	*/
    void setJoueurRelaxant(Joueur *newbie) {
    	_joueurRelaxant = newbie;
    }

//---------------------------------------------------------------- methods for clubContractant
	/**
	* @params Retrourne le club contractant
	*/
    Club* getClubContractant() {
    	return _clubContractant;
    }
	/**
	* @params Modifie le club contractant
	*/
    void setClubContractant(Club *new_club) {
    	_clubContractant = new_club;
    }
//---------------------------------------------------------------- methods for raisonsDuDepart
/**
* @params Retrourne la raison de depart
*/
    std::string getRaisonsDuDepart() {
    	return _raisonsDuDepart;
    }
	/**
	* @params Modifie la raison de depart
	*/
    void setRaisonsDuDepart(std::string raisons) {
    	_raisonsDuDepart = raisons;
    }

//---------------------------------------------------------------- methods for penalite
/**
* @params Retrourne la penalite
*/
    double getPenalite() {
    	return _penalite;
    }
	/**
	* @params Modifie la penalite
	*/
    void setPenalite(double cost)  {
    	_penalite = cost;
    }

};

#endif
