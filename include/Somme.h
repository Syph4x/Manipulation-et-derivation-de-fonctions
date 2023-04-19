


#ifndef SOMME_H
#define SOMME_H

#include "Fonction.h"

class Somme : public Fonction
{
    public:
        //ctor
        Somme()=delete;
        Somme(Fonction* ,Fonction*);


        //dtor
        virtual ~Somme()=default;

        //methodes
       void  affiche() const override;
       double evalue(double) override;
       Fonction* derivee() override;

    protected:

    private:
    Fonction* m_a;
    Fonction* m_b;
};

#endif // SOMME_H
