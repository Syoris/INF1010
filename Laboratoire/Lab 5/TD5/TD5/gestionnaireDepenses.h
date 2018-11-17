#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"
#include <algorithm>
#include <vector>

class GestionnaireDepenses : public GestionnaireGenerique<Depense*, Depense*, vector<Depense*>,AjouterDepense> {
public:
	// Constructeurs
	GestionnaireDepenses();
	//constructeur par copie //TODO N�cessaire?
	GestionnaireDepenses(const GestionnaireDepenses&);

	// Destructeur 
	~GestionnaireDepenses();

	// Surcharge de l'operator=
	GestionnaireDepenses& operator=(const GestionnaireDepenses&);

	// M�thode d'acc�s
	double getTotalDepenses() const;
};
