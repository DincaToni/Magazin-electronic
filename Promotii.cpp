#include "Promotii.h"
#include <iostream>
#include <fstream>

using namespace std;

Promotii::Promotii() : Produse()
{
	this->Discount = 0.05;
}

Promotii::Promotii(int IdProdus, string NumeProdus, float pret, int stoc, float Discount) : Produse(IdProdus, NumeProdus, pret, stoc)
{
	if (Discount > 0)
		this->Discount = Discount;
	else this->Discount = 0;
}

Promotii::Promotii(Promotii& p): Produse(p)
{
	this->Discount = p.Discount;
}

void Promotii::operator=(Promotii p)
{
	this->Produse:: operator=(p);
		this->Discount = p.Discount;
}


void Promotii::afisare(int t)
{
	this->Produse::afisare(t);
	float Discount;
	ofstream outfile("Produse.dat", ios::binary | ios::app);
	if (outfile.is_open()) {
		cout << "Introduceti Discountul produsului: ";
		cin >> Discount;
		outfile.write((char*)&Discount, sizeof(float));
		outfile.close();
	}
	else cerr << "Fisierul Produse.dat nu a putut fi deschis";
}

void Promotii::MutareCos(int t)
{
}

