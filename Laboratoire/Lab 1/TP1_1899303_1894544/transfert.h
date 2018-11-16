/*
Écrit par :
Patrick Leclerc 1899303
Charles Sirois 1894544

Implémentation d'un transfert.
Classe pour suivre le transfert d'argent entre deux utilisateurs.

*/
#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>
#include <stdio.h>

class Transfert {
    public :
    
    // Constructeurs
    Transfert();
    Transfert(double montant, Utilisateur* de, Utilisateur* pour);
    
    // Méthodes d'accès
    
    Utilisateur* getDonneur() const;
    Utilisateur* getReceveur() const;
    double getMontant() const;
    
    
    //Méthode d'affichage
    void setDonneur(Utilisateur* donneur);
    void setMontant(double montant);
    void setReceveur(Utilisateur* receveur);
    
    void afficherTransfert() const;
    
    private :
        double montant_;
        Utilisateur* donneur_;
        Utilisateur* receveur_;
    

};
#endif
