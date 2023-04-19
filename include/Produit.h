

#ifndef PRODUIT_H
#define PRODUIT_H

#include "Fonction.h"


class Produit : public Fonction
{
    public:
        //const
        Produit()=delete;
        Produit(Fonction* f,Fonction*g );
      //  Produit (Produit const& autre);
        //des
        virtual ~Produit()=default;

        //methodes herité
        void affiche() const override;
        double evalue(double) override ;
        Fonction* derivee() override;

         //operateur d'affectation
        Produit& operator=(Produit const& autre);

    private:
        Fonction* m_f;
        Fonction* m_g;

};

#endif // PRODUIT_H
