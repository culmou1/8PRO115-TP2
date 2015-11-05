#include "rencontre.h"
#include "calendrier.h"
#include "match.h"
#include "equipe.h"
#include "utils.h"

//----------------------------------------------------------------- Constructeur
Rencontre::Rencontre(Match *game, std::string date) : _match(game), _dateDeRencontre(To_Date(date))
{
    _calendrier->addRencontre(this);
}

//----------------------------------------------------------------- Destructeur
Rencontre::~Rencontre() {
	delete _match; 
	delete _calendrier;
}

//----------------------------------------------------------------- Constructeur de recopie
Rencontre::Rencontre(const Rencontre& other) : 
	_match(other._match), _dateDeRencontre(other._dateDeRencontre), _calendrier(other._calendrier) {}

//----------------------------------------------------------------- Operateur d'affectation
Rencontre& Rencontre::operator=(Rencontre&& other) {
	_match=other._match; _dateDeRencontre=other._dateDeRencontre; _calendrier=other._calendrier;
	return *this;
}

//----------------------------------------------------------------- getMatchAndGame
void Rencontre::getMatchAndGame(){
	std::cout << _dateDeRencontre.To_String() << "/ " << _match->getCouleurClub(_match->getLocaux()) << " vs. "
        << _match->getCouleurClub(_match->getVisiteurs()) << std::endl;
}

//----------------------------------------------------------------- methods for Add Match

/* Ajout des matchs Entre des Équipes */

//----------------------------------------------------------------- methods for affichage

/*double Rencontre::resultatAUneDateDonne(std::string date){
    if (To_Date(date) == _dateDeRencontre)){
        _match->getResultat();
    }
}*/
