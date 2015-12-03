#ifndef JOUEUR_H
#define JOUEUR_H

#include "person.h"
class Contrat;

/**
  * Classe Joueur contient la taille, le poids et l'emplacement de naissance de chaque instance de Joueur_Autonome et Joueur_NonAutonome
  *@authors Gillian Chaville & Daehli Nadeau-Otis
  */
class Joueur : public Person {

protected:
    double _taille;
    double _poids;
    std::string _emplacementNaissance;

public:
/**
* @params Constructeur par defaut
*/
	Joueur();
/**
* @params Constructeur avec lieu de naissance
*/
	Joueur(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance);
/**
* @params Constructeur sans lieu de naissance
*/
    Joueur(std::string prenom,std::string nom, int age);
/**
* @params Destructeur
*/
	virtual ~Joueur();
/**
* @params Constructeur de recopie
*/
	Joueur(const Joueur& other);
/**
* @params Operateur d'affectation
*/
    virtual Joueur& operator=(Joueur& other);

//---------------------------------------------------------------- methods for Taille
/**
* @params Retourne la taille
*/
    double getTaille();
/**
* @params Modifie la taille
*/
    void setTaille(double grandeur);

//---------------------------------------------------------------- methods of poids
/**
* @params Retourne le poids
*/
    double getPoids();
/**
* @params Modifie le poids
*/
    void setPoids(double grosseur);

//---------------------------------------------------------------- methods of emplacementNaissance
/**
* @params Retourne l'emplacement de naissance
*/
    std::string getEmplacementNaissance();
/**
* @params Modifie l'emplacement de naissance
*/
    void setEmplacementNaissance(std::string birthPlace);

//---------------------------------------------------------------- methods for Joueur
/**
* @params Recupere le nom et le prenom
*/
	virtual std::string obtenirNP() { return _prenom+" "+_nom;}

};

/**
  * Classe Joueur_Autonome qui peut decider de rompre son contrat
  * d�engagement avec son ancien club � tout moment, moyennant une
  * penalite.
  *@authors Gillian Chaville & Daehli Nadeau-Otis
  */
class Joueur_Autonome : public Joueur{

public:
/**
* @params Constructeur par defaut
*/
	Joueur_Autonome();
/**
* @params Constructeur
*/
	Joueur_Autonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance);
/**
* @params Destructeur
*/
    virtual ~Joueur_Autonome();
/**
* @params Constructeur de recopie
*/
	Joueur_Autonome(const Joueur_Autonome& other);
/**
* @params Operateur d'affectation
*/
    virtual Joueur_Autonome& operator=(Joueur_Autonome& other);

};

/**
  * Classe Joueur_NonAutonome qui est rep�che (junior) pour evoluer dans
  *	la ligue en question. Il peut �tre transfere suite � un avis favorable
  *	de son Directeur (President) du club et apr�s avoir accumule un
  *	certain nombre d�annees (en general).
  *@authors Gillian Chaville & Daehli Nadeau-Otis
  */
class Joueur_NonAutonome : public Joueur{

private:
	int    _anneeCumulee;
	bool   _avisFavorable;

public:
/**
* @params Constructeur par defaut
*/
	Joueur_NonAutonome();
/**
* @params Constructeur avec annee cumulee
*/
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance,int anneecumulee);
/**
* @params Constructeur sans annee cumulee
*/
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance);
/**
* @params Destructeur
*/
    virtual ~Joueur_NonAutonome();
/**
* @params Constructeur de recopie
*/
	Joueur_NonAutonome(const Joueur_NonAutonome& other);
/**
* @params Operateur d'affectation
*/
    virtual Joueur_NonAutonome& operator=(Joueur_NonAutonome& other);

//---------------------------------------------------------------- methods for AnneeCumulee
/**
* @params Retourne les annees cumulees
*/
	int getAnneeCumulee();
/**
* @params Modifie les annees cumulees
*/
	void setAnneeCumulee(int annee);

//---------------------------------------------------------------- methods for avisFavorable
/**
* @params Retourne l'avis favorable
*/
	bool getAvisFavorable();
/**
* @params Modifie l'avis favorable
*/
	void getAvisFavorable(bool avis);

//---------------------------------------------------------------- methods of Joueur_NonAutonome
/**
* @params Retourne l'autorisation d'une demande de transfert
*/
	bool DemandeDeTransfert();
};

#endif
