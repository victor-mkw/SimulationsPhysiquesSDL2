#include <iostream>
#include <SDL.h>

// Ce projet à pour but d'apprendre le C++ ainsi que de comprendre et réaliser des simulations physiques (collisions, gravité...)
// avec la librairie graphique SDL2, sa documentation et le cours de thenumb sur https://thenumb.at/cpp-course

int main(int argc, char** argv) {

	// Fenêtre sur laquelle se feront les affichages des I/O multimédias 
	SDL_Window* fenetre = nullptr;

	// Une surface est une manière d'afficher les éléments par rendu logiciel (aucune utilisation de la carte graphique pour ce dernier)
	SDL_Surface* surface = nullptr;

	// Initialisation de SDL, prend en paramètre un flag qui indique quoi initialiser (ici on initialise tout)
	SDL_Init(SDL_INIT_EVERYTHING);

	// Création de la fenêtre
	// SDL_CreateWindow prend en paramètre, le label de la fenêtre, sa position (x et y), ses dimensions (largeur et hauteur en pixels) 
	// et une option (fullscreen, cachée etc..). Cette fonction retourne un pointeur sur SDL_Window
	fenetre = SDL_CreateWindow("Ma fenetre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 720, SDL_WINDOW_SHOWN);
	// Si la création échoue, on affiche un message et on sort du programme
	if (!fenetre) {
		std::cout << "Erreur création de la fenêtre" << std::endl;
		return 1;
	}
	// Sinon on créer une surface pour notre fenêtre
	surface = SDL_GetWindowSurface(fenetre);
	
	// Le nom est assez clair, les paramètres moins : prend la surface sur la quelle dessiner, un pointeur sur SDL_Rect 
	// (si mis à NULL la fenêtre entière est colorée), puis un indicateur de couleur
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));

	// Met à jour la fenêtre avec la surface modifiée
	SDL_UpdateWindowSurface(fenetre);

	std::cout << "Appuyez sur Entrer pour sortir du programme" << std::endl;
	std::cin.get();
	

	// Libère la mémoire allouée pour la fenêtre et toutes ses ressources (dont la surface)
	SDL_DestroyWindow(fenetre);

	return 0;
}