/********************************************
* Titre: Travail pratique #2 - transfert.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par Charles Sirois et Patrick Leclerc
* En-tête d'un Transfert. Un Transfert est caractérisé par son montant, l'éxpéditeur de l'argent et le receveur.
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

	// Méthodes d'accès
	//Méthode qui retourne expediteur_
	Utilisateur* getExpediteur() const;

	// Méthode qui retourne receveur_
	Utilisateur* getReceveur() const;

	// Méthode qui retourne montant_
	double getMontant() const;


	// Méthodes d'affichage
	// Méthode qui modifie montant_ à montant
	void setMontant(double montant);

	// Méthode qui modifie expediteur_ à expediteur
	void setExpediteur(Utilisateur* expediteur);

	// Méthode qui modifie receveur_ à receveur
	void setReceveur(Utilisateur* receveur);

	// Surcharge de l'opérateur << pour permettre d'afficher un transfert avec <<
	friend ostream& operator<<(ostream& o , const Transfert& transfert);

private:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};

#endif