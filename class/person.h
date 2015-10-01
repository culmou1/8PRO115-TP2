#ifndef HEADER_FILE
#define HEADER_FILE


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

    virtual std::string setFirstName = function(firstName){

        std::string prenom = firstName;

    }


    virtual std::string getLastName = function(){

        return std::string nom;
    }

    virtual std::string setLastName = function(lastName){

        std::string prenom = lastName;

    }

};

class Joueur : public Person {

protected:
    float taille;
    float poids;
    std::string emplacementNaissance;

public:


}

class Entraineur :Person





#endif
