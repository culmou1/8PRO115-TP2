#ifndef JOUEUR_H
#define JOUEUR_H

#include "person.h"
class Contrat;

class Joueur : public Person {

protected:
    double _taille;
    double _poids;
    std::string _emplacementNaissance;

public:
	Joueur();
	Joueur(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance);
    Joueur(std::string prenom,std::string nom, int age);
	virtual ~Joueur();
	Joueur(const Joueur& other);
    virtual Joueur& operator=(Joueur& other);

//----------------------------------------------------------------- methods for Taille
    double getTaille();
    void setTaille(double grandeur);

//----------------------------------------------------------------- methods of poids
    double getPoids();
    void setPoids(double grosseur);

//----------------------------------------------------------------- methods of emplacementNaissance
    std::string getEmplacementNaissance();
    void setEmplacementNaissance(std::string birthPlace);

//----------------------------------------------------------------- methods for Joueur
	virtual void RompreSonContrat(Contrat* leContrat) = 0;

};


class Joueur_Autonome : public Joueur{

public:
	Joueur_Autonome();
	Joueur_Autonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance);
    virtual ~Joueur_Autonome();
	Joueur_Autonome(const Joueur_Autonome& other);
    virtual Joueur_Autonome& operator=(Joueur_Autonome& other);

//----------------------------------------------------------------- methods of Joueur_Autonome
	void RompreSonContrat(Contrat* leContrat);

};

class Joueur_NonAutonome : public Joueur{

private:
	int    _anneeCumulee;
	bool   _avisFavorable;

public:
	Joueur_NonAutonome();
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance,int anneecumulee);
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance);
    virtual ~Joueur_NonAutonome();
	Joueur_NonAutonome(const Joueur_NonAutonome& other);
    virtual Joueur_NonAutonome& operator=(Joueur_NonAutonome& other);

//----------------------------------------------------------------- methods for AnneeCumulee
	int getAnneeCumulee();
	void setAnneeCumulee(int annee);

//----------------------------------------------------------------- methods for avisFavorable
	bool getAvisFavorable();
	void getAvisFavorable(bool avis);

//----------------------------------------------------------------- methods of Joueur_NonAutonome
	bool DemandeDeTransfert();
	void RompreSonContrat(Contrat* leContrat);
};

#endif