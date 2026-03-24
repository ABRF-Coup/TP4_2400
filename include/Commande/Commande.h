#ifndef COMMANDE_H
#define COMMANDE_H

#include "Yogourt/Yogourt.h"
#include "Commande/Commande.h"
#include "Paiement/StrategiePaiement.h"
#include <memory>
#include <string>
#include <vector>

class Commande {
public:
    Commande();
    ~Commande()=default;
    ajouterBase(const std::string& type);
    ajouterGarniture(const std::string& nom);
    annulation();
    retablissement();
    
    
private:
    std::unique_ptr<StrategiePaiement> sp;
    int yogourtSelectione;
    std::vector<std::vector<std::unique_ptr<Yogourt>>> historique_[2];
    std::vector<std::vector<std::string>> redo_[2];


};

#endif