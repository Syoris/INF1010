#include "groupe.h"
Groupe::Groupe():nom_("default"),totalDepenses_(0.0),tailleTabUtilisateurs_(5),listeUtilisateurs_(nullptr),nombreDepenses_(0),nombreUtilisateurs_(0),tailleTabDepenses_(10),comptes_(nullptr),nombreTransferts_(0),listeTransferts_(nullptr),listeDepenses_(nullptr)
{

	//Tableau utilisateurs.
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
		listeUtilisateurs_[i] = nullptr;
	
	//Tableau dépenses.
	listeDepenses_ = new Depense* [tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++)
		listeDepenses_[i] = nullptr;
	
	//on initialise les valeurs du tableau à zéro.
	comptes_ = new double[nombreUtilisateurs_];
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		comptes_[i] = 0;
	comptes_ = {};
	
	//Tableau transferts.
	listeTransferts_ = new Transfert*[nombreUtilisateurs_]; //pas nombre transfert?
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		listeTransferts_[i] = nullptr;

}

Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) :nom_(nom), totalDepenses_(0.0), tailleTabUtilisateurs_(tailleTabUtilisateurs), listeUtilisateurs_(nullptr), nombreDepenses_(0), nombreUtilisateurs_(0), tailleTabDepenses_(tailleTabDepenses), comptes_(nullptr), nombreTransferts_(0), listeTransferts_(nullptr), listeDepenses_(nullptr)
{
	
	//Tableau utilisateurs.
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
		listeUtilisateurs_[i] = nullptr;

	//Tableau dépenses.
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++)
		listeDepenses_[i] = nullptr;

	//on initialise les valeurs du tableau à zéro.
	comptes_ = new double[nombreUtilisateurs_];
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		comptes_[i] = 0;

	//Tableau transferts.
	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
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
	if (nombreDepenses_ >= tailleTabDepenses_) 
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

		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
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
	totalDepenses_ = 0.0;
	for (unsigned i = 0; i < nombreUtilisateurs_; i++) {
		listeUtilisateurs_[i]->calculerTotal();
		totalDepenses_ += listeUtilisateurs_[i]->getTotal();
	}
	//Calculer cout par personne
	double coutParPersonne = totalDepenses_ / nombreUtilisateurs_;
	
	//Mettre à jour les comptes
	for (unsigned i = 0; i < nombreUtilisateurs_; i++) {
		comptes_[i] = listeUtilisateurs_[i]->getTotal() - coutParPersonne;
	}
}

void Groupe::equilibrerComptes()
{
	bool comptesRegles = false;
	while (!comptesRegles)
	{
		{
			//On trouve d'abord l'utilisateur qui devrait recevoir le plus d'argent,
			//puis l'utilisateur qui devrait donner le plus d'argent.
			unsigned int indiceMax = 0;
			double montantMax = 0;
			unsigned int indiceMin = 0;
			double montantMin = 0;
			for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
			{
				if (montantMax < comptes_[i])
				{
					montantMax = comptes_[i];
					indiceMax = i;
				}

				if (montantMin > comptes_[i])
				{
					montantMin = comptes_[i];
					indiceMin = i;
				}
			}
			//On ajuste le compte de ces deux utilisateurs
			double montantTransfert = 0;

			if ((-montantMin) < montantMax)
				montantTransfert = -montantMin;
			else
				montantTransfert = montantMax; //montantTransfert contient désormais la valeur absolue minimale entre montantMin et montantMax.

			comptes_[indiceMax] -= montantTransfert;
			comptes_[indiceMin] += montantTransfert;

			if (montantMax != 0 && montantMin != 0)
			{
				Transfert* transfert = new Transfert(montantTransfert, listeUtilisateurs_[indiceMin], listeUtilisateurs_[indiceMax]);
				listeTransferts_[nombreTransferts_] = transfert;
				nombreTransferts_++;
				//On ajuste les comptes des utilisateurs dans listeUtilisateur??
			}
			else
				comptesRegles = true;
		}
	}
}

void Groupe::afficherGroupe() const
{
	cout << "L'évenement : " << nom_ << " a couté un total pour le groupe de : "
		<< endl << totalDepenses_ << " voici les dépenses :" << endl;
	
	for (unsigned int j = 0; j < nombreUtilisateurs_; j++)
		listeUtilisateurs_[j]->afficherUtilisateur();


	bool comptesAZero = true;
	for (unsigned int j = 0; j < nombreUtilisateurs_; j++)
		if (comptes_[j] != 0)
		{
			comptesAZero = false;
			break; //Si on trouve un compte pas à zéro, on sort de la boucle.
		}

	if (comptesAZero)
	{
		for (unsigned int h = 0; h < nombreTransferts_; h++)
			listeTransferts_[h]->afficherTransfert();
	}
	else
	{
		cout << "Soit les comptes suivants : " << endl;
		for (unsigned int j = 0; j < nombreUtilisateurs_; j++)
			cout << "\t" << listeUtilisateurs_[j]->getNom() << " : " << comptes_[j] << endl;
	}
	
}