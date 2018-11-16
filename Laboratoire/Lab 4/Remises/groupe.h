/********************************************
* Titre: Travail pratique #4 - groupe.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modifié par Charles Sirois et Patrick Leclerc le 04/11/2018
* En-tête d'un groupe. Un groupe possède des utilisateurs et les dépenses du groupes. Il s'occupe aussi d'équilibrer les comptes.
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>

#include "depense.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include "transfertInterac.h"
#include "transfertPaypal.h"

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);
	~Groupe();

	// Methodes d'acces
	// Méthode qui retourne le nom_ du groupe.
	string getNom() const;

	// Méthode qui retourne le vecteur depenses_.
	vector<Depense*> getDepenses() const;

	// Méthode qui retourne le vecteur utilisateurs_.
	vector<Utilisateur*> getUtilisateurs() const;

	// Méthode qui retourne le vecteur transferts_.
	vector<Transfert*> getTransferts() const;

	// Méthode qui retourne le vecteur comptes_.
	vector<double> getComptes() const;

	// Méthode pour calculer le total dépensé
	double getTotalDepenses() const;


	// Methodes de modification
	// Méthode pour modifier nom_ a nom.
	void setNom(const string& nom);


	// Methodes d'ajout
	// Méthode pour ajouter une dépense dans au groupe.
	Groupe& ajouterDepense(double montant, Utilisateur* payePar, const string& nom = "", const string& lieu = "Montreal");

	// Surcharge de l'opérateur += pour ajouter un utilisateur au groupe.
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	// Méthode qui équilibre les comptes.
	void equilibrerComptes();

	// Methode d'affichage
	// Surcharge de l'opérateur << pour pouvoir afficher le groupe.
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Utilisateur*> utilisateurs_;
	vector<Depense*> depenses_;
	vector<Transfert*> transferts_;
	vector<double> comptes_; 
};

#endif
