/********************************************
* Titre: Travail pratique #4 - groupe.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
	nom_ = "";
}

Groupe::Groupe(const string& nom) : nom_(nom) {
}

Groupe::~Groupe() {
	for (unsigned i = 0; i < depenses_.size(); i++)
		delete depenses_[i];
	for (unsigned i = 0; i < transferts_.size(); i++)
		delete transferts_[i];
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<Depense*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

vector<double> Groupe::getComptes() const
{
	return comptes_;
}

double Groupe::getTotalDepenses() const {
	double totalDepenses = 0;
	for (unsigned i = 0; i < depenses_.size(); i++) {
		totalDepenses += depenses_[i]->getMontant();
	}
	return totalDepenses;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

void Groupe::equilibrerComptes() {

	bool calcul = true;
	unsigned count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (unsigned i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		//indexMin recoit, indexMax donne
		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			// Faire le transfert  du bon type
			if (utilisateurs_[indexMin]->getMethodePaiement() == Interac)
				transferts_.push_back(new TransfertInterac(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			else 
				transferts_.push_back(new TransfertPaypal(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			// Faire le transfert du bon type
			if (utilisateurs_[indexMin]->getMethodePaiement() == Interac)
				transferts_.push_back(new TransfertInterac(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			else
				transferts_.push_back(new TransfertPaypal(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}
		//Faire le transfert
		transferts_[transferts_.size()-1]->effectuerTransfert();

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (unsigned i = 0; i < groupe.utilisateurs_.size(); i++) {
		os <<"\t- " << *groupe.utilisateurs_[i];
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (unsigned i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (unsigned i = 0; i < groupe.comptes_.size(); i++) {
			os << groupe.utilisateurs_[i]->getNom() << " : " << groupe.comptes_[i] << endl;
		}
	}

	os << endl;
	return os;
}

// Methode d'ajout
Groupe & Groupe::ajouterDepense(double montant, Utilisateur * payePar, const string & nom, const string & lieu)
{
	// Vérifier que l'utilisateur est dans le groupe
	bool estDansGroupe = false;
	int indice = 0;
	for (unsigned i = 0; i < utilisateurs_.size() && estDansGroupe==false; i++)
		if (utilisateurs_[i] == payePar){
			estDansGroupe = true;
			indice = i;
		}
	
	// Créer une dépense et l'ajouter au groupe
	if (estDansGroupe) {
		Depense* nouvelleDepense = new Depense(nom, montant, lieu);
		depenses_.push_back(nouvelleDepense);
		*utilisateurs_[indice] += nouvelleDepense;
		// Mettre à jour les comptes de tous les utilisateurs
		double montantParPersonne = montant / utilisateurs_.size();

		// Compte de la personne qui a payé
		comptes_[indice] += montant - montantParPersonne;

		// Comptes du reste du groupe
		for (unsigned i = 0; i < utilisateurs_.size(); i++)
			if(i!=indice)
				comptes_[i] += -montantParPersonne;
	}
	return *this;

}

Groupe & Groupe::operator+=(Utilisateur * utilisateur)
{
	//Si l'utilisateur est un UtilisateurRegulier
	if (dynamic_cast<UtilisateurRegulier*>(utilisateur) != nullptr) {
		if (dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe() == false  ) {
		utilisateurs_.push_back(utilisateur);
		dynamic_cast<UtilisateurRegulier*>(utilisateur)->setPossedeGroupe(true);
		// Ajouter un compte pour le nouvel utilisateur
		comptes_.push_back(0.0);
		}
	}

	// Si l'utilisateur est un UtilisateurPremium
	else if (dynamic_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() != 0) {
		utilisateurs_.push_back(utilisateur);
		// Ajouter un compte pour le nouvel utilisateur
		comptes_.push_back(0.0);
		}


	return *this;
}

