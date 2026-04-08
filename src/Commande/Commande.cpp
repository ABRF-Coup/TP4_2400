    #include "Commande/Commande.h"
    #include "Inventaire/Inventaire.h"
    #include "Garnitures/Fruit.h"
    #include "Garnitures/Chocolat.h"
    #include "Garnitures/Granola.h"
    #include "Garnitures/Miel.h"
    #include "Yogourt/YogourtGrec.h"
    #include "Yogourt/YogourtNature.h"
    #include "ui/ConsoleColors.h"
    #include "Phase/PhaseInitiale.h"
    #include <iostream>
    #include <iomanip>



    void Commande::setIndexActif(int indexActif)
    {
        indexActif_ = indexActif-1;
    }

    int Commande::getIndexActif(){
        return indexActif_;
    }

    Commande::Commande()
    {
        indexActif_ = 0;
        phaseActuelle = std::make_unique<PhaseInitiale>();
        inventaire_.attacher(this);
    }


    void Commande::paiement(){
        phaseActuelle->payer(this);
    }

    void Commande::executerPaiement(){

        double totalFinal = calculerTotal();

        std::cout << "Paiement accepte (" << sp->obtenirNom() << ") | Montant: " 
                  << totalFinal << " CAD" << std::endl;

        std::cout << "Merci pour votre achat. A bientot!" << std::endl;
    }

    std::string Commande::getPhaseNom() const { return phaseActuelle->obtenirNom(); }


    double Commande::calculerSousTotal() const {
        double soustotal = 0;
        if (yogourts_[0]) {
            soustotal += yogourts_[0]->obtenirPrix();
        }
        if (yogourts_[1]) {
            soustotal += yogourts_[1]->obtenirPrix();
        }

        return soustotal; 
        
    }

    double Commande::calculerTotal() const {
        if (sp) return sp->calculerPrixFinal(calculerSousTotal());
        return calculerSousTotal();
        /*return sp->calculerPrixFinal(calculerSousTotal());*/
    }

    void Commande::afficherDetailsCalcul(){
        double st = calculerSousTotal();
        std::cout << "Sous-total : " << st << " CAD" << std::endl;
        
        if (sp) {
            std::cout << "Total avec " << sp->obtenirNom() << " : " 
                    << sp->calculerPrixFinal(st) << " CAD" << std::endl;
        }
    }


    void Commande::executerAjouterBase(const std::string& type)
    {
        if (!base_[indexActif_].empty()) {
       
            if (indexActif_ < 1) { 
                indexActif_++; 
            } else {
                return; 
            }
        }

        if (inventaire_.estDisponible(type)) {
            inventaire_.retirerStock(type);
            base_[indexActif_] = type;
            reconstruireYogourt(indexActif_);
            std::cout << yogourts_[indexActif_]->obtenirDescription() << " selectionne." << std::endl;
            redo_[indexActif_].clear();
        }
        else{
            std::cout << "Stock insuffisant pour " << type << "." << std::endl;
        }

    }

    void Commande::ajoutBase(const std::string& type){
        phaseActuelle->ajouterBase(this,type);
    }




    void Commande::executerAjouterGarniture(const std::string& nomGarniture){
        if (base_[indexActif_].empty()) return ;

        if (inventaire_.estDisponible(nomGarniture)) {
            inventaire_.retirerStock(nomGarniture);
            historiqueNomsGarnitures_[indexActif_].push_back(nomGarniture);
            reconstruireYogourt(indexActif_);
            redo_[indexActif_].clear();

            std::cout << "Garniture '" << nomGarniture << "' ajoutee." << std::endl;
            return;
        }

        std::cout << "Stock insuffisant pour la garniture '" << nomGarniture << "'." << std::endl;
        return;


    }

    void Commande::ajoutGarniture(const std::string& nom){
        phaseActuelle->ajouterGarniture(this, nom);
    }



    void Commande::executerAnnulation() {
        if (historiqueNomsGarnitures_[indexActif_].empty()) {
            std::cout << "Aucune garniture a annuler." << std::endl;
            return;
        }

        std::string nom = historiqueNomsGarnitures_[indexActif_].back();
        historiqueNomsGarnitures_[indexActif_].pop_back();

        inventaire_.remettreStock(nom);
        redo_[indexActif_].push_back(nom);

        reconstruireYogourt(indexActif_);

        std::cout << "Derniere garniture annulee." << std::endl;
    }

    void Commande::annuler(){
        phaseActuelle->annuler(this);
    }




    void Commande::executerRetablissement() {
        if (redo_[indexActif_].empty()) {
            std::cout << "Aucune garniture a retablir." << std::endl;
            return;
        }

        std::string nom = redo_[indexActif_].back();
        if (inventaire_.estDisponible(nom)) {
            inventaire_.retirerStock(nom);
            historiqueNomsGarnitures_[indexActif_].push_back(nom);
            redo_[indexActif_].pop_back();
            reconstruireYogourt(indexActif_);

            std::cout << "Garniture retablie." << std::endl;
        }
    }

    void Commande::retablissement(){
        phaseActuelle->retablir(this);
    }




    void Commande::reconstruireYogourt(int index) {
        if (base_[index].empty()) {
            yogourts_[index].reset();
            return;
        }



        std::unique_ptr<Yogourt> nouveau;
        if (base_[index] == "nature") 
            nouveau = std::make_unique<YogourtNature>();
        else 
            nouveau = std::make_unique<YogourtGrec>();


        for (const std::string& nom : historiqueNomsGarnitures_[index]) {
            if (nom == "fruits") nouveau = std::make_unique<Fruit>(std::move(nouveau));
            else if (nom == "chocolat") nouveau = std::make_unique<Chocolat>(std::move(nouveau));
            else if (nom == "granola") nouveau = std::make_unique<Granola>(std::move(nouveau));
            else if (nom == "miel") nouveau = std::make_unique<Miel>(std::move(nouveau));
        }

        
        yogourts_[index] = std::move(nouveau);
    }




    void Commande::setStrategie(std::unique_ptr<StrategiePaiement> s){
            sp = std::move(s);
            std::cout << "Mode de paiement actif: " << sp->obtenirNom() << "." << std::endl;
    }

    StrategiePaiement* Commande::getStrategie(){
        return sp.get();
    }

    void Commande::setPhase(std::unique_ptr<Phase> p){
        phaseActuelle = std::move(p);
    }

    void Commande::preparer(){
        phaseActuelle->preparer(this);
    }


    void Commande::terminer(){
        phaseActuelle->terminer(this);
    }


    bool Commande::existanceYogourt() const
        {
            if(yogourts_[indexActif_] == nullptr){
                return false;
            }

            return true;
        }

void Commande::afficher() const {

    std::cout << std::fixed << std::setprecision(2);
  
    std::cout << "Phase: " << phaseActuelle->obtenirNom() << std::endl;

    
    if (!existanceYogourt() && base_[0].empty() && base_[1].empty()) {
        std::cout << "Yogourts: aucun" << std::endl;
    } else {
        for (int i = 0; i < 2; ++i) {
            if (base_[i].empty()) continue;
            
            std::cout << "Yogourt #" << i + 1;
            if (i == indexActif_) std::cout << " (actif)";
            
            std::cout << ": " << (yogourts_[i] ? yogourts_[i]->obtenirDescription() : base_[i]);
            std::cout << " | Prix: " << (yogourts_[i] ? yogourts_[i]->obtenirPrix() : 0.0) << " CAD" << std::endl;
        }
    }

    
    std::cout << "Sous-total commande: " << calculerSousTotal() << " CAD" << std::endl;

   
    std::cout << "Paiement: " << (sp ? sp->obtenirNom() : "Aucune");
   
    if (sp) {
        std::cout << " | Total projete: " << calculerTotal() << " CAD";
    } else {
        std::cout << " | choisir un mode de paiement";
    }
    

    std::cout << " | ";
    if (phaseActuelle->obtenirNom() == "Terminee" && sp != nullptr) {
        std::cout << "payable" << std::endl;
    } else {
        std::cout << ConsoleColor::red << "non payable" << ConsoleColor::reset << std::endl;
    }

    std::cout << ConsoleColor::magenta << "Commande: " << ConsoleColor::reset;
}


void Commande::afficherInventaire() const {
    std::cout << "  nature:   " << inventaire_.obtenirStock("nature") << std::endl;
    std::cout << "  grec:     " << inventaire_.obtenirStock("grec") << std::endl;
    std::cout << "  fruits:   " << inventaire_.obtenirStock("fruits") << std::endl;
    std::cout << "  granola:  " << inventaire_.obtenirStock("granola") << std::endl;
    std::cout << "  miel:     " << inventaire_.obtenirStock("miel") << std::endl;
    std::cout << "  chocolat: " << inventaire_.obtenirStock("chocolat") << std::endl;
}


void Commande::afficherOptionsGarnitures() const {
    std::cout << "  1 -> fruits   (" << inventaire_.obtenirStock("fruits") << " en stock)" << std::endl;
    std::cout << "  2 -> granola  (" << inventaire_.obtenirStock("granola") << " en stock)" << std::endl;
    std::cout << "  3 -> miel     (" << inventaire_.obtenirStock("miel") << " en stock)" << std::endl;
    std::cout << "  4 -> chocolat (" << inventaire_.obtenirStock("chocolat") << " en stock)" << std::endl;
}



Commande::~Commande(){
    inventaire_.detacher(this);
}


void Commande::mettreAJour(const std::string& article, bool enRupture) {
    auto it = std::find(abonnements_.begin(), abonnements_.end(), article);
    if (it != abonnements_.end()) {
        if (enRupture) {
            std::cout << ConsoleColor::red << "[Notif Abonne] "  << ConsoleColor::reset << "Rupture de stock pour '" << article << "'." << std::endl;
        } else {
            std::cout << ConsoleColor::green << "[Notif Abonne] '" << ConsoleColor::reset << article << "' est de retour en stock." << std::endl;
        }
    }
}


void Commande::sabonner(const std::string& article) {
    abonnements_.push_back(article);
    std::cout << ConsoleColor::green << "[Abonnement] " << ConsoleColor::reset << "Notifications actvies pour  '" << article << "'." << std::endl;
}


void Commande::desabonner(const std::string& article) {
    auto it = std::find(abonnements_.begin(), abonnements_.end(), article);
    if (it != abonnements_.end()) {
        abonnements_.erase(it);
        std::cout << "[Abonnement] Desabonne de '" << article << "'." << std::endl;
    }
}


void Commande::afficherAbonnements() const {
    std::cout << ConsoleColor::blue << "Abonnements actifs:" << ConsoleColor::reset << std::endl;
    for (const auto& a : abonnements_) {
        std::cout << " - " << a << std::endl;
    }
}