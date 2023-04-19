#include "CFonction.h"
#include "Produit.h"
#include "Constante.h"
#include "puissance.h"
#include "Somme.h"
#include "Quotient.h"
#include "Polynomes.h"

using namespace std;


CFonction::CFonction(string a ) : m_nom(a)
{
    if (a=="tan")
    {
        cfonction_=tan;
    }
    else if (a=="cos")
    {
        cfonction_=cos;
    }
    else if (a=="sin")
    {
        cfonction_=sin;
    }
      else if (a=="log")
    {
        cfonction_=log;
    }
    else if (a=="exp")
    {
        cfonction_=exp;
    }

    else
    {
        cout<<"La fonction saisie n'est pas prises en charge par ce programme "<<endl;
    }
}

void CFonction::affiche() const
{
    cout<<m_nom;
}
double CFonction::evalue(double a)
{
    return cfonction_(a);
}

Fonction* CFonction::derivee()
{
    Fonction* cf_;
    if (m_nom=="sin")
    {
        cf_= new CFonction ("cos");
    }
    else if (m_nom=="cos")
    {
        cf_= new Produit(new Constante (-1),new CFonction ("sin"));
    }
    else if (m_nom=="tan")
    {
        cf_=new Somme(new Constante (1),new Puissance(new CFonction ("cos"), 2));
    }
    else if (m_nom=="exp")
    {
        cf_= new CFonction ("exp");
    }
    else if (m_nom=="log")
    {
        cf_= new Quotient(new Constante (1),new Polynomes (vector<double> {0,1}));
    }
    else
    {
        cout<<"La fonction saisie ne peut pas etre utiliser avec ce programme "<<endl;
    }

    return cf_;
}
CFonction::~CFonction()
{
    //dtor
}
