#ifndef MIEL_H
#define MIEL_H


#include "Garnitures/Garniture.h"


class Miel : public Garniture {
public:
    Miel(std::unique_ptr<Yogourt> f);
    std::string obtenirDescription() override;
    double obtenirPrix() override;
};

#endif