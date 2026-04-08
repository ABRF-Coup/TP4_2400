#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "Commande/Commande.h"
#include "Paiement/StrategieVenteEclaire.h"
#include "Paiement/StrategiePrevente.h"
#include "Paiement/StrategiePoly.h"
#include "ui/ConsoleColors.h"


void afficherAide() {
    std::cout << ConsoleColor::cyan <<      "Commandes:" << ConsoleColor::reset << std::endl;
    std::cout << "  c nature|grec           -> Ajouter un yogourt (max 2)" << std::endl;
    std::cout << "  sel 1|2                 -> Selectionner le yogourt actif" << std::endl;
    std::cout << "  f                       -> Ouvrir menu garnitures du yogourt actif" << std::endl;
    std::cout << "  u                       -> Annuler derniere garniture du yogourt actif" << std::endl;
    std::cout << "  r                       -> Refaire derniere garniture du yogourt actif" << std::endl;
    std::cout << "  p                       -> Preparer la commande" << std::endl;
    std::cout << "  t                       -> Terminer la commande" << std::endl;
    std::cout << "  mode prev|eclair|poly   -> Changer le mode de paiement" << std::endl;
    std::cout << "  pay                     -> Finaliser paiement (etat Terminee requis)" << std::endl;
    std::cout << "  pay prev|eclair|poly    -> Alias mode + payer" << std::endl;
    std::cout << "  total                   -> Afficher sous-total et total projete" << std::endl;
    std::cout << "  sub article             -> S'abonner aux notifications d'un article" << std::endl;
    std::cout << "  unsub article           -> Se desabonner d'un article" << std::endl;
    std::cout << "  subs                    -> Afficher abonnements actifs" << std::endl;
    std::cout << "  clear|cls               -> Nettoyer l'ecran" << std::endl;
    std::cout << "  s                       -> Afficher les stocks" << std::endl;
    std::cout << "  h                       -> Aide" << std::endl;
    std::cout << "  q                       -> Quitter" << std::endl;
}


void gererMenuGarnitures(Commande& c) {
    std::string choix;
    while (true) {
        std::cout << "\n" << ConsoleColor::cyan << "Menu Garnitures" << ConsoleColor::reset << std::endl;
        std::cout << "  Yogourt actif: #" << (c.getIndexActif() + 1) << std::endl;
        c.afficherOptionsGarnitures();
        std::cout << "  q -> retour menu principal" << std::endl;
        
        std::cout << ConsoleColor::magenta << "Choix garniture: " << ConsoleColor::reset;
        std::cin >> choix;
        if (choix == "q") { 
            std::cout << ConsoleColor::cyan << "Retour au menu principal" << ConsoleColor::reset << std::endl;
            std::cin.ignore(); break;
         }

        if (choix == "1") c.ajoutGarniture("fruits");
        else if (choix == "2") c.ajoutGarniture("granola");
        else if (choix == "3") c.ajoutGarniture("miel");
        else if (choix == "4") c.ajoutGarniture("chocolat");
        
    }
}

int main() {
    Commande maCommande;
    std::string ligne;

    std::cout << ConsoleColor::green << "Bienvenue sur TonYogourt !" << ConsoleColor::reset << std::endl;
    afficherAide();
    maCommande.afficher();

    while (std::getline(std::cin, ligne) && ligne != "q") {
        if (ligne.empty()) continue;
        std::stringstream ss(ligne);
        std::string cmd, arg;
        ss >> cmd >> arg;

        if (cmd == "c") maCommande.ajoutBase(arg);
        else if (cmd == "sel") maCommande.setIndexActif(std::stoi(arg));
        else if (cmd == "f") gererMenuGarnitures(maCommande);
        else if (cmd == "u") maCommande.annuler();
        else if (cmd == "r") maCommande.retablissement();
        else if (cmd == "p") maCommande.preparer();
        else if (cmd == "t") maCommande.terminer();

        else if (cmd == "sub") maCommande.sabonner(arg);
        else if (cmd == "unsub") maCommande.desabonner(arg);
        else if (cmd == "subs") maCommande.afficherAbonnements();


        else if (cmd == "mode") {
            if (arg == "eclair") maCommande.setStrategie(std::make_unique<StrategieVenteEclaire>());
            else if (arg == "prev") maCommande.setStrategie(std::make_unique<StrategiePrevente>());
            else if (arg == "poly") maCommande.setStrategie(std::make_unique<StrategiePoly>());
        }
        else if (cmd == "pay") {
            if (arg == "eclair") maCommande.setStrategie(std::make_unique<StrategieVenteEclaire>());
            else if (arg == "prev") maCommande.setStrategie(std::make_unique<StrategiePrevente>());
            else if (arg == "poly") maCommande.setStrategie(std::make_unique<StrategiePoly>());
            maCommande.paiement();

            if (maCommande.getPhaseNom() == "Terminee" && maCommande.getStrategie() != nullptr) {
                return 0;
            }
        }
        else if (cmd == "total") maCommande.afficherDetailsCalcul();
        else if (cmd == "s") {
            std::cout << ConsoleColor::cyan << "Stocks:" << ConsoleColor::reset << std::endl;
            maCommande.afficherInventaire();
        }
        else if (cmd == "h") afficherAide();
        else if (cmd == "clear" || cmd == "cls") system(cmd.c_str());

        maCommande.afficher();
    }
    return 0;
}