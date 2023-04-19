#include "Produit.h"
#include <iostream>
#include "Somme.h"
using namespace std;

Produit::Produit(Fonction* a, Fonction* b) :m_f(a),m_g(b)
{

}
/*Produit::Produit(Produit const& autre)
{

}*/
void Produit::affiche() const
{
 cout<<"( ";
 m_f->affiche();
 cout<<" ) ";
 cout<<" * " ;
 cout<<" ( ";
 m_g->affiche();
 cout<<" ) " ;

}
double Produit::evalue(double w)
{
    return ((m_f->evalue(w))*(m_g->evalue(w)));
}

Fonction* Produit::derivee()
{

    return new Somme(new Produit(m_f->derivee(),m_f),new Produit(m_g->derivee(),m_g));
}
Produit& Produit::operator=(Produit const& autre)
{

    if (this == &autre) return *this; // handle self assignment
    //assignment operator
    return *this;
}
