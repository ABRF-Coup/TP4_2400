#ifndef PHASE_INITIALE_H
#define PHASE_INITIALE_H

#include "Phase/Phase.h"


class PhaseInitiale:public Phase{

public:
    
    PhaseInitiale() = default;

    // Tu DOIS ré-écrire toutes les signatures ici pour dire qu'elles existent
    void ajouterBase(Commande* c, std::string type) override;
    void ajouterGarniture(Commande* c, std::string nomGarniture) override;
    std::string obtenirNom() const override;
    void annuler(Commande* c) override;
    void preparer(Commande* c) override;
    void retablir(Commande* c) override;
    void terminer() override;
    void payer() override;
};



#endif