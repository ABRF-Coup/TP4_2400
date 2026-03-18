#ifndef CHOCOLAT_H
#define CHOCOLAT_H


#include "Garnitures/Garniture.h"


class Chocolat : public Garniture {
public:
    Chocolat(std::unique_ptr<Yogourt> y);
    std::string obtenirDescription() const override;
    double obtenirPrix()const override;
};

#endif