#include <iostream>
#include <SDL.h>
#include "FenetrePrincipale.h"

// Ce projet � pour but d'apprendre le C++ ainsi que de comprendre et r�aliser des simulations physiques (collisions, gravit�...)
// avec la librairie graphique SDL2, sa documentation et le cours de C++ de thenumb sur https://thenumb.at/cpp-course

int main(int argc, char** argv) { 
	// Cr�ation d'une instance de fen�tre
	FenetrePrincipale f;
	// D�marre une nouvelle fen�tre
	f.demarrerFenetre();

	return 0;
}