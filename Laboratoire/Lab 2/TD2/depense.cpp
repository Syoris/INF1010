/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par Charles Sirois et Patrick Leclerc
* Implémentation d'une dépense. Une dépense est caractérisée par un montant, un nom et un lieu.
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_(""), montant_(0), lieu_(nullptr) {
}

Depense::Depense(const string& nom, double montant, string lieu) : nom_(nom), montant_(montant), lieu_(nullptr) {
	lieu_ = new string(lieu);
}

Depense::Depense(const Depense& depense) : nom_(depense.nom_), montant_(depense.montant_)
{
	lieu_ = new string(*(depense.lieu_));
}

 //Destructeur
Depense::~Depense() {
	delete lieu_;
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string Depense::getLieu() const {
	return *lieu_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string lieu) {
	*lieu_ = lieu;
}

// Surcharge d'opérateurs
Depense& Depense::operator=(const Depense& depense) {
	if (this != &depense) {
		delete lieu_;
		lieu_ = new string(*(depense.lieu_));
	}
	return *this;
}

ostream& operator<<(ostream& o, const Depense& depense) {
	o << "Achat : " << depense.nom_ << " Prix : " << depense.montant_ << " Lieux : " << *(depense.lieu_) << "; " << endl;
	return o;
}

