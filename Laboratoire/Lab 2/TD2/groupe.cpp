/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par Charles Sirois et Patrick Leclerc
* Implémentation d'un Groupe. Un Groupe est caractérisé un nom et les utilisateurs qui le compose. Il permet de calculer les la façon la plus efficace de redistrbuer l'argent.
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :
	nom_("")
{
}

Groupe::Groupe(const string& nom) :
	nom_(nom)
{
}

// Methodes d'acces

string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return depenses_.size();
}

double Groupe::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < getNombreDepenses(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

int Groupe::getNombreUtilisateurs() const {
	return utilisateurs_.size();
}

int Groupe::getNombreTransferts() const {
	return transferts_.size();
}


// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}


// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {

	depenses_.push_back(depense);
	*utilisateur+=depense;
	return *this;
}

void Groupe::calculerComptes()
{
	double moyenne = getTotalDepenses() / getNombreUtilisateurs();
	for (int i = 0; i < getNombreUtilisateurs(); i++) {
		comptes_.push_back(((utilisateurs_[i]->getTotalDepenses()) - moyenne));
	}
}

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < getNombreUtilisateurs(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= getNombreUtilisateurs() - 1) {
			calcul = false;
		}
	}
}

//Surcharge d'opérateurs
Groupe& Groupe::operator+=(Utilisateur* utilisateur) {
	utilisateurs_.push_back(utilisateur);
	return *this;
}

ostream& operator<<(ostream& o, const Groupe& groupe) {
	o << "L'evenement " << groupe.nom_ << " a coute un total de " << groupe.getTotalDepenses() << " :  \n\n";
	for (int i = 0; i < groupe.getNombreUtilisateurs(); i++) {
		o << *(groupe.utilisateurs_[i]);
	}
	o << endl;

	if (groupe.getNombreTransferts() != 0) {
		o << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
		for (int i = 0; i < groupe.getNombreTransferts(); i++) {
			o << "\t";
			o << *(groupe.transferts_[i]);
		}
	}
	else {
		o << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	o << endl;
	return o;
}


