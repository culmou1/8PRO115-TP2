#ifndef HEADER_FILE
#define HEADER_FILE

class Person
{


protected:
    std:: string prenom;
    std:: string nom;

public:

    virtual Person();

    virtual ~Person() = default;
    virtual Person(const Person& other) = default;
    virtual Person(Person&& other) = default;
    virtual Person& operator=(const Person& other) = default;
    virtual Person& operator=(Person&& other) = default;
};

class Joueur : public Person {

protected:
    float taille;
    float poids;
    std::string emplacementNaissance;

public:

    
}





#endif
