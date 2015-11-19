#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "ecrans.h"
#include "Calendrier.h"
#include "Contrat.h"
#include "club.h"
#include "person.h"
#include "rencontre.h"
using namespace std;


void Ecran::afficherMenu()
{
	int choix=0;

	do{

		cout << "\n\n" << endl;
		cout << "*" << setfill('*') << setw(70) << "*" << endl;
		cout << "|	<1> - Ajouter un nouveau club." << endl;
		cout << "|	<2> - Supprimer un club." << endl;
		cout << "|	<3> - Afficher la liste des joueurs pour un club" << endl;
		cout << "|	<4> - Afficher le staff pour un club" << endl;
		cout << "|	<5> - Creer un nouveau joueur." << endl;
		cout << "|	<6> - Modifier un joueur." << endl;
		cout << "|	<7> - Supprimer un joueur." << endl;
		cout << "|	<8> - Afficher les clubs pour la ligue" << endl;
		cout << "|	<9> - Creer un calendrier pour la ligue" << endl;
		cout << "|	<10> - Afficher le calendrier de la ligue." << endl;
		cout << "|	<11> - Afficher le calendrier d'un club" << endl;
		cout << "|	<12> - Modifier une rencontre au calendrier." << endl;
		cout << "|	<13> - Creer une nouvelle rencontre." << endl;
		cout << "|	<14>- Afficher le resultat d'un match." << endl;
		cout << "|	<15> - Modifier le seuil de transfert." << endl;
		cout << "|	<16>- Transferer un joueur dans un nouveau club." << endl;
		cout << "|	<17>- Rompre le contrat d'un joueur avec un club." << endl;
		cout << "|	<18>- Afficher les montants des transferts pour un club." << endl;
		cout << "|	<19>- Afficher le montant total des transferts pour un club." << endl;
		cout << "|	<20>- Afficher l'entraineur ayant le plus de titres." << endl;
		cout << "|	<21>- Afficher le club ayant le plus de titres." << endl;
		cout << "|	<0>- Quitter." << endl;
		cout << "*" << setfill('*') << setw(70) << "*" << endl;
		cout << "\n\n" << endl;

		choix = getChoixUtilisateur();
		

	} while(choix!=0);

}

int Ecran::getChoixUtilisateur()
{
	int ret_choix=0;
	
	cout << "Entrer choix :";
	cin >> ret_choix;
	
	switch(ret_choix)
	{
	case 1:
		{
			std::cout << std::endl << "*******************CREATION D\'UN CLUB*******************" << std::endl;
			CreerClub();
			break;
		}
	case 2:
		{
			std::cout << std::endl << "*******************SUPPRESSION D\'UN CLUB*******************" << std::endl;
			SupprimerClub();
			break;
		}
	case 3:
		{
			std::cout << std::endl << "*******************AFFICHAGE LISTE DES JOUEURS DU CLUB******************* " << std::endl;
			AfficherEffectif();
			break;
		}
	case 4:
		{
			std::cout << std::endl << "*******************AFFICHAGE LISTE DU STAFF DU CLUB******************* " << std::endl;
			AfficherStaff();
			break;
		}
	case 5:
		{
			std::cout << std::endl << "*******************CREATION D\'UN JOUEUR*******************" << std::endl;
			CreerJoueur();
			break;
		}
	case 6:
		{
			std::cout << std::endl << "*******************MODIFICATION D\'UN JOUEUR*******************" << std::endl;
			ModifierJoueur();
			break;
		}
	case 7:
		{
			std::cout << std::endl << "*******************SUPPRESSION D\'UN JOUEUR*******************" << std::endl;
			SupprimerJoueur();
			break;
		}
	case 8:
		{
			std::cout << std::endl << "*******************AFFICHAGE LISTE DES CLUBS DE LA LIGUE*******************" << std::endl;
			AfficherClubs();
			break;
		}
	case 9:
		{
			std::cout << std::endl << "*******************CREATION DU CALENDRIER*******************" << std::endl;
			CreerCalendrierLigue();
			break;
		}
	case 10:
		{
			std::cout << std::endl << "*******************AFFICHAGE CALENDRIER DE LA LIGUE******************* " << std::endl;
			AfficherCalendrierLigue();
			break;
		}
	case 11:
		{
			std::cout << std::endl << "*******************AFFICHAGE CALENDRIER DU ClUB******************* " << std::endl;
			AfficherCalendrierClub();
			break;
		}
	case 12:
		{
			std::cout << std::endl << "*******************MODIFICATION D\'UNE RENCONTRE*******************" << std::endl;
			ModifierRencontre();
			break;
		}
	case 13:
		{
			std::cout << std::endl << "*******************CREATION D\'UNE RENCONTRE*******************" << std::endl;
			CreerRencontre();
			break;
		}
	case 14:
		{
			std::cout << std::endl << "*******************AFFICHAGE RESULTAT D\'UNE RENCONTRE*******************" << std::endl;
			AfficherResultat();
			break;
		}
	case 15:
		{
			std::cout << std::endl << "*******************MODIFICATION DU SEUIL DE TRANSFERT*******************" << std::endl;
			ModifierSeuil();
			break;
		}
	case 16:
		{
			std::cout << std::endl << "*******************TRANSFERT DU JOUEUR*******************" << std::endl;
			TransfertJoueur();
			break;
		}
	case 17:
		{
			std::cout << std::endl << "*******************ROMPRE LE CONTRAT DU JOUEUR*******************" << std::endl;
			RompreSonContrat();
			break;
		}
	case 18:
		{
			std::cout << std::endl << "*******************AFFICHAGE MONTANTS DES TRANSFERT D\'UN CLUB******************* " << std::endl;
			AfficherMontantTransferts();
			break;
		}
	case 19:
		{
			std::cout << std::endl << "*******************AFFICHAGE MONTANT TOTAL DES TRANSFERT D\'UN CLUB******************* " << std::endl;
			AfficherMontantTotal();
			break;
		}
	case 20:
		{
			std::cout << std::endl <<"*******************L\'ENTRAINEUR LE PLUS TITRE******************* " << std::endl;
			EntraineurLePlusTitre();
			break;
		}
	case 21:
		{
			std::cout << std::endl <<"*******************LE CLUB LE PLUS TITRE******************* " << std::endl;
			ClubLePlusTitre();
			break;
		}
	case 0://quit
		break;
	}

	return ret_choix;

}

//----------------------------------------------------------------- CreerClub
void Ecran::CreerClub() {
	std::string _nomDuClub, _histoireDuClub, _couleurDuClub, _adresseDuClub, _villeDuClub, _anneeDeCreation;

	std::cout << std::endl << "//		NOM : "; std::cin >> _nomDuClub;
	std::cout << std::endl << "//		COULEUR : "; std::cin >> _couleurDuClub;
	std::cin.ignore(1);
	std::cout << std::endl << "//		ADDRESSE : "; getline(std::cin, _adresseDuClub);
	std::cout << std::endl << "//		VILLE : "; std::cin >> _villeDuClub;
	std::cout << std::endl << "//		DATE DE CREATION <JJ-MM-AAAA>: "; std::cin >> _anneeDeCreation;
	std::cin.ignore(1);
	std::cout << std::endl << "//		HISTOIRE: " ; getline(std::cin,_histoireDuClub);

	//Cree le nouveau club et l'ajoute aux clubs de la ligue
	Club* newClub = new Club(_nomDuClub, _histoireDuClub, _couleurDuClub, _adresseDuClub, _villeDuClub, _anneeDeCreation, _ligue);
	_ligue->AjouterClub(newClub);
}

//----------------------------------------------------------------- SupprimerClub
void Ecran::SupprimerClub() {
	std::string nom;
	
	std::cout << std::endl << "Entrer le nom du club a supprimer : "; std::cin >> nom;
	Club* aSupprimer = _ligue->RechercherClub(nom);

	if(aSupprimer != NULL) {//Si le club existe
		for (unsigned int i=0; i<_ligue->getClubsDeLaLigue().size(); i++) {
			if(_ligue->getClubsDeLaLigue()[i] == aSupprimer) {
				_ligue->SupprimerCalendrier(nom);
				delete _ligue->getClubsDeLaLigue()[i];
				_ligue->getClubsDeLaLigue().erase(_ligue->getClubsDeLaLigue().begin()+i);
			}
		}
		std::cout << "Le club " << nom << " a ete supprime de la ligue." << std::endl;
	}
	else
		std::cerr << "Ce club n\'existe pas dans la ligue." << std::endl;
}

//----------------------------------------------------------------- AfficherEffectif
void Ecran::AfficherEffectif() {
	std::string nom;
	
	std::cout << std::endl << "Entrer le nom du club : "; std::cin >> nom;
	Club* aAfficher = _ligue->RechercherClub(nom);

	if(aAfficher != NULL) {//Si le club existe
		if(!aAfficher->getEffectif().empty()) {
			//Itere dans l'_effectif du club et affiche le nom et prenom dun joueur
			for (unsigned int i = 0; i < aAfficher->getEffectif().size(); i++)
			{
				std::cout << aAfficher->getEffectif()[i]->obtenirNP() << ", ";
			}
		}
		else
			std::cerr << "Il n'y a pas de joueurs dans ce club." << std::endl;
	}
	else
		std::cerr << "Ce club n\'existe pas dans la ligue." << std::endl;
}

//----------------------------------------------------------------- AfficherStaff
void Ecran::AfficherStaff(){
	std::string nom;
	
	std::cout << std::endl << "Entrer le nom du club : "; std::cin >> nom;
	Club* aAfficher = _ligue->RechercherClub(nom);

	if(aAfficher != NULL) {//Si le club existe
		if(!aAfficher->getStaffTechnique().empty()) {
			//Itere dans le staff du club et affiche le nom et prenom du personnel
			for (unsigned int i = 0; i < aAfficher->getStaffTechnique().size(); i++)
			{
				std::cout << aAfficher->getStaffTechnique()[i]->obtenirNP() << ", ";
			}
		}
		else
			std::cerr << "Il n'y a pas de staff dans ce club." << std::endl;
	}
	else
		std::cerr << "Ce club n\'existe pas dans la ligue." << std::endl;
}

//----------------------------------------------------------------- CreerJoueur
void Ecran::CreerJoueur(){
	std::string nomClub, nom, prenom, ville, dateDuContrat, datedEntree, droit;
	int dureeDuContrat, age; double taille, poids, montant; bool autonome(false);

	std::cout << std::endl << "Entrer le nom du club : "; std::cin >> nomClub;
	Club* aAjouter = _ligue->RechercherClub(nomClub);

	if(aAjouter != NULL) {//Si le club existe
		std::cout << std::endl << "//		NOM : "; std::cin >> nom;
		std::cout << std::endl << "//		PRENOM : "; std::cin >> prenom;
		std::cout << std::endl << "//		AGE : "; std::cin >> age;
		std::cout << std::endl << "//		TAILLE : "; std::cin >> taille;
		std::cout << std::endl << "//		POIDS : "; std::cin >> poids;
		std::cout << std::endl << "//		VILLE DE NAISSANCE : "; std::cin >> ville;
		std::cout << std::endl << "//		AUTONOME(OUI = 1/NON = 0) : "; std::cin >> autonome;

		std::cout << std::endl << "*******************NOUVEAU CONTRAT DU JOUEUR*******************" << std::endl;
		std::cout << std::endl << "//		DUREE DU CONTRAT : "; std::cin >> dureeDuContrat;
		std::cout << std::endl << "//		DATE D\'ENTREE DU JOUEUR <JJ-MM-AAAA>: "; std::cin >> datedEntree;
		std::cout << std::endl << "//		DATE DU CONTRAT <JJ-MM-AAAA>: "; std::cin >> dateDuContrat;
		std::cout << std::endl << "//		PRIX DU TRANSFERT : "; std::cin >> montant;
		std::cin.ignore(1);
		std::cout << std::endl << "//		DROITS DU JOUEUR : "; getline(std::cin,droit);

		Joueur* newbie = NULL;
		if (autonome) {//S'il est autonome
			//Cree le nouveau joueur et l'ajoute a l_effectif du club
			newbie = new Joueur_Autonome(prenom, nom, age, taille, poids, ville);
			aAjouter->addEffectif(newbie);
			//Cree son nouveau contrat et l'ajoute aux _contratsdEngagement du club
			Contrat* newContrat = new Contrat(newbie, aAjouter, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
			aAjouter->addContratdEngagement(newContrat);
		}
		else {
			//Cree le nouveau joueur et l'ajoute a l_effectif du club
			newbie = new Joueur_NonAutonome(prenom, nom, age, taille, poids, ville);
			aAjouter->addEffectif(newbie);
			//Cree son nouveau contrat et l'ajoute aux _contratsdEngagement du club
			Contrat* newContrat = new Contrat(newbie, aAjouter, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
			aAjouter->addContratdEngagement(newContrat);
		}
		std::cout << "Le joueur " << newbie->obtenirNP() << " a ete cree et ajoute a l'_effectif du club " << _nom << "." << std::endl;
	}
	else
		std::cerr << "Ce club n\'existe pas dans la ligue." << std::endl;
}

