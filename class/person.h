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
    std::string
    std::nameTitle(null)
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

        std::string setLastName = function(lastName){

            std::string prenom = lastName;

        }





};

#endif
