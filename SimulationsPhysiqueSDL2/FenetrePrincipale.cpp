#include "FenetrePrincipale.h"

FenetrePrincipale::FenetrePrincipale() {
	_fenetre = nullptr;

	_surface = nullptr;

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
	// Initialisation de SDL, prend en paramètre un flag qui indique quoi initialiser (ici on initialise tout)
	SDL_Init(SDL_INIT_EVERYTHING);

	// Création de la fenêtre
	// SDL_CreateWindow prend en paramètre, le label de la fenêtre, sa position (x et y), ses dimensions (largeur et hauteur en pixels) 
	// et une option (fullscreen, cachée etc..). Cette fonction retourne un pointeur sur SDL_Window
	_fenetre = SDL_CreateWindow("Ma fenetre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _largeur, _hauteur, SDL_WINDOW_SHOWN);
	// Si la création échoue, on affiche un message et on sort du programme
	if (!_fenetre) {
		std::cout << "Erreur création de la fenêtre" << std::endl;
		SDL_Quit();
	}
	// Sinon on créer la surface pour notre fenêtre
	_surface = SDL_GetWindowSurface(_fenetre);
}

void FenetrePrincipale::boucleFenetre() {
	// Cette boucle remplace l'utilisation de l'attente d'une entrée sur le cmd
	while (_fenetreEtat == Etat::EN_COURS) {
		evenementFenetre();
		colorierFenetre();
	}
	// Libère la mémoire allouée pour la fenêtre et toutes ses ressources (dont la surface)
	SDL_DestroyWindow(_fenetre);
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

void FenetrePrincipale::colorierFenetre() {
	// Le nom est assez clair, les paramètres moins : prend la surface sur la quelle dessiner, un pointeur sur SDL_Rect 
	// (si mis à NULL la fenêtre entière est colorée), puis un indicateur de couleur
	SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, 255, 0, 0));

	// Met à jour la fenêtre avec la surface modifiée
	SDL_UpdateWindowSurface(_fenetre);
}
