/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom, MethodePaiement methodePaiement, const string & courriel, const string & idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), possedeGroupe_(false)
{}


bool UtilisateurRegulier::getPossedeGroupe() const {
	return possedeGroupe_;
}

void UtilisateurRegulier::setPossedeGroupe(bool possedeGroupe) {
	possedeGroupe_ = possedeGroupe;
}

void UtilisateurRegulier::print(ostream& os) const {
	if (possedeGroupe_)
		os << "Utilisateur (regulier, dans un groupe) ";
	else
		os << "Utilisateur (regulier, pas dans un groupe) ";
	os << nom_ << " :" << endl;
	os << "\t\tTotal a payer: " << balanceTransferts_ << "$ (" << balanceFrais_ << "$ de frais)" << endl;
	os << "\t\tDepenses : " << endl;
	for (unsigned i = 0; i < depenses_.size(); i++)
		os << "\t\t\t" << *depenses_[i];
	os << endl;
}