/********************************************
* Titre: Travail pratique #4 - groupe.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modifi� par Charles Sirois et Patrick Leclerc le 04/11/2018
* En-t�te d'un groupe. Un groupe poss�de des utilisateurs et les d�penses du groupes. Il s'occupe aussi d'�quilibrer les comptes.
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
	// M�thode qui retourne le nom_ du groupe.
	string getNom() const;

	// M�thode qui retourne le vecteur depenses_.
	vector<Depense*> getDepenses() const;

	// M�thode qui retourne le vecteur utilisateurs_.
	vector<Utilisateur*> getUtilisateurs() const;

	// M�thode qui retourne le vecteur transferts_.
	vector<Transfert*> getTransferts() const;

	// M�thode qui retourne le vecteur comptes_.
	vector<double> getComptes() const;

	// M�thode pour calculer le total d�pens�
	double getTotalDepenses() const;


	// Methodes de modification
	// M�thode pour modifier nom_ a nom.
	void setNom(const string& nom);


	// Methodes d'ajout
	// M�thode pour ajouter une d�pense dans au groupe.
	Groupe& ajouterDepense(double montant, Utilisateur* payePar, const string& nom = "", const string& lieu = "Montreal");

	// Surcharge de l'op�rateur += pour ajouter un utilisateur au groupe.
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	// M�thode qui �quilibre les comptes.
	void equilibrerComptes();

	// Methode d'affichage
	// Surcharge de l'op�rateur << pour pouvoir afficher le groupe.
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Utilisateur*> utilisateurs_;
	vector<Depense*> depenses_;
	vector<Transfert*> transferts_;
	vector<double> comptes_; 
};

#endif
