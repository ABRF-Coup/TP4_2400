#include "Phase/PhaseInitiale.h"
#include "Phase/PhasePreparation.h"
#include "Commande/Commande.h"
#include <iostream>



 std::string PhaseInitiale::obtenirNom() const {
    return "Initiale";
}


 void PhaseInitiale::ajouterGarniture(Commande* c, std::string nomGarniture){
    c->executerAjouterGarniture(nomGarniture);
}


 void PhaseInitiale::ajouterBase(Commande* c,std::string type){
    c->executerAjouterBase(type);
}

 void PhaseInitiale::annuler(Commande* c){
    c->executerAnnulation();
}

 void PhaseInitiale::retablir(Commande* c){
    c->executerRetablissement();
}

 void PhaseInitiale::payer(Commande* c){
    std::cout << "Paiement refuse: etat Terminee requis (etat actuel: " << obtenirNom() << ")" << std::endl;
}


 void PhaseInitiale::terminer(Commande* c){
    std::cout << "La commande doit etre preparee avant d'etre terminee." << std::endl; 
}


 void PhaseInitiale::preparer(Commande* c){

    if(c->existanceYogourt()==false){
        std::cout << "Impossible de preparer sans yogourt." << std::endl;
    }
    else{
        std::cout << "Preparation en cours ..." << std::endl;
        c->setPhase(std::make_unique<PhasePreparation>());
    }
}






