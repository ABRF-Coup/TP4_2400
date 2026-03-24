#include "Inventaire/Inventaire.h"
#include <iostream>
#include <string>

bool Inventaire::estDisponible(const std::string& nom) const
{
    auto it = stocks_.find(nom);
    return it != stocks_.end() && it->second > 0;
}

void Inventaire::remettreStock(const std::string& nom)
{
    auto it = stocks_.find(nom);
    
}

bool Inventaire::retirerStock(const std::string& nom)
{
    auto it = stocks_.find(nom);
    if(it != stocks_.end()){
        if(it->second > 0){
            auto itAncien = it->second;
            auto itNouveau = it->second-1;
            std::cout << "[Stock]" << nom << " : " << itAncien << " -> " << itNouveau << std::endl;
            it->second--;
            return true;

        } else {
            return false;
        }
    }
}


int Inventaire::obtenirQuantite(const std::string& nom) const
{
    auto it = stocks_.find(nom);
    if(it != stocks_.end()){
        return it->second;
    } else {
        return 0;
    }
}



void Inventaire::afficherInventaire() const
{
    std::cout << "Inventaire:" << std::endl;
    for(const auto& item : stocks_){
        std::cout << "- " << item.first << ": " << item.second << std::endl;
    }
}


void Inventaire::initialisationVisuelle(const std::string& nom, int quantite)
{
    std::cout << "[Stock] " << nom << " : " << stocks_[nom] << " -> " << quantite << std::endl; 
    stocks_[nom] = quantite;
}

void Inventaire::initialiserStock()
{
    stocks_["nature"] = 0;
    stocks_["grec"] = 0;
    stocks_["fruits"] = 0;
    stocks_["granola"] = 0;
    stocks_["miel"] = 0;
    stocks_["chocolat"] = 0;


    initialisationVisuelle("nature", 3);
    initialisationVisuelle("grec", 1);
    initialisationVisuelle("fruits", 5);
    initialisationVisuelle("granola", 4);
    initialisationVisuelle("miel", 4);
    initialisationVisuelle("chocolat", 1);
    
    
}


Inventaire::Inventaire()
{
    initialiserStock();
}