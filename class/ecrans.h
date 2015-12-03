#ifndef ECRAN_H
#define ECRAN_H

#include "ligue.h"

/**
 *  La class Ecran s occupe de tout l affichage du logiciel.
 * 	Elle Contient tout les méthdes d affichages
 */
class Ecran
{
	public:
		/**
		* @params Constructeur par defaut
		*/
		Ecran();
		/**
		* @params Constructeur de recopie
		*/
		~Ecran();
		/**
		* @params Retrourne la ligue
		*/
		Ligue* getLigue() {
			return &_ligue;
		}
		/**
		* @params Afficher le menu principal avec tout les choix
		*/
		void afficherMenu();
		/**
		* @params Obtenir les choix de l utilisateur
		*/
		int getChoixUtilisateur();
		/**
		* @params Creer le joueur
		*/
		void CreerJoueur();
		/**
		* @params Modifie le joueur
		*/
		void ModifierJoueur();
		/**
		* @params Supprimer le joueur
		*/
		void SupprimerJoueur();
		/**
		* @params Afficher l effectif
		*/
		void AfficherEffectif();
		/**
		* @params Creer un entraineur
		*/
		void CreerEntraineur();
		/**
		* @params Afficher le staff
		*/
		void AfficherStaff();
		/**
		* @params Modifie le seuil
		*/
		void ModifierSeuil();
		/**
		* @params Transfert le joueur d un equipe a l autre
		*/
		void TransfertJoueur();
		/**
		* @params Rompre le contrat du joueur
		*/
		void RompreSonContrat();
		/**
		* @params Afficher le montant du transfert
		*/
		void AfficherMontantTransferts();
		/**
		* @params Afficher le montant total
		*/
		void AfficherMontantTotal();
		/**
		* @params Creer le club
		*/
		void CreerClub();
		/**
		* @params Supprimer le club
		*/
		void SupprimerClub();
		/**
		* @params Afficher le club
		*/
		void AfficherClubs();
		/**
		* @params obtenir l entraineur avec le plus titre
		*/

		void EntraineurLePlusTitre();
		/**
		* @params Obtenir le club avec le plus titre
		*/
		void ClubLePlusTitre();
		/**
		* @params Creer le calendrier
		*/
		void CreerCalendrierLigue();
		/**
		* @params Afficher le calendrier
		*/
		void AfficherCalendrierLigue();
		/**
		* @params Afficher le club demander
		*/
		void AfficherCalendrierClub();
		/**
		* @params Afficher le resultat
		*/
		void AfficherResultat();
		/**
		* @params Creer une rencontre
		*/
		void CreerRencontre();
		/**
		* @params Modifie la rencontre
		*/
		void ModifierRencontre();

	private:
		Ligue _ligue;
};
#endif
