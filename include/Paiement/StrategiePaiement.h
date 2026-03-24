#pragma once
#include <string>

#ifndef STRATEGIEPAIEMENT_H
#define STRATEGIEPAIEMENT_H


class StrategiePaiement {
public:
	virtual ~StrategiePaiement() = default;
	virtual double calculerPrixFinal(double sousTotal) const = 0;
	virtual std::string obtenirNom() const = 0;

};


#endif