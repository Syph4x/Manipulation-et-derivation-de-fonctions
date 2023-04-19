

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Fonction.h"
#include <iostream>


class Constante : public Fonction
{
    public:
        Constante();
        virtual ~Constante();
        void affiche () const override;
        double evalue (double) override ;
        Fonction* derivee() override ;
        Constante (double);



    private:
        double m_c{0};
};

#endif // CONSTANTE_H
