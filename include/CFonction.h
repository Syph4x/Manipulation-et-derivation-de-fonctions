
#ifndef CFONCTION_H
#define CFONCTION_H


#include "Fonction.h"
#include "iostream"
#include <string>
#include <cmath>



class CFonction : public Fonction
{
    public:

        CFonction()=delete;// on interdit le ctor par defaut
        CFonction(std::string);

        virtual ~CFonction();

        // pour pouvoire manipuler les fonction inclus dans la bibliotheque  CMaths
        void affiche() const override; //override parceque on redefinie une methode d'une classe mére
        double evalue(double) override;
        Fonction* derivee() override;



    private:
        std::string m_nom ;
        double (*cfonction_) (double);
};

#endif // CFONCTION_H
