/*
	Sudoku.cpp

	Read COPYING for my very permissive and delicious licence.

	-------------------

	Main grid construct, sample puzzle anmd first recursive call.

*/

#include "Grille.h"
#include <iostream>

int main()
{
	Grille g;

	// Grille test, supposée "infernale".
	g.Init({
		8,0,0,0,0,6,3,0,0,
		3,6,0,7,0,0,0,0,0,
		0,0,0,0,2,4,9,0,0,
		0,8,1,0,0,9,0,0,0,
		0,7,0,0,0,0,0,5,0,
		0,0,0,4,0,0,2,8,0,
		0,0,8,9,4,0,0,0,0,
		0,0,0,0,0,3,0,1,6,
		0,0,5,6,0,0,0,0,2 });
	
	g.Print();

	g.Recurse(0);
}

