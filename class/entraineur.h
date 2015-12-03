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
/**
* @params Construteur par defaut
*/ 
	Entraineur();
/**
* @params Construteur
*/ 
    Entraineur(std::string prenom,std::string nom, int age, std::string place);
/**
* @params Destructeur
*/ 
    virtual ~Entraineur();
/**
* @params Constructeur de recopie
*/ 
    Entraineur(const Entraineur& other);
/**
* @params Operateur d'affectation
*/ 
    virtual Entraineur& operator=(Entraineur& other);

//---------------------------------------------------------------- methods of placeGrade
/**
* @params Retourne le lieu d'obtention du Grade
*/ 
    std::string getPlaceGrade();
/**
* @params Modifie le lieu d'obtention du Grade
*/ 
    void setPlaceGrade(std::string Grade);

//---------------------------------------------------------------- methods of TitresGagnes
/**
* @params Retourne la liste de TitreGagne
*/
	VectorPal getTitreGagne();
/**
* @params Ajoute un titre a la liste de TitreGagne
*/
	void addTitreGagne(TitreGagne* titre);
/**
* @params Affiche la liste de TitreGagne
*/
    void afficherTitreGagne();

//---------------------------------------------------------------- getNumberOfTitre
/**
* @params Retourne le nombre de TitreGagne
*/
    int getNumberOfTitre();

};
/**
 *  Cette classe est une entite d héritage multiple entre un joueur et un entraineur
 *  Classe Heritage Multiple
 */

/**
  * Classe Joueur_Entraineur issu de l'heritage multiple de Joueur et Entraineur. 
  *	Il appartient � la fois au staff et � l'effectif de son Club.
  *@authors Gillian Chaville & Daehli Nadeau-Otis
  */
class Joueur_Entraineur : public Joueur, public Entraineur {
public:
/**
* @params Constructeur par defaut
*/ 
	Joueur_Entraineur();
/**
* @params Constructeur
*/ 
    Joueur_Entraineur(std::string prenom,std::string nom, int age, double taille, double poids,std::string emplacementNaissance, std::string place);
/**
* @params Destructeur
*/ 
    virtual ~Joueur_Entraineur();
/**
* @params Constructeur de recopie
*/
    Joueur_Entraineur(const Joueur_Entraineur& other);
/**
* @params Operateur d'affectation
*/ 
    virtual Joueur_Entraineur& operator=(Joueur_Entraineur& other);

//----------------------------------------------------------------obtenirNP
/**
  * @params Recupere le prenom et le nom
  */
	std::string obtenirNP() { return Joueur::obtenirNP();}
};


#endif
