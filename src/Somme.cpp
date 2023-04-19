#include "Somme.h"
#include <iostream>

 using namespace std;

Somme::Somme(Fonction *a , Fonction* b ):m_a(a),m_b(b)

{

}
void Somme::affiche() const
{
    m_a->affiche();
   cout<<" + ";
    m_b->affiche();
}

Fonction* Somme::derivee()
{
    return new Somme(m_a->derivee(),m_b->derivee());

}
double Somme::evalue(double v)
{
    return m_a->evalue(v)+ m_b->evalue(v);
}
