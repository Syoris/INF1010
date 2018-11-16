/********************************************
* Titre: Travail pratique #4 - transfertInterac.h
* Date: 4 novembre 2018
* Auteur: Wassim Khene & David Dratwa
* Modifié par Charles Sirois et Patrick Leclerc
* Entête de transfert
*  Un transfert est caractérisé par l'échange d'un montant entre un donneur et un receveur.
*******************************************/
#pragma once

#include "transfert.h"
#include "utilisateurPremium.h"

const double FRAIS_TRANSFERT = 1.0;

class TransfertInterac : public Transfert {
public:
	// Constructeur
	TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur);
	
	//méthode qui retourne courriel_
	string getCourriel() const;
	
	//méthode qui modifie courriel_ à courriel
	void setcourriel(string courriel);
	
	//méthode qui retourne les frais associés à un transfert Interac pour un utilisateur Premium ou Regulier
	virtual double getFraisTransfert() const;
private:
	string courriel_;
};