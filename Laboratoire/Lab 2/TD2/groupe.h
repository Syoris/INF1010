/********************************************
* Titre: Travail pratique #2 - groupe.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par Charles Sirois et Patrick Leclerc
* En-tête d'un Groupe. Un Groupe est caractérisé un nom et les utilisateurs qui le compose. Il permet de calculer les la façon la plus efficace de redistrbuer l'argent.
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H
#include <vector>
#include <string>
#include "transfert.h"

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);

	// Methodes d'acces
	// Méthode qui retourne nom_
	string getNom() const;

	// Méthode qui retourne la taille du vecteur depense_
	unsigned int getNombreDepenses() const;

	// Méthode qui retourne le total des dépenses
	double getTotalDepenses() const;

	// Méthode qui retourne la taille du vecteur utilisateurs_
	int getNombreUtilisateurs() const;

	// Méthode qui retourne la taille du vecteur transferts_
	int getNombreTransferts() const;

	// Methodes de modification
	//Méthode qui modifie nom_ à nom.
	void setNom(const string& nom);

	// Methodes d'ajout
	// Méthode pour ajouter une dépense à un utilisateur et au tableau des dépenses
	Groupe& ajouterDepense(Depense* depense, Utilisateur* utilisateur);

	// Methodes de calcul
	// Méthode qui calcul l'argent que chaque personne doit donner ou recevoir
	void calculerComptes();

	// Méthode qui calcul comment redistribuer l'argent en limitant le nombre de transferts
	void equilibrerComptes();

	// Surcharge d'opérateurs
	// Surcharge de l'opérateur += pour permettre l'ajout d'un utilisateur au groupe
	Groupe& operator+=(Utilisateur* utilisateur);

	// Surcharge de l'opérateur << pour permettre l'affichage d'un groupe
	friend ostream& operator<<(ostream& o, const Groupe& groupe);

private:
	string nom_;
	vector <Utilisateur*> utilisateurs_;
	vector <Depense*> depenses_;
	vector <Transfert*> transferts_;
	vector <double> comptes_;
};

#endif
