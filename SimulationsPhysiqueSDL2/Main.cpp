#include <iostream>
#include <SDL.h>

// Ce projet � pour but d'apprendre le C++ ainsi que de comprendre et r�aliser des simulations physiques (collisions, gravit�...)
// avec la librairie graphique SDL2, sa documentation et le cours de thenumb sur https://thenumb.at/cpp-course

int main(int argc, char** argv) {

	SDL_Window* fenetre = nullptr;

	// Une surface est une mani�re d'afficher les �l�ments par rendu logiciel (aucune utilisation de la carte graphique pour ce dernier)
	SDL_Surface* surface = nullptr;

	// Sinon on cr�er une surface pour notre fen�tre
	surface = SDL_GetWindowSurface(fenetre);
	
	// Le nom est assez clair, les param�tres moins : prend la surface sur la quelle dessiner, un pointeur sur SDL_Rect 
	// (si mis � NULL la fen�tre enti�re est color�e), puis un indicateur de couleur
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));

	// Met � jour la fen�tre avec la surface modifi�e
	SDL_UpdateWindowSurface(fenetre);

	// Lib�re la m�moire allou�e pour la fen�tre et toutes ses ressources (dont la surface)
	SDL_DestroyWindow(fenetre);

	return 0;
}