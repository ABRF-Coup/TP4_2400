#pragma once
#ifndef YOGOURT_H
#define YOGOURT_H

#include <string>



// -- TODO : Changer le nom de la classe du fichier et puis ajouter toutes les méthodes nécessaires pour cette composante 
// Composante = Patron de conception, classe, etc etc
class Yogourt {
public:
    virtual std::string obtenirDescription() const = 0;
    virtual double obtenirPrix() const = 0;
    virtual ~Yogourt() = default;
};

#endif