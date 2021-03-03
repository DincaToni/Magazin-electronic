#include "Resigilate.h"
#include <iostream>
#include <fstream>

using namespace std;

Resigilate::Resigilate():Promotii()
{
	this->Stare = "Perfecta";
}

Resigilate::Resigilate(int IdProdus, string NumeProdus, float pret, int stoc, float Discount, string Stare) : Promotii(IdProdus, NumeProdus, pret, stoc, Discount)
{
	this->Stare = Stare;
}

Resigilate::Resigilate(Resigilate& r) : Promotii()
{
	this->Stare = r.Stare;
}

void Resigilate::operator=(Resigilate r)
{
	this->Promotii :: operator=(r);
	this->Stare = r.Stare;
}

void Resigilate::afisare(int t)
{
	this->Promotii::afisare(t);
	size_t size;
	string Stare;
	ofstream outfile("Produse.dat", ios::binary | ios::app);
	if (outfile.is_open()) {
		cout << "Introduceti Starea produsului: ";
		char buffer1[50];
		cin.get();
		cin.get(buffer1, 50);
		Stare = buffer1;
		size = Stare.size();
		outfile.write((char*)&size, sizeof(size_t));
		outfile.write((char*)Stare.c_str(), size);
		outfile.close();
	}
	else cerr << "Fisierul Produse.dat nu a putut fi deschis";
}

void Resigilate::MutareCos(int)
{
}

