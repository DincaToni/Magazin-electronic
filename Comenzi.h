#pragma once
#include "CosElectronic.h"
#include "Client.h"
class Comenzi :
    protected CosElectronic, Client
{

    int Nr_Comanda;

public :

    Comenzi()
    {
        Nr_Comanda = 1;
    }


};

