#include <iostream>
#include <SDL.h>

// Ce projet � pour but d'apprendre le C++ ainsi que de comprendre et r�aliser des simulations physiques (collisions, gravit�...)
// avec la librairie graphique SDL2, sa documentation et le cours de thenumb sur https://thenumb.at/cpp-course

int main(int argc, char** argv) {

	// Fen�tre sur laquelle se feront les affichages des I/O multim�dias 
	SDL_Window* fenetre = nullptr;

	// Une surface est une mani�re d'afficher les �l�ments par rendu logiciel (aucune utilisation de la carte graphique pour ce dernier)
	SDL_Surface* surface = nullptr;

	// Initialisation de SDL, prend en param�tre un flag qui indique quoi initialiser (ici on initialise tout)
	SDL_Init(SDL_INIT_EVERYTHING);

	// Cr�ation de la fen�tre
	// SDL_CreateWindow prend en param�tre, le label de la fen�tre, sa position (x et y), ses dimensions (largeur et hauteur en pixels) 
	// et une option (fullscreen, cach�e etc..). Cette fonction retourne un pointeur sur SDL_Window
	fenetre = SDL_CreateWindow("Ma fenetre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 720, SDL_WINDOW_SHOWN);
	// Si la cr�ation �choue, on affiche un message et on sort du programme
	if (!fenetre) {
		std::cout << "Erreur cr�ation de la fen�tre" << std::endl;
		return 1;
	}
	// Sinon on cr�er une surface pour notre fen�tre
	surface = SDL_GetWindowSurface(fenetre);
	
	// Le nom est assez clair, les param�tres moins : prend la surface sur la quelle dessiner, un pointeur sur SDL_Rect 
	// (si mis � NULL la fen�tre enti�re est color�e), puis un indicateur de couleur
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));

	// Met � jour la fen�tre avec la surface modifi�e
	SDL_UpdateWindowSurface(fenetre);

	std::cout << "Appuyez sur Entrer pour sortir du programme" << std::endl;
	std::cin.get();
	

	// Lib�re la m�moire allou�e pour la fen�tre et toutes ses ressources (dont la surface)
	SDL_DestroyWindow(fenetre);

	return 0;
}