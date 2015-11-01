#ifndef HEADER_FILE
#define HEADER_FILE

//http://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
#include list
#include "palmares.h"

typedef std::vector<Palmares> VectorPal; // Une ensemble de vecteur de type Palmares


class Person
{


protected:
    std::string _prenom;
    std::string _nom;
    Role _role;

public:

    virtual Person();

    virtual ~Person() = default;
    virtual Person(const Person& other) = default;
    virtual Person(Person&& other) = default;
    virtual Person& operator=(const Person& other) = default;
    virtual Person& operator=(Person&& other) = default;


    virtual std::string getFirstName(){

        return _prenom;
    }

    virtual void setFirstName(std::string firstName){

            _prenom = firstName;

    }


    virtual std::string getLastName(){

        return _nom;
    }

    virtual void setLastName(std::lastName){

        _prenom = lastName;

    }

};

class Joueur : public Person {

protected:
    float _taille;
    float _poids;
    std::string _emplacementNaissance;

public:

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
        float getPoids(){

            return _poids;
        }

        void setPoids(float grosseur){

            _poids = grosseur;

        }
        std::string getEmplacementNaissance(){

            return std::string _emplacementNaissance;
        }

        void setEmplacementNaissance(std::string birthDay){

            _emplacementNaissance = birthDay;

        }


};

class Entraineur : public Person{

protected:

    std::string _placeGrade;
    VectorPal _TitreGagne;
public:

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

};

#endif
