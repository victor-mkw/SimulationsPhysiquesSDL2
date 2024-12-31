#include "FenetrePrincipale.h"

static SDL_Rect r;

FenetrePrincipale::FenetrePrincipale() {
	_fenetre = nullptr;

	_moteurRendu = nullptr;

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
	_moteurRendu = SDL_CreateRenderer(_fenetre, -1, SDL_RENDERER_ACCELERATED);
	if (!_moteurRendu) {
		std::cout << "Erreur création du moteur de rendu" << std::endl;
		SDL_Quit();	
	}

	SDL_SetRenderDrawColor(_moteurRendu, 255, 255, 255, 255);
	SDL_RenderClear(_moteurRendu);
}

void FenetrePrincipale::boucleFenetre() {
	SDL_SetRenderDrawColor(_moteurRendu, 255, 255, 255, 255);
	SDL_RenderClear(_moteurRendu);
	// Cette boucle remplace l'utilisation de l'attente d'une entrée sur le cmd
	while (_fenetreEtat == Etat::EN_COURS) {
		evenementFenetre();

		SDL_RenderPresent(_moteurRendu);
	}
	// Libère la mémoire allouée pour le moteur de rendu
	SDL_DestroyRenderer(_moteurRendu);
	// Libère la mémoire allouée pour la fenêtre et toutes ses ressources
	SDL_DestroyWindow(_fenetre);
}

void FenetrePrincipale::evenementFenetre() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_fenetreEtat = Etat::ARRET;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_SPACE:
				SDL_SetRenderDrawColor(_moteurRendu, 255, 0, 0, 255);

				r.x = 500;
				r.y = 300;
				r.w = 200;
				r.h = 200;

				SDL_RenderFillRect(_moteurRendu, &r);
				break;

			case SDL_SCANCODE_BACKSPACE:
				SDL_SetRenderDrawColor(_moteurRendu, 0, 0, 255, 255);

				r.x = 500;
				r.y = 300;
				r.w = 200;
				r.h = 200;

				SDL_RenderFillRect(_moteurRendu, &r);
				break;
			}
		case SDL_MOUSEMOTION:
			break;

		}
		
	}
}

void FenetrePrincipale::colorierFenetre() {
	NULL;
}
