#ifndef CALENDRIER_H
#define CALENDRIER_H

#include "rencontre.h"

typedef std::vector<Rencontre*> 	VectorRen; // Une ensemble de vecteur de type Contract

class Calendrier
{
    VectorRen *_rencontre;
public:
    Calendrier();

    ~Calendrier() = default;
    Calendrier(const Calendrier& other) = default;
    Calendrier(Calendrier&& other) = default;
    Calendrier& operator=(const Calendrier& other) = default;
    Calendrier& operator=(Calendrier&& other) = default;


    VectorRen getRencontre(){
        for(int i = 0;i > _rencontre.size();i++){

        }

    }
};





#endif
