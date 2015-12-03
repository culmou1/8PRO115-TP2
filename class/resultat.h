#ifndef RESULTAT_H
#define RESULTAT_H
/**
 *  La classe resultat, contient le resultat des but locaux et des but visiteurs
 */

/**
  *
  */
class Resultat {

private:
	int _butsLocaux;
	int _butsVisiteurs;

public:
	/**
	* @params Constructeur par defaut
	*/
	Resultat() {}
	/**
	* @params Constructeur Avec tout les parametres
	*/
	Resultat(int home, int visitor) : _butsLocaux(home), _butsVisiteurs(visitor) {}
	/**
	* @params Destructeur par defaut
	*/
	~Resultat() {}
	/**
	* @params Constructeur de recopie
	*/
	Resultat(const Resultat& other) : _butsLocaux(other._butsLocaux), _butsVisiteurs(other._butsVisiteurs) {}
	/**
	* @params Operateur d'affectation
	*/
    Resultat& operator=(Resultat&& other);
//----------------------------------------------------------------- methods for butsLocaux
/**
* @params Retrourne les buts locaux
*/
	int getButsLocaux() {
		return _butsLocaux;
	}
	/**
	* @params Modifie les buts locaux
	*/
	void setButsLocaux(int goals) {
		_butsLocaux = goals;
	}

//----------------------------------------------------------------- methods for butsVisiteurs
/**
* @params Retrourne les buts visisteur
*/
	int getButsVisiteurs() {
		return _butsVisiteurs;
	}
	/**
	* @params Modifie les buts visisteur
	*/
	void setButsVisiteurs(int goals) {
		_butsVisiteurs = goals;
	}

};

#endif
