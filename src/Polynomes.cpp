#include "Polynomes.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "Constante.h"

using namespace std;

Polynomes::Polynomes(vector <double> coeff ) : m_coeff(coeff)
{

}

void Polynomes::poly()const
{
  int valD;
  int d;
  vector <double> v ;
  cout<< "quel est le degree du Polynomes ? "<<endl;
  cin >> d;


  for (int j=0; j< d; j++)
  {
    cout <<"donnez le coeff associer au degre : "<<j<<endl;
    cin >> valD;
  v.push_back(valD);
  }
  Polynomes Q(v);
  Q.affiche();

}
void Polynomes::affiche() const
{
    if (m_coeff[0]!=0)
    {
    cout<<m_coeff[0]<<"+";
    }

    if (m_coeff[1]!=0)
    cout<<m_coeff[1]<<"x+";
 for(size_t i = 2 ; i < size(m_coeff)-1 ; i++)
    {
    if (m_coeff[i]!=0)
    {

        std::cout<< m_coeff[i] << "x^"<<i;
        std::cout<<"+";
    }
    }
    if (m_coeff[m_coeff.size()-1]!=0)
    std::cout << m_coeff.back() << "x^"<< m_coeff.size()-1;
}
double Polynomes::evalue(double a)
{
    double s=0;
    for (size_t i=0;i<size(m_coeff);i++)
    {
    s=s+(pow(a,i)*m_coeff[i]);
    }

    return s;
}
Fonction* Polynomes::derivee ()
{
vector <double> v;
for (size_t i=1;i<size(m_coeff);i++)
    {
 v.push_back(m_coeff[i]*i);
    }
Fonction* P = new Polynomes(v);
return P;
}
void Polynomes::set_coeff(std::vector<double> coeff)
{
    m_coeff=coeff;
}
vector<double> Polynomes::get_coeff() const
{
    return m_coeff;
}
Polynomes::~Polynomes()
{
    //dtor
}
