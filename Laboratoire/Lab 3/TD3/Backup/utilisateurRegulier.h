/********************************************
* Titre: Travail pratique #3 - utilisateurRegulier.h
* Date premiere version : 2 octobre 2018
* Auteur: David Dratwa
*******************************************/
#ifndef UTILISATEUR_REGULIER_H
#define UTILISATEUR_REGULIER_H

#include "utilisateur.h"

class UtilisateurRegulier : public Utilisateur {
public : 

	// Constructeurs 
	UtilisateurRegulier(const string& nom = ""); 
	UtilisateurRegulier(const Utilisateur& utilisateur); 

	// Destructeur
	~UtilisateurRegulier();

	// Getters
	bool estGroupe() const; 
	 
	// Setters
	void setEtatGroupe(bool etat); 

	// Surcharge
	UtilisateurRegulier& operator=(Utilisateur* utilisateur);
	friend ostream& operator<<(ostream& os, const UtilisateurRegulier& utilisateur); 

private :
	bool estGroupe_; 

};

#endif // !UTILISATEUR_REGULIER_H
