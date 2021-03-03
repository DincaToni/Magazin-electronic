#pragma once
#include<iostream>
#include <list>

using namespace std;
class CosElectronic
{
protected:
	list  <string> Produse_comandate;
	list  <string> Cantitate_ProduseComandate;
	list  <string> PretProduseComandate;
	int NrProduse;

public:
	CosElectronic();
	list<string*> ListaCos();
};


