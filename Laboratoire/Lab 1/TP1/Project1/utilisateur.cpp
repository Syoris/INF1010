#include "utilisateur.h"

Utilisateur::Utilisateur():nom_("default"),tailleTabDepense_(5),nombreDepenses_(0),totalDepense_(0.0), listeDepenses_(nullptr)
{
	
	listeDepenses_ = new Depense*[tailleTabDepense_];
	for (unsigned int i = 0; i < tailleTabDepense_; i++)
		listeDepenses_[i] = nullptr;
}

Utilisateur::Utilisateur(const string& name): nom_(name), tailleTabDepense_(5), nombreDepenses_(0), totalDepense_(0.0),listeDepenses_(nullptr)
{
	listeDepenses_ = new Depense*[tailleTabDepense_];
	for (unsigned i = 0; i < tailleTabDepense_; i++)
		listeDepenses_[i] = nullptr;
}

Utilisateur::~Utilisateur() {
	delete[] listeDepenses_;
	listeDepenses_ = nullptr;
}

string Utilisateur::getNom() const{
	return (nom_);
}

unsigned int Utilisateur::getNombreDepense() const {
	return nombreDepenses_;
}

double Utilisateur::getTotal() const {
	return totalDepense_;
}

void Utilisateur::setNom(string& nom) {
	nom_ = nom;
}

void Utilisateur::ajouterDepense(Depense* uneDepense) {
	if (nombreDepenses_ >= tailleTabDepense_) {

		int newTaille = 2 * tailleTabDepense_;
		Depense** newArray = new Depense*[newTaille];

		for (unsigned i = 0; i < nombreDepenses_; i++) 
			newArray[i] = listeDepenses_[i];

		delete [] listeDepenses_;

		listeDepenses_ = newArray;

		tailleTabDepense_ = newTaille;
		newArray = nullptr;
	}
	listeDepenses_[nombreDepenses_] = uneDepense;
	nombreDepenses_++;
	totalDepense_ += uneDepense->getMontant();
}

void Utilisateur::calculerTotal() {
	totalDepense_ = 0;//valeur déjà initialisée à 0
	for (unsigned int i = 0; i < nombreDepenses_; i++)
		totalDepense_ += listeDepenses_[i]->getMontant();
}

void Utilisateur::afficherUtilisateur()  { // Pas const puisqu'on utilise la fonction calculerTotal() . 
	calculerTotal();
	cout << "\t Utilisateur : " << nom_ << " a dépensé pour un total de : " << totalDepense_ << endl ;
	cout << "\t Liste de dépenses :" << endl;
	for (unsigned int i = 0; i < nombreDepenses_; i++)
		listeDepenses_[i]->afficherDepense();
	cout << endl;
}
