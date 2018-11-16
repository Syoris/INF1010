/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardi
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include "algorithm"
#include "functional"
#include "foncteur.h"
using namespace std::placeholders;

vector<double> GestionnaireUtilisateurs::getComptes() const {
	vector<double> comptes;
	for (map<Utilisateur*, double>::iterator it = getConteneur().begin(); it != getConteneur().end(); it++)
		comptes.push_back(it->second);
	return comptes;
}

bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	//??
}

void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) {

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const {
	
	if (!getConteneur().empty()) {
		pair<Utilisateur*, double> paireMax = make_pair(getConteneur().begin()->first, getConteneur().begin()->second);
		for (map<Utilisateur*,double>::iterator  it = getConteneur().begin(); it != getConteneur().end(); it++)
			if (it->second > paireMax.second) {
				paireMax.first = it->first;
				paireMax.second = it->second;
			}

		return paireMax;
	}
	else
		cout << "Erreur GestionnaireUtilisateur::getMax(). Le conteneur ne contient aucun utilisateur." << endl;
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const {
	
	if (!getConteneur().empty()) {
		pair<Utilisateur*, double> paireMin = make_pair(getConteneur().begin()->first, getConteneur().begin()->second);
		for (map<Utilisateur*, double>::iterator it = (getConteneur().begin()); it != getConteneur().end(); it++)
			if (it->second > paireMin.second) {
				paireMin.first = it->first;
				paireMin.second = it->second;
			}

		return paireMin;
	}
	else
		cout << "Erreur GestionnaireUtilisateur::getMax(). Le conteneur ne contient aucun utilisateur." << endl;
}

Utilisateur* GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {
	map<Utilisateur*,double>::iterator it = find_if(getConteneur().begin(), getConteneur().end(), bind(equal_to<Utilisateur*>(), _1, utilisateur));
	it++;
	return it->first;
}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {
	vector<pair<Utilisateur*, double>> vecteurRetour;
	copy_if(getConteneur().begin(), getConteneur().end(), back_inserter(vecteurRetour), FoncteurIntervalle(borneInf, borneSup));
	return vecteurRetour;
}

GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {

}
