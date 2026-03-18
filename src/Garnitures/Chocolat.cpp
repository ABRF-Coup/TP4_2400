#include "Garnitures/Garniture.h"

#include "Garnitures/Chocolat.h"


Chocolat::Chocolat(std::unique_ptr<Yogourt> y) : Garniture(std::move(y)) {}

std::string Chocolat::obtenirDescription() const
{
    return yogourtEnvelope->obtenirDescription() + " + chocolat";
}

double Chocolat::obtenirPrix() const
{
    return yogourtEnvelope->obtenirPrix() + 0.90;
}