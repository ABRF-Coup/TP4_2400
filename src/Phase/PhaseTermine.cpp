#include "Phase/PhaseTermine.h"
#include "Commande/Commande.h"
#include <iostream>





 std::string PhaseTermine::obtenirNom() const {
    return "Terminee";
}


 void PhaseTermine::ajouterGarniture(Commande* c,std::string nomGarniture){
    std::cout << "Commande terminee: impossible d'ajouter une garniture." << std::endl;
}


 void PhaseTermine::ajouterBase(Commande* c,std::string type){
    std::cout << "Commande terminee: impossible de modifier le yogourt." << std::endl;
}

 void PhaseTermine::annuler(Commande* c){
    std::cout << "Commande terminee: annulation impossible." << std::endl;
}

 void PhaseTermine::retablir(Commande* c){
    std::cout << "Commande terminee: retablissement impossible." << std::endl;
}

 void PhaseTermine::payer(Commande* c){
    if(c->getStrategie()==nullptr){
        std::cout << "Paiement refuse: choisissez d'abord un mode (mode prev|eclair|poly)." << std::endl;
    }else{
         c->executerPaiement();
    }
   
}


 void PhaseTermine::terminer(Commande* c){
    std::cout << "Commande deja terminee." << std::endl;
}


 void PhaseTermine::preparer(Commande* c){
    std::cout << "Commande terminee: preparation verouillee." << std::endl;
}






