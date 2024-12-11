#pragma once
#include <iostream>
#include <SDL.h>

enum Etat { EN_COURS, ARRET };

// Classe en charge de la fenêtre SDL 
class FenetrePrincipale
{
public:
	// Constructeur de la classe FenetrePrincipale
	FenetrePrincipale();
	// Destructeur de la classe FenetrePrincipale
	~FenetrePrincipale();

	// Méthode qui démarre la fenêtre graphique en l'initialisant et en entrant dans la boucle
	void demarrerFenetre();

	// Méthode d'initialisation de la fenêtre
	void initialiserFenetre();

	// Méthode de boucle en attente des entrées de l'utilisateur
	void boucleFenetre();

	// Méthode qui gère les entrées/sorties en liens avec la fenêtre
	void evenementFenetre();

	// Méthode qui attribue une couleur à la fenêtre
	void colorierFenetre();

private:

	// Fenêtre sur laquelle se feront les affichages des I/O multimédias 
	SDL_Window* _fenetre;

	// Une surface est une manière d'afficher les éléments par rendu logiciel (aucune utilisation de la carte graphique pour ce dernier)
	SDL_Surface* _surface;

	// Dimensions de la fenêtre
	int _largeur;
	int _hauteur;

	// État courrant de la fenêtre
	Etat _fenetreEtat;
};

