/*
�crit par :
Patrick Leclerc 1899303
Charles Sirois 1894544

Impl�mentation d'une d�pense.
Classe pour contenir le nom et la co�t d'une d�pense.

*/

#include "depense.h"

Depense::Depense():titre_("default"),montant_(0.0)
{
}
Depense::Depense(const string& titre, double montant):titre_(titre),montant_(montant)
{
}
string Depense::getTitre()const
{
	return titre_;
}
double Depense::getMontant()const
{
	return montant_;
}
void Depense::setTitre(string& titre)
{
	titre_ = titre;
}
void Depense::setMontant(double montant)
{
	montant_ = montant;
}
void Depense::afficherDepense()const
{
	cout << "Achat : " << titre_ << " Prix : " << montant_ << ";" << endl;
}