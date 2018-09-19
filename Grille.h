/*
   Grille.h

    Read COPYING for my very permissive and delicious licence.

    -------------------

    Grid header file.
*/


#pragma once
#include <vector>

class Grille
{

protected:

	std::vector<int> Cellules;

	bool CheckH(int i, int v);
	bool CheckV(int i, int v);
	bool CheckZ(int i, int v);


public:

	void Init(const std::vector<int> uniques);
	void Print();
	void Recurse(int index);
};

