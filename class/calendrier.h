#ifndef CALENDRIER_H
#define CALENDRIER_H

#include "rencontre.h"

typedef std::vector<Rencontre*> 	VectorRen; // Une ensemble de vecteur de type Contrat

class Calendrier
{
    VectorRen *_rencontre;
public:
    Calendrier();

    ~Calendrier();
    Calendrier(const Calendrier& other);
    Calendrier(Calendrier&& other);
    Calendrier& operator=(const Calendrier& other);
    Calendrier& operator=(Calendrier&& other);


    VectorRen getRencontre(){
        for(int i = 0;i > _rencontre->size();i++){

        }

    }
};





#endif
