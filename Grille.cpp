/*
   Grille.cpp

    Read COPYING for my very permissive and delicious licence.

    -------------------

    Grid implementation.

	Init()   : Initializes the grid.
	Print()  : Prints the grid.
	Recurse(): Main recursive function.
	CheckH() : Horizontal test.
	CheckV() : Vertical test.
	CheckZ() : Zone test.
*/

#include "Grille.h"
#include <iostream>

void Grille::Init(const std::vector<int> uniques)
{
	Cellules.clear();

	for (int c : uniques)
		Cellules.push_back(c);
}

void Grille::Print()
{
	int i = 0;

	std::cout << "|-----------------------------------|" << std::endl;

	for (int &c : Cellules)
	{
		if (i != 0 && !(i % 9))
			std::cout << "|" << std::endl << "|-----------------------------------|" << std::endl;

		if (c == 0)
			std::cout << "| . ";
		else
			std::cout << "| " << c << " ";

		i++;
	}

	std::cout << "|" << std::endl << "|-----------------------------------|" << std::endl << std::endl;

}

void Grille::Recurse(int i)
{
	if (i == 81)
	{
		Print();
		exit(0);
	}

	if (Cellules[i] != 0)
		Recurse(i + 1);
	else
	{
		for (int v = 1; v <= 9; v++)
		{
			Cellules[i] = v;

			if (CheckH(i, v) && CheckV(i, v) && CheckZ(i, v))
				Recurse(i + 1);
		}

		Cellules[i] = 0;
	}
}

bool Grille::CheckH(int i, int v)
{
	int d = i / 9 * 9;	// Début
	int f = d + 8;	// Fin

	for (int j = d; j <= f; j++ )
	{
		if (j != i && Cellules[j] == v)
			return false;
	}

	return true;
}

bool Grille::CheckV(int i, int v)
{
	int d = i % 9; // Déplacement

	for (int j = 0; j <= 8; j++)
	{
		int r = j * 9 + d; // Colonne

		if (r != i && Cellules[r] == v)
			return false;
	}

	return true;
}

bool Grille::CheckZ(int i, int v)
{
	std::vector<int> d = { 0, 1, 2, 9, 10, 11, 18, 19, 20 }; // Déplacements

	int z = ((i / 3 * 3) % 9) + (i / 27 * 27 / 9 * 9);	// Zones

	for (int j = 0; j <= 8; j++)
	{
		int t = z + d[j];	// Total de la zone + déplacement.

		if (t != i && Cellules[t] == v)
			return false;
	}

	return true;
}


