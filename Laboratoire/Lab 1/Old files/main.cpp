
#include <iostream>
#include "groupe.h"
#include <string>

using namespace std; 

int main(int argc, const char * argv[]) {
    cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
    // Creer un  groupe pour  6 depenses et 4 utilisateurs.
  
    
    // Creer 5 utlisateurs.

    
    //Creer 7 dépenses.
    

    
    //ajouter les utilisateurs au groupe
    

    //ajouter les depenses au groupe
    

    
    //calculer le total du grouoe et de chaque utilisateur

    //Afficher  le groupe

    
    //Equilibrer les comptes

    //Afficher le groupe

   
    //terminer le programme correctement



	string nom = "allo";
	Depense* test1 =new Depense();
	Depense* test2 =new Depense("nom", 11);
	Depense* test3 =new Depense(nom, 22);
	Depense* test4 =new Depense(nom, 33);
	Depense* test5 =new Depense(nom, 44);
	Depense* test6 =new Depense(nom, 55);

	Utilisateur uTest1 = Utilisateur();
	Utilisateur utest2 = Utilisateur(nom);
	uTest1.ajouterDepense(test1);
	uTest1.ajouterDepense(test2);
	uTest1.ajouterDepense(test3);
	uTest1.ajouterDepense(test4);
	uTest1.ajouterDepense(test5);
	uTest1.ajouterDepense(test6);
	uTest1.afficherUtilisateur();
	
	int x;
	cin >> x;

}
