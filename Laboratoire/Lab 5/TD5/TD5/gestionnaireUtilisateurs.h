/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "utilisateur.h"

#include <vector>

class GestionnaireUtilisateur: public GestionnaireGenerique<Utilisateur*, double, map<Utilisateur*,double>, AjouterUtilisateur> {
public:


};