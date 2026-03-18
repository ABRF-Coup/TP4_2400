#ifndef MIEL_H
#define MIEL_H


#include "Garnitures/Garniture.h"


class Miel : public Garniture {
public:
    Miel(std::unique_ptr<Yogourt> y);
    std::string obtenirDescription() const override;
    double obtenirPrix() const override;
};

#endif