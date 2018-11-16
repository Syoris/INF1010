
#include "utilisateurPremium.h"

// Constructeurs
UtilisateurPremium::UtilisateurPremium(const string& nom):Utilisateur(nom,Premium),joursRestants_(30),taux_(TAUX_REGULIER){

}

UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur) : Utilisateur(utilisateur), joursRestants_(30), taux_(TAUX_REGULIER) {

}

UtilisateurPremium::~UtilisateurPremium() {

}


// Getters
unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

double UtilisateurPremium::getTaux() const {
	return taux_;
}

// Setters
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

// Méthode de calcul
	//TODO TESTER calcul du taux
void UtilisateurPremium::calculerTaux() {
	taux_ = 0.05 - ceil(getNombreDepenses() / 2)/100;
	if (taux_ < 0)
		taux_ = 0;
}

UtilisateurPremium& UtilisateurPremium::operator=(Utilisateur* utilisateur) {
	if (this != utilisateur) {
		*this = utilisateur;
		joursRestants_ = 30;
		taux_ = TAUX_REGULIER;
	}
	return *this;
}

ostream& operator<<(ostream & os, const UtilisateurPremium & utilisateur)
{
	os << static_cast<Utilisateur>(utilisateur);
	os << "( taux final de : " << utilisateur.getTaux() << ") et il reste " << utilisateur.getJoursRestants() << " jours a son abonnement." << endl;
	return os;
}
