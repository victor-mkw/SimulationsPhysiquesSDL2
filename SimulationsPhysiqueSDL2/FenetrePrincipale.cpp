#include "FenetrePrincipale.h"

FenetrePrincipale::FenetrePrincipale() {
	_fenetre = nullptr;

	_largeur = 1024;
	_hauteur = 720;

	_fenetreEtat = Etat::EN_COURS;
}

FenetrePrincipale::~FenetrePrincipale() {}

void FenetrePrincipale::demarrerFenetre() {
	initialiserFenetre();
	boucleFenetre();
}

void FenetrePrincipale::initialiserFenetre() {
	// Initialisation de SDL, prend en param�tre un flag qui indique quoi initialiser (ici on initialise tout)
	SDL_Init(SDL_INIT_EVERYTHING);

	// Cr�ation de la fen�tre
	// SDL_CreateWindow prend en param�tre, le label de la fen�tre, sa position (x et y), ses dimensions (largeur et hauteur en pixels) 
	// et une option (fullscreen, cach�e etc..). Cette fonction retourne un pointeur sur SDL_Window
	_fenetre = SDL_CreateWindow("Ma fenetre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _largeur, _hauteur, SDL_WINDOW_SHOWN);
	// Si la cr�ation �choue, on affiche un message et on sort du programme
	if (!_fenetre) {
		std::cout << "Erreur cr�ation de la fen�tre" << std::endl;
		SDL_Quit();
	}
}

void FenetrePrincipale::boucleFenetre() {
	// Cette boucle remplace l'utilisation de l'attente d'une entr�e sur le cmd
	while (_fenetreEtat == Etat::EN_COURS) {
		evenementFenetre();
	}
}

void FenetrePrincipale::evenementFenetre() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_fenetreEtat = Etat::ARRET;
			break;
		}
	}
}
