#include "Difference.h"
#include<iostream>

 using namespace std;

Difference::Difference(Fonction* a,Fonction* b):m_f1(a),m_f2(b)
{

}

Difference::Difference(Difference const& autre )
{
//copy
}
void Difference::affiche() const
{
    m_f1->affiche();
    cout<<" - ";
    m_f2->affiche();
}
double Difference::evalue(double x)
{
    return m_f1->evalue(x) - m_f2->evalue(x);

}
Fonction* Difference::derivee()
{
   return new Difference(m_f1->derivee(),m_f2->derivee());
}
