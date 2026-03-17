#include "Garnitures/Garniture.h"

#include "Garnitures/Fruit.h"


Fruit::Fruit(std::unique_ptr<Yogourt> y) : Garniture(std::move(y)) {}

std::string Fruit::obtenirDescription()
{
    return obtenirBase()->obtenirDescription() + " + fruits";
}

double Fruit::obtenirPrix()
{
    return obtenirBase()->obtenirPrix() + 1.00;
}