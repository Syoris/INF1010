/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#ifndef GESTIONNAIRE_UTILISATEURS_H
#define GESTIONNAIRE_UTILISATEURS_H

#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"

#include <algorithm>
#include <map>
#include <vector>
#include <functional>

class GestionnaireUtilisateurs: public GestionnaireGenerique<Utilisateur*, pair<Utilisateur*, double>, map<Utilisateur*,double>, AjouterUtilisateur> { 
public:
	// Constructeur
	GestionnaireUtilisateurs();
	// TODO : Par copie nécessaire?
	//GestionnaireUtilisateurs(const GestionnaireUtilisateurs&);

	// Destructeur TODO: Nécessaire?
	~GestionnaireUtilisateurs() {};
	// Surcharge de l'operator=
	//GestionnaireUtilisateurs& operator=(const GestionnaireUtilisateurs&);


	vector<double> getComptes() const;

	bool estExistant(Utilisateur* utilisateur) const;

	void mettreAJourComptes(Utilisateur* utilisateur , double montant);

	pair<Utilisateur*, double>& getMax() const;

	pair<Utilisateur*, double>& getMin() const;

	Utilisateur* getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;

	vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const;

	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> p);
};

#endif