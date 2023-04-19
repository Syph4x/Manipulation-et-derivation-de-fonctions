#include "Quotient.h"
#include <iostream>
#include "Difference.h"
#include "produit.h"
Quotient::Quotient(Fonction* fh,Fonction* fb ):m_fh(fh),m_fb(fb)
{

}
Quotient::Quotient(Quotient const & autre)
{

}

void Quotient::affiche() const
{
    std::cout<<"(";
    m_fh->affiche();
    std::cout<<")";
    std::cout<<"/";
    std::cout<<"(";
    m_fb->affiche();
    std::cout<<")";
}
double Quotient::evalue(double x)
{
    return (m_fh->evalue(x))/(m_fb->evalue(x));
}
 Fonction* Quotient::derivee()
{

return new Quotient(new Difference(( new Produit(m_fh->derivee(),m_fb)),new Produit(m_fh,m_fb->derivee())), new Produit(m_fb,m_fb));
}
