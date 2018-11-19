/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
* Édité par Charles Sirois et Patrick Leclerc
* Classe d'un utilisateur générique
*******************************************/
#ifndef GESTIONNAIRE_GENERIQUE_H
#define GESTIONNAIRE_GENERIQUE_H

// Classe générique pour un gestionnaire où T est le type de donnée manipuler, 
// D est le type de retour de getElementParIndex,
// C est le type du conteneur et 
// FoncteurAjouter est le foncteur pour ajouter le type T dans C.

template<typename T, typename D, typename C, typename FoncteurAjouter>
class GestionnaireGenerique {
public:
	//Retourne le conteneur de type C de la classe
	C getConteneur() const{
		return conteneur_;
	};

	//Ajoute le type T au conteneur de type C
	void ajouter(T t) {
		FoncteurAjouter f(conteneur_);
		conteneur_ = f(t);
	};

	//Retourne le nombre d'éléments dans le conteneur_
	int getNombreElements() const {
		return conteneur_.size();
	};

	// Retourne l'élément de type D à la position i du conteneur_
	D getElementParIndex(int i) const {
		return conteneur_[i];
	};

protected:
	C conteneur_;

};
	
#endif // !GESTIONNAIRE_GENERIQUE_H


