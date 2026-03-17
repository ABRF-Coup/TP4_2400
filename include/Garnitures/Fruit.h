#ifndef FRUIT_H
#define FRUIT_H


#include "Garnitures/Garniture.h"


class Fruit : public Garniture {
public:
    Fruit(std::unique_ptr<Yogourt> f);
    std::string obtenirDescription() override;
    double obtenirPrix() override;
};

#endif