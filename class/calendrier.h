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
        for(int i = 0;i < _rencontre->size();i++){
            std::cout << _rencontre[i]->getMatch() << std::endl;
        }
    }
    void getAllRencontreForAwayClub(Club *club){
        for(int i=0;i<_rencontre->size();i++){
            if(_rencontre[i]->getMatch()->getVisiteurs()== club){
                _rencontre[i]->getMatchAndGame();
            }
        }
    }

    void getAllRencontreForHomeClub(Club *club){
        for(int i=0;i<_rencontre->size();i++){
            if(_rencontre[i]->getMatch()->getLocaux()== club){
                _rencontre[i]->getMatchAndGame();
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
            std::cerr << "Il n\'y a aucune Rencontre pour ce Club en tant que Locale" << std::endl;
        }
        try
        {
            getAllRencontreForAwayClub(club);
            throw std::logic_error("Il n\'y a aucune Rencontre Pour ce Club en tant que Visiteur")
        }
        catch (const std::exception & e)
        {
            std::cerr << e.what() <<std::endl;
            std::cerr << "Il n\'y a aucune Rencontre Pour ce Club en tant que Visiteur" << std::en
        }
    }
};





#endif
