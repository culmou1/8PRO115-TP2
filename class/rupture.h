#ifndef RUPTURE_H
#define RUPTURE_H
class Joueur;
class Club;


class Rupture {

private:
	Joueur 			*_joueurRelaxant;
	Club 			*_clubContractant;
	Raison	        _raisonsDuDepart;
	float 			_penalite;

public:
	Rupture(Joueur *player, Club *new_club, Raison why, float money) :
		_joueurRelaxant(player), _clubContractant(new_club), _raisonsDuDepart(why), _penalite(money) {}

    ~Rupture();
    Rupture(const Rupture& other);
    Rupture(Rupture&& other);
    Rupture& operator=(const Rupture& other);
    Rupture& operator=(Rupture&& other);

//----------------------------------------------------------------- methods for joueurRelaxant
    Joueur *getJoueurRelaxant() {
    	return _joueurRelaxant;
    }

    void setJoueurRelaxant(Joueur *newbie) {
    	_joueurRelaxant = newbie;
    }

//----------------------------------------------------------------- methods for clubContractant
    Club *getClubContractant() {
    	return _clubContractant;
    }

    void setClubContractant(Club *new_club) {
    	_clubContractant = new_club;
    }
//----------------------------------------------------------------- methods for raisonsDuDepart
    Raison getRaisonsDuDepart() {
    	return _raisonsDuDepart;
    }

    void setRaisonsDuDepart(Raison raisons) {
    	_raisonsDuDepart = raisons;
    }

//----------------------------------------------------------------- methods for penalite
    float getPenalite() {
    	return _penalite;
    }

    void setPenalite(float cost)  {
    	_penalite = cost;
    }

};

#endif
