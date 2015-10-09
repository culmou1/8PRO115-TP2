#ifndef HEADER_FILE
#define HEADER_FILE

//http://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
#include list
#include "palmares.h"

typedef std::vector<Palmares> VectorPal; // Une ensemble de vecteur de type Palmares


class Person
{


protected:
    std::string prenom;
    std::string nom;
    Role role;

public:

    virtual Person();

    virtual ~Person() = default;
    virtual Person(const Person& other) = default;
    virtual Person(Person&& other) = default;
    virtual Person& operator=(const Person& other) = default;
    virtual Person& operator=(Person&& other) = default;


    virtual std::string getFirstName = function(){

        return std::string prenom;
    }

    virtual std::string setFirstName = function(std::firstName){

        std::string prenom = firstName;

    }


    virtual std::string getLastName = function(){

        return std::string nom;
    }

    virtual std::string setLastName = function(std::lastName){

        std::string prenom = lastName;

    }

};

class Joueur : public Person {

protected:
    float taille;
    float poids;
    std::string emplacementNaissance;

public:


        std::string getFirstName(){

            return std::string prenom;
        }

        void setFirstName(std::string firstName){

            prenom = firstName;

        }


        std::string getLastName(){

            return std::string nom;
        }

        void setLastName(lastName){

           prenom = lastName;

        }

        float getTaile(){

            return taille;
        }

        void setTaile(float grandeur){

            taille = grandeur;

        }
        float getPoids = function(){

            return poids;
        }

        void setPoids(float grosseur){

            poids = grosseur;

        }
        std::string getEmplacementNaissance(){

            return std::string emplacementNaissance;
        }

        void setEmplacementNaissance = function(std::string birthDay){

            emplacementNaissance = birthDay;

        }


};

class Entraineur : public Person{

protected:

    std::string placeGrade;
    VectorPal TitreGagne;
public:

        void getFirstName(){

            return std::string prenom;
        }

        std::string setFirstName(std::string firstName){

           prenom = firstName;

        }


        void getLastName = function(){

            return std::string nom;
        }

        void setLastName = function(std::string lastName){

            std::string prenom = lastName;

        }

        std::string getGrade = function(){

            return std::string grade;
        }

        void setGrade = function(std::string Grade){

            std::string placeGrade = Grade;

};

#endif
