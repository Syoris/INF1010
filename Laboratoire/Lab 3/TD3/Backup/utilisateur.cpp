/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur():nom_(""),type_(Regulier), interet_(0),totalDepense_(0) {

}

Utilisateur::Utilisateur(const string& nom , TypeUtilisateur type) : nom_(nom), type_(type), interet_(0), totalDepense_(0) {

}

Utilisateur::Utilisateur(const Utilisateur& utilisateur):nom_(utilisateur.nom_),type_(utilisateur.type_),interet_(utilisateur.interet_),totalDepense_(utilisateur.totalDepense_),depenses_(utilisateur.depenses_) {

}


// Destructeur
Utilisateur::~Utilisateur() {

}


// Methodes d'acces

string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_; 
}

double Utilisateur::getInteret() const {
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const {
	
	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_; 
}


// Methodes de modification

void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::calculerTotalDepenses() {
	for (unsigned i = 0; i < getNombreDepenses(); i++) 
		totalDepense_ += depenses_[i]->getMontant();
}

void Utilisateur::setInteret(double interet) {
	interet_ = interet;
}

void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

 // Surcharge des opérateurs

Utilisateur& Utilisateur::operator=(Utilisateur* utilisateur)
{
	if (this != utilisateur) {
		nom_ = utilisateur->nom_;
		interet_ = utilisateur->interet_;
		type_ = utilisateur->type_;
		depenses_ = utilisateur->depenses_;
		totalDepense_ = utilisateur->totalDepense_;
	}
	return *this;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)
{
	os << "Utilisateur " << utilisateur.nom_ << "("<<utilisateur.getType()<<") a depense pour un total de : " << utilisateur.getTotalDepenses();
	os << "Polycount prend en interet : " << utilisateur.interet_ << ", voici les dépenses :"<< endl;
	os << "\t Liste de depenses : " << endl;
	for (unsigned int i = 0; i < utilisateur.getNombreDepenses(); i++) {
		os << "\t\t";
		os << *(utilisateur.depenses_[i]);
	}
	return os;
}
