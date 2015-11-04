#include "match.h"
#include "rencontre.h"
#include "periode.h"
#include "equipe.h"

Match::Match(Equipe *home, Equipe *visitor, Resultat score) :
    _locaux(home), _visiteurs(visitor), _resultatFinal(score) {}

Match::~Match(){};

//----------------------------------------------------------------- methods for Locaux
Equipe* Match::getLocaux(){
    return _locaux;
}

//----------------------------------------------------------------- methods for Locaux
Equipe* Match::getVisiteurs(){
    return _visiteurs;
}

void Match::setVisiteurs(Equipe *stranger){
    _visiteurs = stranger;
}

//----------------------------------------------------------------- methods for periodesJouees
VectorPer Match::getPeriodes() {
    return _periodesJouees;
}

void Match::setPeriodes(VectorPer half) {
    _periodesJouees.clear();
    for (unsigned int i = 0; i < half.size(); i++) {
        _periodesJouees.push_back(half[i]);
    }
}

//----------------------------------------------------------------- methods for resultat
Resultat Match::getResultat(){
    return _resultatFinal;
}

void Match::setResulat(int home, int visitor) {
    _resultatFinal.setButsLocaux(home);
    _resultatFinal.setButsVisiteurs(visitor);
}

//----------------------------------------------------------------- methods of Match
void Match::obtenirResulatFinal() {
    int home, visitor;
    for (unsigned int i = 0; i <_periodesJouees.size(); i++) {
        home += _periodesJouees[i]->getScore().getButsLocaux();
        visitor += _periodesJouees[i]->getScore().getButsVisiteurs();
    }
    Match::setResulat(home, visitor);
}
//----------------------------------------------------------------- methods of Teams
