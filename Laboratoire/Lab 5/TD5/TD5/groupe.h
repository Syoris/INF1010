/********************************************
* Titre: Travail pratique #5 - groupe.h
* Date: 4 novembre 2018
* Modifié le : 18 novembre 2018
* Auteur: Ryan Hardie
* Édité par Charles Sirois et Patrick Leclerc
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include "gestionnaireDepenses.h"
#include "gestionnaireUtilisateurs.h"
#include "depense.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include "transfertInterac.h"
#include "transfertPaypal.h"
#include "foncteur.h"


#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);
	Groupe(const Groupe& groupe);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	vector<Transfert*> getTransferts() const;
	vector<double> getComptes() const;
	double getTotalDepenses() const;
	vector<Depense*> getDepenses() const;
	map<Utilisateur*, double> getUtilisateurs() const;

	// Ajouté :
	GestionnaireUtilisateurs* getGestionnaireUtilisateurs() const;
	GestionnaireDepenses* getGestionnaireDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	Groupe& ajouterDepense(double montant, Utilisateur* payePar, const string& nom = "", const string& lieu = "Montreal");
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	void equilibrerComptes();

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Transfert*> transferts_;
	
	GestionnaireUtilisateurs* gestionnaireUtilisateurs_;
	GestionnaireDepenses* gestionnaireDepenses_;
};

#endif
