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
    bool ajouterGarniture(const std::string& nom);

    void annulation();
    void retablissement();

    void setIndexActif(int indexActif);
    void reconstruireYogourt(int index);

    void setStrategie(std::unique_ptr<StrategiePaiement> s);
    double calculerTotal() const;

    void afficher() const;
    
    
    
private:
    std::unique_ptr<StrategiePaiement> sp;
    int indexActif_;
    std::string base_[2];
    std::unique_ptr<Yogourt> yogourts_[2];
    std::vector<std::string> redo_[2];
    std::vector<std::string> historiqueNomsGarnitures_[2];
    Inventaire inventaire_;


};

#endif