#ifndef ECRAN_H
#define ECRAN_H

#include "ligue.h"

class Ecran
{
	public:
		Ecran();
		~Ecran();

		Ligue* getLigue() {
			return &_ligue;
		}

		void afficherMenu();
		int getChoixUtilisateur();

		void CreerJoueur();
		void ModifierJoueur();
		void SupprimerJoueur();
		void AfficherEffectif();

		void CreerEntraineur();
		void AfficherStaff();

		void ModifierSeuil();
		void TransfertJoueur();
		void RompreSonContrat();
		void AfficherMontantTransferts();
		void AfficherMontantTotal();

		void CreerClub();
		void SupprimerClub();
		void AfficherClubs();

		void EntraineurLePlusTitre();
		void ClubLePlusTitre();

		void CreerCalendrierLigue();
		void AfficherCalendrierLigue();
		void AfficherCalendrierClub();

		void AfficherResultat();
		void CreerRencontre();
		void ModifierRencontre();

	private:
		Ligue _ligue;
};
#endif
