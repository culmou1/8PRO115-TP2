#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include "person.h"
#include "joueur.h"
#include <vector>

class Palmares;
class TitreGagne;

typedef std::vector<Palmares*> VectorPal;


/**
 *  Un entraineur est chargé de préparer physiquement et tactiquement son équipe pour les différentes rencontres
 *  L entraineur peut obtenir des titres
 */

class Entraineur : public PersonStaff{

protected:
    std::string _placeGrade;
    VectorPal	_titreGagne;

public:
	Entraineur();
    Entraineur(std::string prenom,std::string nom, int age, std::string place);
    virtual ~Entraineur();
    Entraineur(const Entraineur& other);
    virtual Entraineur& operator=(Entraineur& other);

//----------------------------------------------------------------- methods of placeGrade
    std::string getPlaceGrade();
    void setPlaceGrade(std::string Grade);

//----------------------------------------------------------------- methods of TitresGagnes
	VectorPal getTitreGagne();
	void addTitreGagne(TitreGagne* titre);
    void afficherTitreGagne();
    int getNumberOfTitre();

};
/**
 *  Cette classe est une entite d héritage multiple entre un joueur et un entraineur
 *  Classe Heritage Multiple
 */

class Joueur_Entraineur : public Joueur, public Entraineur {
public:
	Joueur_Entraineur();
    Joueur_Entraineur(std::string prenom,std::string nom, int age, double taille, double poids,std::string emplacementNaissance, std::string place);
    virtual ~Joueur_Entraineur();
    Joueur_Entraineur(const Joueur_Entraineur& other);
    virtual Joueur_Entraineur& operator=(Joueur_Entraineur& other);

//----------------------------------------------------------------- methods for Joueur
	std::string obtenirNP() { return Joueur::obtenirNP();}
};


#endif
