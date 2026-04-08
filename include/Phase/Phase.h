#ifndef PHASE_H
#define PHASE_H


#include <string>

class Commande;


class Phase{

    public:
    
        ~Phase() = default;

        virtual void ajouterBase(Commande* c,std::string type) = 0;
        virtual void ajouterGarniture(Commande* c,std::string nomGarniture)= 0;
        /*virtual void setModeVente(Commande* c, std::string nomStrategiePaiement)=0;*/
        virtual std::string obtenirNom() const =0 ;
        virtual void annuler(Commande* c)= 0;
        virtual void preparer(Commande* c)= 0;
        virtual void retablir(Commande* c)= 0;
        virtual void terminer(Commande* c)= 0;
        virtual void payer(Commande* c)= 0;


};


#endif




