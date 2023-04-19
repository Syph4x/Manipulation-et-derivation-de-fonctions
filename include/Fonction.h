#ifndef FONCTION_H
#define FONCTION_H







class Fonction
{
    public:
        Fonction();
        virtual void affiche() const=0 ;
        virtual double evalue (double ) =0;
        virtual Fonction *derivee () =0;
        virtual ~Fonction();
        Fonction (Fonction const & autre);
        Fonction& operator=(Fonction const& autre);
    protected:

    private:
};

#endif // FONCTION_H
