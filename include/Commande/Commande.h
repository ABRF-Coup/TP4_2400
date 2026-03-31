#ifndef COMMANDE_H
#define COMMANDE_H

#include "Yogourt/Yogourt.h"
#include "Commande/Commande.h"
#include "Paiement/StrategiePaiement.h"
#include "Inventaire/Inventaire.h"
#include "Phase/Phase.h"
#include <memory>
#include <string>
#include <vector>

class Commande {
public:
    Commande();
    ~Commande()=default;

    void executerAjouterBase(const std::string& type);
    void ajoutBase(const std::string& type);


    void executerAjouterGarniture(const std::string& nom);
    void ajoutGarniture(const std::string& nom);

    void annuler();
    void executerAnnulation();


    void retablissement();
    void executerRetablissement();


    void terminer();
    void preparer();

    void paiement();
    


    void setIndexActif(int indexActif);
    void reconstruireYogourt(int index);

    void setStrategie(std::unique_ptr<StrategiePaiement> s);
    double calculerTotal() const;

    void setPhase(std::unique_ptr<Phase> p);

    void afficher() const;

    bool existanceYogourt() const;
    
    
    
private:
    std::unique_ptr<StrategiePaiement> sp;
    std::unique_ptr<Phase> phaseActuelle;
    int indexActif_;
    std::string base_[2];
    std::unique_ptr<Yogourt> yogourts_[2];
    std::vector<std::string> redo_[2];
    std::vector<std::string> historiqueNomsGarnitures_[2];
    Inventaire inventaire_;


};

#endif