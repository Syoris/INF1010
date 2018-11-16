/*
�crit par :
Patrick Leclerc 1899303
Charles Sirois 1894544

En-t�te d'un transfert.
Classe pour suivre le transfert d'argent entre deux utilisateurs.

*/
#include "transfert.h"

Transfert::Transfert():montant_(0.0),donneur_(nullptr),receveur_(nullptr)
{
}
Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour) : montant_(montant), donneur_(de), receveur_(pour)
{
}
Utilisateur* Transfert::getDonneur()const
{
	return donneur_;
}
Utilisateur* Transfert::getReceveur()const
{
	return receveur_;
}
double Transfert::getMontant()const
{
	return montant_;
}
void Transfert::setDonneur(Utilisateur* donneur)
{
	donneur_ = donneur;
}
void Transfert::setMontant(double montant)
{
	montant_ = montant;
}
void Transfert::setReceveur(Utilisateur* receveur)
{
	receveur_ = receveur;
}
void Transfert::afficherTransfert()const
{
	cout << "Transfert fait par : " << donneur_->getNom() << " pour : " << receveur_->getNom() << " d'un montant de : " << montant_ << endl;
}