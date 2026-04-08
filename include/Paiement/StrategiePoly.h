#pragma once
#ifndef STRATEGIEPOLY_H
#define STRATEGIEPOLY_H


#include "Paiement/StrategiePaiement.h"


class StrategiePoly : public StrategiePaiement {

public:
	virtual double calculerPrixFinal(double sousTotal) const override;
	virtual std::string obtenirNom() const override;
};



#endif