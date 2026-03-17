#include "Garnitures/Garniture.h"

#include "Garnitures/Granola.h"


Granola::Granola(std::unique_ptr<Yogourt> y) : Garniture(std::move(y)) {}

std::string Granola::obtenirDescription()
{
    return obtenirBase()->obtenirDescription() + " + granola";
}

double Granola::obtenirPrix()
{
    return obtenirBase()->obtenirPrix() + 0.80;
}