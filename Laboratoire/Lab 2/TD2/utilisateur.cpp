/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par Charles Sirois et Patrick Leclerc
* Implémentation d'un Utilisateur. Un Utilisateur est caractérisé par son nom et les dépenses qu'il a fait.
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_(""){
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom){
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur) : nom_(utilisateur.nom_){
	depenses_ = utilisateur.getDepenses();
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return depenses_.size();
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < getNombreDepense(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}
vector<Depense*> Utilisateur::getDepenses()const {
	return depenses_;
}
//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}

Utilisateur& Utilisateur::operator=(const Utilisateur& utilisateur){
	if (&utilisateur != this) {
		depenses_ = utilisateur.depenses_;
	}
	
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& o,const Utilisateur& utilisateur) {

	o << "Utilisateur : " << utilisateur.nom_ << " a depense pour un total de : " << utilisateur.getTotalDepenses() << endl;
	o << "\t Liste de depenses : " << endl;
	for (unsigned int i = 0; i < utilisateur.getNombreDepense(); i++) {
		o << "\t\t";
		o << *(utilisateur.depenses_[i]);
	}
	return o;
}
