#include "Produse.h"
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;


Produse::Produse() : IdProdus (1)
{
	this->NumeProdus = "Masina de spalat rufe Zanussi";
	this->pret = 1179.90;
	this->stoc = 50;
}

Produse::Produse(int IdProdus, string NumeProdus, float pret, int stoc) : IdProdus(IdProdus)
{
	this->NumeProdus = NumeProdus;
	if (pret > 0) this->pret = pret;
	else this->pret = 0;
	if (stoc > 0) this->stoc = stoc;
	else this->stoc = 0;
}

Produse::Produse(Produse& p) : IdProdus(p.IdProdus)
{
	this->NumeProdus = p.NumeProdus;
	this->pret = p.pret;
	this->stoc = p.stoc;
}

void Produse::operator=(Produse p)
{
	this->NumeProdus = p.NumeProdus;
	this->pret = p.pret;
	this->stoc = p.stoc;
}


void Produse:: afisare( int t)
{
	ofstream outfile("Produse.dat", ios::binary | ios:: app);
	if (outfile.is_open()) {
		size_t size;
		int IdProdus, stoc;
		string NumeProdus;
		float pret;
		cout << "Introduceti Id-ul produsului: ";
		cin >> IdProdus;
		IdProdus = IdProdus * 10 + t;
		cout << "Introduceti Numele produsului: ";
		char buffer[100];
		cin.get();
		cin.get(buffer,100);
		NumeProdus = buffer;
		cout << "Introduceti Pretul produsului: ";
		cin >> pret;
		cout << "Introduceti stocul produsului: ";
		cin >> stoc;
		outfile.write((char*)&IdProdus, sizeof(int));
		size = NumeProdus.size();
		outfile.write((char*)&size, sizeof(size_t));
		outfile.write((char*)NumeProdus.c_str(), size);
		outfile.write((char*)&pret, sizeof(float));
		outfile.write((char*)&stoc, sizeof(int));
		outfile.close();
	}
	else cerr << "Fisierul Produse.dat nu a putut fi deschis";
}

void Produse::afisareEcran( int t)
{
	ifstream infile("Produse.dat", ios::binary);
	if (infile.is_open()) {
		if (infile.peek() == -1) cout << endl << "----" << endl <<endl<<"Ne pare rau, momentan nu exista produse in magazin!" << endl;
		else
		{
			size_t size;
			char* data;
			int IdProdus, stoc;
			string NumeProdus, Stare;
			float pret, Discount;
			infile.read((char*)&IdProdus, sizeof(int));
			if (IdProdus % 10 == 1) {
				infile.read((char*)&size, sizeof(size));
				data = new char[size + 1];
				infile.read(data, size);
				data[size] = '\0';
				NumeProdus = data;
				delete[] data;
				infile.read((char*)&pret, sizeof(float));
				infile.read((char*)&stoc, sizeof(int));
			}
			if (IdProdus % 10 == 2) {
				infile.read((char*)&size, sizeof(size));
				data = new char[size + 1];
				infile.read(data, size);
				data[size] = '\0';
				NumeProdus = data;
				delete[] data;
				infile.read((char*)&pret, sizeof(float));
				infile.read((char*)&stoc, sizeof(int));
				infile.read((char*)&Discount, sizeof(float));
			}
			if (IdProdus % 10 == 3) {
				infile.read((char*)&size, sizeof(size_t));
				data = new char[size + 1];
				infile.read(data, size);
				data[size] = '\0';
				NumeProdus = data;
				delete[] data;
				infile.read((char*)&pret, sizeof(float));
				infile.read((char*)&stoc, sizeof(int));
				infile.read((char*)&Discount, sizeof(float));
				infile.read((char*)&size, sizeof(size_t));
				data = new char[size + 1];
				infile.read(data, size);
				data[size] = '\0';
				Stare = data;
				delete[] data;
			}
			while (infile) {
				if (IdProdus % 10 == 1 && IdProdus % 10 == t) {
					cout << IdProdus << setw(30) << NumeProdus << setw(30) << pret << setw(30); if (stoc > 0) cout << "DA" << endl; else cout << "NU" << endl;
				}
				if (IdProdus % 10 == 2 && IdProdus % 10 == t) {
					cout << IdProdus << setw(30) << NumeProdus << setw(30) << pret << setw(30) << Discount << setw(30); if (stoc > 0) cout << "DA" << endl; else cout << "NU" << endl;
				}
				if (IdProdus % 10 == 3 && IdProdus % 10 == t) {
					cout << IdProdus << setw(23) << NumeProdus << setw(23) << pret << setw(23) << Discount << setw(23) << Stare << setw(23); if (stoc > 0) cout << "DA" << endl; else cout << "NU" << endl;
				}
				infile.read((char*)&IdProdus, sizeof(int));
				if (IdProdus % 10 == 1) {
					infile.read((char*)&size, sizeof(size));
					data = new char[size + 1];
					infile.read(data, size);
					data[size] = '\0';
					NumeProdus = data;
					delete[] data;
					infile.read((char*)&pret, sizeof(float));
					infile.read((char*)&stoc, sizeof(int));
				}
				if (IdProdus % 10 == 2) {
					infile.read((char*)&size, sizeof(size));
					data = new char[size + 1];
					infile.read(data, size);
					data[size] = '\0';
					NumeProdus = data;
					delete[] data;
					infile.read((char*)&pret, sizeof(float));
					infile.read((char*)&stoc, sizeof(int));
					infile.read((char*)&Discount, sizeof(float));
				}
				if (IdProdus % 10 == 3) {
					infile.read((char*)&size, sizeof(size));
					data = new char[size + 1];
					infile.read(data, size);
					data[size] = '\0';
					NumeProdus = data;
					delete[] data;
					infile.read((char*)&pret, sizeof(float));
					infile.read((char*)&stoc, sizeof(int));
					infile.read((char*)&Discount, sizeof(float));
					infile.read((char*)&size, sizeof(size));
					data = new char[size + 1];
					infile.read(data, size);
					data[size] = '\0';
					Stare = data;
					delete[] data;
				}
			}

			infile.close();
		}
	}
	else cerr << "Fisierul Produse.dat nu a putut fi deschis";
}

void Produse::stergere(int id)
{
	int flag = 0;
	ifstream infile("Produse.dat", ios::binary | ios:: in);
	if (infile.peek() == -1) cout << "Nu exista produse in magazin!" << endl;
	else
	{
		ofstream ofs;
		ofs.open("Temp.dat", ios::binary | ios::out);

		int IdProdus, stoc;
		string NumeProdus, Stare;
		float pret, Discount;


			if (infile.is_open()) {
				size_t size;
				char* data;

				infile.read((char*)&IdProdus, sizeof(int));
				if (IdProdus % 10 == 1) {
					infile.read((char*)&size, sizeof(size));
					data = new char[size + 1];
					infile.read(data, size);
					data[size] = '\0';
					NumeProdus = data;
					delete[] data;
					infile.read((char*)&pret, sizeof(float));
					infile.read((char*)&stoc, sizeof(int));
				}
				if (IdProdus % 10 == 2) {
					infile.read((char*)&size, sizeof(size));
					data = new char[size + 1];
					infile.read(data, size);
					data[size] = '\0';
					NumeProdus = data;
					delete[] data;
					infile.read((char*)&pret, sizeof(float));
					infile.read((char*)&stoc, sizeof(int));
					infile.read((char*)&Discount, sizeof(float));
				}
				if (IdProdus % 10 == 3) {
					infile.read((char*)&size, sizeof(size_t));
					data = new char[size + 1];
					infile.read(data, size);
					data[size] = '\0';
					NumeProdus = data;
					delete[] data;
					infile.read((char*)&pret, sizeof(float));
					infile.read((char*)&stoc, sizeof(int));
					infile.read((char*)&Discount, sizeof(float));
					infile.read((char*)&size, sizeof(size_t));
					data = new char[size + 1];
					infile.read(data, size);
					data[size] = '\0';
					Stare = data;
					delete[] data;
				}
				while (infile) {

					if (IdProdus == id) {
						flag = 1;
						cout << "Produsul sters este " << NumeProdus << " cu pretul " << pret << " lei." << endl;
					}
					else
					{
						if (IdProdus % 10 == 1) {
							ofs.write((char*)&IdProdus, sizeof(int));
							size = NumeProdus.size();
							ofs.write((char*)&size, sizeof(size_t));
							ofs.write((char*)NumeProdus.c_str(), size);
							ofs.write((char*)&pret, sizeof(float));
							ofs.write((char*)&stoc, sizeof(int));
						}
						if (IdProdus % 10 == 2) {
							ofs.write((char*)&IdProdus, sizeof(int));
							size = NumeProdus.size();
							ofs.write((char*)&size, sizeof(size_t));
							ofs.write((char*)NumeProdus.c_str(), size);
							ofs.write((char*)&pret, sizeof(float));
							ofs.write((char*)&stoc, sizeof(int));
							ofs.write((char*)&Discount, sizeof(float));
						}
						if (IdProdus % 10 == 3) {
							ofs.write((char*)&IdProdus, sizeof(int));
							size = NumeProdus.size();
							ofs.write((char*)&size, sizeof(size_t));
							ofs.write((char*)NumeProdus.c_str(), size);
							ofs.write((char*)&pret, sizeof(float));
							ofs.write((char*)&stoc, sizeof(int));
							ofs.write((char*)&Discount, sizeof(float));
							size = Stare.size();
							ofs.write((char*)&size, sizeof(size_t));
							ofs.write((char*)Stare.c_str(), size);
						}
					}
					infile.read((char*)&IdProdus, sizeof(int));
					if (IdProdus % 10 == 1) {
						infile.read((char*)&size, sizeof(size));
						data = new char[size + 1];
						infile.read(data, size);
						data[size] = '\0';
						NumeProdus = data;
						delete[] data;
						infile.read((char*)&pret, sizeof(float));
						infile.read((char*)&stoc, sizeof(int));
					}
					if (IdProdus % 10 == 2) {
						infile.read((char*)&size, sizeof(size));
						data = new char[size + 1];
						infile.read(data, size);
						data[size] = '\0';
						NumeProdus = data;
						delete[] data;
						infile.read((char*)&pret, sizeof(float));
						infile.read((char*)&stoc, sizeof(int));
						infile.read((char*)&Discount, sizeof(float));
					}
					if (IdProdus % 10 == 3) {
						infile.read((char*)&size, sizeof(size_t));
						data = new char[size + 1];
						infile.read(data, size);
						data[size] = '\0';
						NumeProdus = data;
						delete[] data;
						infile.read((char*)&pret, sizeof(float));
						infile.read((char*)&stoc, sizeof(int));
						infile.read((char*)&Discount, sizeof(float));
						infile.read((char*)&size, sizeof(size_t));
						data = new char[size + 1];
						infile.read(data, size);
						data[size] = '\0';
						Stare = data;
						delete[] data;
					}
				}
				ofs.close();
				infile.close();

				remove("Produse.dat");
				rename("Temp.dat", "Produse.dat");
			}
			else cerr << "Fisierul Produse.dat nu a putut fi deschis";

		if (flag != 1) cout << "Produsul cu id-ul " << id << " nu a fost gasit";
	}
}


void Produse :: MutareCos(int t)
{

}