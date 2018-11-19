/********************************************
* Titre: Travail pratique #5 - gestionnaireDepenses.h
* Date: 18 novembre 2018
* Auteur:  Charles Sirois et Patrick Leclerc
* Classe dérivée d'un utilisateur générique
*******************************************/

#ifndef GESTIONNAIRE_DEPENSES_H
#define GESTIONNAIRE_DEPENSES_H

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"

#include <algorithm>
#include <vector>
#include <functional>

class GestionnaireDepenses : public GestionnaireGenerique<Depense*, Depense*, vector<Depense*>,AjouterDepense> {
public:
	// Constructeurs
	GestionnaireDepenses();

	// Méthode d'accès
	//Retourne le total des dépenses effectuées par le groupe
	double getTotalDepenses() const;
};

#endif