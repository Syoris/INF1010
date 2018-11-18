/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include <map>
#include <utility>

#include "groupe.h"

/*
	Foncteur AjouterDepense

	M�thode :
	Constructeur
	vector<Depense*>& operator()();

	Attribut :
	vector<Depense*> conteneur_;
*/
class AjouterDepense {
public:
	AjouterDepense(vector<Depense*>& conteneur) :conteneur_(conteneur) {};
	vector<Depense*>& operator()(Depense* depense) {
		conteneur_.push_back(depense);
		return conteneur_;
	};
private:
	vector<Depense*> conteneur_;
};


/*
Foncteur AjouterUtilisateur

M�thode :
Constructeur
map<Utilisateur*, double>& operator()();

Attribut :
map<Utilisateur*, double> conteneur_;
*/
class AjouterUtilisateur {
public:
	AjouterUtilisateur(map<Utilisateur*, double>& conteneur) :conteneur_(conteneur) {};
	map<Utilisateur*, double>& operator()(Utilisateur* utilisateur) {
		pair<Utilisateur*, double> pair = make_pair(utilisateur, 0);
		conteneur_.insert(pair);
		return conteneur_;
	}
private:
	map<Utilisateur*, double> conteneur_;
};


/*
Foncteur FoncteurIntervalle

M�thode :
Constructeur
bool operator()();

Attribut :
double borneInf_, borneSup_;
*/
class FoncteurIntervalle {
public:
	FoncteurIntervalle(double borneInf, double borneSup) :borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<Utilisateur*, double> pair) {
		return((pair.second > borneInf_ && pair.second < borneSup_) ? true : false);
	};

private:
	double borneInf_, borneSup_;
};
