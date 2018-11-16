/********************************************
* Titre: Travail pratique #4 - transfertInterac.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertInterac.h"

TransfertInterac::TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur), courriel_(receveur->getCourriel())
{
}

string TransfertInterac::getCourriel() const
{
	return courriel_;
}

void TransfertInterac::setcourriel(string courriel)
{
	courriel_ = courriel;
}

double TransfertInterac::getFraisTransfert() const
{
	// Si l'utilisateur est régulier
	if (dynamic_cast<UtilisateurRegulier*>(expediteur_) != nullptr)
		return 1.0;
	// Si l'utilisateur est premium
	else
		return 0.0;
}
