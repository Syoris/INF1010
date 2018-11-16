/********************************************
* Titre: Travail pratique #2 - transfert.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifi� par Charles Sirois et Patrick Leclerc
* En-t�te d'un Transfert. Un Transfert est caract�ris� par son montant, l'�xp�diteur de l'argent et le receveur.
*******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>
#include <stdio.h>

class Transfert {
public:

	// Constructeursa
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// M�thodes d'acc�s
	//M�thode qui retourne expediteur_
	Utilisateur* getExpediteur() const;

	// M�thode qui retourne receveur_
	Utilisateur* getReceveur() const;

	// M�thode qui retourne montant_
	double getMontant() const;


	// M�thodes d'affichage
	// M�thode qui modifie montant_ � montant
	void setMontant(double montant);

	// M�thode qui modifie expediteur_ � expediteur
	void setExpediteur(Utilisateur* expediteur);

	// M�thode qui modifie receveur_ � receveur
	void setReceveur(Utilisateur* receveur);

	// Surcharge de l'op�rateur << pour permettre d'afficher un transfert avec <<
	friend ostream& operator<<(ostream& o , const Transfert& transfert);

private:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};

#endif