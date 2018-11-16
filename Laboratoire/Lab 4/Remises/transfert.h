/********************************************
* Titre: Travail pratique #4 - transfert.h
* Date: 4 novembre 2018
* Auteur: Wassim Khene & David Dratwa
* Modifi� par Charles Sirois et Patrick Leclerc
* Ent�te de transfert
*  Un transfert est caract�ris� par l'�change d'un montant entre un donneur et un receveur.
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

	// M�thodes d'acc�s
	//M�thode qui retourne expediteur_
	Utilisateur* getExpediteur() const;
	
	//M�thode qui retourne receveur_
	Utilisateur* getReceveur() const;
	
	//M�thode qui retourne montant_
	double getMontant() const;
	
	//M�thode qui retourne les frais de transferts relatifs au type de transfert et aux l'utilisateur qui participent au transfert
	virtual double getFraisTransfert() const = 0;

	// M�thode qui modifie montant_ � montant
	void setMontant(double montant);
	
	// M�thode qui modifie expediteur_ � expediteur
	void setExpediteur(Utilisateur* expediteur);
	
	// M�thode qui modifie receveur_ � receveur
	void setReceveur(Utilisateur* receveur);


	//m�thode qui effectue le transfert d'argent d'un utilisateur � un autre en consid�rant les frais applicables au transfert
	void effectuerTransfert();
	
	// M�thodes d'affichage
	// Surcharge de l'op�rateur << pour permettre d'afficher un transfert avec <<
	friend ostream& operator<<(ostream& os, const Transfert& transfert);

protected:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};

#endif