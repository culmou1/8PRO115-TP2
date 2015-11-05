#include "person.h"
#include "club.h"
#include "rupture.h"
#include "contrat.h"
#include "palmares.h"
#include "ligue.h"

//----------------------------------------------------------------- obtenirNP
std::string Person::obtenirNP() {
	return _prenom+" "+_nom;
}

//----------------------------------------------------------------- RompreSonContrat
void Joueur_Autonome::RompreSonContrat(Contrat* leContrat){
	std::string raisonDuDepart, choisirClub;
    double penalite;

	//Creation de la rupture
    if(this == leContrat->getJoueurContractant())
	{
        std::cout << "*******************ROMPRE LE CONTRAT DU JOUEUR*******************" << std::endl;
        std::cout << std::endl <<  "//		RAISON DU DEPART : "; std::cin >> raisonDuDepart;
        std::cout << std::endl <<  "//		PENALITE DE DEPART : "; std::cin >> penalite;
		std::cout << std::endl << "//		CHOISIR NOUVELLE EQUIPE : ";  std::cin >> choisirClub; //choix de la couleur du Club

		Club *newClub = leContrat->getClubContractant()->getLigue()->RechercherClub(choisirClub);

        // Construction de la rupture
		Rupture* newRupture = new Rupture(this,newClub,raisonDuDepart,penalite);
		leContrat->getClubContractant()->addRuptureDeContrats(newRupture);

		//Creation du nouveau contrat du joueur
		leContrat->getClubContractant()->TransfertJoueur(this, newClub);
	}
    else 
	{
		std::cout << "Le joueur " << obtenirNP() << " n'a pas de contrat." << std::endl;
    }
}

//-----------------------------------------------------------------addTitreGagne
void Entraineur::addTitreGagne(TitreGagne* titre) {
	_titreGagne.push_back(titre);
}

//-----------------------------------------------------------------afficherTitreGagne
void Entraineur::afficherTitreGagne(){
    for (unsigned int i = 0; i < _titreGagne.size();i++){
		std::cout << "Voici la Position du TitreGagne: " << i << " - "<< getTextForTitre(_titreGagne[i]->getTitre()) << std::endl;
    }
}

//-----------------------------------------------------------------selectTitreGagne
Palmares* Entraineur::selectTitreGagne(int j){
    for(unsigned int i = 0; i < _titreGagne.size();i++){
        if (_titreGagne[j]==_titreGagne[i])
            return _titreGagne[i];
    }
	std::cout << "Le Titre selectionne n\'existe pas" << std::endl;
	return NULL;
}

//-----------------------------------------------------------------getNumberOfTitre
int Entraineur::getNumberOfTitre(){
    return _titreGagne.size();
}

//-----------------------------------------------------------------deleteTitreGagne
void Entraineur::deleteTitreGagne(std::string date) {
	for(unsigned int i=0; i<_titreGagne.size(); i++) {
		if (_titreGagne[i]->getDate() == To_Date(date)) {
			delete _titreGagne[i];
			_titreGagne.erase(_titreGagne.begin()+i);
		}
	}
}
