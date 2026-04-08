#ifndef INVENTAIRE_H
#define INVENTAIRE_H


#include <map>
#include <string>
#include "Observateur/Observateur.h"
#include <algorithm>


class Inventaire{
public:
    Inventaire();
    ~Inventaire() = default;
    void initialiserStock();
    bool estDisponible(const std::string& nom) const;
    void remettreStock(const std::string& nom);
    bool retirerStock(const std::string& nom);
    int obtenirStock(const std::string& nom) const;
    void afficherInventaire() const;
    void initialisationVisuelle(const std::string& nom, int quantite);

    void attacher(Observateur* obs);
    void detacher(Observateur* obs);
    void notifier(const std::string& article, bool enRupture);


private:
    std::map<std::string, int> stocks_;
    std::vector<Observateur*> observateurs_;

};

#endif