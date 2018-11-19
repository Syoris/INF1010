/********************************************
* Titre: Travail pratique #5 - gestionnaireDepenses.cpp
* Date: 18 novembre 2018
* Auteur: Ryan Hardie
* Édité par Charles Sirois et Patrick Leclerc
* Implémentation d'un gestionnaireDepenses
*******************************************/

#include "gestionnaireDepenses.h"


// Constructeurs
GestionnaireDepenses::GestionnaireDepenses():GestionnaireGenerique() {

}

// Méthode d'accès
double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = 0;
	
	for (vector<Depense*>::const_iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		totalDepenses += (*it)->getMontant();
	}
	return totalDepenses;
}
