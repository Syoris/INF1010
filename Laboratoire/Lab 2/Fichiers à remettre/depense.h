/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par Charles Sirois et Patrick Leclerc
* En-tête d'une dépense. Une dépense est caractérisée par un montant, un nom et un lieu.
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs 
	Depense();
	Depense(const string& nom, double montant, string lieu_);

	// Destructeur
	~Depense();

	// Ajouter un constructeur par copie
	Depense(const Depense& depense);

	// Methodes d'acces
	// Méthode qui retourne nom_
	string getNom() const;

	// Méthode qui retourne montant_
	double getMontant() const;

	// Méthode qui retourne lieu_
	string getLieu() const;

	// Methodes de modifications
	// Méthode pour changer nom_ à nom
	void setNom(const string& nom);

	// Méthode pour changer montant_ à montant
	void setMontant(double montant);

	// Méthode pour changer lieu_ à lieu
	void setLieu(const string lieu);

	// Surcharge de l'opérateur = pour copier une dépense dans une autre
	Depense& operator=(const Depense& depense);

	// Surcharge de l'opérateur << pour afficher une dépense à l'aide de <<
	friend ostream& operator<<(ostream& o, const Depense& depense);

private:
	string nom_;
	double montant_;
	string* lieu_;
};
#endif