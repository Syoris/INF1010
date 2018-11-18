/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
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

	C getConteneur() const{
		return conteneur_;
	};
	void ajouter(T t) {
		FoncteurAjouter f(conteneur_);
		conteneur_ = f(t);
	};
	int getNombreElements() const {
		return conteneur_.size();
	};
	D getElementParIndex(int i) const {
		return conteneur_[i];
	};

protected:
	C conteneur_;

};
	
#endif // !GESTIONNAIRE_GENERIQUE_H


