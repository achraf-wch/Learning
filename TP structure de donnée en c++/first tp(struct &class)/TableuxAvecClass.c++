#include <iostream>
using namespace std;
class Tableau{
    private:
    int taille;
    int *tab;
    public:
    Tableau(){
        tab = NULL;
        taille = 0;
    }
    Tableau(int nn){
        taille=nn;
         tab = new int[taille];
    }
    ~Tableau(){
        delete tab;
    }
    void affiche()
    {
        for(int i = 0;i<taille;i++)
        {
            cout<<tab[i];
        }
    }
    void remplir()
    {
        for(int i = 0;i<taille;i++)
        {
            cout<<"n"<<i<<": ";
            cin>>tab[i];
        }
     
    }
void permuter(int i,int j)
{
    if(i>0&&j>>0&&i<taille&&j<taille)
     swap(tab[i],tab[j]);
    else 
    cout << "erreur";
}
void triSelection()
{
    for(int i = 0;i<taille;i++)
    {
    int iMin = i;
    for(int j=i+1;j<taille;j++)
    {
       if(tab[j]<tab[i])
       iMin = j;
    }
    if(iMin!=i)
    {
    swap(tab[iMin],tab[i]);
    affiche();
    }
    }
}
void triInsertion()
{
    for(int i=1;i<taille;i++)
    {
        int key=tab[i];
        int j = i-1;
        while(j>=0&&tab[j]>key)
        {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=key;
        affiche();

    }
}
void recherche(int elem)
{
    int gauche= 0;
    int droit = taille-1;
    while(gauche<=droit)
    {
        int milieu= gauche+(droit-gauche/2);
        if(tab[milieu]=elem)
        cout<<"element trouve"<<milieu;
        else if(elem>milieu)
        gauche=milieu+1;
        else 
           droit=milieu;

    }
}
};


int main()
{
    int taille;
    cout<<"entrer taille: ";
    cin>>taille;
 Tableau tab(taille);
 tab.remplir();
 tab.affiche();
 tab.triSelection();
 //tab.triInsertion();
 //tab.recherche(2);
 
}