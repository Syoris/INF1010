/********************************************
* Titre: Travail pratique #4 - utilisateur.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modifié par Charles Sirois et Patrick Leclerc le 04/11/2018
* En-tête d'un Utilisateur. C'est une classe abstraite
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

	// Methodes d'accès
	// Méthode qui retourne le nom.
	string getNom() const;

	// Méthode qui retourne un vecteur avec les dépenses de l'utilisateur.
	vector<Depense*> getDepenses() const;

	// Méthode qui retourne le courriel de l'utilisateur.
	string getCourriel() const;

	// Méthode qui retourne le IdPaypal de l'utilisateur.
	string getIdPaypal() const;

	// Méthode qui retourne la méthode de paiment.
	MethodePaiement getMethodePaiement() const;

	// Méthode qui retourne le total tu montant à recevoir ou à donner.
	double getTotalATransferer() const;

	// Méthode qui retourne la balance des frais.
	double getBalance() const;

	// Methodes de modification
	// Méthode pour modifier le nom_ à nom.
	void setNom(const string& nom);
	// Méthode pour modifier le courriel_ à courriel.
	void setCourriel(const string& courriel);
	// Méthode pour modifier le idPaypal_ à idPaypal.
	void setIdPaypal(const string idPaypal);
	// Méthode pour modifier le methodePaiement à methodePaiement.
	void setMethodePaiement(MethodePaiement methodePaiement);

	// Méthode pour ajouter montant à balanceTransferts_.
	void modifierBalanceTranferts(double montant);
	// Méthode pour ajouter montant à balanceFrais_.
	void modifierBalanceFrais(double montant);

	// Surcharge de l'opérateur += pour ajouter depense aux vector depenses_.
	Utilisateur& operator+=(Depense* depense);

	// Méthode virutal pour afficher l'utilisateur et ses dépenses
	virtual void print(ostream& os) const= 0;
	
	// Methode d'affichage
	// Surcharge de l'opérateur << pour permetter de l'afficher.
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