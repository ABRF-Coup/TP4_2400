#ifndef GRANOLA_H
#define GRANOLA_H


#include "Garnitures/Garniture.h"


class Granola : public Garniture {
public:
    Granola(std::unique_ptr<Yogourt> y);
    std::string obtenirDescription() const override;
    double obtenirPrix() const override;
};

#endif