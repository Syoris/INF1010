#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"
#include <algorithm>
#include <vector>

class GestionnaireDepenses : public GestionnaireGenerique<Depense*, Depense*, vector<Depense*>,AjouterDepense> {
public:
	//constructeur par copie
	GestionnaireDepenses(const GestionnaireDepenses&);
	//destructeur 
	~GestionnaireDepenses();
	//surcharge de l'operator=
	GestionnaireDepenses& operator=(const GestionnaireDepenses&);
	double getTotalDepenses() const;
};
