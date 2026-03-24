#ifndef COMMANDE_H
#define COMMANDE_H

#include "Yogourt/Yogourt.h"
#include "Commande/Commande.h"
#include "Paiement/StrategiePaiement.h"
#include "Inventaire/Inventaire.h"
#include <memory>
#include <string>
#include <vector>

class Commande {
public:
    Commande();
    ~Commande()=default;
    void ajouterBase(const std::string& type);
    void ajouterGarniture(const std::string& nom);
    void annulation();
    void retablissement();
    void setIndexActif(int indexActif);
    
    
private:
    std::unique_ptr<StrategiePaiement> sp;
    int indexActif_;
    std::vector<std::vector<std::unique_ptr<Yogourt>>> historique_[2];
    std::vector<std::vector<std::string>> redo_[2];
    Inventaire inventaire_;


};

#endif