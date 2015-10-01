#ifdef CLUB_H
#define CLUB_H

#include string
#include vector
#include "person.h"
#include "palmares.h"

typedef set::vector <int> Date;

class Club {

private : 
	std::string HistoireDuClub;
	std::string CouleurDuClub;
	Date AnneeDeCreation;
	Joueur Effectif;
	std::vector <Palmares> unPalmares;
	std::string VilleDuClub;
	std::vector <Person> StaffTechnique; 

public :
    Club();

    ~Club() = default;
    Club(const Club& other) = default;
    Club(Club&& other) = default;
    Club& operator=(const Club& other) = default;
    Club& operator=(Club&& other) = default;

};

#endif