#ifndef INVENTAIRE_H
#define INVENTAIRE_H


#include <map>
#include <string>


class Inventaire{
public:
    Inventaire();
    ~Inventaire() = default;
    void initialiserStock();
    bool estDisponible(const std::string& nom) const;
    void remettreStock(const std::string& nom);
    bool retirerStock(const std::string& nom);
    int obtenirQuantite(const std::string& nom) const;
    void afficherInventaire() const;
    void initialisationVisuelle(const std::string& nom, int quantite);
private:
    std::map<std::string, int> stocks_;
};

#endif