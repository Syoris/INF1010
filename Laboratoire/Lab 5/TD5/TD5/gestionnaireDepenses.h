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
	//constructeur par copie //TODO Nécessaire?
	//GestionnaireDepenses(const GestionnaireDepenses&);

	// Destructeur 
	~GestionnaireDepenses() {};

	// Surcharge de l'operator=
	//GestionnaireDepenses& operator=(const GestionnaireDepenses&);

	// Méthode d'accès
	double getTotalDepenses() const;
};

#endif