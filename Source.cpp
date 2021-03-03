#include <iostream>
#include <stdlib.h>
#include "Produse.h"
#include "Promotii.h"
#include "Resigilate.h"
#include "Client.h"
#include <iomanip>


using namespace std;

int main()
{
	//int IdProdus, stoc;
	//string NumeProdus;
	//float pret;
	Produse p1;
	Promotii p2;
	Resigilate r3;
	Client c1;

	// Realizam meniul
	int t, ok, msg;
	//msg vine de la mesager, atunci cand se apasa 'back' mesager devine 1. daca mesager devine 1, ok se sesizeaza si devine si el 1, blocand while-ul repetand meniul anterior.
	ok = 1;
	while (ok == 1)
	{
		system("CLS");
		cout << "Welcome!" << endl;
		cout << "Pentru meniul 'Magazin' apasati tasta 1." << endl << "Pentru meniul 'Client' apasati tasta 2.";
		cout << endl << "Daca doriti sa inchideti aplicatia, apasati tasta 3" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			ok = 1;
			while (ok == 1)
			{
				msg = 0;
				ok = 0;
				system("CLS");
				cout << "Pentru adaugare produse apasati tasta 1" << endl;
				//cout << "Pentru editare produse apasati tasta 2" << endl; (to be added)
				cout << "Pentru stergere produse apasati tasta 3" << endl;
				//cout << "Pentru prelucrare comenzi apasati tasta 4" << endl; (to be added)
				cout << "Pentru vizualizare clienti apasati tasta 5" << endl;
				cout << "Pentru vizualizare raport comenzi apasati tasta 6" << endl;
				cout << "'Back'---> tasta 7" << endl;
				cin >> t;
				switch (t)
				{
				case 1:
					ok = 1;
					while (ok == 1)
					{
						msg = 0;
						ok = 0;
						system("CLS");
						cout << "Selectati locatia in care doriti sa introduceti produsul" << endl;
						cout << "'Produse'---> tasta 1" << endl;
						cout << "'Reduceri'---> tasta 2" << endl;
						cout << "'Resigilate'---> tasta 3" << endl;
						cout << "'Back'---> tasta 4" << endl;
						cin >> t;
						switch (t)
						{
						case 1:
							system("CLS");
							p1.afisare(t);
							cout << "Produsul a fost introdus cu succes!" << endl;
							cout << endl; cout << endl;
							cout << "----";
							cout << endl; cout << endl;
							cout << "'Inchidere program'---> tasta 1" << endl;
							cout << "'Back'---> tasta 2" << endl;
							cin >> t;
							switch (t)
							{
							case 1:
								return 0;
								break;
							case 2:
								ok = 0;
								msg = 1;
								break;
							default:
								system("CLS");
								ok = 1;
								break;
							}
							break;
						case 2:
							system("CLS");
							p2.afisare(t);
							cout << "Produsul a fost introdus cu succes!";
							cout << endl; cout << endl;
							cout << "----";
							cout << endl; cout << endl;
							cout << "'Inchidere program'---> tasta 1" << endl;
							cout << "'Back'---> tasta 2" << endl;
							cin >> t;
							switch (t)
							{
							case 1:
								return 0;
								break;
							case 2:
								ok = 0;
								msg = 1;
								break;
							default:
								system("CLS");
								ok = 1;
								break;
							}
							break;
						case 3:
							system("CLS");
							r3.afisare(t);
							cout << "Produsul a fost introdus cu succes!";
							cout << endl; cout << endl;
							cout << "----";
							cout << endl; cout << endl;
							cout << "'Inchidere program'---> tasta 1" << endl;
							cout << "'Back'---> tasta 2" << endl;
							cin >> t;
							switch (t)
							{
							case 1:
								return 0;
								break;
							case 2:
								ok = 0;
								msg = 1;
								break;
							default:
								system("CLS");
								ok = 1;
								break;
							}
							break;
						case 4:
							ok = 0;
							msg = 1;
							break;
						default:
							system("CLS");
							ok = 1;
							break;
						}
					}
					if (msg == 1) ok = 1;
					else ok = 0;
					
					break;
				case 2:
					ok = 1;
					while (ok == 1)
					{
						msg = 0;
						ok = 0;
						system("CLS");
						cout << "Selectati locatia din care doriti sa modificati produsul" << endl;
						cout << "'Produse'---> tasta 1" << endl;
						cout << "'Reduceri'---> tasta 2" << endl;
						cout << "'Resigilate'---> tasta 3" << endl;
						cout << "'Back'---> tasta 4" << endl;
						cin >> t;
						switch (t)
						{
						case 1:
							system("CLS");
							cout << "Functionalitatea nu este disponibila inca";
							break;
						case 2:
							system("CLS");
							cout << "Functionalitatea nu este disponibila inca";
							break;
						case 3:
							system("CLS");
							cout << "Functionalitatea nu este disponibila inca";
							break;
						case 4:
							ok = 0;
							msg = 1;
							break;
						default:
							system("CLS");
							ok = 1;
							break;
						}
					}
					if (msg == 1) ok = 1;
					else ok = 0;
					
					break;
				case 3:
					ok = 1;
					while (ok == 1)
					{
						msg = 0;
						ok = 0;
						system("CLS");
						cout << "Introduceti ID-ul produsului pe care vreti sa il stergeti" << endl;
						int id;
						cin >> id;
						p1.stergere(id);
						cout << endl << "'Inchidere program'---> tasta 1" << endl;
						cout << "'Back'---> tasta 2" << endl;
						cin >> t;
						switch (t)
						{
						case 1:
							return 0;
							break;
						case 2:
							ok = 0;
							msg = 1;
							break;
						default:
							system("CLS");
							ok = 1;
							break;
						}
					}
					if (msg == 1) ok = 1;
					else ok = 0;

					break;
				case 4:
					system("CLS");
					cout << "Functionalitatea nu este disponibila inca";
					break;
				case 5:
					system("CLS");
					cout << "ID" << setw(25) << "Nume" << setw(25) << "Adresa" << setw(25) << "Cod Postal" << setw(25) << "Nr Telefon" << setw(25) << "Email";
					cout << endl;
					c1.AfisareClienti();
					cout << endl;
					cout << "----";
					cout << endl << "'Inchidere program'---> tasta 1" << endl;
					cout << "'Back'---> tasta 2" << endl;
					cin >> t;
					switch (t)
					{
					case 1:
						return 0;
						break;
					case 2:
						ok = 0;
						msg = 1;
						break;
					default:
						system("CLS");
						ok = 1;
						break;
					}
					break;
				case 6:
					system("CLS");
					cout << "Functionalitatea nu este disponibila inca";
					break;
				case 7:
					ok = 0;
					msg = 1;
					break;
				default:
					ok = 1;
					system("CLS");
				}
			}
			if (msg == 1) ok = 1;
			else ok = 0; //aici se face verificarea. Functioneaza precum o frontiera.
			break;
		case 2:
			ok = 1;
			while (ok == 1)
			{
				msg = 0;
				ok = 0;
				system("CLS");
				cout << "Daca sunteti client nou apasati tasta 1" << endl;
				cout << "Pentru vizualizare catalog apasati tasta 2" << endl;
				//cout << "Pentru vizualizare cosului dumneavoastra apasati tasta 3" << endl; (to be added)
				//cout << "Pentru vizualizarea comenzilor dumneavoastra apasati tasta 4" << endl; (to be added)
				cout << "'Back'---> tasta 5" << endl;
				cin >> t;
				switch (t)
				{
				case 1:
					system("CLS");
					cout << "Va rugam sa va introduceti datele pentru inregistrare." << endl;
					c1.IntroducereDate();
					cout << "Ati fost inregistrat. Multumim!";
					cout << endl; cout << endl;
					cout << "----";
					cout << endl; cout << endl;
					cout << "'Inchidere program'---> tasta 1" << endl;
					cout << "'Back'---> tasta 2" << endl;
					cin >> t;
					switch (t)
					{
					case 1:
						return 0;
						break;
					case 2:
						ok = 0;
						msg = 1;
						break;
					default:
						system("CLS");
						ok = 1;
						break;
					}
					break;
				case 2:
					ok = 1;
					while (ok == 1)
					{
						msg = 0;
						ok = 0;
						system("CLS");
						cout << "Selectati catalogul pe care doriti sa il vizualizati" << endl;
						cout << "'Produse'---> tasta 1" << endl;
						cout << "'Reduceri'---> tasta 2" << endl;
						cout << "'Resigilate'---> tasta 3" << endl;
						cout << "'Back'---> tasta 4" << endl;
						cin >> t;
						switch (t)
						{
						case 1:
							system("CLS");
							cout << "ID" << setw(30)<<"Produs"<< setw(30) <<"Pret (lei)"<< setw(30) <<"In Stoc"<<endl;
							p1.afisareEcran(t);
							cout << endl;
							cout << "----";
							cout << endl<<"'Inchidere program'---> tasta 1" << endl;
							cout << "'Back'---> tasta 2" << endl;
							cin >> t;
							switch (t)
							{
							case 1:
								return 0;
								break;
							case 2:
								ok = 0;
								msg = 1;
								break;
							default:
								system("CLS");
								ok = 1;
								break;
							}
							break;
						case 2:
							system("CLS");
							cout << "ID" << setw(30) << "Produs" << setw(30) << "Pret (lei)" << setw(30) << "Discount (%)"<< setw(30) <<"In Stoc" << endl;
							p2.afisareEcran(t);
							cout << endl;
							cout << "----";
							cout << endl << "'Inchidere program'---> tasta 1" << endl;
							cout << "'Back'---> tasta 2" << endl;
							cin >> t;
							switch (t)
							{
							case 1:
								return 0;
								break;
							case 2:
								ok = 0;
								msg = 1;
								break;
							default:
								system("CLS");
								ok = 1;
								break;
							}
							break;
						case 3:
							system("CLS");
							cout << "ID" << setw(23) << "Produs" << setw(23) << "Pret (lei)" << setw(23)<<"Discount (%)"<< setw(23) <<"Stare" << setw(23)<< "In Stoc" << endl;
							r3.afisareEcran(t);
							cout << endl;
							cout << "----";
							cout << endl << "'Inchidere program'---> tasta 1" << endl;
							cout << "'Back'---> tasta 2" << endl;
							cin >> t;
							switch (t)
							{
							case 1:
								return 0;
								break;
							case 2:
								ok = 0;
								msg = 1;
								break;
							default:
								system("CLS");
								ok = 1;
								break;
							}
							break;
						case 4:
							ok = 0;
							msg = 1;
							break;
						default:
							system("CLS");
							ok = 1;
							break;
						}
					}
					if (msg == 1) ok = 1;
					else ok = 0;

					break;
				case 3:
					system("CLS");
					cout << "Functionalitatea nu este disponibila inca";
					break;
				case 4:
					system("CLS");
					cout << "Functionalitatea nu este disponibila inca";
					break;
				case 5:
					ok = 0;
					msg = 1;
					break;
				default:
					ok = 1;
					system("CLS");
				}
				
			}
			if (msg == 1) ok = 1;
			else ok = 0;
			break;
		case 3:
			return 0;
			break;
		default:
			system("CLS");
		}
	}
	
	system("pause");
	return 0;
}