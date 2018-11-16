#include "utilisateurRegulier.h"

// Constructeurs
UtilisateurRegulier::UtilisateurRegulier(const string& nom):Utilisateur(nom, Regulier),estGroupe_(false){
	setInteret(TAUX_REGULIER);
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur):Utilisateur(utilisateur),estGroupe_(false) {
	setInteret(TAUX_REGULIER);
}

// Destructeur
UtilisateurRegulier::~UtilisateurRegulier() {
}

// Getter
bool UtilisateurRegulier::estGroupe() const {
	return estGroupe_;
}

// Setter
void UtilisateurRegulier::setEtatGroupe(bool etat) {
	estGroupe_ = etat;
}

//TODO Tester = 
UtilisateurRegulier& UtilisateurRegulier::operator=(Utilisateur* utilisateur) {
	if (this != utilisateur) {
		*this = utilisateur;
		estGroupe_ = false;
	}
	return *this;
}

//TODO Tester <<
ostream& operator<<(ostream& os, const UtilisateurRegulier& utilisateur) {
	os << static_cast<Utilisateur>(utilisateur);
	if (utilisateur.estGroupe())
		os << "L'utilisateur est dans un groupe";
	else
		os << "L'utilisateur n'est pas dans un groupe";
	os << endl;
	return os;
}