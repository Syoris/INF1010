/*
Écrit par :
Patrick Leclerc 1899303
Charles Sirois 1894544

En-tête d'un utilisateur.
Classe pour suivre les dépenses effectué par un utilisateur et son nom.

*/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

class Utilisateur {
    public :
    // constructeurs
    Utilisateur();
    Utilisateur(const string& nom);
    
    //Destructeur
    ~Utilisateur(); 
    
    //Methodes d'accès
    string getNom() const;
    unsigned int getNombreDepense() const;
    double getTotal() const;
  
    //Methode de modification
    void setNom(string& nom);
    
    // Methode ajout de dépense
    void ajouterDepense(Depense* uneDepense);
    
    //Methode de calcul total
    void calculerTotal();
    
    //Mathode d'affichage
    void afficherUtilisateur();
    
    private :
        string nom_;
        unsigned int tailleTabDepense_;
        unsigned int nombreDepenses_;
        double totalDepense_;
        Depense ** listeDepenses_;
    
    
};
#endif 
