/********************************************
* Titre: Travail pratique #4 - transfert.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}

// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

void Transfert::effectuerTransfert()
{
	// Effectuer un transfert d’argent entre l’expéditeur du transfert et le receveur
	expediteur_->modifierBalanceTranferts(montant_);
	receveur_->modifierBalanceTranferts(-montant_);

	// Modifier les frais à payer ou les retours à recevoir de l’expéditeur.
	if (dynamic_cast<UtilisateurRegulier*>(expediteur_) != nullptr)
		expediteur_->modifierBalanceFrais(getFraisTransfert());
	else
		expediteur_->modifierBalanceFrais(-0.03*montant_);
}

//Methode affichage
ostream& operator<<(ostream& os, const Transfert& transfert) {
	os << "- " << left << setw(9) << setfill(' ') <<transfert.expediteur_->getNom() <<"-> " << left << setw(9) << setfill(' ') << transfert.receveur_->getNom() << ": " << fixed<<setprecision(2)<<transfert.montant_ << "$" << endl;
	return os;
}
