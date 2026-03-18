#ifndef YOGOURTNATURE_H
#define YOGOURTNATURE_H

#include "Yogourt/Yogourt.h"

class YogourtNature : public Yogourt {
public:
	YogourtNature() = default;
	virtual double obtenirPrix() const override;
	virtual std::string obtenirDescription() const override;
};

#endif