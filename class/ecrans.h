#ifndef ECRAN_H
#define ECRAN_H

#include <iostream>
#include <string>
#include "ligue.h"
#include "calendrier.h"
#include "contrat.h"

class Ecran
{
	public:

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
		void SupprimerCalendrier();

	private:
		Ligue *_ligue;
};
#endif