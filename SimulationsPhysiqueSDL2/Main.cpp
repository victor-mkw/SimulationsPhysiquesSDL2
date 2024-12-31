#include <iostream>
#include <SDL.h>
#include "FenetrePrincipale.h"

// Ce projet à pour but d'apprendre le C++ ainsi que de comprendre et réaliser des simulations physiques (collisions, gravité...)
// avec la librairie graphique SDL2, sa documentation et le cours de C++ de thenumb sur https://thenumb.at/cpp-course

int main(int argc, char** argv) { 
	// Création d'une instance de fenêtre
	FenetrePrincipale f;
	// Démarre une nouvelle fenêtre
	f.demarrerFenetre();

	return 0;
}