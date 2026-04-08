#pragma once
#include <string>
#include <vector>

#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H


class Observateur {
public:
	virtual ~Observateur() = default;
	virtual void mettreAJour(const std::string& article, bool enRupture) = 0;
    virtual const std::vector<std::string>& obtenirAbonnements() const = 0;

};


#endif