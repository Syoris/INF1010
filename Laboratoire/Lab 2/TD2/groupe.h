/********************************************
* Titre: Travail pratique #2 - groupe.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifi� par Charles Sirois et Patrick Leclerc
* En-t�te d'un Groupe. Un Groupe est caract�ris� un nom et les utilisateurs qui le compose. Il permet de calculer les la fa�on la plus efficace de redistrbuer l'argent.
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
	// M�thode qui retourne nom_
	string getNom() const;

	// M�thode qui retourne la taille du vecteur depense_
	unsigned int getNombreDepenses() const;

	// M�thode qui retourne le total des d�penses
	double getTotalDepenses() const;

	// M�thode qui retourne la taille du vecteur utilisateurs_
	int getNombreUtilisateurs() const;

	// M�thode qui retourne la taille du vecteur transferts_
	int getNombreTransferts() const;

	// Methodes de modification
	//M�thode qui modifie nom_ � nom.
	void setNom(const string& nom);

	// Methodes d'ajout
	// M�thode pour ajouter une d�pense � un utilisateur et au tableau des d�penses
	Groupe& ajouterDepense(Depense* depense, Utilisateur* utilisateur);

	// Methodes de calcul
	// M�thode qui calcul l'argent que chaque personne doit donner ou recevoir
	void calculerComptes();

	// M�thode qui calcul comment redistribuer l'argent en limitant le nombre de transferts
	void equilibrerComptes();

	// Surcharge d'op�rateurs
	// Surcharge de l'op�rateur += pour permettre l'ajout d'un utilisateur au groupe
	Groupe& operator+=(Utilisateur* utilisateur);

	// Surcharge de l'op�rateur << pour permettre l'affichage d'un groupe
	friend ostream& operator<<(ostream& o, const Groupe& groupe);

private:
	string nom_;
	vector <Utilisateur*> utilisateurs_;
	vector <Depense*> depenses_;
	vector <Transfert*> transferts_;
	vector <double> comptes_;
};

#endif
