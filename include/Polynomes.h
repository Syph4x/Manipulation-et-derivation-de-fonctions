#ifndef POLYNOMES_H
#define POLYNOMES_H


#include "Fonction.h"
#include <vector>



class Polynomes : public Fonction
{
    public:
        Polynomes()=delete;
        virtual ~Polynomes();
        void poly() const; // construit un polynome en demandant à l'utilisateur
        Polynomes(std::vector<double> coeff) ; //le constructeur de polynome a partire d'un vecteur contenant les coeff du poly
        void affiche () const override ; // affiche le polynomes avec ces coefficients
        double evalue(double) override ; //evalue le polynomes en un point
        Fonction * derivee() override ; // derive le polynome
        void set_coeff(std::vector <double> );
        std::vector<double> get_coeff () const;
    protected:

    private:
        std::vector <double> m_coeff;
};

#endif // POLYNOMES_H
