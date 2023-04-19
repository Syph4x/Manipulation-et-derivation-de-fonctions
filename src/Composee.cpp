#include "Composee.h"
#include <string>
#include "Produit.h"
#include <iostream>
using namespace std;
Composee::Composee(Fonction* a ,Fonction*b): m_fc1(a),m_fc2(b)
{

}
Composee::Composee(Composee const& autre)
{

}
Composee& Composee::operator=(const   Composee& autre)
{
    if (this == &autre) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void Composee::affiche() const
{
    std::cout<<"(";
    m_fc1->affiche();
    std::cout<<")";
    std::cout<<"o";
    std::cout<<"(";
    m_fc2->affiche();
    std::cout<<")";
}
double Composee::evalue(double x)
{
    return (m_fc1->evalue(m_fc2->evalue(x)));
}
Fonction* Composee::derivee()
{
    return new Produit(new Composee(m_fc1->derivee(),m_fc2),m_fc2->derivee());
}
