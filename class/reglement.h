#ifndef REGLEMENT_H
#define REGLEMENT_H

#include <string>

class Reglement {

private:
	const float 	seuilDeTransfert;
	std::string		droitDuJoueur;
	float			montantDuTransfert;
	float			montantAncienClub;
	float			montantJoueur;

public:
	Reglement();

    ~Reglement();
    Reglement(const Reglement& other);
    Reglement(Reglement&& other);
    Reglement& operator=(const Reglement& other);
    Reglement& operator=(Reglement&& other);

//----------------------------------------------------------------- methods for droitDuJoueur
    std::string getDroitDuJoueur() {
    	return  droitDuJoueur;
    }

    void setDroitDuJoueur(std::string right) {
    	droitDuJoueur = right;
    }

//----------------------------------------------------------------- methods for montantDuTransfert
    float getMontantDuTransfert() {
    	return  montantDuTransfert;
    }

    void setMontantDuTransfert(float somme){
    	montantDuTransfert = somme;
    }

//----------------------------------------------------------------- methods for montantAncienClub
    float getMontantAncienClub() {
    	return  montantAncienClub;
    }

    void setMontantAncienClub(float somme){
    	montantAncienClub = somme;
    }

//----------------------------------------------------------------- methods for montantJoueur
    float getMontantJoueur() {
    	return  montantJoueur;
    }

    void setMontantJoueur(float somme){
    	montantJoueur = somme;
    }
    
};

#endif