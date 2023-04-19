#ifndef QUOTIENT_H
#define QUOTIENT_H

#include "Fonction.h"


class Quotient :public Fonction
{
    public:
        //ctor
        Quotient()=delete;
        Quotient(Fonction*,Fonction*);
        Quotient (Quotient const & autre);


        //methode
        void affiche() const override;
        double evalue(double) override;
        Fonction* derivee() override;




        //operateur d'affectation
        Quotient& operator=(Quotient const& autre);

        //dtor
        virtual ~Quotient()=default;




    private:
        Fonction* m_fh;
        Fonction* m_fb;
};

#endif // QUOTIENT_H
