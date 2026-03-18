#include "Paiement/StrategieVenteEclaire.h"



double StrategieVenteEclaire::calculerPrixFinal(double sousTotal) const {
		return sousTotal + 1.50;
	};

std::string StrategieVenteEclaire::obtenirNom() const  {
		return "Vente eclair (+1.50)";
	};




