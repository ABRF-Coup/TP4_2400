#include "Paiement/StrategiePoly.h"



double StrategiePoly::calculerPrixFinal(double sousTotal) const  {
		return sousTotal - 2.00;
	};

std::string StrategiePoly::obtenirNom() const  {
		return "Coupon Poly (-2.00)";
	};




