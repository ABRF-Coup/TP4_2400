#include "Garnitures/Garniture.h"

#include "Garnitures/Granola.h"


Granola::Granola(std::unique_ptr<Yogourt> y) : Garniture(std::move(y)) {}

std::string Granola::obtenirDescription() const
{
    return yogourtEnvelope->obtenirDescription() + " + granola";
}

double Granola::obtenirPrix() const
{
    return yogourtEnvelope->obtenirPrix() + 0.80;
}