#include <iostream>
#include <string>
#include "class/ligue.h"
#include "class\utils.h"
#include "class\club.h"
#include "class\person.h"
#include "class\calendrier.h"

using namespace std;



int main(){
	Ligue* ligue = new Ligue();
	Club* A = new Club("aaaaaaa", "jaune", "888 aaaa", "A-Town", "01-01-1900", ligue);
	Club* B = new Club("bbbbbbb", "bleu", "888 bbbb", "B-Town", "01-01-1928", ligue);

	ligue->AjouterClub(A);
	ligue->AjouterClub(B);
	ligue->AfficherClubs();
	Joueur* player;

	string name="A";
	for (int i=0; i<11; i++) {
		player = new Joueur(name, to_string(i), 18);
		A->addEffectif(player);
	}
	A->AfficherEffectif();
	name="B";
	for (int i=0; i<11; i++) {
		player = new Joueur(name, to_string(i), 18);
		B->addEffectif(player);
	}
	B->AfficherEffectif();
	ligue->AjouterRencontre(A,B,"01-02-1995");
	ligue->AjouterRencontre(B,A,"01-02-1995");
	ligue->AfficherRencontre(A);
	ligue->AfficherRencontre(B);

    system("pause");

    return 0;
};
