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

//----------------------------------------------------------------- AfficherRencontreForAwayClub
void Calendrier::AfficherRencontreForAwayClub(Club *club){
    for(unsigned int i=0;i<_rencontres.size();i++)
    {
        if(_rencontres[i]->getMatch()->getVisiteurs()->getClub() == club)
        {
            std::cout << std::endl << "Visiteur : ";
            _rencontres[i]->getMatchAndGame();
        }
        else
			std::cerr<< "Il n\'y a aucune Rencontre Pour ce Club en tant que Visiteur" << std::endl;
    }
}

//----------------------------------------------------------------- AfficherRencontreForHomeClub
void Calendrier::AfficherRencontreForHomeClub(Club *club){
    for(unsigned int i=0;i<_rencontres.size();i++){
        if(_rencontres[i]->getMatch()->getLocaux()->getClub() == club)
		{
            std::cout << std::endl << "Domicile : ";
            _rencontres[i]->getMatchAndGame();
        }
        else 
            std::cerr<<"Il n\'y a aucune Rencontre Pour ce Club a Domicile" << std::endl;
    }
}

//----------------------------------------------------------------- AfficherRencontre
void Calendrier::AfficherRencontre(Club *club){
    try
    {
       AfficherRencontreForHomeClub(club);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        AfficherRencontreForAwayClub(club);
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() <<std::endl;
    }
}
