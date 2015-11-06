#ifndef PERSON_H
#define PERSON_H
#include <vector>
#include "utils.h"

class Contrat;
class Palmares;
class TitreGagne;

typedef std::vector<Palmares*> VectorPal;


class Person {

protected:
    std::string     _prenom;
    std::string     _nom;
    int             _age;
    Role            _role;

public:
    Person(std::string prenom,std::string nom, int age,Role role): _prenom(prenom),_nom(nom),_age(age),_role(role){};

    virtual ~Person() {}

    Person(const Person& other) : _prenom(other._prenom), _nom(other._nom), _age(other._age), _role(other._role) {}

    virtual Person& operator=(Person& other) {
		_prenom=other._prenom; _nom=other._nom; _age=other._age; _role=other._role;
		return *this;
	}



//----------------------------------------------------------------- methods of prenom
    virtual std::string getFirstName(){
        return _prenom;
    }

	virtual void setFirstName(std::string firstName){
		_prenom = firstName;
    }

//----------------------------------------------------------------- methods of nom
    virtual std::string getLastName(){
        return _nom;
    }

    virtual void setLastName(std::string lastName){
		_nom = lastName;
    }
//----------------------------------------------------------------- methods of age
	virtual int getAge() {
		return _age;
	}

	virtual void setAge(int nb){
		_age = nb;
	}

//----------------------------------------------------------------- methods of role
	virtual Role getRole() {
		return _role;
	}

	virtual void setRole(Role choix){
		_role = choix;
	}

//----------------------------------------------------------------- methods for Person
	std::string obtenirNP();
	virtual int getNumberOfTitre() {return 0;}
};



class Joueur : public Person {

protected:
    double _taille;
    double _poids;
    std::string _emplacementNaissance;

public:
	Joueur(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance):
        Person(prenom,nom,age,JOUEUR),_taille(taille),_poids(poids),_emplacementNaissance(emplacementNaissance) {}

    Joueur(std::string prenom,std::string nom, int age):Person(prenom,nom,age,JOUEUR){ }

	virtual ~Joueur();
	Joueur(const Joueur& other) :
		Person(other), _taille(other._taille), _poids(other._poids), _emplacementNaissance(other._emplacementNaissance) {}

    virtual Joueur& operator=(Joueur& other) {
		Person *a, *b;
		a = this;
		b = &other;
		*a = *b; _taille = other._taille; _poids = other._poids; _emplacementNaissance = other._emplacementNaissance;
		return *this;
	}



//----------------------------------------------------------------- methods for Taille
    double getTaille(){
        return _taille;
    }

    void setTaille(double grandeur){
        _taille = grandeur;
    }

//----------------------------------------------------------------- methods of poids
    double getPoids(){
        return _poids;
    }

    void setPoids(double grosseur){
        _poids = grosseur;
    }

//----------------------------------------------------------------- methods of emplacementNaissance
    std::string getEmplacementNaissance(){
        return _emplacementNaissance;
    }


    void setEmplacementNaissance(std::string birthPlace){
        _emplacementNaissance = birthPlace;
    }

	virtual void RompreSonContrat(Contrat* leContrat) = 0;

};


class Joueur_Autonome : public Joueur{

public:
	Joueur_Autonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance):
		Joueur(prenom, nom, age, taille, poids, emplacementNaissance) {}

    virtual ~Joueur_Autonome() {}

	Joueur_Autonome(const Joueur_Autonome& other) : Joueur(other) {}

    virtual Joueur_Autonome& operator=(Joueur_Autonome& other) {
		Joueur *a, *b;
		a = this;
		b = &other;
		*a = *b;
		return *this;
	}


//----------------------------------------------------------------- methods of Joueur_Autonome
	void RompreSonContrat(Contrat* leContrat);

};

class Joueur_NonAutonome : public Joueur{

private:
	int    _anneeCumulee;
	bool   _avisFavorable;

public:
    // Avec AnneeCumulee
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance,int anneecumulee):
        Joueur(prenom, nom, age, taille, poids, emplacementNaissance),_anneeCumulee(anneecumulee),_avisFavorable(false) {}

    // Sans AnneeCumulee
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,double taille,double poids,std::string emplacementNaissance):
        Joueur(prenom, nom, age, taille, poids, emplacementNaissance), _anneeCumulee(0),_avisFavorable(false) {}

    virtual ~Joueur_NonAutonome() {}

	Joueur_NonAutonome(const Joueur_NonAutonome& other) :
		Joueur(other), _anneeCumulee(other._anneeCumulee), _avisFavorable(other._avisFavorable) {}

    virtual Joueur_NonAutonome& operator=(Joueur_NonAutonome& other) {
		Joueur *a, *b;
		a = this;
		b = &other;
		*a = *b; _anneeCumulee = other._anneeCumulee; _avisFavorable= other._avisFavorable;
		return *this;
	}

//----------------------------------------------------------------- methods for AnneeCumulee
	int getAnneeCumulee() {
		return _anneeCumulee;
	}

	bool DemandeDeTransfert();

	void setAnneeCumulee(int annee) {
		_anneeCumulee = annee;
	}

//----------------------------------------------------------------- methods for avisFavorable
	bool getAvisFavorable(){
		return _avisFavorable;
    }

	void getAvisFavorable(bool avis) {
		_avisFavorable = avis;
	}

//----------------------------------------------------------------- methods of Joueur_NonAutonome
	void RompreSonContrat(Contrat* leContrat);
};


class Entraineur : public Person{

protected:
    std::string _placeGrade;
    VectorPal	_titreGagne;


public:

    Entraineur(std::string prenom,std::string nom, int age, std::string place) :
		Person(prenom, nom, age, ENTRAINEUR), _placeGrade(place) {}

    virtual ~Entraineur() {}

    Entraineur(const Entraineur& other) :
		Person(other), _placeGrade(other._placeGrade), _titreGagne(other._titreGagne) {}

    virtual Entraineur& operator=(Entraineur& other) {
		Person *a, *b;
		a = this;
		b = &other;
		*a = *b; _placeGrade = other._placeGrade; _titreGagne = other._titreGagne;
		return *this;
	}

//----------------------------------------------------------------- methods of placeGrade
    std::string getPlaceGrade(){
        return _placeGrade;
    }

    void setPlaceGrade(std::string Grade){
		_placeGrade = Grade;
	}

//----------------------------------------------------------------- methods of TitresGagnes
	VectorPal getTitreGagne() {
		return _titreGagne;
	}

	void addTitreGagne(TitreGagne* titre);
	void deleteTitreGagne(std::string date);
    void afficherTitreGagne();
    Palmares* selectTitreGagne(int j);
    int getNumberOfTitre();

};


#endif
