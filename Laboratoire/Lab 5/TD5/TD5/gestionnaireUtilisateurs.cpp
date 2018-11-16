/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
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
	for (auto it = getConteneur().begin(); it != getConteneur().end(); it++)
		comptes.push_back(it->second);
}

bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {

}

void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* utilisateur, double montant) {

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const {
	
	pair<Utilisateur*, double> paireMax = make_pair(getConteneur().begin(), getConteneur().begin()->second);

	for (auto it = (getConteneur().begin()+1); it != getConteneur().end(); it++)
		if (it->second > paireMax.second)
			paireMax = (it, it->second);
	return paireMax;
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const {
	
	pair<Utilisateur*, double> paireMin = make_pair(getConteneur().begin(), getConteneur().begin()->second);

	for (auto it = (getConteneur().begin()+1); it != getConteneur().end(); it++)
		if (it->second < paireMin.second)
			paireMin = (it, it->second);
	return paireMin;
}

Utilisateur* GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {
	return find_if(getConteneur().begin(), getConteneur().end(), bind(equal_to<Utilisateur*>(), _1, utilisateur));
}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {
	return copy_if(getConteneur().begin(), getConteneur().end(), FoncteurIntervalle(borneInf, borneSup))
}

GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {

}
