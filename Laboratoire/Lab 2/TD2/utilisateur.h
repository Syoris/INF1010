/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifi� par Charles Sirois et Patrick Leclerc
* En-t�te d'un Utilisateur. Un Utilisateur est caract�ris� par son nom et les d�penses qu'il a fait.
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

	// Methodes d'acc�s
	// M�thode qui retourne nom_
	string getNom() const;

	// M�thode qui retourne le nombre de depenses faites
	unsigned int getNombreDepense() const;

	// M�thode qui retourne le total des d�penses faites par l'utilisateur
	double getTotalDepenses() const;

	// M�thode qui retourne un veteur contenant toutes les d�penses faites.
	vector <Depense*> getDepenses()const;

	// Methodes de modification
	// M�thode modifie nom_ � nom
	void setNom(const string& nom);

	// Surcharge de += pour permettre l'ajout d'une d�pense � un utilisateur.
	Utilisateur& operator+=(Depense* uneDepense);

	// D�finition de l'op�rateur = pour permettre la copie d'un utilisateur dans un autre.
	Utilisateur& operator=(const Utilisateur& utilisateur);
	
	// Surcharge de l'op�rateur << pour permettre l'affichage d'un utilisateur
	friend ostream& operator<<(ostream& o , const Utilisateur& utilisateur) ;

private:
	string nom_;
	vector <Depense*> depenses_;

};
#endif