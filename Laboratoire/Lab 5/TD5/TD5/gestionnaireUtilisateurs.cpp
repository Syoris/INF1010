/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardi
*******************************************/
#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

//#include "gestionnaireUtilisateurs.h"
//#include "utilisateurPremium.h"
//#include "utilisateurRegulier.h"
//#include "algorithm"
#include "functional"
#include "foncteur.h"
using namespace std::placeholders;


//Constructeurs
GestionnaireUtilisateurs::GestionnaireUtilisateurs() :GestionnaireGenerique() {};

GestionnaireUtilisateurs::GestionnaireUtilisateurs(const GestionnaireUtilisateurs& gestionnaireUtilisateurs) {
	for_each(gestionnaireUtilisateurs.conteneur_.begin(), gestionnaireUtilisateurs.conteneur_.end(), AjouterUtilisateur(conteneur_));
}

GestionnaireUtilisateurs::~GestionnaireUtilisateurs() {
	for (map<Utilisateur*, double>::iterator it = conteneur_.begin(); it != conteneur_.end(); ++it)
		delete it->first;
}

GestionnaireUtilisateurs& GestionnaireUtilisateurs::operator=(const GestionnaireUtilisateurs& gestionnaireUtilisateurs) {

}




vector<double> GestionnaireUtilisateurs::getComptes() const {
	vector<double> comptes;
	for (map<Utilisateur*,double>::const_iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		comptes.push_back(it->second);
	return comptes;
}

bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	bool existe = false;
	for (map<Utilisateur*, double>::const_iterator it = conteneur_.begin(); it != conteneur_.end() && !existe; it++) {
		if ((*it).first == utilisateur) {
			existe = true;
		}
	}
	return existe;
}

// TODO
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) {

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const {
	
	//Construction d'une paire contenant les premiers �l�ments de la liste
	pair<Utilisateur*, double> paireMax = make_pair(conteneur_.begin()->first, conteneur_.begin()->second);
	for (map<Utilisateur*, double>::const_iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		if (it->second > paireMax.second) {
			paireMax.first = it->first;
			paireMax.second = it->second;
		}

	return paireMax;

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const {
	
	//Construction d'une paire contenant les premiers �l�ments de la liste
	pair<Utilisateur*, double> paireMin = make_pair(getConteneur().begin()->first, getConteneur().begin()->second);
	for (map<Utilisateur*, double>::const_iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		if (it->second > paireMin.second) {
			paireMin.first = it->first;
			paireMin.second = it->second;
		}
	return paireMin;
	
}

Utilisateur* GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {
	map<Utilisateur*,double>::const_iterator it = find_if(conteneur_.begin(), conteneur_.end(), bind(equal_to<Utilisateur>(), _1, utilisateur));
	it++;
	return it->first;
}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {
	vector<pair<Utilisateur*, double>> vecteurRetour;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(vecteurRetour), FoncteurIntervalle(borneInf, borneSup));
	return vecteurRetour;
}

GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {
	conteneur_[p.first] = p.second;
}
