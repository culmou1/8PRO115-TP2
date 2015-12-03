#include "contrat.h"
#include "person.h"
#include "club.h"


//----------------------------------------------------------------- Constructeur
Contrat::Contrat() {}

Contrat::Contrat(Joueur *joueurContractant,Club *clubContractant,Club *clubLibere, int duree,
		std::string datedEntree,std::string dateDuContrat,double montant, std::string droit):
				_joueurContractant(joueurContractant),_clubContractant(clubContractant), _clubLibere(clubLibere),_dureeContrat(duree),
				_datedEntree(To_Date(datedEntree)),_dateDuContrat(To_Date(dateDuContrat)), _reglement(montant, droit) {}

// Constructeur lorsque le Joueur n'a pas d'ancienne equipe. Nous Donnons un Pointeur Null au Club libere.
// Pas Besoin d'envoyer un Pointeur NUll. Il va le faire automatiquement
Contrat::Contrat(Joueur *joueurContractant,Club *clubContractant, int duree,
			std::string datedEntree,std::string dateDuContrat,double montant, std::string droit):
				_joueurContractant(joueurContractant),_clubContractant(clubContractant), _clubLibere(NULL),_dureeContrat(duree),
					_datedEntree(To_Date(datedEntree)),_dateDuContrat(To_Date(dateDuContrat)), _reglement(montant, droit) {}

//---------------------------------------------------------------- Destructeur
Contrat::~Contrat() {}

//---------------------------------------------------------------- Constructeur de recopie
Contrat::Contrat(const Contrat& other) :
	_joueurContractant(other._joueurContractant), _clubContractant(other._clubContractant), _clubLibere(other._clubLibere),
	_dureeContrat(other._dureeContrat), _datedEntree(other._datedEntree), _dateDuContrat(other._dateDuContrat), _reglement(other._reglement) {}

//---------------------------------------------------------------- Operateur d'affectation
Contrat& Contrat::operator=(Contrat&& other) {
	_joueurContractant=other._joueurContractant; _clubContractant=other._clubContractant; _clubLibere=other._clubLibere;
	_dureeContrat=other._dureeContrat; _datedEntree=other._datedEntree; _dateDuContrat=other._dateDuContrat; _reglement=other._reglement;
	return *this;
}

//---------------------------------------------------------------- methods for joueurContractant
Joueur* Contrat::getJoueurContractant() {
    return _joueurContractant;
}

void Contrat::setJoueurContractant(Joueur *newbie) {
    _joueurContractant = newbie;
}

//---------------------------------------------------------------- methods for clubContractant
Club* Contrat::getClubContractant() {
    return _clubContractant;
}

void Contrat::setClubContractant(Club *new_club) {
    _clubContractant = new_club;
}

//---------------------------------------------------------------- methods for clubLibere
Club* Contrat::getClubLibere() {
    return _clubLibere;
}

void Contrat::setClubLibere(Club *old_club) {
    _clubLibere = old_club;
}

//---------------------------------------------------------------- methods for dureeContrat
int Contrat::getDureeContrat() {
    return _dureeContrat;
}

void Contrat::setDureeContrat(int duree) {
    _dureeContrat = duree;
}

//---------------------------------------------------------------- methods for datedEntree
Date Contrat::getDatedEntree() {
    return _datedEntree;
}

void Contrat::setDatedEntree(Date entree) {
    _datedEntree = entree;
}

//---------------------------------------------------------------- methods for dateDuContrat
Date Contrat::getDateDuContrat() {
    return _dateDuContrat;
}

void Contrat::setDateDuContrat(int d_day, int m_month,int y_year) {
_dateDuContrat.tm_day = d_day;
_dateDuContrat.tm_month = m_month;
_dateDuContrat.tm_year = y_year;
}

//---------------------------------------------------------------- methods of reglement
Reglement* Contrat::getReglement() {
	return &_reglement;
}

void Contrat::setReglement(double montantT, std::string droit) {
_reglement = Reglement(montantT, droit);
}

Date Contrat::getDatedEcheance() {
	Date echeance; echeance.Create(_dateDuContrat.tm_day, _dateDuContrat.tm_month, _dateDuContrat.tm_year+_dureeContrat);
	return echeance;
}
