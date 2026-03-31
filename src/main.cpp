#include <iostream>
#include "Yogourt/YogourtNature.h"
#include "Yogourt/YogourtGrec.h"
#include "Garnitures/Fruit.h"
#include "Garnitures/Chocolat.h"
#include "Garnitures/Granola.h"
#include "Garnitures/Miel.h"
#include "Paiement/StrategiePrevente.h"
#include "Paiement/StrategieVenteEclaire.h"
#include "Commande/Commande.h"
#include "ui/ConsoleColors.h"
#include "Inventaire/Inventaire.h"
#include "Phase/Phase.h"
#include "Phase/PhaseInitiale.h"



int main()
{



    Commande c;

    c.setIndexActif(1);

    c.afficher();

    c.preparer();

    c.ajoutBase("grec");

    c.afficher();

    c.annuler();

    c.afficher();

    c.ajoutGarniture("chocolat");

    c.afficher();

    c.ajoutGarniture("chocolat");

    c.afficher();

    c.ajoutGarniture("fruits");

    c.afficher();


    c.annuler();

    c.afficher();

    c.retablissement();

    c.afficher();

    c.terminer();

    c.setStrategie(std::make_unique<StrategieVenteEclaire>());

    c.afficher();

    c.preparer();

    c.calculerTotal();

    c.afficher();


    /*std::cout << ConsoleColor::green << "Bienvenue dans notre boutique de yogourt!" << ConsoleColor::reset << std::endl;
    Inventaire inventaire;

    
    inventaire.afficherInventaire();
    std::unique_ptr<Yogourt> yNature = std::make_unique<YogourtNature>();
    yNature = std::make_unique<Fruit>(std::move(yNature));
   

    std::cout << ConsoleColor::yellow << yNature->obtenirDescription() << ConsoleColor::reset << std::endl;
    inventaire.retirerStock("Fruits");





    /*std::unique_ptr<Yogourt> yNature = std::make_unique<YogourtNature>();
    std::unique_ptr<Yogourt> yGrec = std::make_unique<YogourtGrec>();
    std::unique_ptr<StrategiePaiement> strategie = std::make_unique<StrategieVenteEclaire>();
    std::unique_ptr<StrategiePaiement> strategie2 = std::make_unique<StrategiePrevente>();


    yNature = std::make_unique<Fruit>(std::move(yNature));
    yNature = std::make_unique<Miel>(std::move(yNature));

    yGrec = std::make_unique<Granola>(std::move(yGrec));
    yGrec = std::make_unique<Chocolat>(std::move(yGrec));


    std::cout << ConsoleColor::green << "Bienvenue dans notre boutique de yogourt!" << ConsoleColor::reset << std::endl;


    std::cout << ConsoleColor::yellow << yNature->obtenirDescription() << ConsoleColor::reset << std::endl;
    std::cout << ConsoleColor::cyan << yNature->obtenirPrix() << ConsoleColor::reset << std::endl;

    double totalFinal = strategie->calculerPrixFinal(yNature->obtenirPrix());

    std::cout << "Mode: " << strategie->obtenirNom() << std::endl;
    std::cout << "Total final: " << totalFinal << " CAD" << std::endl;


    std::cout << ConsoleColor::yellow << yGrec->obtenirDescription() << ConsoleColor::reset << std::endl;
    std::cout << ConsoleColor::cyan << yGrec->obtenirPrix() << ConsoleColor::reset << std::endl;

    double totalFinal2 = strategie2->calculerPrixFinal(yGrec->obtenirPrix());

    std::cout << "Mode: " << strategie2->obtenirNom() << std::endl;
    std::cout << "Total final: " << totalFinal2 << " CAD" << std::endl;
   
    /*std::cout << ConsoleColor::cyan << "Je suis Pattern1 :  " << p1.getValue() << ConsoleColor::reset << std::endl;
    std::cout << ConsoleColor::cyan << "Je suis Pattern2 :  " << p2.getValue() << ConsoleColor::reset << std::endl;
    std::cout << ConsoleColor::magenta << "Bon TP a tous :) " << ConsoleColor::reset << std::endl;*/

    return 0;
};