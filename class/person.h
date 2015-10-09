#ifndef HEADER_FILE
#define HEADER_FILE

//http://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
#include <ctime>
#include list


typedef std::list<typeof> nameTitle;

enum Role {

    Entraineur,
    JoueurAutonome,
    JoueurNonAutonome,
    Manageur,
    Secretaire,
    Recruteur,
    Infirmier
}



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


        std::string getFirstName = function(){

            return std::string prenom;
        }

        std::string setFirstName = function(firstName){

            std::string prenom = firstName;

        }


        std::string getLastName = function(){

            return std::string nom;
        }

        std::string setLastName = function(lastName){

            std::string prenom = lastName;

        }

        std::string getTaile = function(){

            return taille;
        }

        std::string setTaile = function(float grandeur){

            taille = grandeur;

        }
        std::string getPoids = function(){

            return poids;
        }

        std::string setPoids = function(float grosseur){

            poids = grosseur;

        }
        std::string getEmplacementNaissance = function(){

            return std::string emplacementNaissance;
        }

        std::string setEmplacementNaissance = function(std::string birthDay){

            std::string emplacementNaissance = birthDay;

        }


}

class Entraineur : public Person{

protected:

    std::string placeGrade;
    std::string
    std::nameTitle(null)
public:

        std::string getFirstName = function(){

            return std::string prenom;
        }

        std::string setFirstName = function(firstName){

            std::string prenom = firstName;

        }


        std::string getLastName = function(){

            return std::string nom;
        }

        std::string setLastName = function(lastName){

            std::string prenom = lastName;

        }





}

#endif
