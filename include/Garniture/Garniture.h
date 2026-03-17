#pragma once

#ifndef GARNITURE_H
#define GARNITURE_H

// -- TODO : Changer le nom de la classe du fichier et puis ajouter toutes les méthodes nécessaires pour cette composante 
// Composante = Patron de conception, classe, etc etc



#include "Yogourt/Yogourt.h"

class Garniture : public Yogourt {
public:
	Garniture(std::unique_ptr b) : yogourtEnvelope(b) {}
	std::unique_ptr<Yogourt> obtenirBase() { return yogourtEnvelope; }
	std::string obtenirDescription() override = 0;
private:
	std::unique_ptr yogourtEnvelope;
};

#endif
