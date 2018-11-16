
#include <iostream>
#include "groupe.h"
#include <string>

using namespace std; 

int main(int argc, const char * argv[]) {
    cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
    // Creer un  groupe pour  6 depenses et 4 utilisateurs.
	string nomGroupe = "Les joyeux lurons";
	Groupe groupe(nomGroupe, 6, 4);
    
	// Creer 5 utlisateurs.aa
	Utilisateur* U1 = new Utilisateur( "u1" );
	Utilisateur* U2 = new Utilisateur( "u2" );
	Utilisateur* U3 = new Utilisateur( "u3" );
	Utilisateur* U4 = new Utilisateur( "u4" );
	Utilisateur* U5 = new Utilisateur( "u5" );

	
	//Creer 7 dépenses.
	Depense* d1 = new Depense( "d1", 200 ); //s'tu dememe qu'on fait ça?
	Depense* d2 = new Depense( "d2", 10 );
	Depense* d3 = new Depense( "d3", 50 );
	Depense* d4 = new Depense( "d4", 50 );
	Depense* d5 = new Depense( "d5", 200);
	Depense* d6 = new Depense( "d6", 50 );
	Depense* d7 = new Depense( "d7", 60 );


	//ajouter les utilisateurs au groupe
	groupe.ajouterUtilisateur( U1 );
	groupe.ajouterUtilisateur( U2 );
	groupe.ajouterUtilisateur( U3 );
	groupe.ajouterUtilisateur( U4 );
	groupe.ajouterUtilisateur( U5 );

	//ajouter les depenses au groupe
	groupe.ajouterDepense( d1 , U1 );
	groupe.ajouterDepense( d2 , U2 );
	groupe.ajouterDepense( d3 , U3 );
	groupe.ajouterDepense( d4 , U4 );
	groupe.ajouterDepense( d5 , U5 );
	groupe.ajouterDepense( d6 , U1 );
	groupe.ajouterDepense( d7 , U1 );
    
    
    //calculer le total du groupe et de chaque utilisateur
	U1->calculerTotal();
	U2->calculerTotal();
	U3->calculerTotal();
	U4->calculerTotal();
	U5->calculerTotal();
	groupe.calculerTotalDepenses();

	
    //Afficher  le groupe
	groupe.afficherGroupe();
    
    //Equilibrer les comptes
	groupe.equilibrerComptes();
    //Afficher le groupe
	groupe.afficherGroupe();
   
    //terminer le programme correctement
	groupe.~Groupe();

	U1->~Utilisateur();
	U2->~Utilisateur();
	U3->~Utilisateur();
	U4->~Utilisateur();
	U5->~Utilisateur();
	delete U1;
	delete U2;
	delete U3;
	delete U4;
	delete U5;

	delete d1;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	delete d6;
	delete d7;

	//Réponses aux questions :
	/*

	Questions 1 :
		Le lien entre groupe et transfert est de l'agrégation par pointeur. En effet, la durée de vie des transferts est indépendante de la classe groupe.

	Question 2  :
		Lorsqu'elle est const, une méthode ne peut ni modifier les attributs de l'objet, ni faire appel a d'autres méthode non-constantes. 
	
	*/
}
