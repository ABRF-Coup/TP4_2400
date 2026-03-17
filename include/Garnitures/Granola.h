#ifndef GRANOLA_H
#define GRANOLA_H


#include "Garnitures/Garniture.h"


class Granola : public Garniture {
public:
    Granola(std::unique_ptr<Yogourt> f);
    std::string obtenirDescription() override;
    double obtenirPrix() override;
};

#endif