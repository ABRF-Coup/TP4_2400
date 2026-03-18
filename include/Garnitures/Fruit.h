#ifndef FRUIT_H
#define FRUIT_H


#include "Garnitures/Garniture.h"


class Fruit : public Garniture {
public:
    Fruit(std::unique_ptr<Yogourt> y);
    std::string obtenirDescription() const override;
    double obtenirPrix() const override;
};

#endif