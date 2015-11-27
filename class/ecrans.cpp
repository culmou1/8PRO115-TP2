#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>
#include "ecrans.h"
#include "ligue.h"
#include "Calendrier.h"
#include "Contrat.h"
#include "club.h"
#include "person.h"
#include "joueur.h"
#include "entraineur.h"
#include "rencontre.h"
#include "rupture.h"
using namespace std;

template<class T>
void EnterNumber(T &numb) {
    std::string vide_buffer;
    std::cin >> numb;
    while(cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        std::cout << "Bad entry. Enter a NUMBER : "; std::cin >> numb;
    }
    std::getline(cin, vide_buffer);
}

template<class T>
void isAlphabet(T &str) {
	std::getline(cin, str);
	while(std::find_if(str.begin(), str.end(), (int(*)(int))std::isdigit) != str.end()) {
		std::cout << "No digits allowed in name. Re-enter : "; std::getline(cin, str);
	}
}

Ecran::Ecran() {
	_ligue = *Ligue::getInstance();
}

Ecran::~Ecran() {
}

void Ecran::afficherMenu()
{
	int choix=0;

	do{

		cout << "\n\n" << endl;
		cout << "*" << setfill('*') << setw(70) << "*" << endl;
		cout << "|	<1>  - Ajouter un nouveau club." << endl;
		cout << "|	<2>  - Supprimer un club." << endl;
		cout << "|	<3>  - Afficher la liste des joueurs pour un club" << endl;
		cout << "|	<4>  - Afficher le staff pour un club" << endl;
		cout << "|	<5>  - Creer un nouveau joueur." << endl;
		cout << "|	<6>  - Modifier un joueur." << endl;
		cout << "|	<7>  - Supprimer un joueur." << endl;
		cout << "|	<8>  - Afficher les clubs pour la ligue" << endl;
		cout << "|	<9>  - Creer un calendrier pour la ligue" << endl;
		cout << "|	<10> - Afficher le calendrier de la ligue." << endl;
		cout << "|	<11> - Afficher le calendrier d'un club" << endl;
		cout << "|	<12> - Modifier une rencontre au calendrier." << endl;
		cout << "|	<13> - Creer une nouvelle rencontre." << endl;
		cout << "|	<14> - Afficher le resultat d'un match." << endl;
		cout << "|	<15> - Modifier le seuil de transfert." << endl;
		cout << "|	<16> - Transferer un joueur dans un nouveau club." << endl;
		cout << "|	<17> - Rompre le contrat d'un joueur avec un club." << endl;
		cout << "|	<18> - Afficher les montants des transferts pour un club." << endl;
		cout << "|	<19> - Afficher le montant total des transferts pour un club." << endl;
		cout << "|	<20> - Afficher l'entraineur ayant le plus de titres." << endl;
		cout << "|	<21> - Afficher le club ayant le plus de titres." << endl;
		cout << "|	<0>  - Quitter." << endl;
		cout << "*" << setfill('*') << setw(70) << "*" << endl;
		cout << "\n\n" << endl;

		choix = getChoixUtilisateur();


	} while(choix!=0);

}

int Ecran::getChoixUtilisateur()
{
	int ret_choix=0;

	cout << "Entrer choix :";
	EnterNumber(ret_choix);
	
	switch(ret_choix)
	{
	case 1:
		{
			cout << endl << "*******************CREATION D\'UN CLUB*******************" << endl;
			CreerClub();
			break;
		}
	case 2:
		{
			cout << endl << "*******************SUPPRESSION D\'UN CLUB*******************" << endl;
			SupprimerClub();
			break;
		}
	case 3:
		{
			cout << endl << "*******************AFFICHAGE LISTE DES JOUEURS DU CLUB******************* " << endl;
			AfficherEffectif();
			break;
		}
	case 4:
		{
			cout << endl << "*******************AFFICHAGE LISTE DU STAFF DU CLUB******************* " << endl;
			AfficherStaff();
			break;
		}
	case 5:
		{
			cout << endl << "*******************CREATION D\'UN JOUEUR*******************" << endl;
			CreerJoueur();
			break;
		}
	case 6:
		{
			cout << endl << "*******************MODIFICATION D\'UN JOUEUR*******************" << endl;
			ModifierJoueur();
			break;
		}
	case 7:
		{
			cout << endl << "*******************SUPPRESSION D\'UN JOUEUR*******************" << endl;
			SupprimerJoueur();
			break;
		}
	case 8:
		{
			cout << endl << "*******************AFFICHAGE LISTE DES CLUBS DE LA LIGUE*******************" << endl;
			AfficherClubs();
			break;
		}
	case 9:
		{
			cout << endl << "*******************CREATION DU CALENDRIER*******************" << endl;
			CreerCalendrierLigue();
			break;
		}
	case 10:
		{
			cout << endl << "*******************AFFICHAGE CALENDRIER DE LA LIGUE******************* " << endl;
			AfficherCalendrierLigue();
			break;
		}
	case 11:
		{
			cout << endl << "*******************AFFICHAGE CALENDRIER DU ClUB******************* " << endl;
			AfficherCalendrierClub();
			break;
		}
	case 12:
		{
			cout << endl << "*******************MODIFICATION D\'UNE RENCONTRE*******************" << endl;
			ModifierRencontre();
			break;
		}
	case 13:
		{
			cout << endl << "*******************CREATION D\'UNE RENCONTRE*******************" << endl;
			CreerRencontre();
			break;
		}
	case 14:
		{
			cout << endl << "*******************AFFICHAGE RESULTAT D\'UNE RENCONTRE*******************" << endl;
			AfficherResultat();
			break;
		}
	case 15:
		{
			cout << endl << "*******************MODIFICATION DU SEUIL DE TRANSFERT*******************" << endl;
			ModifierSeuil();
			break;
		}
	case 16:
		{
			cout << endl << "*******************TRANSFERT DU JOUEUR*******************" << endl;
			TransfertJoueur();
			break;
		}
	case 17:
		{
			cout << endl << "*******************ROMPRE LE CONTRAT DU JOUEUR*******************" << endl;
			RompreSonContrat();
			break;
		}
	case 18:
		{
			cout << endl << "*******************AFFICHAGE MONTANTS DES TRANSFERT D\'UN CLUB******************* " << endl;
			AfficherMontantTransferts();
			break;
		}
	case 19:
		{
			cout << endl << "*******************AFFICHAGE MONTANT TOTAL DES TRANSFERT D\'UN CLUB******************* " << endl;
			AfficherMontantTotal();
			break;
		}
	case 20:
		{
			cout << endl <<"*******************L\'ENTRAINEUR LE PLUS TITRE******************* " << endl;
			EntraineurLePlusTitre();
			break;
		}
	case 21:
		{
			cout << endl <<"*******************LE CLUB LE PLUS TITRE******************* " << endl;
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
	string nomDuClub, histoireDuClub, couleurDuClub, adresseDuClub, villeDuClub, anneeDeCreation;
	cout << endl << "|		NOM : "; isAlphabet(nomDuClub);
	cout << endl << "|		COULEUR : "; isAlphabet(couleurDuClub);
	cout << endl << "|		ADDRESSE : "; getline(cin, adresseDuClub);
	cout << endl << "|		VILLE : "; isAlphabet(villeDuClub);
	cout << endl << "|		DATE DE CREATION <JJ-MM-AAAA>: "; cin >> anneeDeCreation;
	
	cout << endl << "|		HISTOIRE: " ; getline(cin,histoireDuClub);

	//Cree le nouveau club et l'ajoute aux clubs de la ligue
	Club* pClub = new Club(nomDuClub, histoireDuClub, couleurDuClub, adresseDuClub, villeDuClub, anneeDeCreation);
	_ligue.addClub(pClub);
}

//----------------------------------------------------------------- SupprimerClub
void Ecran::SupprimerClub() {

	string nomClub;

	cout << endl << "|	Entrer le nom du club a supprimer : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);

	if(pClub != NULL) {//Si le club existe
		for (unsigned int i=0; i<_ligue.getClubs()->size(); i++) {
			if(_ligue.getClubs()->at(i) == pClub) {
				delete _ligue.getClubs()->at(i);
				_ligue.getClubs()->erase(_ligue.getClubs()->begin()+i);
			}
		}
		for (unsigned int i=0;i<_ligue.getCalendrier()->size(); i++) {
			if(_ligue.getCalendrier()->at(i)->getLocaux() == pClub || _ligue.getCalendrier()->at(i)->getVisiteurs() == pClub) {
				delete _ligue.getCalendrier()->at(i);
				_ligue.getCalendrier()->erase(_ligue.getCalendrier()->begin()+i);
			}
		}
		cout << "Le club " << nomClub << " a ete supprime de la ligue->" << endl;
	}
	else
		cerr << "/!\\	Ce club n\'existe pas dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- AfficherEffectif
void Ecran::AfficherEffectif() {

	string nomClub;

	cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);

	if(pClub != NULL) {//Si le club existe
		if(!pClub->getEffectif()->empty()) {
			//Itere dans l'_effectif du club et affiche le nom et prenom dun joueur
			for (unsigned int i = 0; i < pClub->getEffectif()->size(); i++)
			{
				if(i%5 == 0)
					cout << endl;
				cout << pClub->getEffectif()->at(i)->obtenirNP() << ", ";
			}
		}
		else
			cerr << "/!\\	Il n'y a pas de joueurs dans ce club.	/!\\" << endl;
	}
	else
		cerr << "/!\\	Ce club n\'existe pas dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- AfficherStaff
void Ecran::AfficherStaff(){

	string nomClub;

	cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);

	if(pClub != NULL) {//Si le club existe
		if(!pClub->getStaffTechnique()->empty()) {
			//Itere dans le staff du club et affiche le nom et prenom du personnel
			for (unsigned int i = 0; i < pClub->getStaffTechnique()->size(); i++)
			{
				cout << pClub->getStaffTechnique()->at(i)->obtenirNP() << ", ";
			}
		}
		else
			cerr << "/!\\	Il n'y a pas de staff dans ce club.		/!\\" << endl;
	}
	else
		cerr << "/!\\	Ce club n\'existe pas dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- CreerJoueur
void Ecran::CreerJoueur(){
	string nomClub, nom, prenom, ville, dateDuContrat, datedEntree, droit;
	int dureeDuContrat=0, age=0; double taille=0.0, poids=0.0, montant=0.0; bool autonome(false);

	cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);

	if(pClub != NULL) {//Si le club existe
		cout << endl << "|		NOM : "; isAlphabet(nom);
		cout << endl << "|		PRENOM : "; isAlphabet(prenom);
		cout << endl << "|		AGE : "; EnterNumber(age);
		cout << endl << "|		TAILLE : "; EnterNumber(taille);
		cout << endl << "|		POIDS : "; EnterNumber(poids);
		cout << endl << "|		VILLE DE NAISSANCE : "; isAlphabet(ville);
		cout << endl << "|		AUTONOME(OUI = 1/NON = 0) : "; EnterNumber(autonome);

		cout << endl << "*******************NOUVEAU CONTRAT DU JOUEUR*******************" << endl;
		cout << endl << "|		DUREE DU CONTRAT : "; EnterNumber(dureeDuContrat);
		cout << endl << "|		DATE D\'ENTREE DU JOUEUR <JJ-MM-AAAA>: "; cin >> datedEntree;
		cout << endl << "|		DATE DU CONTRAT <JJ-MM-AAAA>: "; cin >> dateDuContrat;
		cout << endl << "|		PRIX DU TRANSFERT : "; EnterNumber(montant);
		
		cout << endl << "|		DROITS DU JOUEUR : "; getline(cin,droit);

		Joueur* pJoueur = NULL;
		if (autonome) {//S'il est autonome
			//Cree le nouveau joueur et l'ajoute a l_effectif du club
			pJoueur = new Joueur_Autonome(prenom, nom, age, taille, poids, ville);
			pClub->addEffectif(pJoueur);
			//Cree son nouveau contrat et l'ajoute aux _contratsdEngagement du club
			Contrat* pContrat = new Contrat(pJoueur, pClub, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
			pClub->addContratdEngagement(pContrat);
		}
		else {
			//Cree le nouveau joueur et l'ajoute a l_effectif du club
			pJoueur = new Joueur_NonAutonome(prenom, nom, age, taille, poids, ville);
			pClub->addEffectif(pJoueur);
			//Cree son nouveau contrat et l'ajoute aux _contratsdEngagement du club
			Contrat* pContrat = new Contrat(pJoueur, pClub, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
			pClub->addContratdEngagement(pContrat);
		}
		cout << "Le joueur " << pJoueur->obtenirNP() << " a ete cree et ajoute a l\'effectif du club." << endl;
	}
	else
		cerr << "/!\\	Ce club n\'existe pas dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- TransfertJoueur
void Ecran::TransfertJoueur(){
	int dureeDuContrat=0; double montant=0.0;
	string datedEntree, dateDuContrat, droit, nomClubContractant, nomClubDelivreur,joueur;


	cout << endl << "|	Entrer le nom du club contractant : "; isAlphabet(nomClubContractant);
	Club* Ptr_clubContractant = _ligue.rechercherClub(nomClubContractant);

	if (Ptr_clubContractant !=NULL){
		cout << endl << "|	Entrer le nom du club delivreur : "; isAlphabet(nomClubDelivreur);
		Club* Ptr_clubDeLivreur = _ligue.rechercherClub(nomClubDelivreur);

		if(Ptr_clubDeLivreur !=NULL){
			cout << endl << "|	Entrer le nom du joueur a transferer <Prenom Nom>: "; isAlphabet(joueur);
			Joueur* Ptr_Transferer = Ptr_clubDeLivreur->rechercherJoueur(joueur);

			if (Ptr_Transferer != NULL) {// Si le joueur existe
				cout << endl << "*******************NOUVEAU CONTRAT DU JOUEUR*******************" << endl;
				cout << endl << "|		DUREE DU CONTRAT : "; EnterNumber(dureeDuContrat);
				cout << endl << "|		DATE D\'ENTREE DU JOUEUR <JJ-MM-AAAA>: "; cin >> datedEntree;
				cout << endl << "|		DATE DU CONTRAT <JJ-MM-AAAA>: "; cin >> dateDuContrat;
				cout << endl << "|		PRIX DU TRANSFERT : "; EnterNumber(montant);
				cout << endl << "|		DROITS DU JOUEUR : "; getline(cin,droit);

				Contrat* Ptr_Contrat = Ptr_clubDeLivreur->rechercherContratdEngagement(Ptr_Transferer);
				Rupture* Ptr_Rupture = Ptr_clubDeLivreur->rechercherRupturesDeContrats(Ptr_Transferer);
				//Si la date d'echeance est inferieure a la date du contrat ou que le joueur a rompu son contrat
				if(To_Date(dateDuContrat) >= Ptr_Contrat->getDatedEcheance() || Ptr_Rupture != NULL) {
					//Si le seuil est respecte
					if (montant <= Ptr_Contrat->getReglement()->getSeuilDeTransert()) {
						//Cree le nouveau contrat du joueur puis l'ajoute aux _contratsdEngagement du nouveau club
						Ptr_Contrat = NULL;
						Ptr_Contrat = new Contrat(Ptr_Transferer, Ptr_clubContractant, Ptr_clubDeLivreur, dureeDuContrat, datedEntree, dateDuContrat, montant, droit);
						Ptr_clubContractant->addContratdEngagement(Ptr_Contrat);

						//ajoute le joueur a l'_effectif du nouveau club
						Ptr_clubContractant->addEffectif(Ptr_Transferer);

						//supprime le joueur de l'_effectif du club libere
						Ptr_clubDeLivreur->deleteEffectif(Ptr_Transferer);
						
						cout << "Le joueur " << joueur << " a ete transfere du club " << nomClubDelivreur << " au club " << nomClubContractant << "." << endl;
					}
					else
						cerr << "/!\\	Montant du transfert superieur au seuil autorise	/!\\" << endl;
				}
				else
					cerr << "/!\\	Verifier la date du contrat ou si le joueur a rompu son contrat		/!\\" << endl;
			}
			else
				cerr << "/!\\	Ce joueur n\'existe pas.	/!\\";
		}
		else
			cerr << "/!\\	Le club delivreur n\'a pas ete trouve	/!\\";
	}
	else
		cerr << "/!\\	Le club contractant n\'a pas ete trouve	/!\\";
}


//----------------------------------------------------------------- ModifierJoueur
void Ecran::ModifierJoueur(){
	string nomClub, joueur; int age=0; double taille=0.0, poids=0; bool autonome(false);

	std::cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);

	if(pClub != NULL) {//Si le club existe
		cout << endl << "|	Entrer le nom du joueur a modifier <Prenom Nom>: "; isAlphabet(joueur);
		Joueur* pJoueur = pClub->rechercherJoueur(joueur);

		if(pJoueur != NULL) {//Si le joueur existe
			cout << endl << "//		AGE : "; EnterNumber(age);
			cout << endl << "//		TAILLE : "; EnterNumber(taille);
			cout << endl << "//		POIDS : "; EnterNumber(poids);

			//Set les caracteristiques
			pJoueur->setAge(age); pJoueur->setTaille(taille); pJoueur->setPoids(poids);
			cout << "Le joueur " << joueur << " a ete modifie." << endl;
		}
		else
			cerr << "/!\\	Ce joueur n\'existe pas dans ce club.	/!\\" << endl;
	}
	else
		cerr << "/!\\	Ce club n\'existe pas dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- SupprimerJoueur
void Ecran::SupprimerJoueur(){
	string nomClub, joueur;

	cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);

	if(pClub != NULL) {//Si le club existe
		cout << endl << "|	Entrer le nom du joueur a supprimer <Prenom Nom>: "; isAlphabet(joueur);
		Joueur* pJoueur = pClub->rechercherJoueur(joueur);

		if(pJoueur != NULL) {//Si le joueur existe
			//Itere dans l'_effectif du club
			for (unsigned int i = 0; i < pClub->getEffectif()->size(); i++)
			{
				if (pJoueur == pClub->getEffectif()->at(i))
				{
					delete pClub->getEffectif()->at(i);
					pClub->getEffectif()->erase(pClub->getEffectif()->begin()+i);
				}
			}
			cout << "Le joueur " << joueur << " a ete supprime de l\'effectif du club." << endl;
		}
		else
			cerr << "/!\\	Ce joueur n\'existe pas dans ce club.	/!\\" << endl;
	}
	else
		cerr << "/!\\	Ce club n\'existe pas dans la ligue->	/!\\" << endl;
}

//----------------------------------------------------------------- AfficherClub
void Ecran::AfficherClubs(){
	if(!_ligue.getClubs()->empty()) {
		for (unsigned int i = 0; i < _ligue.getClubs()->size();i++){
			std::cout << "Voici la Position du Club: " << i << " - "<< _ligue.getClubs()->at(i)->getNomDuClub() << std::endl;
		}
	}
	else
		cerr << "/!\\	Il n'y a pas de clubs dans la ligue.	/!\\" << endl;
}
//----------------------------------------------------------------- RompreSonContrat
void Ecran::RompreSonContrat(){
	string nomClubDelivreur, joueur, raisonDuDepart, nomClubContractant; 
	double penalite=0.0;

	std::cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClubDelivreur);
	Club* Ptr_clubDeLivreur = _ligue.rechercherClub(nomClubDelivreur);

	if(Ptr_clubDeLivreur != NULL) {//Si le club existe
		cout << endl << "|	Entrer le nom du joueur qui veut rompre son contrat <Prenom Nom>: "; isAlphabet(joueur);
		Joueur* pJoueur = Ptr_clubDeLivreur->rechercherJoueur(joueur);

		if(pJoueur != NULL) {//Si le joueur existe
			Contrat* pContrat = Ptr_clubDeLivreur->rechercherContratdEngagement(pJoueur);
			cout << endl << "|		RAISON DU DEPART : "; getline(std::cin,raisonDuDepart);
			cout << endl << "|		PENALITE DE DEPART : "; EnterNumber(penalite);
			cout << endl << "|		NOM DU NOUVEAU CLUB : "; isAlphabet(nomClubContractant);

			Club* Ptr_clubContractant = _ligue.rechercherClub(nomClubContractant);

			if(Ptr_clubContractant != NULL) {
				// Construction de la rupture
				Rupture* Ptr_Rupture = new Rupture(pJoueur, Ptr_clubContractant, raisonDuDepart, penalite);
				Ptr_clubDeLivreur->addRuptureDeContrats(Ptr_Rupture);

				cout << "Le joueur " << joueur << " a rompu son contrat." << std::endl;
			}
			else
				cerr << "/!\\	Le club contractant n\'a pas ete trouve		/!\\";
		}
		else
				cerr << "/!\\	Ce joueur n\'existe pas.	/!\\";
	}
	else
		cerr << "/!\\	Le club delivreur n\'a pas ete trouve	/!\\";
}

//----------------------------------------------------------------- CreerCalendrier
void Ecran::CreerCalendrierLigue(){
	int nb; bool automatique; Club *home=NULL, *away=NULL; Rencontre *match = NULL;
	Date date;

	if(!_ligue.getClubs()->empty()) {
		cout << "|	Determiner les rencontres entre les clubs automatiquement <OUI-1 NON-0> ? "; cin >> automatique;
		if(automatique) {
			_ligue.getCalendrier()->clear();
			//Creer des rencontres aller-retour entre chaque club et affiche
			for(unsigned int i=0; i<_ligue.getClubs()->size(); i++) {
				home = _ligue.getClubs()->at(i);
				for(unsigned int j=i+1; j<_ligue.getClubs()->size(); j++) {
					away = _ligue.getClubs()->at(j);
					date.Create(RandomInt(31),RandomInt(12),2015);
					match = new Rencontre(home,away,date);
					_ligue.addCalendrier(match);
					date.Create(RandomInt(31),RandomInt(12),2016);
					match = new Rencontre(away,home,date);
					_ligue.addCalendrier(match);
				}
			}
		}
		else {
			cout << "|	Combien de rencontres voulez-vous creer ? ";  cin >> nb;
			while(nb != 0) {
				cout << endl <<"*****CREATION RENCONTRE*****";
				CreerRencontre();
				nb--;
			}
		}
	}
	else
		cerr << "/!\\	 Il n'y a pas de clubs dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- AfficherCalendrierLigue
void Ecran::AfficherCalendrierLigue(){
	if(!_ligue.getCalendrier()->empty()) {
		for (unsigned int i = 0; i < _ligue.getCalendrier()->size();i++){
			cout << "|		" << _ligue.getCalendrier()->at(i)->getDate() << "/ " << _ligue.getCalendrier()->at(i)->getLocaux()->getNomDuClub() <<
				" vs. " << _ligue.getCalendrier()->at(i)->getVisiteurs()->getNomDuClub() << endl;
		}
	}
	else
		cerr << "/!\\	Il n'y a pas de rencontres pour la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- AfficherCalendrierClub
void Ecran::AfficherCalendrierClub(){
	string nomClub, pasDeMatchs = "/!\\		Il n'y a pas de rencontres pour ce club.	/!\\";

	
	cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);

	if(pClub != NULL) {//Si le calendrier du club existe
		try // Fait la fonction
		{
			Calendrier* pCalendrier = _ligue.rechercherCalendrier(nomClub);
			if(!pCalendrier->getRencontres()->empty()) {
				cout << endl << "|	Rencontres du club " << nomClub << " a domicile ou a l\'exterieur :" << endl;
				for(unsigned int i=0; i<pCalendrier->getRencontres()->size(); i++) {
					if(pCalendrier->getRencontres()->at(i)->getLocaux() == pClub) {
						cout << "|		Domicile : " << pCalendrier->getRencontres()->at(i)->getDate() << "/ " << nomClub
							<< " vs. " << pCalendrier->getRencontres()->at(i)->getVisiteurs()->getNomDuClub() << endl;
					}
					else {
						cout << "|		Exterieur : " << pCalendrier->getRencontres()->at(i)->getDate() << "/ "
							<< pCalendrier->getRencontres()->at(i)->getLocaux()->getNomDuClub() << " vs. " << nomClub << endl;
					}
				}
			}
			else
				throw pasDeMatchs;
		}
		catch (string e) // Si une Erreur est survenu
		{
			cerr << e << endl; // Description de l'erreur
		}
	}
	else
		cerr << "/!\\	Ce club n\'existe pas dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- AfficherResultat
void Ecran::AfficherResultat() {
	string nomClubLocal, nomClubInvite, date;

	cout << endl << "|	Entrer le nom du club local : "; isAlphabet(nomClubLocal);
	cout << endl << "|	Entrer le nom du club invite : "; isAlphabet(nomClubInvite);
	cout << endl << "|	Entrer la date du match : "; cin >> date;

	Rencontre* pRencontre = _ligue.rechercherRencontre(nomClubLocal, nomClubInvite, date);
 
	if(pRencontre != NULL) {// Si les deux clubs existent
		cout << nomClubLocal << setw(10) << pRencontre->getResultat() << setw(10) << nomClubInvite;
	}
 	else
		std::cerr << "/!\\	Le match entre les clubs " << nomClubLocal << " et " << nomClubInvite << " n\'existe pas.	/!\\" << std::endl;

}

//----------------------------------------------------------------- CreerRencontre
void Ecran::CreerRencontre() {
	string nomClubLocal, nomClubInvite, date; int butsLocaux, butsVisiteurs; bool aleatoire;

	cout << endl << "|	Entrer le nom du club local : "; isAlphabet(nomClubLocal);
	cout << endl << "|	Entrer le nom du club invite : "; isAlphabet(nomClubInvite);
	cout << endl << "|	Entrer la date du match : "; cin >> date;

	Club* pClubLocal = _ligue.rechercherClub(nomClubLocal);
	Club* pClubInvite = _ligue.rechercherClub(nomClubInvite);

	if(pClubLocal != NULL && pClubInvite != NULL) {
		Rencontre* pRencontre = NULL;
		cout << endl << "|	Determiner le resultat aleatoirement <OUI-1 NON-0> ? "; cin >> aleatoire;
		if (!aleatoire) {
			cout << endl << "|		Combien de buts a marque l\'equipe local ? "; cin >> butsLocaux;
			cout << endl << "|		Combien de buts a marque l\'equipe invitee ? "; cin >> butsVisiteurs;
			Match* pMatch = new Match(pClubLocal, pClubInvite, butsLocaux, butsVisiteurs);
			pRencontre = new Rencontre(pClubLocal, pClubInvite, pMatch, To_Date(date));
		}
		else {
			pRencontre = new Rencontre(pClubLocal, pClubInvite, To_Date(date));
		}
		_ligue.addCalendrier(pRencontre);
	}
	else
		cerr << "/!\\	L'un des deux (ou les deux) clubs n\'existe pas dans la ligue.	 /!\\" << endl;
}

//----------------------------------------------------------------- ModifierRencontre
void Ecran::ModifierRencontre() {
	string nomClubLocal, nomClubInvite, date; int choix;

	cout << endl << "|	Entrer le nom du club local : "; isAlphabet(nomClubLocal);
	cout << endl << "|	Entrer le nom du club invite : "; isAlphabet(nomClubInvite);
	cout << endl << "|	Entrer la date du match : "; cin >> date;

	Club* pClubLocal = _ligue.rechercherClub(nomClubLocal);
	Club* pClubInvite = _ligue.rechercherClub(nomClubInvite);

	if(pClubLocal != NULL && pClubInvite != NULL) {
		Rencontre* pRencontre = _ligue.rechercherRencontre(nomClubLocal,nomClubInvite,date);
		if(pRencontre != NULL) {
			do {
				cout << endl << "*" << setfill('*') << setw(50) << "*" << endl;
				cout << "|	Que voulez-vous modifier dans la rencontre ? " << endl;
				cout << "|		<1>  - Changer le club local." << endl;
				cout << "|		<2>  - Changer le club invite." << endl;
				cout << "|		<3>  - Changer la date de la rencontre." << endl;
				cout << "|		<0>  - Terminer modification." << endl;
				cout << "|	Entrer choix : "; cin >> choix;
				cout << "*" << setfill('*') << setw(50) << "*" << endl;
				switch (choix) {
					case 1 :
						
						cout << "|	Entrer le nom du nouveau club local : "; getline(cin,nomClubLocal);
						pClubLocal = _ligue.rechercherClub(nomClubLocal);
						if (pClubLocal != NULL)
							pRencontre->setLocaux(pClubLocal);
						break;
					case 2 :
						
						cout << "|	Entrer le nom du nouveau club invite : "; getline(cin,nomClubInvite);
						pClubInvite = _ligue.rechercherClub(nomClubInvite);
						if (pClubInvite != NULL)
							pRencontre->setVisiteurs(pClubInvite);
						break;
					case 3 :
						cout << "|	Entrer la nouvelle date : "; cin >> date;
						pRencontre->setDate(date);
						break;
					case 0 :
						break;
				}
			} while(choix!=0);
		}
		else
			std::cerr << "/!\\	Le match entre les clubs " << nomClubLocal << " et " << nomClubInvite << " n\'existe pas.	/!\\" << std::endl;
	}
	else
		cerr << "/!\\	L'un des deux (ou les deux) clubs n\'existe pas dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- EntraineurLePlusTitre
void Ecran::EntraineurLePlusTitre() {
	int nbTitre = 0;
	Person *entraineurLePlusTitre = NULL;

	if(!_ligue.getClubs()->empty()) {
		for (unsigned int i = 0; i < _ligue.getClubs()->size();i++){//Itere dans les clubs de la ligue
			if(!_ligue.getClubs()->at(i)->getStaffTechnique()->empty()) {
				for(unsigned int j = 0; j < _ligue.getClubs()->at(i)->getStaffTechnique()->size();j++){//Itere dans le staff du club
					int currentNumber = _ligue.getClubs()->at(i)->getStaffTechnique()->at(j)->getNumberOfTitre();
					if(currentNumber > nbTitre){// si le nb de titre est plus est grand
						nbTitre = currentNumber;
						entraineurLePlusTitre = _ligue.getClubs()->at(i)->getStaffTechnique()->at(j);
					}
				}
			}
		}
		std::cout << "Voici l\'entraineur le plsu titre: " << entraineurLePlusTitre->obtenirNP() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
	}
	else
		cerr << "/!\\	Il n'y a pas de clubs dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- ClubLePlusTitre
void Ecran::ClubLePlusTitre() {
	int nbTitre = 0;
	Club *clubLePlusTitre = NULL;

	if(!_ligue.getClubs()->empty()) {
		for (unsigned int i = 0; i < _ligue.getClubs()->size();i++){//Itere dans les clubs de la ligue
			int currentNumber = _ligue.getClubs()->at(i)->getNumberOfTitre();
			if(currentNumber > nbTitre){// si le nb de titre est plus est grand
				nbTitre = currentNumber;
				clubLePlusTitre = _ligue.getClubs()->at(i);
			}
		}
		std::cout << "Voici le club le plus titre: " << clubLePlusTitre->getNomDuClub() << ", il a gagne " << nbTitre << " titre(s)." <<std::endl;
	}
	else
		cerr << "/!\\	Il n'y a pas de clubs dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- AfficherMontantTransferts
void Ecran::AfficherMontantTransferts(){
	//Convertit en Date
	string nomClub, aDate;
	cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);

	if(pClub != NULL){
		cout << endl << "| Entrer une Date pour connaitre le montant depuis cette Date :"; cin >> aDate;

		Date dateDonnee = To_Date(aDate);
		cout <<  "Les montants des transferts encaisses par le club " << nomClub << " sont :" << std::endl;
		//Itere dans les _contratsdEngagement
		for (unsigned int i = 0; i < pClub->getContratdEngagement()->size(); i++)
		{
			//Si la date correspond alors il affiche
			if(pClub->getContratdEngagement()->at(i)->getDateDuContrat() <= dateDonnee)
				std::cout << "-  " << pClub->getContratdEngagement()->at(i)->getReglement()->getMontantDuTransfert() << "$" << endl;
		}
	}
	else 
		cerr << "/!\\	Ce club n\'existe pas dans la ligue.	/!\\" << endl;
}


//----------------------------------------------------------------- AfficherMontantTotal
void Ecran::AfficherMontantTotal() {
	double sommeTotal = 0; string nomClub, date;
	
	cout << endl << "|	Entrer le nom du club : "; isAlphabet(nomClub);
	Club* pClub = _ligue.rechercherClub(nomClub);
	if (pClub != NULL) {
		if (!pClub->getContratdEngagement()->empty()) {
			cout << endl << "|	Entrer une date  : "; cin >> date;
			//Itere dans les _contratsdEngagement
			for (unsigned int i = 0;i< pClub->getContratdEngagement()->size();i++)
			{
				//Si la date est inferieure il ajoute a la sommeTotal
				if (pClub->getContratdEngagement()->at(i)->getDateDuContrat() <= To_Date(date)){
					sommeTotal += pClub->getContratdEngagement()->at(i)->getReglement()->getMontantDuTransfert();
				}
			}
			std::cout << "Le montant encaisse par le club " << nomClub << " est de : " << sommeTotal << "$." << std::endl;
		}
		else
			cerr << "/!\\	Ce club n\'a pas de contrats d'engagement.	/!\\" << endl;
	}
	else
		cerr << "/!\\	Ce club n\'existe pas dans la ligue.	/!\\" << endl;
}

//----------------------------------------------------------------- ModifierSeuil
void Ecran::ModifierSeuil() {
	double seuil=0.0;

	cout << endl << "|	Entrer le nouveau seuil de transfert : "; EnterNumber(seuil);

	if (seuil < 5000) {
		for (unsigned int i =0; i < _ligue.getClubs()->size(); i++) {
			for (unsigned int j = 0; j < _ligue.getClubs()->at(i)->getContratdEngagement()->size(); j++) {
				_ligue.getClubs()->at(i)->getContratdEngagement()->at(j)->getReglement()->setSeuilDeTransfert(seuil);
			}
		}
	}
	else
		cerr << "/!\\	Le seuil entre est trop bas		/!\\" << endl;
}
