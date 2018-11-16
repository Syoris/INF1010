/********************************************
* Titre: Travail pratique #4 - depense.h
* Date: 4 novembre 2018
* Auteur: Wassim Khene & David Dratwa
* Modifié par Charles Sirois et Patrick Leclerc
* Entête de depense
* Une depense est caractérisé par un nom, un montant, un lieu et un type.
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>
#include<iomanip>

using namespace std;

class Depense {
public:
	// Constructeurs
	Depense(const string& nom = "", double montant = 0 , const string& lieu = "Montreal");
	Depense(const Depense& depense);
	
	//// Surcharge de l'opérateur = pour faire une deep copie d'une depense
	Depense& operator=(const Depense& depense);
	//destructeur
	~Depense();

	// Methodes d'acces
	// Méthode qui retourne nom_
	string getNom() const;
	
	// Méthode qui retourne montant_
	double getMontant() const;
	
	// Méthode qui retourne lieu_
	string* getLieu() const;

	// Methodes de modifications
	// Méthode pour changer nom_ à nom
	void setNom(const string& nom);
	
	// Méthode pour changer montant_ à montant
	void setMontant(double montant);
	
	// Méthode pour changer lieu_ à lieu
	void setLieu(const string& lieu);

	// Affichage
	// Surcharge de l'opérateur << pour afficher une dépense à l'aide de <<
	friend ostream& operator<<(ostream& os, const Depense& depense);
private:
	string nom_;
	double montant_;
	string* lieu_;

};
#endif