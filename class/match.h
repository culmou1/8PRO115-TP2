#ifdef 	MATCH_H
#define	MATCH_H

typedef std::vector<Periode> VectorPrd;

class Match
{
private:
	Equipe 					equipeLocale;
	Equipe 					equipeInvitee;
	VectorPrd			 	*periodesJouees;
	Resultat 				resultatFinal;

public:
    Match();

    ~Match() = default;
    Match(const Match& other) = default;
    Match(Match&& other) = default;
    Match& operator=(const Match& other) = default;
    Match& operator=(Match&& other) = default;

//----------------------------------------------------------------- methods for equipeLocale
    Equipe getEquipeLocale() { return equipeLocale;}

    void setEquipeLocale(Equipe localteam) { equipeLocale = localteam;}

//----------------------------------------------------------------- methods for equipeInvitee
    Equipe getEquipeInvitee() { return equipeInvitee;}

    void setEquipeInvitee(Equipe visitorteam) { equipeInvitee = localteam;}

//----------------------------------------------------------------- methods for periodesJouees
	void getPeriodesJouees(VectorPrd &periodes) {
		for (int i = 0; i < periodesJouees.size(); i++) {
			periodes[i] = periodesJouees[i];
		}
	}

	void setPeriodesJouees(VectorPrd *periodes) {
		periodesJouees->clear();
		for (int i = 0; i < periodes->size(); i++) {
			periodesJouees->push_back(periodes[i]);
		}	
	}

//----------------------------------------------------------------- methods for periodesJouees
	Resultat getResultatFinal() { return resultatFinal;}

	void setResultatFinal(Resultat score) { resultatFinal = score;}
	
};

#endif
