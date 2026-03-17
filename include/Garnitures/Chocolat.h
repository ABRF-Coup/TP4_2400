#ifndef CHOCOLAT_H
#define CHOCOLAT_H


#include "Garnitures/Garniture.h"


class Chocolat : public Garniture {
public:
    Chocolat(std::unique_ptr<Yogourt> f);
    std::string obtenirDescription() override;
    double obtenirPrix() override;
};

#endif