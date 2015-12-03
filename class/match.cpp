#include "match.h"
#include "periode.h"
#include "equipe.h"
#include "club.h"
#include "utils.h"


//---------------------------------------------------------------- Constructeurs
Match::Match()  {}

Match::Match(Club *home, Club *visitor) : _resultatFinal(RandomInt(8),RandomInt(8)) {
	_locaux = new Equipe(home, 18, 2, home->getEffectif()->at(0));
	_visiteurs = new Equipe(visitor, 18, 2, visitor->getEffectif()->at(0));
}

Match::Match(Club *home, Club *visitor, int butL, int butV) : _resultatFinal(butL,butV) {
	_locaux = new Equipe(home, 18, 2, home->getEffectif()->at(0));
	_visiteurs = new Equipe(visitor, 18, 2, visitor->getEffectif()->at(0));
}

//---------------------------------------------------------------- Destructeur
Match::~Match() {
	delete _locaux;
	delete _visiteurs;
}

//---------------------------------------------------------------- Constructeur de recopie
Match::Match(const Match& other) :
	_locaux(other._locaux), _visiteurs(other._visiteurs), _periodesJouees(other._periodesJouees), _resultatFinal(other._resultatFinal) {}

//---------------------------------------------------------------- Operateur d'affectation
Match& Match::operator=(Match&& other) {
	_locaux=other._locaux; _visiteurs=other._visiteurs; _periodesJouees=other._periodesJouees; _resultatFinal=other._resultatFinal;
	return *this;
}

//---------------------------------------------------------------- methods for Locaux
Equipe* Match::getLocaux(){
    return _locaux;
}

void Match::setLocaux(Equipe *home){
    _locaux = home;
}

//---------------------------------------------------------------- methods for Visiteurs
Equipe* Match::getVisiteurs(){
    return _visiteurs;
}

void Match::setVisiteurs(Equipe *stranger){
    _visiteurs = stranger;
}

//---------------------------------------------------------------- methods for periodesJouees
VectorPer Match::getPeriodes() {
	return _periodesJouees;
}

void Match::setPeriodes(VectorPer half) {
	_periodesJouees.clear();
	for (unsigned int i = 0; i < half.size(); i++) {
		_periodesJouees.push_back(half[i]);
	}
}

//---------------------------------------------------------------- methods for resultat
Resultat Match::getResultat(){
	return _resultatFinal;
}

void Match::setResulat(int home, int visitor) {
_resultatFinal.setButsLocaux(home);
_resultatFinal.setButsVisiteurs(visitor);
}

//---------------------------------------------------------------- methods of Match
void Match::obtenirResulatFinal() {
    int home=0, visitor=0;
    for (unsigned int i = 0; i <_periodesJouees.size(); i++) { // Regarde tout les periodes et additionne les resultats
        home += _periodesJouees[i]->getScore().getButsLocaux();
        visitor += _periodesJouees[i]->getScore().getButsVisiteurs();
    }
    setResulat(home, visitor);
}
