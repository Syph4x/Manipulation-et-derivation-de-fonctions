#include "Interface.h"
#include "Interface.h"
#include <string>
using namespace std;
Interface::Interface()
{
    //ctor
}

Interface::~Interface()
{
    //dtor
}

Interface::Interface(Interface const& autre)
{
    //copy ctor
}

Interface& Interface::operator=(Interface const& autre)
{
    if (this == &autre) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void Interface::Interface_Aide() const
{
    string aide{"aide commande: \n poly       : pour creer un polynome.\n constante  : pour creer une fonction constante.\n Cfonction  : pour utiliser  les fonctions de CMATH : trigonometrique , logarithme , exponentielle ... \n somme      : pour faire la somme de fonction . \n difference : pour faire la difference de fonction.\n produit    : pour faire un produit de fonction.\n quotient   : pour creer un quotient de fonction. \n puissance  : pour associer une puissance a une fonction. \n compose    : pour composer des fonctions.\n affiche    : pour afficher les fonctions.\n evalue     : pour evaluer les fonctions en un point. \n exit       : pour sortir du programme.\n "};

    cout << aide <<endl;
}

Fonction* Interface::poly() {
    int a;
    int i;
    std::vector<double> v;
    std::cout<<"Quel est le degres du polynome ?"<<std::endl;
    std::cin >> i ;
    for(int  j= 0 ; j <= i; j++)
    {
        std::cout<<"Donnez le coefficient du degree x^"<<j<< "  :  " ;
        std::cin >> a;
        v.push_back(a);
    }
    Polynomes Q(v);
    Q.affiche();
    Fonction *P = new Polynomes(v);
    return P;
}

Fonction* Interface::fctcst() {
    int a;
    std::cout<<"Quel est la constante"<<std::endl;
    std::cin>> a;
    Fonction *P = new Constante(a);
    return P;
}

Fonction* Interface::fct() {
    std::string b ;
    std::cin>>b ;
    Fonction*P = new CFonction(b);
    return P;
}

Fonction* Interface::Cherchefct(std::string b){

    memoire.at(b)->affiche();
    return memoire.at(b);
}


void Interface::Interface_user()
{
    std::string b;
    while(b != "exit")
    {
        std::cin >> b;
        if(b=="poly")
        {
            std::cout <<"Quel est le nom de la fonction ?" << std::endl;
            std::cin >> b;
            memoire.insert(std::make_pair(b, poly()));
            std::cout << " " << std::endl;
        }
        if(b=="constante")
        {
            std::cout <<"Quel est le nom de la fonction ?" << std::endl;
            std::cin >> b;
            memoire.insert(std::make_pair(b, fctcst()));
            std::cout << " " << std::endl;
        }
        if(b=="Cfonction")
        {
            std::cout <<"comment sera nomer votre fonction?" << std::endl;
            std::cin >> b;
            std::cout <<"Quel  fonction voulez  vous creer ?" << std::endl;
            memoire.insert(std::make_pair(b, fct()));
            std::cout<<"votre fonction a ete creer"<<endl;
            std::cout << " " << std::endl;
        }
        if(b=="affiche")
        {
            std::cout<<"Afficher quel fonction?"<<std::endl;
            std::cin>>b;
            Cherchefct(b);
            std::cout << " " << std::endl;
        }
        if(b=="somme")
        {
            std::cout<<"comment s'appelle la premiere fonction de la Somme ?"<<std::endl;
            std::cin>>b;
            std::string c;
            std::cout<<"comment s'appelle la deuxieme fonction de la Somme ?"<<std::endl;
            std::cin>>c;
            Somme(memoire[b],memoire[c]).affiche();
            std::cout<<"Comment s'appelle cette nouvelle fonction?"<<std::endl;
            std::string d;
            std::cin>> d;
            memoire.insert(std::make_pair(d,new Somme(memoire[b],memoire[c])));
            std::cout << " " << std::endl;
        }
        if(b=="derivee")
        {
            std::cout<<"Derivee de quel fonction?"<<std::endl;
            std::cin>>b;
            Fonction * D = memoire[b]->derivee();
            D->affiche();
            std::cout << " " << std::endl;
            std::cout<<"Comment s'appelle cette nouvelle fonction?"<<std::endl;
            std::string d;
            std::cin>> d;
            memoire.insert(std::make_pair(d,D));
            std::cout << " " << std::endl;
        }
        if(b=="difference")
        {
            std::cout<<"comment s'appelle la premiere fonction de la difference ?"<<std::endl;
            std::cin>>b;
            std::string c;
            std::cout<<"comment s'appelle la deuxieme fonction de la difference ?"<<std::endl;
            std::cin>>c;
            std::cout<<"Comment s'appelle cette nouvelle fonction?"<<std::endl;
            std::string d;
            std::cin>> d;
            Difference(memoire[b],memoire[c]).affiche();
            memoire.insert(std::make_pair(d,new Difference(memoire[b],memoire[c])));
            std::cout << " " << std::endl;
        }
        if(b=="produit")
        {
            std::cout<<"comment s'appelle la premiere fonction du Produit ?"<<std::endl;
            std::cin>>b;
            std::string c;
            std::cout<<"comment s'appelle la deuxieme fonction du Produit ?"<<std::endl;
            std::cin>>c;
            std::cout<<"Comment s'appelle cette nouvelle fonction?"<<std::endl;
            std::string d;
            std::cin>> d;
            Produit(memoire[b],memoire[c]).affiche();
            memoire.insert(std::make_pair(d,new Produit(memoire[b],memoire[c])));
            std::cout << " " << std::endl;
        }
        if(b=="quotient")
        {
            std::cout<<"quel est la premiere fonction du Quotient ?"<<std::endl;
            std::cin>>b;
            std::string c;
            std::cout<<"quel est la deuxieme fonction du Quotient ?"<<std::endl;
            std::cin>>c;
            std::cout<<" "<<std::endl;
            std::cout<<"Comment s'appelle cette nouvelle fonction?"<<std::endl;
            std::string d;
            std::cin>> d;
            Quotient(memoire[b],memoire[c]).affiche();
            memoire.insert(std::make_pair(d,new Quotient(memoire[b],memoire[c])));
            std::cout << " " << std::endl;
        }
        if(b=="compose")
        {
            std::cout<<"quel est la premiere fonction a composer ?"<<std::endl;
            std::cin>>b;
            std::string c;
            std::cout<<"quel est la deuxieme fonction a composer ? "<<std::endl;
            std::cin>>c;
            std::cout<<" "<<std::endl;
            std::cout<<"Comment s'appelle cette nouvelle fonction?"<<std::endl;
            std::string d;
            std::cin>> d;
            Composee(memoire[b],memoire[c]).affiche();
            memoire.insert(std::make_pair(d,new Composee(memoire[b],memoire[c])));
            std::cout << " " << std::endl;
        }
        if(b=="puissance")
        {
            std::cout<<"Puissance de quels fonctions?"<<std::endl;
            std::cin>>b;
            std::cout<<"Quel est la puissance?"<<std::endl;
            double c;
            std::cin>>c;
            std::cout<<" "<<std::endl;
            std::cout<<"Comment s'appelle cette nouvelle fonction?"<<std::endl;
            std::string d;
            std::cin>> d;
            Puissance(memoire[b],c).affiche();
            memoire.insert(std::make_pair(d,new Puissance(memoire[b],c)));
            std::cout << " " << std::endl;
        }
        if(b=="evalue")
        {
            std::cout<<"Evaluation de quels fonctions?"<<std::endl;
            std::cin>>b;
            std::cout<<"Evaluation en quels points?"<<std::endl;
            double d;
            std::cin>>d;
            double q;
            q=memoire[b]->evalue(d);
            std::cout<<q<<std::endl;
        }
    }
}
