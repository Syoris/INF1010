/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modifi� par Charles Sirois et Patrick Leclerc le 04/11/2018
* En-t�te d'un UtilisateurPremium. Un UtilisateurPremium est une classe d�riv�e d'un Utilisateur.
*******************************************/

#ifndef UTILISATEUR_PREMIUM_H
#define UTILISATEUR_PREMIUM_H

#include "utilisateur.h"

const double TAUX_EPARGNE = 0.03;

class UtilisateurPremium : public Utilisateur {
public :

	// Constructeurs 
	UtilisateurPremium(const string& nom = "", MethodePaiement methodePaiement = Interac, unsigned int joursRestants = 0, const string& courriel = "", const string& idPaypal = "");

	// Methodes d'acces
	// M�thode qui retourne le nombre de jours restant � l'abbonement premium.
	unsigned int getJoursRestants() const; 

	// Methodes de modifications
	// M�thode pour modifier joursRestants_ a joursRestants.
	void setJoursRestants(unsigned int joursRestants); 

	// Methode d'affichage
	// M�thode virtual pour afficher un UtilisateurPremium. 
	virtual void print(ostream& os) const;

private : 
	unsigned int joursRestants_;
};

#endif 
