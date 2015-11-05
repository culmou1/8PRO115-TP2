#include "contrat.h"
#include "person.h"
#include "club.h"


//----------------------------------------------------------------- Constructeur
Contrat::Contrat(Joueur *joueurContractant,Club *clubContractant,Club *clubLibere, int duree,
		std::string datedEntree,std::string dateDuContrat,double montant, std::string droit):
				_joueurContractant(joueurContractant),_clubContractant(clubContractant), _clubLibere(clubLibere),_dureeContrat(duree),
				_datedEntree(To_Date(datedEntree)),_dateDuContrat(To_Date(dateDuContrat)), _reglement(montant, droit) {}

// Constructeur lorsque le Joueur n'a pas d'ancienne Équipe. Nous Donnons un Pointeur Null au Club libere.
// Pas Besoin d'envoyer un Pointeur NUll. Il va le faire automatiquement
Contrat::Contrat(Joueur *joueurContractant,Club *clubContractant, int duree,
			std::string datedEntree,std::string dateDuContrat,double montant, std::string droit):
				_joueurContractant(joueurContractant),_clubContractant(clubContractant), _clubLibere(NULL),_dureeContrat(duree),
					_datedEntree(To_Date(datedEntree)),_dateDuContrat(To_Date(dateDuContrat)), _reglement(montant, droit) {}

//----------------------------------------------------------------- Destructeur
Contrat::~Contrat() {
	delete _joueurContractant;
	delete _clubContractant;
	delete _clubLibere;
}

//----------------------------------------------------------------- Constructeur de recopie
Contrat::Contrat(const Contrat& other) : 
	_joueurContractant(other._joueurContractant), _clubContractant(other._clubContractant), _clubLibere(other._clubLibere),
	_dureeContrat(other._dureeContrat), _datedEntree(other._datedEntree), _dateDuContrat(other._dateDuContrat), _reglement(other._reglement) {}

//----------------------------------------------------------------- Operateur d'affectation
Contrat& Contrat::operator=(Contrat&& other) {
	_joueurContractant=other._joueurContractant; _clubContractant=other._clubContractant; _clubLibere=other._clubLibere;
	_dureeContrat=other._dureeContrat; _datedEntree=other._datedEntree; _dateDuContrat=other._dateDuContrat; _reglement=other._reglement; 
	return *this;
}

//----------------------------------------------------------------- methods of dateDuContrat
void Contrat::setDateDuContrat(int d_day, int m_month,int y_year) {
	_dateDuContrat.tm_day = d_day;
	_dateDuContrat.tm_month = m_month;
	_dateDuContrat.tm_year = y_year;
}

//----------------------------------------------------------------- methods of reglement
void Contrat::setReglement(double montantT, std::string droit) {
	_reglement = Reglement(montantT, droit);
}