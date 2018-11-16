/********************************************
* Titre: Travail pratique #4 - utilisateur.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modifi� par Charles Sirois et Patrick Leclerc le 04/11/2018
* En-t�te d'un Utilisateur. C'est une classe abstraite
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

#include "depense.h"

using namespace std;

enum MethodePaiement { Paypal, Interac };

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom = "", MethodePaiement methodePaiement = Interac, const string& courriel = "", const string& idPaypal= "");

	// Methodes d'acc�s
	// M�thode qui retourne le nom.
	string getNom() const;

	// M�thode qui retourne un vecteur avec les d�penses de l'utilisateur.
	vector<Depense*> getDepenses() const;

	// M�thode qui retourne le courriel de l'utilisateur.
	string getCourriel() const;

	// M�thode qui retourne le IdPaypal de l'utilisateur.
	string getIdPaypal() const;

	// M�thode qui retourne la m�thode de paiment.
	MethodePaiement getMethodePaiement() const;

	// M�thode qui retourne le total tu montant � recevoir ou � donner.
	double getTotalATransferer() const;

	// M�thode qui retourne la balance des frais.
	double getBalance() const;

	// Methodes de modification
	// M�thode pour modifier le nom_ � nom.
	void setNom(const string& nom);
	// M�thode pour modifier le courriel_ � courriel.
	void setCourriel(const string& courriel);
	// M�thode pour modifier le idPaypal_ � idPaypal.
	void setIdPaypal(const string idPaypal);
	// M�thode pour modifier le methodePaiement � methodePaiement.
	void setMethodePaiement(MethodePaiement methodePaiement);

	// M�thode pour ajouter montant � balanceTransferts_.
	void modifierBalanceTranferts(double montant);
	// M�thode pour ajouter montant � balanceFrais_.
	void modifierBalanceFrais(double montant);

	// Surcharge de l'op�rateur += pour ajouter depense aux vector depenses_.
	Utilisateur& operator+=(Depense* depense);

	// M�thode virutal pour afficher l'utilisateur et ses d�penses
	virtual void print(ostream& os) const= 0;
	
	// Methode d'affichage
	// Surcharge de l'op�rateur << pour permetter de l'afficher.
	friend ostream& operator<<(ostream& os, const Utilisateur& user);

protected:
	MethodePaiement methodePaiement_;
	string nom_;
	vector <Depense*> depenses_;
	string courriel_;
	string idPaypal_;
	double balanceFrais_;
	double balanceTransferts_;
};
#endif