/********************************************
* Titre: Travail pratique #4 - transfert.h
* Date: 4 novembre 2018
* Auteur: Wassim Khene & David Dratwa
* Modifié par Charles Sirois et Patrick Leclerc
* Entête de transfert
*  Un transfert est caractérisé par l'échange d'un montant entre un donneur et un receveur.
*******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H

#include "utilisateur.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

#include <iostream>
#include <iomanip>

#include <stdio.h>

class Transfert {
public:
	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// Méthodes d'accès
	//Méthode qui retourne expediteur_
	Utilisateur* getExpediteur() const;
	
	//Méthode qui retourne receveur_
	Utilisateur* getReceveur() const;
	
	//Méthode qui retourne montant_
	double getMontant() const;
	
	//Méthode qui retourne les frais de transferts relatifs au type de transfert et aux l'utilisateur qui participent au transfert
	virtual double getFraisTransfert() const = 0;

	// Méthode qui modifie montant_ à montant
	void setMontant(double montant);
	
	// Méthode qui modifie expediteur_ à expediteur
	void setExpediteur(Utilisateur* expediteur);
	
	// Méthode qui modifie receveur_ à receveur
	void setReceveur(Utilisateur* receveur);


	//méthode qui effectue le transfert d'argent d'un utilisateur à un autre en considérant les frais applicables au transfert
	void effectuerTransfert();
	
	// Méthodes d'affichage
	// Surcharge de l'opérateur << pour permettre d'afficher un transfert avec <<
	friend ostream& operator<<(ostream& os, const Transfert& transfert);

protected:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};

#endif