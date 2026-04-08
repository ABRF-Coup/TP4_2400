#include "Phase/PhasePreparation.h"
#include "Phase/PhaseTermine.h"
#include "Commande/Commande.h"
#include "ui/ConsoleColors.h"
#include <iostream>



 std::string PhasePreparation::obtenirNom() const {
    return "En preparation";
}


 void PhasePreparation::ajouterGarniture(Commande* c,std::string nomGarniture){
    std::cout << "Commande en preparation: impossible d'ajouter une garniture." << std::endl;
}


 void PhasePreparation::ajouterBase(Commande* c,std::string type){
    std::cout << "Commande en preparation: impossible de modifier le yogourt." << std::endl;
}

 void PhasePreparation::annuler(Commande* c){
    std::cout << "Commande en preparation : annulation verouillee." << std::endl;
}

 void PhasePreparation::retablir(Commande* c){
    std::cout << "Commande en preparation : retablissement verouillee." << std::endl;
}

 void PhasePreparation::payer(Commande* c){
    std::cout << ConsoleColor::red << "Paiement refuse: etat Terminee requis (etat actuel: " << obtenirNom() << ")." << ConsoleColor::reset << std::endl;
}


 void PhasePreparation::terminer(Commande* c){
     std::cout << "Commande terminee." << std::endl;
     c->setPhase(std::make_unique<PhaseTermine>());
}


 void PhasePreparation::preparer(Commande* c){
    std::cout << "Commande deja en preparation." << std::endl;
}






