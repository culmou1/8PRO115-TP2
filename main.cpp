#include <iostream>
#include <string>
#include "class\contrat.h"
#include "class/ligue.h"
#include "class\utils.h"
#include "class\club.h"
#include "class\person.h"
#include "class\calendrier.h"
#include "class\palmares.h"

using namespace std;



int main(){
	Ligue* ligue = new Ligue();
	Club* A = new Club("aaaaaaa", "jaune", "888 aaaa", "A-Town", "01-01-1900", ligue);
	Club* B = new Club("bbbbbbb", "bleu", "888 bbbb", "B-Town", "01-01-1928", ligue);

	ligue->AjouterClub(A);
	ligue->AjouterClub(B);
	ligue->AfficherClubs();

	Entraineur* trainer;Joueur* player; Person* staff; Contrat* contrat; Palmares *titre; TitreGagne* itt;


	string name="A";
	for (int i=0; i<10; i++) {
		player = new Joueur_NonAutonome(name, "Joueur_"+to_string(i), 18, 1.80, 80.5, "Albertown", 2);
		contrat = new Contrat(player, A, 5, "02-05-2005", "06-04-2004", 5000, "Ne pas fumer");
		A->addEffectif(player);
		A->addContratdEngagement(contrat);
	}
	
	for(int i=2; i<6;i++) {
		staff = new Person(name, "Staff_"+to_string(i), 40, static_cast<Role>(i));
		A->addStaffTechnique(staff);
	}
	trainer = new Entraineur(name, "Trainer_1", 50, "Albertown");
	for(int i=0;i<10;i++) {
		titre = new Palmares ("18-06-2008",COUPE);
		itt = new TitreGagne(A, "18-06-2008", COUPE);
		trainer->addTitreGagne(itt);
		A->addUnPalmares(titre);
	}
	A->addStaffTechnique(trainer);
	A->AfficherEffectif();
	A->AfficherStaff();
	A->afficherContratEngagement();
	trainer->afficherTitreGagne();
	A->AfficherMontantTransferts("01-02-2004");
	//A->montantEncaisseDepuisUneDate("01-05-2010");
	//A->TransfertJoueur("A Joueur_0", B);

	name="B";
	for (int i=0; i<10; i++) {
		player = new Joueur_Autonome(name, "Joueur_"+to_string(i), 18, 1.50, 50.5, "Burnout");
		contrat = new Contrat(player, B, 5, "08-05-2008", "06-04-2007", 5000, "Ne pas boire");
		B->addEffectif(player);
		B->addContratdEngagement(contrat);
	}

	for(int i=2; i<6;i++) {
		staff = new Person(name, "Staff_"+to_string(i), 40, static_cast<Role>(i));
		B->addStaffTechnique(staff);
	}
	trainer = new Entraineur(name, "Trainer_1", 50, "Burnout");
	
	for(int i=0;i<5;i++) {
		titre = new Palmares ("18-06-2010",CHAMPIONNAT);
		itt = new TitreGagne(B, "18-06-2010", CHAMPIONNAT);
		trainer->addTitreGagne(itt);
		B->addUnPalmares(titre);
	}
	B->addStaffTechnique(trainer);
	B->AfficherEffectif();
	B->AfficherStaff();
	B->afficherContratEngagement();
	trainer->afficherTitreGagne();
	//B->AfficherMontantTransferts("01-05-2010");
	//B->montantEncaisseDepuisUneDate("01-05-2010");

	ligue->AjouterRencontre(A,B,"01-02-1995");
	ligue->AjouterRencontre(B,A,"01-02-1995");
	ligue->AfficherRencontre(A);
	ligue->AfficherRencontre(B);

	//A->ModifierJoueur("A Joueur_0");
	//A->SupprimerJoueur("A Joueur_5");

	//Joueur* rompu = A->rechercherJoueur("A Joueur_2");
	//rompu->RompreSonContrat(A->rechercherContratdEngagement(rompu));
	ligue->EntraineurLePlusTitre();
	ligue->ClubLePlusTitre();

	ligue->SupprimerClub("vert");
	ligue->AfficherResultat("jaune","01-02-1995");

    system("pause");

    return 0;
};
