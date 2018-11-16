/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par Charles Sirois et Patrick Leclerc
* En-tête d'un Utilisateur. Un Utilisateur est caractérisé par son nom et les dépenses qu'il a fait.
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);
	Utilisateur(const Utilisateur& utilisateur);

	// Methodes d'accès
	// Méthode qui retourne nom_
	string getNom() const;

	// Méthode qui retourne le nombre de depenses faites
	unsigned int getNombreDepense() const;

	// Méthode qui retourne le total des dépenses faites par l'utilisateur
	double getTotalDepenses() const;

	// Méthode qui retourne un veteur contenant toutes les dépenses faites.
	vector <Depense*> getDepenses()const;

	// Methodes de modification
	// Méthode modifie nom_ à nom
	void setNom(const string& nom);

	// Surcharge de += pour permettre l'ajout d'une dépense à un utilisateur.
	Utilisateur& operator+=(Depense* uneDepense);

	// Définition de l'opérateur = pour permettre la copie d'un utilisateur dans un autre.
	Utilisateur& operator=(const Utilisateur& utilisateur);
	
	// Surcharge de l'opérateur << pour permettre l'affichage d'un utilisateur
	friend ostream& operator<<(ostream& o , const Utilisateur& utilisateur) ;

private:
	string nom_;
	vector <Depense*> depenses_;

};
#endif