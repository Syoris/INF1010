/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertPaypal.h"

TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur), id_(expediteur_->getIdPaypal())
{
}

string TransfertPaypal::getId() const
{
	return id_;
}

void TransfertPaypal::setId(string id)
{
	id_ = id;
}

double TransfertPaypal::getFraisTransfert() const
{
	// Si l'utilisateur est régulier
	if (dynamic_cast<UtilisateurRegulier*>(expediteur_) != nullptr) 
		return (FRAIS + COMMISSION * montant_);
	// Si l'utilisateur est premium
	else
		return 0.0;
}

