
#ifndef RUPTURE_H
#define RUPTURE_H
class Joueur;
class Club;
class Rupture {

private:
	Joueur 			*_joueurRelaxant;
	Club 			*_clubContractant;
	std::string	    _raisonsDuDepart;
	double 			_penalite;

public:
	Rupture(Joueur *player, Club *new_club, std::string why, double money) :
		_joueurRelaxant(player), _clubContractant(new_club), _raisonsDuDepart(why), _penalite(money) {}

	~Rupture() {}

    Rupture(const Rupture& other) :
		_joueurRelaxant(other._joueurRelaxant), _clubContractant(other._clubContractant), _raisonsDuDepart(other._raisonsDuDepart), _penalite(other._penalite) {}

    Rupture& operator=(Rupture&& other) {
		_joueurRelaxant=other._joueurRelaxant; _clubContractant=other._clubContractant; _raisonsDuDepart=other._raisonsDuDepart; _penalite=other._penalite;
		return *this;
	}

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
    std::string getRaisonsDuDepart() {
    	return _raisonsDuDepart;
    }

    void setRaisonsDuDepart(std::string raisons) {
    	_raisonsDuDepart = raisons;
    }

//----------------------------------------------------------------- methods for penalite
    double getPenalite() {
    	return _penalite;
    }

    void setPenalite(double cost)  {
    	_penalite = cost;
    }

};

#endif
