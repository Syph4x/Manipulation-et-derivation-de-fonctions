#ifndef COMPOSEE_H
#define COMPOSEE_H

#include "Fonction.h"


class Composee : public Fonction
{
    public:
        //ctor
        Composee()=delete;
        Composee(Fonction*,Fonction*);
        Composee(Composee const& autre);

        //methode

        void  affiche()const override;
        double evalue(double) override;
        Fonction* derivee() override;

        //dtor
        virtual ~Composee()=default;

        //operateur d'afectation
        Composee& operator=(Composee const& autre);

    private:
        Fonction* m_fc1;
        Fonction* m_fc2;
};

#endif // COMPOSEE_H
