#ifndef YOGOURTGREC_H
#define YOGOURTGREC_H

#include "Yogourt/Yogourt.h"

class YogourtGrec : public Yogourt {
public:
	YogourtGrec() = default;
	std::string obtenirDescription() const override;
	virtual double obtenirPrix() const override;
};

#endif