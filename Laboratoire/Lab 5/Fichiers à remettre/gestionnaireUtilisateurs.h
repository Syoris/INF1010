/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Modifi� le : 18 novembre 2018
* Auteur: Ryan Hardie
* �dit� par Charles Sirois et Patrick Leclerc
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

	// M�thode d'acc�s
	// Retourne un vecteur avec les comptes des utilisateurs.
	vector<double> getComptes() const;

	// Retourne vrai si utilisateur est pr�sent dans conteneur_.
	bool estExistant(Utilisateur* utilisateur) const;

	// Met � jour les comptes des utilisateurs
	void mettreAJourComptes(Utilisateur* utilisateur , double montant);

	// Retourne la paire correspondant � l'utilisateur avec le compte le plus �lev�.
	pair<Utilisateur*, double>& getMax() const;

	// Retourne la paire correspondant � l'utilisateur avec le compte le plus bas.
	pair<Utilisateur*, double>& getMin() const;

	// Retourne l'utilisateur suivant la paire correspondant aux informations pass�es.
	Utilisateur* getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;

	// Retourne un vecteur contenant les paires d'utilisateurs et comptes ayant un compte compris entre les bornes.
	vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const;

	// Modifie le comptes d'un utilisateur par le double pass�.
	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> p);
};

#endif