#ifndef PALMARES_H
#define PALMARES_H

#include <string>
#include "utils.h"

class Club;

/**
 *  Un Palmares est un titre (une coupe, ou un championnat)
 *  obtenu par un club a une certaine date donnee.
 */
class Palmares {

protected:
    Date _date; // Date
    Titre _titre; // titre

public:
/**
* @params Constructeur par defaut
*/
	Palmares() {}
/**
* @params Constructeur
*/
    Palmares(std::string day, Titre trophy) :
		_date(To_Date(day)), _titre(trophy) {}
/**
* @params Destructeur
*/
	~Palmares() {}
/**
* @params Constructeur de recopie
*/
	Palmares(const Palmares& other) : _date(other._date), _titre(other._titre) {}
/**
* @params Operateur d'affectation
*/
    Palmares& operator=(Palmares&& other) {
		_date=other._date; _titre=other._titre;
		return *this;
	}
//---------------------------------------------------------------- methods of date
/**
* @params Retourne la date
*/
    Date getDate(){
        return _date;
    }
/**
* @params Modifie la date
*/
    void setDate(int day, int month, int year){
        _date.tm_day = day;
        _date.tm_month = month;
        _date.tm_year = year;
    }

//---------------------------------------------------------------- methods of titre
/**
* @params Retourne le Titre
*/
    Titre getTitre(){
        return _titre;
    }
/**
* @params Modifie le Titre
*/
    void setTitre(Titre choix){
		_titre = choix;
    }
};

/**
  * Palmarès, auquel on ajoute le club avec lequel 
  * l'entraineur a gagne le titre en question.
  */
class TitreGagne : public Palmares {

private:
    Club  *_club;

public:
/**
* @params Constructeur par defaut
*/
	TitreGagne() {}
/**
* @params Constructeur
*/
    TitreGagne(Club *team, std::string day, Titre trophy) :
		_club(team), Palmares(day, trophy) {}
/**
* @params Destructeur
*/
	~TitreGagne() {}
/**
* @params Constructeur de recopie
*/
    TitreGagne(const TitreGagne& other) : Palmares(other), _club(other._club) {}
/**
* @params Operateur d'affectation
*/
    TitreGagne& operator=(TitreGagne&& other) {
		Palmares *a, *b;
		a = this;
		b = &other;
		*a = *b;
        _club = other._club;
		return *this;
	}

//---------------------------------------------------------------- methods of club
/**
* @params Retourne le Club
*/
    Club *getClub() {
        return _club;
    }
/**
* @params Modifie le Club
*/
    void setClub(Club *other){
        _club = other;
    }
};

#endif
