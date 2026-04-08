#ifndef PHASE_PREPARATION_H
#define PHASE_PREPARATION_H

#include "Phase/Phase.h"


class PhasePreparation:public Phase{

public:
    
    PhasePreparation() = default;
    void ajouterBase(Commande* c,std::string type) override;
    void ajouterGarniture(Commande* c, std::string nomGarniture) override;
    std::string obtenirNom() const override;
    void annuler(Commande* c) override;
    void preparer(Commande* c) override;
    void retablir(Commande* c) override;
    void terminer(Commande* c) override;
    void payer(Commande* c) override;
};



#endif