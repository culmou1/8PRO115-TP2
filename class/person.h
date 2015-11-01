#ifndef PERSON_H
#define PERSON_H

//http://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
#include <vector>
#include "palmares.h"
#include "utils.h"

class Person {

protected:
    std::string     prenom;
    std::string     nom;
    int             age;
    Role            role;

public:
    Person();

    virtual ~Person();
    Person(const Person& other);
    Person(Person&& other);
    virtual Person& operator=(const Person& other);
    virtual Person& operator=(Person&& other);

//----------------------------------------------------------------- methods of prenom
    std::string getFirstName(){
        return prenom;
    }
	
	std::string setFirstName(std::string firstName){
		prenom = firstName;
    }

//----------------------------------------------------------------- methods of nom
    std::string getLastName(){
        return nom;
    }

    std::string setLastName(std::string lastName){
		prenom = lastName;
    }

//----------------------------------------------------------------- methods of age
	int getAge() { 
		return age;
	}

	void setAge(int nb){
		age = nb;
	}

//----------------------------------------------------------------- methods of role
	Role getRole() {
		return role;
	}

	void setRole(Role choix){
		role = choix;
	}

};

class Joueur : public Person {

protected:
    float taille;
    float poids;
    std::string emplacementNaissance;

public:
	Joueur();

    virtual ~Joueur();
    Joueur(const Joueur& other);
    Joueur(Joueur&& other);
    virtual Joueur& operator=(const Joueur& other);
    virtual Joueur& operator=(Joueur&& other);
//----------------------------------------------------------------- methods of taille
    float getTaile(){
        return taille;
    }

    void setTaile(float grandeur){
        taille = grandeur;

    }

//----------------------------------------------------------------- methods of poids
    float getPoids(){
        return poids;
    }

    void setPoids(float grosseur){
        poids = grosseur;

    }

//----------------------------------------------------------------- methods of emplacementNaissance
    std::string getEmplacementNaissance(){
        return emplacementNaissance;
    }

    void setEmplacementNaissance(std::string birthPlace){
        emplacementNaissance = birthPlace;
    }
};

class Joueur_Autonome : public Joueur{
public: 
	Joueur_Autonome();

    virtual ~Joueur_Autonome();
    Joueur_Autonome(const Joueur_Autonome& other);
    Joueur_Autonome(Joueur_Autonome&& other);
    virtual Joueur_Autonome& operator=(const Joueur_Autonome& other);
    virtual Joueur_Autonome& operator=(Joueur_Autonome&& other);
	
//----------------------------------------------------------------- methods of Joueur_Autonome
	void RompreSonContrat();

};

class Joueur_NonAutonome : public Joueur{

private:
	int anneeCumulee;
	bool avisFavorable;

public:
	Joueur_NonAutonome();

    virtual ~Joueur_NonAutonome();
    Joueur_NonAutonome(const Joueur_NonAutonome& other);
    Joueur_NonAutonome(Joueur_NonAutonome&& other);
    virtual Joueur_NonAutonome& operator=(const Joueur_NonAutonome& other);
    virtual Joueur_NonAutonome& operator=(Joueur_NonAutonome&& other);

//----------------------------------------------------------------- methods of Joueur_NpnAutonome
	void DemandeDeTransfert();
};


class Entraineur : public Person{

protected:
    std::string placeGrade;
    VectorPal TitresGagnes;

public:
	Entraineur();

    virtual ~Entraineur();
    Entraineur(const Entraineur& other);
    Entraineur(Entraineur&& other);
    virtual Entraineur& operator=(const Entraineur& other);
    virtual Entraineur& operator=(Entraineur&& other);
//----------------------------------------------------------------- methods of placeGrade
    std::string getPlaceGrade(){
        return placeGrade;
    }

    void setPlaceGrade(std::string Grade){
		placeGrade = Grade;
	}

//----------------------------------------------------------------- methods of TitresGagnes

};

#endif
