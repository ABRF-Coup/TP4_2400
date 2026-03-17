#include "Garnitures/Garniture.h"

#include "Garnitures/Miel.h"


Miel::Miel(std::unique_ptr<Yogourt> y) : Garniture(std::move(y)) {}

std::string Miel::obtenirDescription()
{
    return obtenirBase()->obtenirDescription() + " + miel";
}

double Miel::obtenirPrix()
{
    return obtenirBase()->obtenirPrix() + 0.60;
}