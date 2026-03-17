#ifndef YOGOURTNATURE_H
#define YOGOURTNATURE_H

#include "Yogourt/Yogourt.h"

class YogourtNature : public Yogourt {
public:
	YogourtNature();
	virtual double obtenirPrix() override;
};

#endif