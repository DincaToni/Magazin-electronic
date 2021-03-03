#pragma once
#include "Promotii.h"
#include <iostream>
#include "Virtual.h"
using namespace std;

class Resigilate : public Promotii, public Virtual
{
private:
	string Stare;

public:
	Resigilate();
	Resigilate(int, string, float, int, float, string);
	Resigilate(Resigilate& r);
	void operator=(Resigilate r);

	void afisare(int);

	void MutareCos(int);
};

