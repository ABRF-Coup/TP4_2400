#include "Garnitures/Garniture.h"

#include "Garnitures/Fruit.h"


Fruit::Fruit(std::unique_ptr<Yogourt> y) : Garniture(std::move(y)) {}

std::string Fruit::obtenirDescription() const
{
    return yogourtEnvelope->obtenirDescription() + " + fruits";
}

double Fruit::obtenirPrix() const
{
    return yogourtEnvelope->obtenirPrix() + 1.00;
}