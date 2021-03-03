#pragma once
#include <iostream>
using namespace std;
class Client
{
protected:
	const int IDclient;
	string Nume;
	string Adresa;
	int Cod_postal;
	int Nr_telefon;
	string Email;

public: 
	Client();
	Client( int, string, string, int, int, string);

	string getNume();


	int getIDclient();

	string getAdresa();

	int getCod_postal();

	int getNr_telefon();

	string getEmail();
	
	Client(const Client& p);

	void operator=(Client p);

	void IntroducereDate();
	void AfisareClienti();
};
