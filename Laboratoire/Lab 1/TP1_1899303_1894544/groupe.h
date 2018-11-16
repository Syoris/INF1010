/*
Écrit par :
Patrick Leclerc 1899303
Charles Sirois 1894544

En-tête d'un groupe.
Classe pour suivre les dépenses effectué par plusieurs utilisateur et s'assurer que chaque personnne paye le même montant à la fin du voyage.

*/
#ifndef GROUPE_H
#define GROUPE_H


#include "transfert.h"
#include <string>
using namespace std;

class Groupe{
    public :
    //Constructeurs
    Groupe();
    Groupe( string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs);
    
    //Destructeur
    ~Groupe();
    
    //methode d'acces
    string getNom() const;
    unsigned int getNombreDepenses() const;
    double getTotal() const;
    
    //Methodes de modification
    void setNom(string& nom);
    
    //Methodes d'ajout
    void ajouterDepense(Depense* uneDepense, Utilisateur* payePar);
    void ajouterUtilisateur(Utilisateur* unUtilisateur);
    
    //Méthode de calcul
    void calculerTotalDepenses();
    void equilibrerComptes();
    
    //methode d'affichage
    void afficherGroupe() const;
    
    private :
        string nom_;
        double totalDepenses_;
        Utilisateur** listeUtilisateurs_;
        unsigned int nombreDepenses_;
        unsigned int nombreUtilisateurs_;
        unsigned int tailleTabUtilisateurs_;
        unsigned int tailleTabDepenses_;
        Depense** listeDepenses_;
        double* comptes_;
        Transfert** listeTransferts_;
        unsigned int nombreTransferts_; 
    
};

#endif 
