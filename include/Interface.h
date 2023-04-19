#ifndef INTERFACE_H
#define INTERFACE_H

#include "Polynomes.h"
#include <vector>
#include <iostream>
#include "Fonction.h"
#include "CFonction.h"
#include "Constante.h"
#include "Somme.h"
#include "Difference.h"
#include "Produit.h"
#include "Quotient.h"
#include "Composee.h"
#include "Puissance.h"
#include <map>
class Interface
{
    public:
        //ctor
         Interface();
         Interface(Interface const& other);
         //meth
        Fonction* Cherchefct(std::string);
        void Interface_user();
        Fonction* poly();
        Fonction* fct();
        Fonction* fctcst();
        void Interface_Aide() const ;
        //dtor
        virtual ~Interface();

        //operateur d'affectation
        Interface& operator=(Interface const& autre);

    protected:

    private:
        std::map<std::string, Fonction*> memoire;



};

#endif // INTERFACE_H
