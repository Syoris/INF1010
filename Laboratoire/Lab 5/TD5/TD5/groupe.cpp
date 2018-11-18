/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs et destructeur
Groupe::Groupe() {
	nom_ = "";
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : nom_(nom) {
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const Groupe& groupe) : nom_(groupe.nom_), transferts_(groupe.transferts_), comptes_(groupe.comptes_),gestionnaireDepenses_(nullptr),gestionnaireUtilisateurs_(nullptr) {
	gestionnaireDepenses_ = new GestionnaireDepenses(*groupe.gestionnaireDepenses_);
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs(*groupe.gestionnaireUtilisateurs_);
}

Groupe::~Groupe() {
	vector<Depense*> depenses = gestionnaireDepenses_->getConteneur();
	for (auto it = depenses.begin; it != depenses.end; it++) {
		delete depenses[it];
	}
	for (auto it = transferts_.begin; it != transferts_.end; it++) {
		delete transferts_[it];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

// TODO : TESTER
vector<Depense*> Groupe::getDepenses() const
{
	return gestionnaireDepenses_->getConteneur();
}

// TODO : TESTER
map<Utilisateur*,double> Groupe::getUtilisateurs() const
{
	return gestionnaireUtilisateurs_->getConteneur();
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

// TODO : TESTER
vector<double> Groupe::getComptes() const {
	return gestionnaireUtilisateurs_->getComptes();
}

double Groupe::getTotalDepenses() const {
	return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs * Groupe::getGestionnaireUtilisateurs()
{
	return gestionnaireUtilisateurs_;
}

GestionnaireDepenses * Groupe::getGestionnaireDepenses()
{
	return gestionnaireDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
// TODO : TESTER :
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu)
{
	
	// S'assurer que l'utilisateur est dans le groupe
	if (!gestionnaireUtilisateurs_->estExistant) {
		return *this;
	}

	//Créer une nouvelle dépense
	Depense* depense = new Depense(nom, montant, lieu);

	// Ajouter la dépense au gestionnaireDepenses_
	AjouterDepense(gestionnaireDepenses_->getConteneur);

	// Ajouter la dépense à l'utilisateur qui a payé
	*payePar += depense;

	// Obtenir la map pour avoir accès aux comptes avant modification
	map <Utilisateur*, double> mapPreModification = gestionnaireUtilisateurs_->getConteneur();
	

	// Mise a jour des comptes
	double montantReparti = depense->getMontant() / gestionnaireUtilisateurs_->getConteneur().size();
	
	pair<Utilisateur*,double> paireCompte = make_pair(payePar, mapPreModification[payePar] += depense->getMontant() - montantReparti);

	gestionnaireUtilisateurs_->setCompte(paireCompte);

	for (auto it = mapPreModification.begin(); it!=mapPreModification.end(); ++it) {
		if (it->first != payePar) {
			// Création d'une paire avec le nouveaux comptes
			pair<Utilisateur*, double> p = make_pair(it->first, mapPreModification[it->first]+=montantReparti);
			// Ajustement du compte
			gestionnaireUtilisateurs_->setCompte(p);
		}
	}
	return *this;
}

// TODO : TESTER
Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	// Ajouté :
	AjouterUtilisateur(gestionnaireUtilisateurs_->getConteneur);
	return *this;
}

// TODO : TESTER
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {

		// On cherche le compte le plus eleve et le moins eleve
		pair<Utilisateur*,double> paireMax = gestionnaireUtilisateurs_->getMax();
		pair<Utilisateur*, double> paireMin = gestionnaireUtilisateurs_->getMin;

		// On cherche lequel des deux a la dette la plus grande
		if (-paireMin.second <= paireMax.second && paireMin.second != 0 && paireMax.second != 0) {
			if (paireMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-paireMin.second, paireMin.first, paireMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-paireMin.second, paireMin.first, paireMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			pair<Utilisateur*, double> compteMax = make_pair(paireMax.first, gestionnaireUtilisateurs_->getConteneur[paireMin.first] += paireMin.second);
			pair<Utilisateur*, double> compteMin = make_pair(paireMin.first, 0);

			gestionnaireUtilisateurs_->setCompte(compteMax);
			gestionnaireUtilisateurs_->setCompte(compteMin);
		}
		else if (-paireMin.second > paireMax.second  && paireMin.second != 0 && paireMax.second != 0) {
			if (paireMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(paireMax.second, paireMin.first,paireMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(paireMax.second, paireMin.first, paireMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			pair<Utilisateur*, double> compteMax = make_pair(paireMax.first,0);
			pair<Utilisateur*, double> compteMin = make_pair(paireMin.first, gestionnaireUtilisateurs_->getConteneur[paireMin.first]+= paireMax.second);

			gestionnaireUtilisateurs_->setCompte(compteMax);
			gestionnaireUtilisateurs_->setCompte(compteMin);
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-paireMin.second == paireMax.second) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getConteneur().size() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
// TODO : TESTER
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	map<Utilisateur*, double> mapUtilisateurs = groupe.gestionnaireUtilisateurs_->getConteneur();
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (auto it =mapUtilisateurs.begin ; it!=mapUtilisateurs.end; it++) {
		os << "\t- " << *mapUtilisateurs[it].first;
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (auto it = groupe.transferts_.begin; it !=groupe.transferts_.end; it++)
			os << "\t" << *(groupe.transferts_[it]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (auto it = mapUtilisateurs.begin; it != mapUtilisateurs.end; it++) {
			os << mapUtilisateurs[it].first->getNom() << " : " << mapUtilisateurs[it].second << endl;
		}
	}

	os << endl;
	return os;
}
