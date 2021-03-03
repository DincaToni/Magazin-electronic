#pragma once
#include "Produse.h"
#include <iostream>
#include "Virtual.h"
using namespace std;

class Promotii : public Produse, public Virtual
{
private:
	float Discount;
public:
	Promotii();
	Promotii(int, string, float, int, float);
	Promotii(Promotii& p);
	void operator =(Promotii p);

	void afisare(int);

	void MutareCos(int);
};

