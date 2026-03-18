#include "Paiement/StrategiePrevente.h"



double StrategiePrevente::calculerPrixFinal(double sousTotal) const  {
		return sousTotal * 0.90;
	};

std::string StrategiePrevente::obtenirNom() const  {
		return "Prevente (-10%)";
	};




