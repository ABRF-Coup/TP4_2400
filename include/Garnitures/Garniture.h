#pragma once

#ifndef GARNITURE_H
#define GARNITURE_H

#include <memory>
#include <string>


// -- TODO : Changer le nom de la classe du fichier et puis ajouter toutes les méthodes nécessaires pour cette composante 
// Composante = Patron de conception, classe, etc etc



#include "Yogourt/Yogourt.h"

class Garniture : public Yogourt{
public:
    Garniture(std::unique_ptr<Yogourt> y) : yogourtEnvelope(std::move(y)) {}
    virtual ~Garniture() = default;

    std::string obtenirDescription() const override = 0;
    double obtenirPrix() const override = 0;
   

protected:
    std::unique_ptr<Yogourt> yogourtEnvelope;
};

#endif
