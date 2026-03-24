#include "Commande/Commande.h"
#include "Inventaire/Inventaire.h"
#include <iostream>



void Commande::setIndexActif(int indexActif)
{
    indexActif_ = indexActif-1;
}

Commande::Commande()
{
    indexActif_ = 0;
}





void Commande::ajouterBase(const std::string& type)
{
/////On va reflechir la dessus
}



