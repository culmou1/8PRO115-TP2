#ifndef LIGUEAPP_H
#define LIGUEAPP_H

#include <iostream>
#include <string>
#include <algorithm>

#include "class/ecrans.h"
#include "class/contrat.h"
#include "class/ligue.h"
#include "class/utils.h"
#include "class/club.h"
#include "class/person.h"
#include "class/joueur.h"
#include "class/entraineur.h"
#include "class/calendrier.h"
#include "class/palmares.h"
#include "class/rencontre.h"

/**
 *  Application, Implémentation de plusieurs classe du Programme.
 */
class Application {
public:
	Ecran screen;

	Application() { CreerClubs(); Creer_effectifs_Staffs_Titres(); screen.afficherMenu(); screen.getChoixUtilisateur();}
	~Application() {}

	void CreerClubs() {
		Club* A = new Club("AAA","aaaaaaa", "jaune", "888 aaaa", "A-Town", "01-01-1900");
		Club* B = new Club("BBB","bbbbbbb", "bleu", "888 bbbb", "B-Town", "30-09-1928");
		Club* C = new Club("CCC","ccccccc", "vert", "888 cccc", "C-Town", "24-07-1956");
		Club* D = new Club("DDD","ddddddd", "noir", "888 dddd", "D-Town", "11-11-1918");

		screen.getLigue()->addClub(A);
		screen.getLigue()->addClub(B);
		screen.getLigue()->addClub(C);
		screen.getLigue()->addClub(D);
		//screen.CreerClub();

		//screen.AfficherClubs();
	}

	void Creer_effectifs_Staffs_Titres() {

		Entraineur* trainer;Joueur* player; PersonStaff* staff; Contrat* contrat; Palmares *titre; TitreGagne* itt; Joueur_Entraineur *big_boy;
		char name='A';  std::string nom = "A";
		Club* club = NULL;

		//Creer _effectif du type : club joueur_numero et affiche
		for(unsigned int j=0; j<screen.getLigue()->getClubs()->size(); j++) {
			club = screen.getLigue()->getClubs()->at(j);
			nom[0] = name;
			int k = RandomInt(5);
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
			//screen.CreerJoueur();
			//screen.AfficherEffectif();
			//club->afficherContratEngagement();
			//club->AfficherMontantTransferts("01-02-2004");
			//club->montantEncaisseDepuisUneDate("01-05-2010");

			//Creer staff du type : club staff_numero et affiche
			for(int i=2; i<6;i++) {
				staff = new PersonStaff(nom, "Staff_"+std::to_string(i), 40, static_cast<Role>(i));
				club->addStaffTechnique(staff);
			}
			trainer = new Entraineur(nom, "Trainer_1", 50, "Gilbertown");
			club->addStaffTechnique(trainer);

			big_boy = new Joueur_Entraineur(nom, "JoueurTrainer_1", 40, 1.82, 90, "NoWhereTown", "NoWhereTown");
			club->addEffectif(big_boy);
			club->addStaffTechnique(big_boy);

			//Creer titres du type : club titre_numero et affiche
			for(int i=0;i<k;i++) {
				titre = new Palmares ("18-06-2008","Coupe de France");
				itt = new TitreGagne(club, "18-06-2008", "Coupe de France");
				trainer->addTitreGagne(itt);
				big_boy->addTitreGagne(itt);
				club->addUnPalmares(titre);
			}
			trainer->afficherTitreGagne();

			name = static_cast<char>(name+1);
			//screen.AfficherStaff();
		}

	}



	void FaireAutresFonctions() {

		//Rompre le contrat du joueur A Joueur_2 du club A puis afficher _effectif du club A
		Club* club =(screen.getLigue()->getClubs())[0];
		Joueur* rompu = club->rechercherJoueur("A Joueur_2");
		//Choisir autre couleur que: jaune
		rompu->RompreSonContrat(club->rechercherContratdEngagement(rompu));
		club->AfficherEffectif();

		club = (screen.getLigue()getClubs())[1];
		Club* other =(screen.getLigue()getClubs())[3];
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

		screen.getLigue()EntraineurLePlusTitre();
		screen.getLigue()ClubLePlusTitre();

		screen.getLigue()SupprimerClub("AAA");
		screen.getLigue()SupprimerClub("FFF");
	}
};


#endif
