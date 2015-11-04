#include "calendrier.h"
#include "club.h"
#include "rencontre.h"
#include "match.h"
#include <string>


Calendrier::Calendrier(){}

Calendrier::~Calendrier(){}


VectorRen Calendrier::getAllRencontre(){
    return _rencontre;
}

void Calendrier::addRencontre(Rencontre* game) {
    _rencontre.push_back(game);
}

void Calendrier::getAllRencontreForAwayClub(Club *club){
    for(unsigned int i=0;i<_rencontre.size();i++)
    {
        if(_rencontre[i]->getMatch()->getVisiteurs()->getClub() == club)
        {
            std::cout << std::endl << "Visiteur : ";
            _rencontre[i]->getMatchAndGame();
        }
        else {
                std::cerr<< "Il n\'y a aucune Rencontre Pour ce Club en tant que Visiteur" << std::endl;

        }
    }
}

void Calendrier::getAllRencontreForHomeClub(Club *club){
    for(unsigned int i=0;i<_rencontre.size();i++){
        if(_rencontre[i]->getMatch()->getLocaux()->getClub() == club){
            std::cout << std::endl << "Domicile : ";
            _rencontre[i]->getMatchAndGame();
        }
        else {
            std::cerr<<"Il n\'y a aucune Rencontre Pour ce Club a Domicile" << std::endl;
        }
    }
}

void Calendrier::getAllRencontre(Club *club){
    try
    {
        getAllRencontreForHomeClub(club);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        getAllRencontreForAwayClub(club);
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() <<std::endl;
    }
}
