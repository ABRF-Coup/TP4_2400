#ifndef COMMANDE_H
#define COMMANDE_H

#include "Yogourt/Yogourt.h"
#include "Commande/Commande.h"
#include "Paiement/StrategiePaiement.h"
#include "Inventaire/Inventaire.h"
#include "Phase/Phase.h"
#include "Observateur/Observateur.h"
#include <memory>
#include <string>
#include <vector>

class Commande : public Observateur{
public:
    Commande();
    virtual ~Commande();

    void mettreAJour(const std::string& article, bool enRupture) override;
    const std::vector<std::string>& obtenirAbonnements() const override { return abonnements_; }

    
    void sabonner(const std::string& article);
    void desabonner(const std::string& article);
    void afficherAbonnements() const;


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
    void executerPaiement();
    void setStrategie(std::unique_ptr<StrategiePaiement> s);
    StrategiePaiement* getStrategie();
    void afficherDetailsCalcul() ;
    double calculerSousTotal() const ;
    double calculerTotal() const ;

    


    void setIndexActif(int indexActif);
    int getIndexActif();
    void reconstruireYogourt(int index);

    

    void setPhase(std::unique_ptr<Phase> p);
    std::string getPhaseNom() const;

    void afficher() const;

    bool existanceYogourt() const;


    void afficherOptionsGarnitures() const;

    void afficherInventaire() const;


    
    
    
private:
    std::unique_ptr<StrategiePaiement> sp;
    std::unique_ptr<Phase> phaseActuelle;
    int indexActif_;
    std::string base_[2];
    std::unique_ptr<Yogourt> yogourts_[2];
    std::vector<std::string> redo_[2];
    std::vector<std::string> historiqueNomsGarnitures_[2];
    Inventaire inventaire_;
    std::vector<std::string> abonnements_;


};

#endif