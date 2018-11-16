/********************************************
* Titre: Travail pratique #4 - transfertPaypal.h
* Date: 4 novembre 2018
* Auteur: Wassim Khene & David Dratwa
* Modifié par Charles Sirois et Patrick Leclerc
* Entête de transfert
*  Un transfert est caractérisé par l'échange d'un montant entre un donneur et un receveur.
*******************************************/

#pragma once

const double COMMISSION = 0.026;
const double FRAIS = 0.30;

#include "transfert.h"
#include "utilisateurPremium.h"


class TransfertPaypal : public Transfert {
public:
	// Constructeur
	TransfertPaypal(double montant, Utilisateur* expediteur, Utilisateur* receveur);
	
	//méthode qui retourne Id_
	string getId() const;
	
	//méthode qui modifie Id_ à Id
	void setId(string id);
	
	//méthode qui retourne les frais de transfert associés au transfert Paypal pour les utilisateur regulier ou premium
	double getFraisTransfert() const;

private:
	string id_;
};