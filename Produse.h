#pragma once
#include <iostream>
#include "Virtual.h"

using namespace std;

class Produse : public Virtual
{
private:
	const int IdProdus;
	string NumeProdus;
	float pret;
	int stoc;
public:
	Produse();
	Produse(int, string, float, int);
	Produse(Produse& p);
	void operator = (Produse p);

	virtual void afisare( int);
	void afisareEcran(int);
	void stergere(int);
	
	void MutareCos(int);
};

