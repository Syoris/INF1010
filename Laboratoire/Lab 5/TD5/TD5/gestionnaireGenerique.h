/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

template<typename T, typename D, typename C, typename FoncteurAjouter>
class GestionnaireGenerique {
public:

	C getConteneur() const{
		return conteneur_;
	};
	void ajouter(T t) {
		FoncteurAjouter f;
		f(t);
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
	


