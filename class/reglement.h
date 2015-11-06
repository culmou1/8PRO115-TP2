#ifndef REGLEMENT_H
#define REGLEMENT_H

#include <string>
const double pourcentJoueur = 0.002;

class Reglement {

private:
	double 			_seuilDeTransfert;
	std::string		_droitDuJoueur;
	double			_montantDuTransfert;
	double			_montantAncienClub;
	double			_montantJoueur;

public:
	Reglement(double montant, std::string droit) :
		_droitDuJoueur(droit), _montantDuTransfert(montant), _montantAncienClub(montant), _montantJoueur(montant*pourcentJoueur) {}

    ~Reglement() {}

    Reglement(const Reglement& other) : 
		_droitDuJoueur(other._droitDuJoueur), _montantDuTransfert(other._montantDuTransfert), _montantAncienClub(other._montantAncienClub), _montantJoueur(other._montantJoueur) {}

    Reglement& operator=(Reglement&& other) {
		_droitDuJoueur=other._droitDuJoueur; _montantDuTransfert=other._montantDuTransfert; _montantAncienClub=other._montantAncienClub; _montantJoueur=other._montantJoueur;
		return *this;
	}

//----------------------------------------------------------------- methods for droitDuJoueur
    std::string getDroitDuJoueur() {
    	return  _droitDuJoueur;
    }

    void setDroitDuJoueur(std::string right) {
    	_droitDuJoueur = right;
    }

//----------------------------------------------------------------- methods for montantDuTransfert
    double getMontantDuTransfert() {
    	return  _montantDuTransfert;
    }

    void setMontantDuTransfert(double somme){
    	_montantDuTransfert = somme;
    }

//----------------------------------------------------------------- methods for montantAncienClub
    double getMontantAncienClub() {
    	return  _montantAncienClub;
    }

    void setMontantAncienClub(double somme){
    	_montantAncienClub = somme;
    }

//----------------------------------------------------------------- methods for montantJoueur
    double getMontantJoueur() {
    	return  _montantJoueur;
    }

    void setMontantJoueur(double somme){
    	_montantJoueur = somme;
    }

	double getSeuilDeTransert() {
		return _seuilDeTransfert;
	}

};


#endif
