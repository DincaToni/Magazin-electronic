#pragma once
#include "Client.h"
#include "CosElectronic.h"
#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;

Client::Client() : IDclient(1)
{
	this -> Nume= "Cviatcovschi Stefan";
	this -> Adresa = "Dimitrie Grozdea";
	this-> Cod_postal = 123456;
	this-> Nr_telefon = 0770654321;
	this-> Email = "cviatcovschistefan@gmail.com";

}

Client:: Client(int IDclient ,string Nume, string Adresa, int Cod_postal, int Nr_Telefon, string Email) : IDclient(IDclient){
	if (Nume != "")
		this->Nume = Nume;
	else
		this->Nume = "Cviatcovschi Stefan";

		if (Adresa != "")
		this->Adresa = Adresa;
	else
		this->Adresa = "Dimitrie Grozdea";

	if (Cod_postal < 0)
		this->Cod_postal = Cod_postal;
	else
		this->Cod_postal = 123456;

	if (Nr_Telefon < 0)
		this->Nr_telefon = Nr_telefon;
	else
		this->Nr_telefon = 0770654321;

	if (Email != "")
		this->Email = Email;
	else
		this->Email = "cviatcovschistefan@gmail.com";
}

string Client::getNume()
{
	return Nume;
}

int Client::getIDclient()
{
	return IDclient;
}

string Client::getAdresa()
{
	return Adresa;
}

int Client::getCod_postal()
{
	return Cod_postal;
}

int Client::getNr_telefon()
{
	return Nr_telefon;
}

string Client::getEmail()
{
	return Email;
}

void setNume(string Nume)
{
	if (Nume != "")
		Nume = Nume;
}

void setID_client(int ID_client)
{
	if (ID_client != 0)
		ID_client = ID_client;
}


void setPrenume(string Prenume)
{
	if (Prenume != "")
		Prenume = Prenume;
}

void setAdresa(string Adresa)
{
	if (Adresa != "")
		Adresa = Adresa;
}

void setCod_Postal(int Cod_Postal)
{
	if (Cod_Postal < 0)
		Cod_Postal = Cod_Postal;
}

void setNr_telefon(int Nr_telefon)
{
	if (Nr_telefon < 0)
		Nr_telefon = Nr_telefon;

}

void setEmail(string Email)
{
	if (Email != "")
		Email = Email;
}


Client::Client(const Client& p) : IDclient(p.IDclient)
{
	this->Nume = p.Nume;
	this->Adresa = p.Adresa;
	this->Cod_postal = p.Cod_postal;
	this-> Nr_telefon = p.Nr_telefon;
	this-> Email = p.Email;
}
		
void Client:: operator=(Client p) 
{
	this->Nume = p.Nume;
	this->Adresa = p.Adresa;
	this->Cod_postal = p.Cod_postal;
	this->Nr_telefon = p.Nr_telefon;
	this->Email = p.Email;
}

void Client::IntroducereDate()
{
	ofstream outfile("Clienti.dat", ios::binary | ios::app);
	if (outfile.is_open()) {
		size_t size;
		int IDclient, Cod_postal, Nr_telefon;
		string Nume , Adresa, Email;
		cout << "Introduceti un Id: ";
		cin >> IDclient;
		cout << "Introduceti Numele si Prenumele dumneavoastra: ";
		char buffer[100];
		cin.get();
		cin.get(buffer, 100);
		Nume = buffer;
		cout << "Introduceti Adresa dumneavoastra: ";
		cin.get();
		cin.get(buffer, 100);
		Adresa = buffer;
		cout << "Introduceti Codul Postal produsului: ";
		cin >> Cod_postal;
		cout << "Introduceti numarul dumneavoastra de telefon: ";
		cin >> Nr_telefon;
		cout << "Introduceti adresa dumneavoastra de Email: ";
		cin.get();
		cin.get(buffer, 100);
		Email = buffer;
		outfile.write((char*)&IDclient, sizeof(int));
		size = Nume.size();
		outfile.write((char*)&size, sizeof(size_t));
		outfile.write((char*)Nume.c_str(), size);

		size = Adresa.size();
		outfile.write((char*)&size, sizeof(size_t));
		outfile.write((char*)Adresa.c_str(), size);

		outfile.write((char*)&Cod_postal, sizeof(int));
		outfile.write((char*)&Nr_telefon, sizeof(int));

		size = Email.size();
		outfile.write((char*)&size, sizeof(size_t));
		outfile.write((char*)Email.c_str(), size);

		outfile.close();
	}
	else cerr << "Fisierul Clienti.dat nu a putut fi deschis";
}

void Client::AfisareClienti()
{
	ifstream infile("Clienti.dat", ios::binary);
	if (infile.is_open()) {
		if (infile.peek() == -1) cout << endl << "----" << endl << endl << "Ne pare rau, momentan nu exista clienti inscrisi in baza!" << endl;
		else
		{
			size_t size;
			char* data;
			int IDclient, Cod_postal, Nr_telefon;
			string Nume, Adresa, Email;
			infile.read((char*)&IDclient, sizeof(int));

			infile.read((char*)&size, sizeof(size));
			data = new char[size + 1];
			infile.read(data, size);
			data[size] = '\0';
			Nume = data;

			infile.read((char*)&size, sizeof(size));
			data = new char[size + 1];
			infile.read(data, size);
			data[size] = '\0';
			Adresa = data;
			delete[] data;

			infile.read((char*)&Cod_postal, sizeof(int));
			infile.read((char*)&Nr_telefon, sizeof(int));

			infile.read((char*)&size, sizeof(size));
			data = new char[size + 1];
			infile.read(data, size);
			data[size] = '\0';
			Email = data;
			delete[] data;
			
			while (infile) {
				cout << IDclient << setw(25) << Nume << setw(25) << Adresa << setw(25)<< Cod_postal << setw(25) << Nr_telefon << setw(25) << Email << endl;				
				infile.read((char*)&IDclient, sizeof(int));

				infile.read((char*)&size, sizeof(size));
				data = new char[size + 1];
				infile.read(data, size);
				data[size] = '\0';
				Nume = data;

				infile.read((char*)&size, sizeof(size));
				data = new char[size + 1];
				infile.read(data, size);
				data[size] = '\0';
				Adresa = data;
				delete[] data;

				infile.read((char*)&Cod_postal, sizeof(int));
				infile.read((char*)&Nr_telefon, sizeof(int));

				infile.read((char*)&size, sizeof(size));
				data = new char[size + 1];
				infile.read(data, size);
				data[size] = '\0';
				Email = data;
				delete[] data;
				
			}

			infile.close();
		}
	}
	else cerr << "Fisierul Clienti.dat nu a putut fi deschis";
}
