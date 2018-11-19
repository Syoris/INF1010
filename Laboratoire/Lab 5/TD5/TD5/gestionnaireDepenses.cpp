/********************************************
* Titre: Travail pratique #5 - gestionnaireDepenses.cpp
* Date: 18 novembre 2018
* Auteur: Ryan Hardie
* �dit� par Charles Sirois et Patrick Leclerc
* Impl�mentation d'un gestionnaireDepenses
*******************************************/

#include "gestionnaireDepenses.h"


// Constructeurs
GestionnaireDepenses::GestionnaireDepenses():GestionnaireGenerique() {

}

// M�thode d'acc�s
double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = 0;
	
	for (vector<Depense*>::const_iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		totalDepenses += (*it)->getMontant();
	}
	return totalDepenses;
}
