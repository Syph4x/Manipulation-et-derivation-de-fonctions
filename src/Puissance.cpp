#include "Puissance.h"
#include <cmath>
#include <iostream>
#include "Constante.h"
#include <Produit.h>
using namespace std;
Puissance::Puissance(Fonction* f, double p) : m_fct(f),m_pf(p)
{

}

Puissance::Puissance(const Puissance& autre)
{

}
Puissance& Puissance::operator=(Puissance const& autre)
{
    if (this == &autre) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void Puissance::affiche() const
{
    std::cout<<"(";
    m_fct->affiche();
    std::cout<<")";
    std::cout<<"^";
    std::cout<<"(";
    std::cout<<m_pf;
    std::cout<<")";
}
double Puissance::evalue(double x)
{
    return (pow((m_fct->evalue(x)),(Constante(m_pf).evalue(x))));
}
Fonction* Puissance::derivee()
{
    return new Produit(new Produit(new Constante(m_pf),new Puissance(m_fct,m_pf-1)),m_fct->derivee());
}
