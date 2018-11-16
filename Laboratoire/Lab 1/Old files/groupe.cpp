#include "groupe.h"
Groupe::Groupe()
{
	nom_ = "default";
	totalDepenses_ = 0.0;
	//Tableau utilisateurs.
	tailleTabUtilisateurs_ = 5;
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
		listeUtilisateurs_[i] = nullptr;
	
	//Tableau dépenses.
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabDepenses_ = 10;
	listeDepenses_ = new Depense* [tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++)
		listeDepenses_[i] = nullptr;

	comptes_ = new double[nombreUtilisateurs_];

	//Tableau transferts.
	nombreTransferts_ = 0;
	listeTransferts_ = new Transfert*[nombreUtilisateurs_]; //pas nombre transfert?
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		listeTransferts_[i] = nullptr;

}

Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs)
{
	nom_ = nom;
	totalDepenses_ = 0.0;
	//Tableau utilisateurs.
	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
		listeUtilisateurs_[i] = nullptr;

	//Tableau dépenses.
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabDepenses_ = tailleTabDepenses;
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++)
		listeDepenses_[i] = nullptr;

	comptes_ = new double[nombreUtilisateurs_];

	//Tableau transferts.
	nombreTransferts_ = 0;
	listeTransferts_ = new Transfert*[nombreUtilisateurs_]; //pas nombre transfert?
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		listeTransferts_[i] = nullptr;

}

Groupe::~Groupe()
{
	delete [] listeUtilisateurs_;
	delete [] listeDepenses_;
	delete [] listeTransferts_;
	delete    comptes_;
	listeUtilisateurs_ = nullptr;
	listeDepenses_ = nullptr;
	listeTransferts_ = nullptr;
	comptes_ = nullptr;
}

string Groupe::getNom() const
{
	return nom_;
}

unsigned int Groupe::getNombreDepenses()const
{
	return nombreDepenses_;

}

double Groupe::getTotal()const
{
	return totalDepenses_;
}

void Groupe::setNom(string& nom)
{
	nom_ = nom;
}

void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar)
{
	// Agrandir la taille du tableau si nécessaire.
	if (nombreTransferts_ >= tailleTabDepenses_) 
	{
		Depense** nouvelleListeDepenses = new Depense*[tailleTabDepenses_ * 2];
		
		for (unsigned int i = 0; i < nombreDepenses_; i++)
			nouvelleListeDepenses[i] = listeDepenses_[i];
		
		tailleTabDepenses_ *= 2;
		delete [] listeDepenses_;
		listeDepenses_ = nouvelleListeDepenses;
		nouvelleListeDepenses = nullptr;
	}
	// Ajoute la dépense à la liste et à l'utilisateur .
	listeDepenses_[nombreDepenses_] = uneDepense;
	payePar->ajouterDepense(uneDepense);
	nombreDepenses_ ++;
}

void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur)
{
	// Agrandir la taille du tableau si nécessaire.
	if (nombreUtilisateurs_ >= tailleTabUtilisateurs_)
	{
		Utilisateur** nouvelleListeUtilisateurs = new Utilisateur*[tailleTabUtilisateurs_ * 2];

		for (unsigned int i = 0; i < nombreDepenses_; i++)
			nouvelleListeUtilisateurs[i] = listeUtilisateurs_[i];

		tailleTabUtilisateurs_ *= 2;
		delete[] listeUtilisateurs_;
		listeUtilisateurs_ = nouvelleListeUtilisateurs;
		nouvelleListeUtilisateurs = nullptr;
	}
	listeUtilisateurs_[nombreUtilisateurs_] = unUtilisateur;
	nombreUtilisateurs_++;
}

void Groupe::calculerTotalDepenses()
{
	//Calculer total
	totalDepenses_ = 0;
	for (unsigned i = 0; i < nombreUtilisateurs_; i++) {
		listeUtilisateurs_[i]->calculerTotal();
		totalDepenses_ += listeUtilisateurs_[i]->getTotal();
	}
	//Calculer cout par personne
	double coutParPersonne = totalDepenses_ / nombreUtilisateurs_;

	//Augmenter la taille du tableau des comptes
	delete comptes_;
	comptes_ = new double[nombreUtilisateurs_];

	//Mettre à jour les comptes
	for (unsigned i = 0; i < nombreUtilisateurs_; i++) {
		comptes_[i] = listeUtilisateurs_[i]->getTotal() - coutParPersonne;
	}
}

void Groupe::equilibrerComptes()
{
	bool estEgal = false;
	 while (!estEgal){
		 for (unsigned i = 0; i < nombreUtilisateurs_ && comptes_[i]>0; i++) {
				 for (unsigned j = 0; j < nombreUtilisateurs_&& comptes_[j]<0; j++) {
					
				 }
			}
		 
		 }





		estEgal = true;
		for (unsigned i = 0; i < nombreUtilisateurs_; i++)
			if (comptes_[i] != 0)
				estEgal = false;
	 } 


void Groupe::afficherGroupe() //const?
{

}