#ifdef CONTRAT_H
#define CONTRAT_H

#include "club.h"

class Contract {

private :
	Joueur 	joueurContractant;
 	Club 	clubContractant;
 	Club 	clubLibere;
 	int 	dureeContrat;
 	Date 	datedEntree;
 	Date 	dateDuContrat;
 	float 	seuilTransfert;

public :
	Contract();

    ~Contract();
    Contract(const Contract& other) = default;
    Contract(Contract&& other) = default;
    Contract& operator=(const Contract& other) = default;
    Contract& operator=(Contract&& other) = default;

//----------------------------------------------------------------- methods for joueurContractant
    Joueur getJoueurContractant() {
    	return joueurContractant;
    }

    void setJoueurContractant(Joueur newbie) {
    	joueurContractant = newbie;
    }

//----------------------------------------------------------------- methods for clubContractant
    Club getClubContractant() {
    	return clubContractant;
    }

    void setClubContractant(Club new_club) {
    	clubContractant = new_club;
    }

//----------------------------------------------------------------- methods for clubLibere
    Club getClubLibere() {
    	return clubLibere;
    }

    void setClubLibere(Club old_club) {
    	clubLibere = old_club;
    }

//----------------------------------------------------------------- methods for dureeContrat
    int getDureeContrat() {
    	return dureeContrat;
    }

    void setDureeContrat(int duree) {
    	dureeContrat = duree;
    }

//----------------------------------------------------------------- methods for datedEntree
    Date getDatedEntree() {
    	return datedEntree;
    }

    void setDatedEntree(Date entree) {
    	datedEntree = entree;
    }

//----------------------------------------------------------------- methods for dateDuContrat
    Date getDateDuContrat() {
    	return dateDuContrat;
    }

    void setDateDuContrat(Date d_day) {
    	dateDuContrat = d_day;
    }

//----------------------------------------------------------------- methods of Contract
    void updateSeuilTransfert();
};



class Rupture {

private:
	Joueur 			joueurRelaxant;
	Club 			clubContractant;
	std::string 	raisonsDuDepart;
	float 			penalite;

public:
	Rupture();

    ~Rupture();
    Rupture(const Rupture& other) = default;
    Rupture(Rupture&& other) = default;
    Rupture& operator=(const Rupture& other) = default;
    Rupture& operator=(Rupture&& other) = default;

//----------------------------------------------------------------- methods for joueurRelaxant
    Joueur getJoueurRelaxant() {
    	return joueurRelaxant;
    }

    void setJoueurRelaxant(Joueur newbie) {
    	joueurRelaxant = newbie;
    }

//----------------------------------------------------------------- methods for clubContractant
    Club getClubContractant() {
    	return clubContractant;
    }

    void setClubContractant(Club new_club) {
    	clubContractant = new_club;
    }
//----------------------------------------------------------------- methods for raisonsDuDepart
    std::string getRaisonsDuDepart() {
    	return raisonsDuDepart;
    }

    void setRaisonsDuDepart(std::string raisons) {
    	raisonsDuDepart = raisons;
    }

//----------------------------------------------------------------- methods for penalite
    float getPenalite() {
    	return penalite;
    }

    void setPenalite(float cost)  {
    	penalite = cost;
    }

};


#endif
