#ifndef PERSON_H
#define PERSON_H

#include "utils.h"

class Person {

protected:
    std::string     _prenom;
    std::string     _nom;
    int             _age;

public:
	Person() {}
    Person(std::string prenom,std::string nom, int age): _prenom(prenom),_nom(nom),_age(age){};
    virtual ~Person() {}
    Person(const Person& other) : _prenom(other._prenom), _nom(other._nom), _age(other._age) {}
    virtual Person& operator=(Person& other) {
		_prenom=other._prenom; _nom=other._nom; _age=other._age;
		return *this;
	}

//----------------------------------------------------------------- methods of prenom
    virtual std::string getPrenom(){ return _prenom;}
	virtual void setPrenom(std::string firstName){ _prenom = firstName;}

//----------------------------------------------------------------- methods of nom
    virtual std::string getNom(){ return _nom;}
    virtual void setNom(std::string lastName){ _nom = lastName;}
//----------------------------------------------------------------- methods of age
	virtual int getAge() { return _age;}
	virtual void setAge(int nb){ _age = nb;}

//----------------------------------------------------------------- methods for Person
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
	PersonStaff() {}
    PersonStaff(std::string prenom,std::string nom, int age,Role role): Person(prenom, nom, age),_role(role){};
    virtual ~PersonStaff() {}
    PersonStaff(const PersonStaff& other) : Person(other), _role(other._role) {}
    virtual PersonStaff& operator=(PersonStaff& other) {
		Person *a, *b;
		a = this;
		b = &other;
		*a = *b; _role=other._role;
		return *this;
	}

//----------------------------------------------------------------- methods of role
	virtual Role getRole() { return _role;}
	virtual void setRole(Role choix){ _role = choix;}

	virtual std::string obtenirNP() { return _prenom+" "+_nom;}
	virtual int getNumberOfTitre(){return 0;}
};

#endif
