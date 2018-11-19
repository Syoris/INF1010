/********************************************
* Titre: Travail pratique #5 - gestionnaireDepenses.h
* Date: 18 novembre 2018
* Auteur:  Charles Sirois et Patrick Leclerc
* Classe d�riv�e d'un utilisateur g�n�rique
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

	// M�thode d'acc�s
	//Retourne le total des d�penses effectu�es par le groupe
	double getTotalDepenses() const;
};

#endif