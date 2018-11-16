/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
	nom_ = ""; 
}

Groupe::Groupe(const string& nom) : nom_(nom) {
}

Groupe::~Groupe() {
	for (unsigned i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}
}


// Methodes d'accès
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const
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

double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	bool aUneErreur = false;	//Pour savoir s'il y a une erreur
	bool utilisateurTrouve = false; //Pour savoir si l'utilisateur a été trouvé dans le groupe
	vector <int> index;	//Pour garder l'index des utilisateurs dans le groupe

	//Vérifier pour chaque utilisateur de payePour s'il est présent dans le groupe
	for (unsigned i = 0; i < payePour.size(); i++)
	{
		utilisateurTrouve = false; //Pour verifier si l'utilisateur a été trouvé
		for (unsigned j = 0; j < utilisateurs_.size(); j++)
		{
			if (payePour[i] == utilisateurs_[j]) {
				//Si l'utilisateur est trouvé
				utilisateurTrouve = true; 
				index.push_back(j);
			}
		}
		//Si l'utilisateur n'est pas trouvé, il y a une erreur
		if (!utilisateurTrouve)
			aUneErreur = true;	
	}
	//Vérifier que l'utilisateur qui a payé est dans le groupe
	utilisateurTrouve = false;
	for (unsigned j = 0; j < utilisateurs_.size(); j++)
	{
		if (payePar == utilisateurs_[j]) {
			//Si l'utilisateur est trouvé
			utilisateurTrouve = true;
			index.push_back(j);
		}
	}
	if (!utilisateurTrouve)
		aUneErreur = true;


	//Vérifier que la dépense est une DepenseGroupe
	if (depense->getType() != groupe)
		aUneErreur = true;

	//S'il n'y a pas d'erreur
	if (!aUneErreur) {
		//Mettre à jour le nombre de participants à la dépense
		DepenseGroupe depenseGroupe = *(static_cast<DepenseGroupe*>(depense));
		depenseGroupe.setNombreParticipants(payePour.size() + 1);

		*payePar += depense;
		comptes_[index[index.size()-1]] = depense->getMontant();
		payePar->calculerTotalDepenses();
		for (unsigned i = 0; i < payePour.size(); i++)
		{
			*payePour[i] += depense;
			payePour[i]->calculerTotalDepenses();
			comptes_[index[i]] = -1*(depenseGroupe.getMontantPersonnel());
		}
		depenses_.push_back(static_cast<DepenseGroupe*>(depense));
	}

	//S'il y a une erreur
	else
	{
		cout << "Erreur : Vous tenter d'ajouter une dépense individuelle au groupe ou alors les personnes impliquees dans la depense de groupe ne sont pas dans le groupe." << endl;
	}
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	comptes_.push_back(0);
	if (utilisateur->getType() == Premium || !(static_cast<UtilisateurRegulier>(*utilisateur).estGroupe()))
		utilisateurs_.push_back(utilisateur);
	else
		cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " n'est pas souscrit a un abonnement premium et est deja en groupe.";
	return *this;
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

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			
			//Ajouter l'intérêt
			if(utilisateurs_[indexMin]->getType() == Regulier)
				utilisateurs_[indexMin]->ajouterInteret(-min * TAUX_REGULIER);
			else
				(static_cast<UtilisateurPremium*>(utilisateurs_[indexMin]))->ajouterInteret(-min * (static_cast<UtilisateurPremium*>(utilisateurs_[indexMin]))->getTaux());
			
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			
			//Ajouter l'intérêt
			if (utilisateurs_[indexMin]->getType() == Regulier)
				utilisateurs_[indexMin]->ajouterInteret(max * TAUX_REGULIER);
			else
				(static_cast<UtilisateurPremium*>(utilisateurs_[indexMin]))->ajouterInteret(max * (static_cast<UtilisateurPremium*>(utilisateurs_[indexMin]))->getTaux());

			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
			

		}

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

void Groupe::calculerTotalDepense() {
	totalDepenses_ = 0;
	for (unsigned i = 0; i < utilisateurs_.size(); i++)
		utilisateurs_[i]->calculerTotalDepenses();

	for (unsigned i = 0; i < depenses_.size(); i++)
		totalDepenses_ += depenses_[i]->getMontant();

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "L'evenement nomme : " << groupe.getNom() << " a coute un total (en terme de depenses groupee) de : " << groupe.getTotalDepenses() << ". Voici les utilisateurs et leurs depenses :" << endl;
	for (unsigned i = 0; i < groupe.getUtilisateurs().size(); i++) {
		if(groupe.getUtilisateurs()[i]->getType() == Regulier)
			os << *(static_cast<UtilisateurRegulier*>(groupe.getUtilisateurs()[i]))<<endl;
		else
			os << *(static_cast<UtilisateurPremium*>(groupe.getUtilisateurs()[i]))<<endl;
	}

	os << "Les transferts suivant ont ete realiser pour equilibrer les comptes : " << endl;
	for (unsigned i = 0; i < groupe.getTransferts().size(); i++) {
		os << *(groupe.getTransferts()[i]) << endl;
	}
	return os;
}
