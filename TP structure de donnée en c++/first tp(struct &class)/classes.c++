#include <iostream>

using namespace std;
class CompteBancaire{
    private:
         string titulaire;
         float solde;
         string telephone;
     public:    
    CompteBancaire()
    {
        titulaire="";
          solde=0;
         telephone="";

    }
    CompteBancaire(string titulaire2,float solde2,string telephone2)
    {
        titulaire=titulaire2;
         solde=solde2;
         telephone=telephone2;
         cout<<"initialisation reussi"<<endl;
    }
    void setSolde(float montant)
    {
        if(montant>0)
            solde = montant;
     else cout<<"ca pas marche le mantatn doit etre >0"<<endl;
            
    }
    void setTitulaire(string nom)
    {
        if(nom.empty())
        titulaire = nom;
        else
        cout<<"ca pas marche le nom ne doit pas etre vide"<<endl;
    }
    void setTelephone(string numero)
    {
      if(numero.size()!=10)
          cout<<"ca pas marche le doit doit avoi 10 chiffres";
    else
           telephone = numero;
    
    }
    string getTitulaire()
    {
        cout<<"titulaire est: "<<titulaire<<endl;
    }
    float getSolde()              
    {cout<<"solde es: "<<solde<<endl;

    }


   void affiche()
    {
        cout<<titulaire<<endl;
        cout<<solde<<endl;
        cout<<telephone<<endl;
    }
    bool deposer(float montant)
    {
        if(montant>0)
        {
            solde+=montant;
            return true;
        }
        return false;
    }
    virtual bool retirer(float montant)
    {
        if(solde>=montant && montant>0)
        {
        solde-=montant;
        return true;
        }

    }
    bool vermentVers(CompteBancaire *d, float montant)
    {
        if(solde>montant&&montant>0)
        {
            solde-=montant;
            d->solde+=montant;
            return true;
        }
    }
    ~CompteBancaire(){
        cout<<"objet detruit "<<titulaire<<endl;
    }

};
class CompteCourant : public CompteBancaire {
  private:
 
    public:
    int retrait =1000;
      CompteCourant(string titulaire, float solde, string telephone) 
      : CompteBancaire(titulaire, solde, telephone) {}
  
      bool retirer(float montant) override {
        if (montant > retrait) {
          cout << "Retrait supérieur à la limite de 100 DH non autorisé." << endl;
          return false;
        }
        return CompteBancaire::retirer(montant);
      }
  };
  class CompteEpargne : public CompteBancaire {
    private:
      float tauxInteret;
  
    public:
      CompteEpargne(string titulaire, float solde, string telephone, float tauxInteret) 
        : CompteBancaire(titulaire, solde, telephone), tauxInteret(tauxInteret) {}
  
      bool retirer(float montant) override {
        cout << "Erreur : les retraits sont interdits sur les comptes épargne." << endl;
        return false;
      }
  
      void appliqueInteret() {
        float interet = getSolde() * tauxInteret / 100;
        setSolde(getSolde() + interet);
        cout << "Intérêts appliqués : " << interet << endl;
      }
  };
  
int main(){
   /* 
  CompteBancaire CompteVide;
  CompteBancaire CompteFatima("fatima",5000,"0633445566");
  //tring nom = "0705089400";


  CompteFatima.setTelephone(nom);
  CompteFatima.affiche();
 // CompteVide.affiche();
  /*
  cout<<"//////////////////////////////////////////////////////"<<endl;
  CompteFatima.affiche();
  CompteBancaire *CompteKarim = new CompteBancaire("karim", 300,"0644556677");
  CompteKarim->affiche();
  cout<<"//////////////////////////////////////////////////////"<<endl;

  if(CompteFatima.vermentVers(CompteKarim,2000))
  
          cout<<"verment russi"<<endl;
 else 
      cout<<"pas reussi";
CompteFatima.affiche();
cout<<"//////////////////////////////////////////////////////"<<endl;
CompteKarim->affiche();
delete CompteKarim;

CompteBancaire CompteAli("ali",3500,"0655667788");
CompteAli.setSolde(-5000);
CompteAli.setTitulaire("Hassan");
ompteAli.setTelephone("012");

CompteBancaire *CompteOmar = new CompteBancaire("Omar",6000,"066778899");
CompteOmar->getTitulaire();
CompteOmar->getSolde();
*/
CompteCourant CompteAli("ali",500,"0655667788");
CompteAli.retirer(1500);

CompteEpargne CompteOmar("Omar", 10000, "066778899", 3.5);
CompteOmar.getSolde();
CompteOmar.appliqueInteret();
CompteOmar.retirer(100);


return 0;
}