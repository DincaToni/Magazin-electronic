#include "CosElectronic.h"
#include <iostream>
#include <list>
using namespace std;


CosElectronic::CosElectronic()
{
	string x = " Placa video";
	string y = " Ram,";

	int	NrProduse = 0;

	int a = 4;
	int b = 5;

	int h = 2500;
	int i = 250;
	int sum = 0;


	list<string> ListaProduselorComandate;
	ListaProduselorComandate.push_back(y);
	NrProduse++;
	ListaProduselorComandate.insert(ListaProduselorComandate.end(), x);
	NrProduse++;
	list<string>::iterator itListaProduselorComandate;
	cout << "Ati adaugat in cos urmatoarele elemente :";
	for (auto& itListProduselorComandate : ListaProduselorComandate)
	{
		cout << itListProduselorComandate << " ";
	}
	cout << endl;


	list<int> ListaCantitateProduseComandate;
	ListaCantitateProduseComandate.push_back(a);
	ListaCantitateProduseComandate.push_front(b);
	list<int>::iterator itListaCantitateProduseComandate;
	cout << "Cantitatea produselor comandate este : ";
	for (auto& itListaCantitateProduseComandate : ListaCantitateProduseComandate)
	{
		cout << itListaCantitateProduseComandate << " ";
	}
	cout << endl;


	list<int> ListaPretProduseComandate;
	ListaPretProduseComandate.push_back(i);
	ListaPretProduseComandate.push_front(h);
	list<int>::iterator itListaPretPretProduseComandate;
	cout << "Pretul Produselor comandate este : ";
	sum = h + i;
	cout << h << " + " << i << " = " << sum;
};