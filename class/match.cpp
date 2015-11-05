#include "match.h"
#include "periode.h"
#include "equipe.h"
#include "club.h"

//----------------------------------------------------------------- Constructeur
Match::Match(Equipe *home, Equipe *visitor, Resultat score) :
    _locaux(home), _visiteurs(visitor), _resultatFinal(score) {}

//----------------------------------------------------------------- Destructeur
Match::~Match() {
	delete _locaux;
	delete _visiteurs;
}

//----------------------------------------------------------------- Constructeur de recopie
Match::Match(const Match& other) :
	_locaux(other._locaux), _visiteurs(other._visiteurs), _periodesJouees(other._periodesJouees), _resultatFinal(other._resultatFinal) {}

//----------------------------------------------------------------- Operateur d'affectation


Match& Match::operator=(Match&& other) {
	_locaux=other._locaux; _visiteurs=other._visiteurs; _periodesJouees=other._periodesJouees; _resultatFinal=other._resultatFinal;
	return *this;
}

//----------------------------------------------------------------- methods for resultat
void Match::setResulat(int home, int visitor) {
    _resultatFinal.setButsLocaux(home);
    _resultatFinal.setButsVisiteurs(visitor);
}

//----------------------------------------------------------------- methods of Match
std::string Match::getCouleurClub(Equipe* team) {
	return team->getClub()->getCouleurDuClub();
}

void Match::obtenirResulatFinal() {
    int home=0, visitor=0;
    for (unsigned int i = 0; i <_periodesJouees.size(); i++) {
        home += _periodesJouees[i]->getScore().getButsLocaux();
        visitor += _periodesJouees[i]->getScore().getButsVisiteurs();
    }
    setResulat(home, visitor);
}
