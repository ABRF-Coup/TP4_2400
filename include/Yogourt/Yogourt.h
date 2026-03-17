#pragma once
#ifndef YOGOURT_H
#define YOGOURT_H

#include <string>



// -- TODO : Changer le nom de la classe du fichier et puis ajouter toutes les méthodes nécessaires pour cette composante 
// Composante = Patron de conception, classe, etc etc
class Yogourt {
public:
    Yogourt() {}
    Yogourt(std::string d) : description(d) {}
    virtual std::string obtenirDescription() { return description; }
    virtual double obtenirPrix() = 0;
private:
    std::string description;
};

#endif