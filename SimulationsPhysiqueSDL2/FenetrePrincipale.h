#pragma once
#include <iostream>
#include <SDL.h>

enum Etat { EN_COURS, ARRET };

// Classe en charge de la fen�tre SDL 
class FenetrePrincipale
{
public:
	// Constructeur de la classe FenetrePrincipale
	FenetrePrincipale();
	// Destructeur de la classe FenetrePrincipale
	~FenetrePrincipale();

	// M�thode qui d�marre la fen�tre graphique en l'initialisant et en entrant dans la boucle
	void demarrerFenetre();

	// M�thode d'initialisation de la fen�tre
	void initialiserFenetre();

	// M�thode de boucle en attente des entr�es de l'utilisateur
	void boucleFenetre();

	// M�thode qui g�re les entr�es/sorties en liens avec la fen�tre
	void evenementFenetre();

	// M�thode qui attribue une couleur � la fen�tre
	void colorierFenetre();

private:

	// Fen�tre sur laquelle se feront les affichages des I/O multim�dias 
	SDL_Window* _fenetre;

	// Une surface est une mani�re d'afficher les �l�ments par rendu logiciel (aucune utilisation de la carte graphique pour ce dernier)
	SDL_Surface* _surface;

	// Dimensions de la fen�tre
	int _largeur;
	int _hauteur;

	// �tat courrant de la fen�tre
	Etat _fenetreEtat;
};

