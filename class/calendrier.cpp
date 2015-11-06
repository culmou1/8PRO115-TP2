#include "calendrier.h"
#include "club.h"
#include "rencontre.h"
#include "match.h"
#include "equipe.h"
#include <string>
#include <stdexcept>


//----------------------------------------------------------------- Constructeur
Calendrier::Calendrier(){}

//----------------------------------------------------------------- Destructeur
Calendrier::~Calendrier(){
	//Supprime les rencontres du calendrier
	for(unsigned int i=0; i<_rencontres.size(); i++) {
		delete _rencontres[i];
	}
	_rencontres.clear();
}

//----------------------------------------------------------------- Constructeur de recopie
Calendrier::Calendrier(const Calendrier& other) : _rencontres(other._rencontres) {}

//----------------------------------------------------------------- Operateur d'affectation
Calendrier& Calendrier::operator=(Calendrier&& other) {
	_rencontres=other._rencontres;
	return *this;
}

//----------------------------------------------------------------- addRencontre
void Calendrier::addRencontre(Rencontre* game) {
    _rencontres.push_back(game);
}

//----------------------------------------------------------------- rechercherAfficherResultat
void Calendrier::AfficherResultat(Club *club, std::string date) {
    for(unsigned int i=0;i<_rencontres.size();i++)
    {
		if(_rencontres[i]->getMatch()->getLocaux()->getClub() == club || _rencontres[i]->getMatch()->getVisiteurs()->getClub() == club)
			std::cout << "Resultat : ";  _rencontres[i]->resultatAUneDateDonne(date);
    }
}

//----------------------------------------------------------------- AfficherRencontreForAwayClub
void Calendrier::AfficherRencontreForAwayClub(Club *club){
    for(unsigned int i=0;i<_rencontres.size();i++)
    {
        if(_rencontres[i]->getMatch()->getVisiteurs()->getClub() == club)
        {
            std::cout << "Visiteur : ";
            _rencontres[i]->getMatchAndGame() ;
        }
    }
}

//----------------------------------------------------------------- AfficherRencontreForHomeClub
void Calendrier::AfficherRencontreForHomeClub(Club *club){
    for(unsigned int i=0;i<_rencontres.size();i++)
	{
        if(_rencontres[i]->getMatch()->getLocaux()->getClub() == club)
		{
            std::cout << "Domicile : ";
            _rencontres[i]->getMatchAndGame();
        }
    }
}


