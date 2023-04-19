#include "Constante.h"


Constante::Constante()
{
    //ctor
}
Constante::Constante(double a ) :m_c(a)
{

}
void Constante :: affiche() const
{
    std::cout<<m_c;
}
double Constante::evalue(double a)
{
    return m_c;
}
Fonction* Constante::derivee()
{
    Fonction* P = new Constante(0);
    return P;
}
Constante::~Constante()
{
    //dtor
}
