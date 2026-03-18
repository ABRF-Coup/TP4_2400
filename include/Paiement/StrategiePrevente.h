#pragma once
#ifndef STRATEGIEPREVENTE_H
#define STRATEGIEPREVENTE_H


#include "Paiement/StrategiePaiement.h"


class StrategiePrevente : public StrategiePaiement {

public:
	virtual double calculerPrixFinal(double sousTotal) const override;
	virtual std::string obtenirNom() const override;
};





#endif