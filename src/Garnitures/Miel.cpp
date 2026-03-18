#include "Garnitures/Garniture.h"

#include "Garnitures/Miel.h"


Miel::Miel(std::unique_ptr<Yogourt> y) : Garniture(std::move(y)) {}

std::string Miel::obtenirDescription() const
{
    return yogourtEnvelope->obtenirDescription() + " + miel";
}

double Miel::obtenirPrix() const
{
    return yogourtEnvelope->obtenirPrix() + 0.60;
}