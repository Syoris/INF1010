#include "depenseGroupe.h"

//constructeur
DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu): Depense::Depense(nom,montant,lieu),nombreParticipants_(0){
	Depense::setType(groupe); 
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense) : Depense::Depense(static_cast<Depense>(depense)) {//sinon DepenseGroupe(depense.getNom(),depense.getMontant(),*(depense.getLieu()) 
	nombreParticipants_ = depense.nombreParticipants_;
}

//getters 
unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const {
	if (nombreParticipants_ == 0)
		return 0;
	else
		return (Depense::getMontant()/nombreParticipants_); 
}


//setters
void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}



//surcharge 
ostream& operator<<(ostream& os, const DepenseGroupe& depense) {
	os <<"\tDepense de groupe : Achat fait\t(a " << *(depense.getLieu()) << ")\t: "
		<< depense.getNom() << " Prix : " << depense.getMontant() << " fait par : "
		<< depense.nombreParticipants_ << " soit : "
		<< depense.getMontantPersonnel() <<" par personne." <<  endl;
	return os;
}

