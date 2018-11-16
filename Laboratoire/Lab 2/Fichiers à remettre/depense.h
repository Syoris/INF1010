/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifi� par Charles Sirois et Patrick Leclerc
* En-t�te d'une d�pense. Une d�pense est caract�ris�e par un montant, un nom et un lieu.
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
	// M�thode qui retourne nom_
	string getNom() const;

	// M�thode qui retourne montant_
	double getMontant() const;

	// M�thode qui retourne lieu_
	string getLieu() const;

	// Methodes de modifications
	// M�thode pour changer nom_ � nom
	void setNom(const string& nom);

	// M�thode pour changer montant_ � montant
	void setMontant(double montant);

	// M�thode pour changer lieu_ � lieu
	void setLieu(const string lieu);

	// Surcharge de l'op�rateur = pour copier une d�pense dans une autre
	Depense& operator=(const Depense& depense);

	// Surcharge de l'op�rateur << pour afficher une d�pense � l'aide de <<
	friend ostream& operator<<(ostream& o, const Depense& depense);

private:
	string nom_;
	double montant_;
	string* lieu_;
};
#endif