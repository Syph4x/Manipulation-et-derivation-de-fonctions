#ifndef PUISSANCE_H
#define PUISSANCE_H
#include "Fonction.h"


class Puissance :public Fonction
{
    public:
        //ctor
        Puissance()=delete;
        Puissance(Fonction*, double );
        Puissance(Puissance const& autre );

        //methodes

        void affiche() const override;
        double evalue(double) override;
        Fonction* derivee() override;
        //dtor
        virtual ~Puissance()=default;

        //operateur d'affectation
         Puissance& operator=(const Puissance& other);
    protected:

    private:
        Fonction* m_fct;
        double m_pf;
};

#endif // PUISSANCE_H
