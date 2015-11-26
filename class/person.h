#ifndef PERSON_H
#define PERSON_H

#include "utils.h"

class Person {

protected:
    std::string     _prenom;
    std::string     _nom;
    int             _age;
    Role            _role;

public:
	Person() {}
    Person(std::string prenom,std::string nom, int age,Role role): _prenom(prenom),_nom(nom),_age(age),_role(role){};
    virtual ~Person() {}
    Person(const Person& other) : _prenom(other._prenom), _nom(other._nom), _age(other._age), _role(other._role) {}
    virtual Person& operator=(Person& other) {
		_prenom=other._prenom; _nom=other._nom; _age=other._age; _role=other._role;
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

//----------------------------------------------------------------- methods of role
	virtual Role getRole() { return _role;}
	virtual void setRole(Role choix){ _role = choix;}

//----------------------------------------------------------------- methods for Person
	std::string obtenirNP() { return _prenom+" "+_nom;}
	virtual int getNumberOfTitre() {return 0;}
};


#endif
