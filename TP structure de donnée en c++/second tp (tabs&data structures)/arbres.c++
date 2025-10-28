#include <iostream>
using namespace std;
struct noeud{
    int valeur;
    noeud *parent;
    noeud *gfils;
    noeud *dfils;
};
class arbre{
    private:
         noeud *racine;
         void dele(noeud *n)
         {
            if(!n)
            {
                dele(n->gfils);
                dele(n->dfils);
                delete n;
            }
         }
    public:
    arbre(){
        racine = NULL;
    }
    ~arbre(){
        dele(racine);
    }
    void setracine(noeud *n)
    {
        racine = n;
    }
    void afficher(int v)
    {
        cout<<v;
    }
    void rgd(noeud *n)
    {
        afficher(n->valeur);
        afficher(n->gfils->valeur);
        afficher(n->dfils->valeur);
    }

void grd(noeud *n)
{
    afficher(n->gfils->valeur);
    afficher(n->valeur);
    afficher(n->dfils->valeur);
}
void gdr(noeud *n)
{
    afficher(n->gfils->valeur);
    afficher(n->dfils->valeur);
    afficher(n->valeur);
   
}
void rgd2(noeud *n)
{
  if(!n)
  {
    cout<<n->valeur;
    rgd2(n->gfils);
    rgd2(n->dfils);
  }
}
void gdr2(noeud *n)
{
  if(!n)
  {
    gdr2(n->gfils);
    gdr2(n->dfils);
    cout<<n->valeur;
    }
}
void ajoute(noeud *n)
{
    if(!racine)
    {
        racine = n;
        return;
    }
    else{
        noeud *courant = racine;
        noeud *emp = NULL;
        while(courant)
        {
            emp = courant;
            if(courant->valeur>n->valeur)
            {
                courant = courant->gfils;
            }
            else  
            courant = courant->dfils;   
        }
        if(n->valeur>emp->valeur)
        {
            emp->dfils = n;
        }
        else emp->gfils = n;
    }
}

};
int main()
{
     noeud n6,n3,n1,n2,n4,n5,n8,n7,n9;
     n6.gfils = &n3;
     n6.dfils = &n8;
     n3.parent=&n3;
     n3.gfils=&n1;
     n3.dfils=&n4;
     n1.parent = &n3;
     n1.dfils = &n2;
     n2.parent=&n1;
     n4.parent = &n3;
     arbre abr;
     abr.setracine(&n6);
     abr.gdr(&n6);
}