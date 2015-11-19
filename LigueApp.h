#ifndef LIGUEAPP_H
#define LIGUEAPP_H

#include <iostream>
#include <string>
#include <random>
#include <algorithm>

#include "class/contrat.h"
#include "class/ligue.h"
#include "class/utils.h"
#include "class/club.h"
#include "class/person.h"
#include "class/calendrier.h"
#include "class/palmares.h"

class Application {
public:
	Ligue *ligue;

	Application() : ligue(new Ligue()) {}
	~Application() {delete ligue;}

	void CreerClubs() {
		Club* A = new Club("AAA","aaaaaaa", "jaune", "888 aaaa", "A-Town", "01-01-1900", ligue);
		Club* B = new Club("BBB","bbbbbbb", "bleu", "888 bbbb", "B-Town", "30-09-1928", ligue);
		Club* C = new Club("CCC","ccccccc", "vert", "888 cccc", "C-Town", "24-07-1956", ligue);
		Club* D = new Club("DDD","ddddddd", "noir", "888 dddd", "D-Town", "11-11-1918", ligue);

		ligue->AjouterClub(A);
		ligue->AjouterClub(B);
		ligue->AjouterClub(C);
		ligue->AjouterClub(D);

		ligue->AfficherClubs();
	}

	void Creer_effectifs_Staffs_Titres() {
		//Genere un int random
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution (1,5);

		Entraineur* trainer;Joueur* player; Person* staff; Contrat* contrat; Palmares *titre; TitreGagne* itt;
		char name='A';  std::string nom = "A";
		Club* club = NULL;

		//Creer _effectif du type : club joueur_numero et affiche
		for(unsigned int j=0; j<ligue->getClubsDeLaLigue().size(); j++) {
			club = ligue->getClubsDeLaLigue()[j];
			nom[0] = name;
			int k = distribution(generator);
			for (int i=0; i<18; i++) {
				if (i%2 == 0) {//Pair = Autonome, Impair = NonAutonome
					player = new Joueur_Autonome(nom, "Joueur_"+std::to_string(i), 27, 1.80, 80.5, "Albertown");
					contrat = new Contrat(player, club, 5, "02-05-2005", "06-04-2004", 5000, "Ne pas fumer");
					club->addEffectif(player);
					club->addContratdEngagement(contrat);
				}
				else {
					//Donne un nombre d'annee cumulee aleatoire entre 1 et 5
					player = new Joueur_NonAutonome(nom, "Joueur_"+std::to_string(i), 18, 1.70, 65.5, "Albertown", k);
					contrat = new Contrat(player, club, 5, "02-05-2005", "06-04-2004", 5000, "Ne pas fumer, ni boire, ni se droguer");
					club->addEffectif(player);
					club->addContratdEngagement(contrat);
				}
			}
			club->AfficherEffectif();
			club->afficherContratEngagement();
			club->AfficherMontantTransferts("01-02-2004");
			club->montantEncaisseDepuisUneDate("01-05-2010");

			//Creer staff du type : club staff_numero et affiche
			for(int i=2; i<6;i++) {
				staff = new Person(nom, "Staff_"+std::to_string(i), 40, static_cast<Role>(i));
				club->addStaffTechnique(staff);
			}
			trainer = new Entraineur(nom, "Trainer_1", 50, "Gilbertown");
			club->addStaffTechnique(trainer);
			club->AfficherStaff();

			//Creer titres du type : club titre_numero et affiche
			for(int i=0;i<k;i++) {
				titre = new Palmares ("18-06-2008",COUPE);
				itt = new TitreGagne(club, "18-06-2008", COUPE);
				trainer->addTitreGagne(itt);
				club->addUnPalmares(titre);
			}
			trainer->afficherTitreGagne();

			name = static_cast<char>(name+1);
		}
	}

	void CreerRencontres() {
		Club *home=NULL, *away=NULL;

		//Creer des rencontres aller-retour entre chaque club et affiche
		for(unsigned int i=0; i<ligue->getClubsDeLaLigue().size(); i++) {
			home = ligue->getClubsDeLaLigue()[i];
			for(unsigned int j=i+1; j<ligue->getClubsDeLaLigue().size(); j++) {
				away = ligue->getClubsDeLaLigue()[j];
				ligue->AjouterRencontre(home,away,"07-11-2010");
				ligue->AjouterRencontre(away,home,"22-02-2011");
			}
			ligue->AfficherRencontre(home);
			ligue->AfficherResultat(home->getNomDuClub(), "22-02-2011");
		}
	}

	void FaireAutresFonctions() {

		//Rompre le contrat du joueur A Joueur_2 du club A puis afficher _effectif du club A
		Club* club =(ligue->getClubsDeLaLigue())[0];
		Joueur* rompu = club->rechercherJoueur("A Joueur_2");
		//Choisir autre couleur que: jaune
		rompu->RompreSonContrat(club->rechercherContratdEngagement(rompu));
		club->AfficherEffectif();

		club = (ligue->getClubsDeLaLigue())[1];
		Club* other =(ligue->getClubsDeLaLigue())[3];
		//Transferer le joueur B Joueur_9 du club B au club D
		club->TransfertJoueur("B Joueur_9", other);

		//Modifier le joueur C Joueur_0 du club B
		club->ModifierJoueur("C Joueur_0");

		//Supprimer le joueur D Joueur_9 du club D
		other->SupprimerJoueur("D Joueur_9");

		//Cree un joueur au club B
		club->CreerJoueur();

		//Afficher leur _effectifs respectifs
		club->AfficherEffectif();

		ligue->EntraineurLePlusTitre();
		ligue->ClubLePlusTitre();

		ligue->SupprimerClub("AAA");
		ligue->SupprimerClub("FFF");
	}
};


#endif
