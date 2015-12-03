#ifndef PERSON_H
#define PERSON_H

#include "utils.h"

/**
  * Classe virtuelle Person contient le nom, le prenom et l'age de chaque instance de Joueur et PersonStaff 
  *@authors Gillian Chaville & Daehli Nadeau-Otis
  */
class Person {

protected:
    std::string     _prenom;
    std::string     _nom;
    int             _age;

public:
/**
* @params Constructeur par defaut
*/
	Person() {}
/**
* @params Constructeur
*/
    Person(std::string prenom,std::string nom, int age): _prenom(prenom),_nom(nom),_age(age){};
/**
* @params Destructeur
*/
    virtual ~Person() {}
/**
* @params Constructeur de recopie
*/
    Person(const Person& other) : _prenom(other._prenom), _nom(other._nom), _age(other._age) {}
/**
* @params Operateur d'affectation
*/
    virtual Person& operator=(Person& other) {
		_prenom=other._prenom; _nom=other._nom; _age=other._age;
		return *this;
	}

//---------------------------------------------------------------- methods of prenom
/**
* @params Retourne le prenom
*/
    virtual std::string getPrenom(){ return _prenom;}
/**
* @params Modifie le prenom
*/
	virtual void setPrenom(std::string firstName){ _prenom = firstName;}

//---------------------------------------------------------------- methods of nom
/**
* @params Retourne le nom
*/
    virtual std::string getNom(){ return _nom;}
/**
* @params Modifie le nom
*/
    virtual void setNom(std::string lastName){ _nom = lastName;}
//---------------------------------------------------------------- methods of age
/**
* @params Retourne l'age
*/
	virtual int getAge() { return _age;}
/**
* @params Modifie l'age
*/
	virtual void setAge(int nb){ _age = nb;}

//---------------------------------------------------------------- methods for Person
/**
* @params Methode virtuelle pure
*/
	virtual std::string obtenirNP()= 0;
};

/**
 *  Une Person Staff est une classe  qui hérite de Person.
 *  On lui ajoute seulement un role supplémentaire
 */
class PersonStaff : public Person{

protected:
	Role            _role;

public:
/**
* @params Constructeur par defaut
*/
	PersonStaff() {}
/**
* @params Constructeur
*/
    PersonStaff(std::string prenom,std::string nom, int age,Role role): Person(prenom, nom, age),_role(role){}
/**
* @params Destructeur
*/
    virtual ~PersonStaff() {}
/**
* @params Constructeur de recopie
*/
    PersonStaff(const PersonStaff& other) : Person(other), _role(other._role) {}
/**
* @params Operateur d'affectation
*/
    virtual PersonStaff& operator=(PersonStaff& other) {
		Person *a, *b;
		a = this;
		b = &other;
		*a = *b; _role=other._role;
		return *this;
	}

//---------------------------------------------------------------- methods of role
/**
* @params Retourne le Role
*/
	virtual Role getRole() { return _role;}
/**
* @params Modifie le Role
*/
	virtual void setRole(Role choix){ _role = choix;}

/**
* @params Recupere le nom et le prenom
*/
	virtual std::string obtenirNP() { return _prenom+" "+_nom;}
/**
* @params Recupere le nombre de titres
*/
	virtual int getNumberOfTitre(){return 0;}
};

#endif
