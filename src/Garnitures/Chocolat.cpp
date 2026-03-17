#include "Garnitures/Garniture.h"

#include "Garnitures/Chocolat.h"


Chocolat::Chocolat(std::unique_ptr<Yogourt> y) : Garniture(std::move(y)) {}

std::string Chocolat::obtenirDescription()
{
    return obtenirBase()->obtenirDescription() + " + chocolat";
}

double Chocolat::obtenirPrix()
{
    return obtenirBase()->obtenirPrix() + 0.90;
}