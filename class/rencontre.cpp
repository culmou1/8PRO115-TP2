#include "rencontre.h"
#include "match.h"
#include "equipe.h"
#include "resultat.h"
#include "utils.h"

//----------------------------------------------------------------- Constructeur
Rencontre::Rencontre(Club* home, Club* away, std::string date) : _match(CreerMatch(home,away)), _dateDeRencontre(To_Date(date)) {}

//----------------------------------------------------------------- Destructeur
Rencontre::~Rencontre() {
	delete _match; 
}

//----------------------------------------------------------------- Constructeur de recopie
Rencontre::Rencontre(const Rencontre& other) : 
	_match(other._match), _dateDeRencontre(other._dateDeRencontre) {}

//----------------------------------------------------------------- Operateur d'affectation
Rencontre& Rencontre::operator=(Rencontre&& other) {
	_match=other._match; _dateDeRencontre=other._dateDeRencontre;
	return *this;
}

//----------------------------------------------------------------- getMatchAndGame
void Rencontre::getMatchAndGame(){
	std::cout << _dateDeRencontre.To_String() << "/ " << _match->getCouleurClub(_match->getLocaux()) << " vs. "
        << _match->getCouleurClub(_match->getVisiteurs()) << std::endl;
}

//----------------------------------------------------------------- CreerMatch
/* Ajout des matchs Entre des Équipes */
Match* Rencontre::CreerMatch(Club* home, Club* away) {
		Equipe* locaux = new Equipe(home, 18, 2, home->getEffectif()[0]);
		Equipe* visiteurs = new Equipe(away, 18, 2, away->getEffectif()[0]);

		Match* newMatch = new Match(locaux, visiteurs);
		return newMatch;
	}

//----------------------------------------------------------------- resultatAUneDateDonne
void Rencontre::resultatAUneDateDonne(std::string date){
    if (To_Date(date) == _dateDeRencontre){
		std::cout << _match->getCouleurClub(_match->getLocaux()) << _match->getResultat().getButsLocaux() 
			<< " - " << _match->getCouleurClub(_match->getVisiteurs()) << _match->getResultat().getButsVisiteurs() << std::endl;
    }
}
