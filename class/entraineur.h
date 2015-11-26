#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include "person.h"
#include <vector>

class Palmares;
class TitreGagne;

typedef std::vector<Palmares*> VectorPal;

class Entraineur : public Person{

protected:
    std::string _placeGrade;
    VectorPal	_titreGagne;

public:
	Entraineur();
    Entraineur(std::string prenom,std::string nom, int age, std::string place);
    virtual ~Entraineur();
    Entraineur(const Entraineur& other);
    virtual Entraineur& operator=(Entraineur& other);

//----------------------------------------------------------------- methods of placeGrade
    std::string getPlaceGrade();
    void setPlaceGrade(std::string Grade);

//----------------------------------------------------------------- methods of TitresGagnes
	VectorPal getTitreGagne();
	void addTitreGagne(TitreGagne* titre);
    void afficherTitreGagne();
    int getNumberOfTitre();

};


#endif