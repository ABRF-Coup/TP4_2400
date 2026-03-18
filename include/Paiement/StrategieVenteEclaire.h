#pragma once
#ifndef STRATEGIEVENTEECLAIRE_H
#define STRATEGIEVENTEECLAIRE_H


#include "Paiement/StrategiePaiement.h"


class StrategieVenteEclaire : public StrategiePaiement {

public:
	virtual double calculerPrixFinal(double sousTotal) const override;
	virtual std::string obtenirNom() const override;
};





#endif