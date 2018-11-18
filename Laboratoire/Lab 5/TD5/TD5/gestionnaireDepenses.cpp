#include "gestionnaireDepenses.h"


// Constructeurs
GestionnaireDepenses::GestionnaireDepenses(){}

//GestionnaireDepenses::GestionnaireDepenses(const GestionnaireDepenses& gestionnaireDepenses){
//	for_each(gestionnaireDepenses.conteneur_.begin(), gestionnaireDepenses.conteneur_.end(), AjouterDepense(conteneur_));
//}


// TODO : Vérifier si on a besoin de delete un vecteur? Le delete devrait se faire ou le new est fait
//GestionnaireDepenses::~GestionnaireDepenses() {
//	for (vector<Depense*>::iterator it = conteneur_.begin(); it != conteneur_.end(); ++it)
//		delete *it;
//}

//GestionnaireDepenses& GestionnaireDepenses::operator=(const GestionnaireDepenses& gestionnaireDepenses) {
//	if (this != &gestionnaireDepenses) {
//		for (vector<Depense*>::iterator it = conteneur_.begin(); it != conteneur_.end(); ++it)
//			delete *it;
//		this->conteneur_.clear();
//		for_each(gestionnaireDepenses.conteneur_.begin(), gestionnaireDepenses.conteneur_.end(), AjouterDepense(conteneur_));
//	}
//	return *this;
//}

double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = 0;
	for (vector<Depense*>::const_iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		totalDepenses += (*it)->getMontant();
	}
	return totalDepenses;
}
