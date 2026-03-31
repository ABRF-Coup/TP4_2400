#include "Commande/Commande.h"
#include "Inventaire/Inventaire.h"
#include "Garnitures/Fruit.h"
#include "Garnitures/Chocolat.h"
#include "Garnitures/Granola.h"
#include "Garnitures/Miel.h"
#include "Yogourt/YogourtGrec.h"
#include "Yogourt/YogourtNature.h"
#include "Phase/PhaseInitiale.h"
#include <iostream>



void Commande::setIndexActif(int indexActif)
{
    indexActif_ = indexActif-1;
}

Commande::Commande()
{
    indexActif_ = 0;
    phaseActuelle = std::make_unique<PhaseInitiale>();
}


void Commande::paiement(){
    phaseActuelle->payer();
}


void Commande::executerAjouterBase(const std::string& type)
{
    if (!base_[indexActif_].empty()) {
        return;
    }

    if (inventaire_.estDisponible(type)) {
        inventaire_.retirerStock(type);
        base_[indexActif_] = type;
        reconstruireYogourt(indexActif_);
        std::cout << yogourts_[indexActif_]->obtenirDescription() << " selectionne." << std::endl;
        redo_[indexActif_].clear();
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


double Commande::calculerTotal() const {
    double total = 0;
    if (yogourts_[0]) {
        total += yogourts_[0]->obtenirPrix();
    }
    if (yogourts_[1]) {
        total += yogourts_[1]->obtenirPrix();
    }

    if (!sp) return total; 
    
    
    return sp->calculerPrixFinal(total);
}


void Commande::setStrategie(std::unique_ptr<StrategiePaiement> s){
        sp = std::move(s);
        std::cout << "Mode de paiement actif: " << sp->obtenirNom() << "." << std::endl;
}

void Commande::setPhase(std::unique_ptr<Phase> p){
    phaseActuelle = std::move(p);
}

void Commande::preparer(){
    phaseActuelle->preparer(this);
}


void Commande::terminer(){
    phaseActuelle->terminer();
}


bool Commande::existanceYogourt() const
    {
        if(yogourts_[indexActif_] == nullptr){
            return false;
        }

        return true;
    }



void Commande::afficher() const {
    std::cout << "\n========== DEBUG YOGOURT #" << indexActif_ + 1 << " ==========" << std::endl;
    
    // Affichage de la base
    std::cout << "Base choisie     : " << (base_[indexActif_].empty() ? "AUCUNE" : base_[indexActif_]) << std::endl;
    
    // Affichage des piles
    std::cout << "Historique (u)   : [ ";
    for (const auto& nom : historiqueNomsGarnitures_[indexActif_]) std::cout << nom << ", ";
    std::cout << "]" << std::endl;

    std::cout << "Pile Redo (r)    : [ ";
    for (const auto& nom : redo_[indexActif_]) std::cout << nom << " ";
    std::cout << "]" << std::endl;

    // Affichage de l'objet concret
    if (yogourts_[indexActif_]) {
        std::cout << "Description      : " << yogourts_[indexActif_]->obtenirDescription() << std::endl;
        std::cout << "Prix Total       : " << calculerTotal() << " CAD" << std::endl;
    }
    std::cout << "==========================================\n" << std::endl;
}






