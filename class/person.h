#ifndef PERSON_H
#define PERSON_H

//http://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
#include <vector>
#include "palmares.h"
#include "contrat.h"
#include "utils.h"

class Person {

protected:
    std::string     _prenom;
    std::string     _nom;
    int             _age;
    Role            _role;


public:
    Person(std::string prenom,std::string nom, int age,Role role): _prenom(prenom),_nom(nom),_age(age),_role(role){};

    virtual ~Person();
    Person(const Person& other);
    Person(Person&& other);
    virtual Person& operator=(const Person& other);
    virtual Person& operator=(Person&& other);


//----------------------------------------------------------------- methods of prenom
    std::string getFirstName(){
        return _prenom;
    }

	std::string setFirstName(std::string firstName){
		_prenom = firstName;
    }

//----------------------------------------------------------------- methods of nom
    std::string getLastName(){
        return _nom;
    }

    std::string setLastName(std::string lastName){
		_nom = lastName;
    }

//----------------------------------------------------------------- methods of age
	int getAge() {
		return _age;
	}

	void setAge(int nb){
		_age = nb;
	}

//----------------------------------------------------------------- methods of role
	Role getRole() {
		return _role;
	}

	void setRole(Role choix){
		_role = choix;
	}

//----------------------------------------------------------------- methods for Person
	std::string obtenirNP() {
		return _prenom+" "+_nom;
	}
};



class Joueur : public Person {

protected:
    float _taille;
    float _poids;
    std::string _emplacementNaissance;

public:
	Joueur(std::string prenom,std::string nom, int age,float taille,float poids,std::string emplacementNaissance):
        Person(prenom,nom,age,JOUEUR),_taille(taille),_poids(poids),_emplacementNaissance(emplacementNaissance){};

    Joueur(std::string prenom,std::string nom, int age):Person(prenom,nom,age,JOUEUR){};

    virtual ~Joueur();
    Joueur(const Joueur& other);
    Joueur(Joueur&& other);
    virtual Joueur& operator=(const Joueur& other);
    virtual Joueur& operator=(Joueur&& other);

//----------------------------------------------------------------- methods for Taille
    float getTaille(){
        return _taille;
    }

    void setTaille(float grandeur){
        _taille = grandeur;
    }

//----------------------------------------------------------------- methods of poids
    float getPoids(){
        return _poids;
    }

    void setPoids(float grosseur){
        _poids = grosseur;
    }

//----------------------------------------------------------------- methods of emplacementNaissance
    std::string getEmplacementNaissance(){
        return _emplacementNaissance;
    }


    void setEmplacementNaissance(std::string birthPlace){
        _semplacementNaissance = birthPlace;
    }
};


class Joueur_Autonome : public Joueur{

public:
	Joueur_Autonome(std::string prenom,std::string nom, int age,float taille,float poids,std::string emplacementNaissance):
		Joueur(prenom, nom, age, taille, poids, emplacementNaissance) {}

    virtual ~Joueur_Autonome();
    Joueur_Autonome(const Joueur_Autonome& other);
    Joueur_Autonome(Joueur_Autonome&& other);
    virtual Joueur_Autonome& operator=(const Joueur_Autonome& other);
    virtual Joueur_Autonome& operator=(Joueur_Autonome&& other);

//----------------------------------------------------------------- methods of Joueur_Autonome
	void RompreSonContrat(Contrat* leContrat){
		std::string raisonDuDepart, choisirClub;
        float penalite;

		//Creation de la rupture
        if(this == leContrat->getJoueurContractant())
		{
            std::cout << "*******************ROMPRE LE CONTRAT DU JOUEUR*******************" << std::endl;
            std::cout << std::endl <<  "//		RAISON DU DEPART : "; std::cin >> raisonDuDepart;
            std::cout << std::endl <<  "//		PENALITE DE DEPART : "; std::cin >> penalite;
			std::cout << std::endl << "//		CHOISIR NOUVELLE EQUIPE : ";  std::cin >> choisirClub;

			Club *newClub;
			//newClub = Ligue->getClub(choisirClub(couleur));

            // Construction de la rupture
			Rupture newRupture = new Rupture(this,newClub,raisonDuDepart,penalite);
			leContrat->getClubContractant()->getRupturesDeContrats().push_back(newRupture);

			//Creation du nouveau contrat du joueur
			leContrat->getClubContractant()->TransfertJoueur(this, newClub);
		}
        else 
		{
			std::cout << "Le joueur " << obtenirNP() << " n'a pas de contrat." << std::endl;
        }
    }
};

class Joueur_NonAutonome : public Joueur{

private:
	int    _anneeCumulee;
	bool   _avisFavorable;

public:
    // Avec Avis Favorable
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,float taille,float poids,std::string emplacementNaissance,int anneecumulee,bool avisFavorable):
        Joueur(prenom, nom, age, taille, poids, emplacementNaissance),_anneeCumulee(anneecumulee),_avisFavorable(avisFavorable) {}
    // Sans AvisFavorable
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,float taille,float poids,std::string emplacementNaissance):
        Joueur(prenom, nom, age, taille, poids, emplacementNaissance), _anneeCumulee(0),_avisFavorable(false) {}

    virtual ~Joueur_NonAutonome();
    Joueur_NonAutonome(const Joueur_NonAutonome& other);
    Joueur_NonAutonome(Joueur_NonAutonome&& other);
    virtual Joueur_NonAutonome& operator=(const Joueur_NonAutonome& other);
    virtual Joueur_NonAutonome& operator=(Joueur_NonAutonome&& other);

//----------------------------------------------------------------- methods for AnneeCumulee
	int getAnneeCumulee() {
		return _anneeCumulee;
	}

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

};


class Entraineur : public Person{

protected:
    std::string _placeGrade;
    VectorPal	_TitreGagne;

public:
    Entraineur(std::string prenom,std::string nom, int age, std::string place) :
		Person(prenom, nom, age, ENTRAINEUR), _placeGrade(place) {}

    virtual ~Entraineur();
    Entraineur(const Entraineur& other);
    Entraineur(Entraineur&& other);
    virtual Entraineur& operator=(const Entraineur& other);
    virtual Entraineur& operator=(Entraineur&& other);

//----------------------------------------------------------------- methods of placeGrade
    std::string getPlaceGrade(){
        return _placeGrade;
    }

    void setPlaceGrade(std::string Grade){
		_placeGrade = Grade;
	}

//----------------------------------------------------------------- methods of TitresGagnes

};

#endif