#ifndef YOGOURTGREC_H
#define YOGOURTGREC_H

#include "Yogourt/Yogourt.h"

class YogourtGrec : public Yogourt {
public:
	YogourtGrec();
	virtual double obtenirPrix() override;
};

#endif