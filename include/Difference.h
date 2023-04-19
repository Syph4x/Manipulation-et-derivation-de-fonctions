#ifndef DIFFERENCE_H
#define DIFFERENCE_H
#include "Fonction.h"


class Difference:public Fonction
{
    public:
        //ctor
        Difference()=delete;
        Difference(Fonction* ,Fonction*);
        Difference(Difference const& autre);

        //methode
        void affiche() const override;
        double evalue(double) override;
        Fonction* derivee() override ;


        //dtor
        virtual ~Difference()=default;

    protected:

    private:
        Fonction* m_f1;
        Fonction* m_f2;
};

#endif // DIFFERENCE_H
