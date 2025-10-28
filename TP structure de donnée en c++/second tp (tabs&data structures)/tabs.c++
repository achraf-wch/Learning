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
    Tableau(int n){
        taille=n;
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
        cout<<endl;
    }
   void remplir()
    {
        for(int i = 0;i<taille;i++)
        {
            cout<<"entrer n"<<i+1<<": ";
            cin>>tab[i];
        }
        cout<<endl;
    }
   void permuter(int i,int j)
   {
    cout<<"on permute "<<i<<" et "<<j<<endl;
    if(i>0&&j>>0&&i<taille&&j<taille)
     swap(tab[i],tab[j]);
    else
    cout << "erreur";
    }
void triSelection()
{
    for(int i=0;i<taille;i++)
    {
        int iMin = i;
        for(int j = i+1;j<taille;j++)

        {
            if(tab[j]<tab[i])
            {
             iMin=j;
            }
        }
        if(i!=iMin)
            swap(tab[iMin],tab[i]);
        affiche();
    }
cout<<endl;
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
    cout<<endl;
}
void recherche(int elem)
{
    int gauche= 0;
    int droit = taille-1;
    while(gauche<=droit)
    {
        int milieu= gauche+(droit-gauche)/2;
        if(tab[milieu]==elem){
        cout<<"element trouve "<<milieu;
        return;
        }
        else if(elem>milieu)
        gauche=milieu+1;
        else
           droit=milieu;

    }
    cout<<"not found";
}
};
struct Message{
    string expediteur;
    string contenu;
    Message *precedent;

};
class Messagerie{
private:
    Message *dernierMessage;
public:
     void envoyerMessage(string e,string c)
     {
          Message *nv = new Message;
          nv->contenu = c;
          nv->expediteur=e;
          nv->precedent= dernierMessage;
     }
     void lire()
     {
        cout<<dernierMessage->contenu;
        cout<<dernierMessage->expediteur;
        Message *temp = dernierMessage;
        dernierMessage=dernierMessage->precedent;
        delete temp;
        
     }

};
struct etudiant{
    string nom;
    int note;
    int id;
    etudiant *suivant;

};
struct Personne{
    string nom;
    int ticket;
    Personne *suivant;
};
class FileGare{
    private: 
    Personne *debut;
    Personne *fin;
    public:
    FileGare(){
        debut = NULL;
        fin = NULL:
    }
    ~FileGare(){
        while(debut)
        {
            Personne *temp = debut;
            debut = debut->suivant;
            delete temp;
        }
    }
    void entrer(string nom,int ticket)
    {
        Personne *nouveau = new Personne;
        nouveau->nom = nom;
        nouveau->ticket = ticket;
        fin->suivant = nouveau;
        fin = nouveau;

    }
    void sortir(){
        if(!debut) return;
        else{
            Personne *temp = debut;
            debut = debut->suivant;
            delete temp;
        }
    }
    void afficher(){
        Personne *temp = debut;
        while(temp)
        {
            cout<<"nom: "<<temp->nom<<endl;
            cout<<"ticket: "<<temp->ticket<<endl;
        }

    }
};
class array{
    private: 
    int taille;
    int *tab;
    public:
    array(){
        taille = 0;
        tab= new int[taille];
    }
    ~array(){delete tab}
    void remplir()
    {
        fpr(int i = 0;i<)
    }

};
         




int main()
{
    /*
 int taille;
 cout<<"entrer taille: ";
 cin>>taille;
 Tableau tab(taille);
 tab.remplir();
 tab.affiche();
 int i,j;
 //cout<<"entre i: ";
 //cin>>i;
 //cout<<"enter j:";
 //cin>>j;
 //tab.permuter(i,j);
 //tab.affiche();
 //tab.triSelection();
 //tab.triInsertion();
 int num;
 cout<<"entrer num: ";
 cin>>num;
 if(num)
 tab.recherche(num);
 */



}
