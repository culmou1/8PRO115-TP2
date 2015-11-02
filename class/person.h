#ifndef PERSON_H
#define PERSON_H

//http://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
#include <vector>
#include "palmares.h"
#include "utils.h"

class Person {

protected:
    std::string     _prenom;
    std::string     _nom;
    int             _age;
    Role            _role;


public:
    Person(std::string prenom,std::string nom, int age,Role role): _prenom(prenom),_nom(nom),_age(age)_role(role){};

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

};

class Joueur : public Person {

protected:
    float _taille;
    float _poids;
    std::string _emplacementNaissance;

public:
	Joueur(std::string prenom,std::string nom, int age,Role role,float taille,float poids,std::string emplacementNaissance):
        Person(prenom,nom,age,role),_taille(taille),_poids(poids),_emplacementNaissance(emplacementNaissance){};
    Joueur(std::string prenom,std::string nom, int age,Role role):Person(prenom,nom,age,role){};

    virtual ~Joueur();
    Joueur(const Joueur& other);
    Joueur(Joueur&& other);
    virtual Joueur& operator=(const Joueur& other);
    virtual Joueur& operator=(Joueur&& other);

//----------------------------------------------------------------- methods for FirstName



        std::string getFirstName(){

            return _prenom;
        }

        void setFirstName(std::string firstName){

            _prenom = firstName;

        }

//----------------------------------------------------------------- methods for LastName

        std::string getLastName(){

            return std::string _nom;
        }

        void setLastName(lastName){

           _prenom = lastName;

        }
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
	Joueur_Autonome();
    virtual ~Joueur_Autonome();
    Joueur_Autonome(const Joueur_Autonome& other);
    Joueur_Autonome(Joueur_Autonome&& other);
    virtual Joueur_Autonome& operator=(const Joueur_Autonome& other);
    virtual Joueur_Autonome& operator=(Joueur_Autonome&& other);

//----------------------------------------------------------------- methods of Joueur_Autonome
	void RompreSonContrat(Contrat* leContrat){;

        leContrat
    }

    std::string getEmplacementNaissance(){
        return _emplacementNaissance;
    }

    void setEmplacementNaissance(std::string birthDay){

        _emplacementNaissance = birthDay;
    }

}

class Joueur_NonAutonome : public Joueur{

private:
	int    _anneeCumulee;
	bool   _avisFavorable;

public:
    // Avec Avis Favorable
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,Role role,float taille,float poids,std::string emplacementNaissance,int anneecumulee,bool avisFavorable):
        Person(prenom,nom,age,role),_taille(taille),_poids(poids),_emplacementNaissance(emplacementNaissance),_anneeCumulee(anneecumulee),_avisFavorable(avisFavorable){};
    // Sans AvisFavorable
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,Role role,float taille,float poids,std::string emplacementNaissance,int anneecumulee):
        Person(prenom,nom,age,role),_taille(taille),_poids(poids),_emplacementNaissance(emplacementNaissance),_anneeCumulee(anneecumulee)){};

    virtual ~Joueur_NonAutonome();
    Joueur_NonAutonome(const Joueur_NonAutonome& other);
    Joueur_NonAutonome(Joueur_NonAutonome&& other);
    virtual Joueur_NonAutonome& operator=(const Joueur_NonAutonome& other);
    virtual Joueur_NonAutonome& operator=(Joueur_NonAutonome&& other);

//----------------------------------------------------------------- methods of Joueur_NpnAutonome

	bool DemandeDeTransfert(){
        if (this._avisFavorable == True){
            return true;
        }
        else return false;
    }
};


class Entraineur : public Person{

protected:
    std::string _placeGrade;
    VectorPal _TitreGagne;
public:

    	Entraineur();
        virtual ~Entraineur();
        Entraineur(const Entraineur& other);
        Entraineur(Entraineur&& other);
        virtual Entraineur& operator=(const Entraineur& other);
        virtual Entraineur& operator=(Entraineur&& other);

        void getFirstName(){

            return _prenom;
        }

        std::string setFirstName(std::string firstName){

           _prenom = firstName;

        }

        void getLastName(){

            return _nom;
        }

        void setLastName(std::string lastName){

            _prenom = lastName;

        }

        std::string getGrade(){

            return _placeGrade;
        }

        void setGrade(std::string Grade){

            _placeGrade = Grade;
        }

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
