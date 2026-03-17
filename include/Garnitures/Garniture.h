#pragma once

#ifndef GARNITURE_H
#define GARNITURE_H

#include <memory>
#include <string>
#include <utility>

// -- TODO : Changer le nom de la classe du fichier et puis ajouter toutes les méthodes nécessaires pour cette composante 
// Composante = Patron de conception, classe, etc etc



#include "Yogourt/Yogourt.h"

class Garniture : public Yogourt{
public:
    Garniture(std::unique_ptr<Yogourt> b) : yogourtEnvelope(std::move(b)) {}

    Yogourt * obtenirBase() const { return yogourtEnvelope.get(); }

    std::string obtenirDescription() override = 0;
    double obtenirPrix() override = 0;

private:
    std::unique_ptr<Yogourt> yogourtEnvelope;
};

#endif
