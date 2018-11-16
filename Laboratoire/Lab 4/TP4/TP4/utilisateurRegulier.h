/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modifié par Charles Sirois et Patrick Leclerc le 04/11/2018
* En-tête d'un UtilisateurRégulier. Un UtlisateurRegulier est une classe dérivée d'un Utilisateur.
*******************************************/
#ifndef UTILISATEUR_REGULIER_H
#define UTILISATEUR_REGULIER_H

#include "utilisateur.h"

class UtilisateurRegulier : public Utilisateur {
public : 

	// Constructeurs 
	UtilisateurRegulier(const string& nom = "", MethodePaiement methodePaiement = Interac, const string& courriel = "", 
		const string& idPaypal = "");

	// Methode d'acces 
	// Méthode qui retourne si l'utilisateur est dans un groupe.
	bool getPossedeGroupe() const; 
	 
	// Methodes de modifications
	// Méthode qui modifie possedeGroupe_ a etat.
	void setPossedeGroupe(bool etat); 
		
	//Affichage
	// Méthode virtual pour afficher un UtilisateurRegulier. 
	virtual void print(ostream& os) const;

private :
	bool possedeGroupe_; 
};

#endif
