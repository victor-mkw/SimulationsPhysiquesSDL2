#include <iostream>
#include <SDL.h>

// Ce projet à pour but d'apprendre le C++ ainsi que de comprendre et réaliser des simulations physiques (collisions, gravité...)
// avec la librairie graphique SDL2, sa documentation et le cours de thenumb sur https://thenumb.at/cpp-course

int main(int argc, char** argv) {

	SDL_Window* fenetre = nullptr;

	// Une surface est une manière d'afficher les éléments par rendu logiciel (aucune utilisation de la carte graphique pour ce dernier)
	SDL_Surface* surface = nullptr;

	// Sinon on créer une surface pour notre fenêtre
	surface = SDL_GetWindowSurface(fenetre);
	
	// Le nom est assez clair, les paramètres moins : prend la surface sur la quelle dessiner, un pointeur sur SDL_Rect 
	// (si mis à NULL la fenêtre entière est colorée), puis un indicateur de couleur
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));

	// Met à jour la fenêtre avec la surface modifiée
	SDL_UpdateWindowSurface(fenetre);

	// Libère la mémoire allouée pour la fenêtre et toutes ses ressources (dont la surface)
	SDL_DestroyWindow(fenetre);

	return 0;
}