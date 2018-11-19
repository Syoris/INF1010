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

	Groupe& operator=(const Groupe& groupe);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	// Retourne le nom du groupe.
	string getNom() const;
	
	// Retourne un vecteur contenant les transferts.
	vector<Transfert*> getTransferts() const;

	// Retourne un vecteur de double contenant les comptes des utilisateurs.
	vector<double> getComptes() const;

	// Retourne le total des dépenses.
	double getTotalDepenses() const;

	// Retourne un vecteur contenant les depenses des utilisateurs.
	vector<Depense*> getDepenses() const;
	
	// Retourne une map contenant les utilisateurs et leurs comptes
	map<Utilisateur*, double> getUtilisateurs() const;

	// Ajouté :
	// Retourne le gestionnaireUtilisateurs_ du groupe.
	GestionnaireUtilisateurs* getGestionnaireUtilisateurs() const;

	// Retourne le gestionnaireDepenses_ du groupe.
	GestionnaireDepenses* getGestionnaireDepenses() const;

	// Methodes de modification
	// Modifie nom_ à nom.
	void setNom(const string& nom);

	// Methodes d'ajout
	// Crée une nouvelle dépense et l'ajoute au groupe et aux utilisateurs
	Groupe& ajouterDepense(double montant, Utilisateur* payePar, const string& nom = "", const string& lieu = "Montreal");

	// Surcharge de l'opérateur += pour permettre d'ajouter un utilisateur au groupe.
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	// Crée les transferts nécessaire pour remettre les comptes à 0.
	void equilibrerComptes();

	// Methode d'affichage
	// Surcharge de l'opérateur << pour afficher le groupe.
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Transfert*> transferts_;
	
	GestionnaireUtilisateurs* gestionnaireUtilisateurs_;
	GestionnaireDepenses* gestionnaireDepenses_;
};

#endif
