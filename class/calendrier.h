#ifndef CALENDRIER_H
#define CALENDRIER_H

#include "rencontre.h"
#include <stdexcept>

typedef std::vector<Rencontre*> 	VectorRen; // Une ensemble de vecteur de type Contrat

class Calendrier
{
    VectorRen _rencontre;
public:
    Calendrier();

    ~Calendrier();
    Calendrier(const Calendrier& other);
    Calendrier(Calendrier&& other);
    Calendrier& operator=(const Calendrier& other);
    Calendrier& operator=(Calendrier&& other);


    VectorRen getAllRencontre(){
        for(int i = 0;i < _rencontre.size();i++){
            std::cout << _rencontre[i]->getMatch() << std::endl;
        }
    }
    void getAllRencontreForAwayClub(Club *club){
        for(int i=0;i<_rencontre.size();i++){
            if(_rencontre[i]->getMatch()->getVisiteurs()== club){
                _rencontre[i]->getMatchAndGame();
            }
            else {
                throw std::exception("Il n\'y a aucune Rencontre Pour ce Club en tant que Visiteur");

            }
        }
    }

    void getAllRencontreForHomeClub(Club *club){
        for(int i=0;i<_rencontre.size();i++){
            if(_rencontre[i]->getMatch()->getLocaux()== club){
                _rencontre[i]->getMatchAndGame();
            }
            else {
                throw std::exception("Il n\'y a aucune Rencontre Pour ce Club en tant que Visiteur");
            }
        }
    }

    void getAllRenontre(Club *club){
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
};





#endif
