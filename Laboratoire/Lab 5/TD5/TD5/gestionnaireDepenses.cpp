#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>


double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = 0;
	vector<Depense*>::const_iterator it = conteneur_.begin();
	for (; it != conteneur_.end(); it++) {
		totalDepenses += (*it)->getMontant();
	}
	return totalDepenses;
}
