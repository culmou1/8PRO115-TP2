#ifndef REGLEMENT_H
#define REGLEMENT_H

#include <string>
const double pourcentJoueur = 0.002;

/**
 *  La classe Reglement comporte tout les regles lors d'un engagement avec un contrat
 */
class Reglement {

private:
	double 			_seuilDeTransfert;
	std::string		_droitDuJoueur;
	double			_montantDuTransfert;
	double			_montantAncienClub;
	double			_montantJoueur;

public:
	/**
	* @params Constructeur par defaut
	*/
	Reglement() {};
	/**
	* @params Constructeur sans un match
	*/
	Reglement(double montant, std::string droit) :
		_droitDuJoueur(droit), _montantDuTransfert(montant), _montantAncienClub(montant), _montantJoueur(montant*pourcentJoueur), _seuilDeTransfert(1000000.00) {}
		/**
		* @params Destructeur par defaut
		*/
    ~Reglement() {}
	/**
	* @params Constructeur de recopie
	*/
    Reglement(const Reglement& other) :
		_droitDuJoueur(other._droitDuJoueur), _montantDuTransfert(other._montantDuTransfert), _montantAncienClub(other._montantAncienClub), _montantJoueur(other._montantJoueur) {}
		/**
		* @params Operateur d'affectation
		*/
    Reglement& operator=(Reglement&& other) {
		_droitDuJoueur=other._droitDuJoueur; _montantDuTransfert=other._montantDuTransfert; _montantAncienClub=other._montantAncienClub; _montantJoueur=other._montantJoueur;
		return *this;
	}
//---------------------------------------------------------------- methods for droitDuJoueur
/**
* @params Retrourne le droit du joueur
*/
    std::string getDroitDuJoueur() {
    	return  _droitDuJoueur;
    }
	/**
	* @params Modifie le droit du joueur
	*/

    void setDroitDuJoueur(std::string right) {
    	_droitDuJoueur = right;
    }

//---------------------------------------------------------------- methods for montantDuTransfert
/**
* @params Retrourne le montant du transfert
*/
    double getMontantDuTransfert() {
    	return  _montantDuTransfert;
    }
	/**
	* @params Modifie le montant du transfert
	*/

    void setMontantDuTransfert(double somme){
    	_montantDuTransfert = somme;
    }

//---------------------------------------------------------------- methods for montantAncienClub
/**
* @params Retrourne le montant de l ancien club
*/
    double getMontantAncienClub() {
    	return  _montantAncienClub;
    }
	/**
	* @params Modifie le montant de l ancien club
	*/

    void setMontantAncienClub(double somme){
    	_montantAncienClub = somme;
    }

//---------------------------------------------------------------- methods for montantJoueur
/**
* @params Retrourne le montant du joueur
*/
    double getMontantJoueur() {
    	return  _montantJoueur;
    }
	/**
	* @params Modifie le montant du joueur
	*/

    void setMontantJoueur(double somme){
    	_montantJoueur = somme;
    }

//---------------------------------------------------------------- methods for seuilDeTransfert
/**
* @params Retrourne  le seuil du transfert
*/
	double getSeuilDeTransert() {
		return _seuilDeTransfert;
	}
	/**
	* @params Modifie  le seuil du transfert
	*/

	 void setSeuilDeTransfert(double somme){
    	_seuilDeTransfert = somme;
    }

};


#endif
