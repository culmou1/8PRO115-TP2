#ifndef REGLEMENT_H
#define REGLEMENT_H

#include <string>
const float pourcentJoueur = 0.002;

class Reglement {

private:
	const float 	_seuilDeTransfert;
	std::string		_droitDuJoueur;
	float			_montantDuTransfert;
	float			_montantAncienClub;
	float			_montantJoueur;

public:
	Reglement(float montant, std::string droit) : 
		_droitDuJoueur(droit), _montantDuTransfert(montant), _montantAncienClub(montant), _montantJoueur(montant*pourcentJoueur) {}

    ~Reglement();
    Reglement(const Reglement& other);
    Reglement(Reglement&& other);
    Reglement& operator=(const Reglement& other);
    Reglement& operator=(Reglement&& other);

//----------------------------------------------------------------- methods for droitDuJoueur
    std::string getDroitDuJoueur() {
    	return  _droitDuJoueur;
    }

    void setDroitDuJoueur(std::string right) {
    	_droitDuJoueur = right;
    }

//----------------------------------------------------------------- methods for montantDuTransfert
    float getMontantDuTransfert() {
    	return  _montantDuTransfert;
    }

    void setMontantDuTransfert(float somme){
    	_montantDuTransfert = somme;
    }

//----------------------------------------------------------------- methods for montantAncienClub
    float getMontantAncienClub() {
    	return  _montantAncienClub;
    }

    void setMontantAncienClub(float somme){
    	_montantAncienClub = somme;
    }

//----------------------------------------------------------------- methods for montantJoueur
    float getMontantJoueur() {
    	return  _montantJoueur;
    }

    void setMontantJoueur(float somme){
    	_montantJoueur = somme;
    }
    
};

#endif