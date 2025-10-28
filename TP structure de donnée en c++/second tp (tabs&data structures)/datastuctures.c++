
#include <iostream>
using namespace std;
struct Produit{
    int id;
    string nom;
    float prix;
    int stock;
    Produit *suivant;

    Produit(int i,string n,float p,int s)
    {
        id = i;
        nom  = n;
        prix = p;
        stock = s;
    }


};
struct Notification{
    int id;
    string produit;
    string date;
    Notification *suivant;
    Notification(int i,string p,string d)
    {
        id = i;
        produit= p;
        date = d;
    }
};
struct Commande{
int id;
string produit;
int qte;
Commande *suivant;
Commande(int i,string p,int q)
{
    id= i;
    produit = p;
    qte = q;
}
};
class GestionProduits{
 private:
     Produit *debut;
     Produit *fin;
     int taille;

 public:
    GestionProduits()
    {
        debut = NULL;
        fin = NULL;
        taille =0;

    }
  ~GestionProduits(){

      while(debut)
      {
          Produit *temp = debut;
          debut=debut->suivant;
          delete temp;
      }
  }
 void afficheProduit()
  {
      Produit *temp = debut;
      while(temp)
      {

        cout<<"id: "<<temp->id<<endl;
        cout<<"nom: "<<temp->nom<<endl;
        cout<<"prix: "<<temp->prix<<endl;
        temp = temp->suivant;



      }
  }
  int rechercheProduit(int id)
  {
      int pos=0;
      Produit *temp = debut;
      while(temp)
      {

    if(temp->id == id)
            return pos;
    temp = temp->suivant;
    pos++;



  }
  return -1;
  }
void ajouteProduit(Produit *p){
    if(!debut)
       {
        debut = fin = p;
       }
    else{
    Produit  *temp = debut;
    Produit *pre = NULL;
    while(temp&&temp->id!=p->id)
    {
        pre = temp;
        temp = temp->suivant;
    }
    if(temp)
    {
        temp->stock+=p->stock;
        //delete temp;
    }
    else if(p->prix <=100)
    {
        p->suivant = debut;
        debut = p;
    }
    else if(p->prix>=1000)
    {
        p->suivant = fin;
        fin= p;
    }


    else {
        Produit *temp = debut;
        Produit *pre = NULL;
        while(temp&&temp->prix<p->prix)
        {
            pre = temp;
            temp = temp->suivant;
        }
        if(!pre)
        {
            p->suivant = debut;
            debut= p;
        }
        else {
            pre->suivant= p;
            p->suivant = temp;
        }
    }}}

void supprimerProduitDebut(){
    if(!debut) return;
    Produit *temp= debut;
    debut = debut->suivant;
    delete temp;
    taille--;


}
void supprimerProduitFin(){
    if(!debut) return;
    if(debut ==fin)
        debut = fin = NULL;
    else
    {
        Produit *temp = debut;
        while(temp->suivant)
        {
            temp = temp->suivant;
        }
        delete fin;
        fin = temp;
        fin->suivant= NULL;
    }
}

void suprrimerProduitId(int id) {
    if (!debut)
        return;
    Produit *temp = debut;
    Produit *prev = NULL;
    if (temp != NULL && temp->id == id) {
        supprimerProduitDebut();
        return;
    }
    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->suivant;
    }
    if (temp == NULL) {
        cout <<" non trouvé." << endl;
        return;
    }
    prev->suivant = temp->suivant;
    delete temp;
}
};
class GestionNotification{
private:
    Notification *debut;
    Notification *sommet;
    int taille;
public:
    GestionNotification()
    {
        debut = NULL;
        sommet = NULL;
        taille = 0;
    }
    ~GestionNotification()
    {
       
        while(debut)
        {
            Notification *temp= debut;
            debut = debut->suivant;
            delete temp;
        
        }
    }
    /*
        ~GestionNotification()
    {
       
        while(sommet)
        {
          depilerNotification{}
        
        }
    }
    */
    
    void afficheNotifiaction()
    {
        Notification *temp = debut;
        while(temp)
        {
            cout<<"id: "<<temp->id;

            cout<<" nom: "<<temp->produit;

            cout<<" date: "<<temp->date<<endl;
            temp=temp->suivant;

        }

    }
    void emplirNotification(Notification *n)
    {
        if(!debut)
        {
            debut = n;
            sommet = n;
        }
      else
       {
        sommet->suivant = n;
        sommet = n;
         }
     taille++;
    }
    void depilerNotification()
    {
        if (!debut) return;
        
        if (debut == sommet) {
            delete debut;
            debut = sommet = NULL;
        } else {
            Notification *temp = debut;
            while (temp->suivant) {
                temp = temp->suivant;
            }
            delete sommet;
            sommet = temp;
            sommet->suivant = NULL;
        }
    
        taille--;
    }
    
    void consulNotification() {
        if (!debut) {
            cout << "Aucune notification disponible." << endl;
            return;
        }

        Notification *temp = debut;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }

        cout << "Notification la plus récente:";
        cout << " id: " << temp->id;
        cout << " produit: " << temp->produit;
        cout << " date: " << temp->date << endl;
    }

    


};
class GestionCommands{
private:
    Commande *debut;
    Commande *fin;
    int taille;
public:
       GestionCommands(){
        fin  = NULL;
        debut = NULL;
        taille = 0;

       }
       ~GestionCommands(){
          defiler();
       }

      void affichecommande()
       {
        Commande *temp = debut;
        while(temp)
        {
            cout<<"id: "<<temp->id;

            cout<<" nom: "<<temp->produit;

            cout<<" qte: "<<temp->qte<<endl;
            temp=temp->suivant;

        }
       }
       void enfiler(Commande *c)
       {
        if(!debut)
            debut = fin = c;
            else{
                fin->suivant=c;
                fin = c;
            }
            taille++;
       }
     Commande* defiler(){

        if(!debut) return 0;
        Commande *temp = debut;
        debut = debut->suivant;
        if(!debut) fin = NULL;

        taille --;
        return temp;

     }
    void consulterCommande() {
        if (!debut) {
            cout << "La file est vide !" << endl;
            return;
        }
         
             cout<< "ID = " << debut->id;
             cout<< "  Produit = " << debut->produit;
             cout<< " qte = " << debut->qte << endl;
    }
    struct livre{
        string titre;
        string auteur;
        int anne;
    };
    class table{
        private: int taille;
        livre *tab;
        public:
        table(int n)
        {
            taille = n;
            tab = new livre[taille] ;
        }
        void ajoute()
        {
            for(int i = 0;i<taille;i++)
            {
                cin>>tab[i].auteur;
            }
        }
    };
    

};

int main()
{
    /*
    Produit *p1 = new Produit(101,"smartphone",3000,10);
    Produit *p2 = new Produit(102,"clavier",420,25);
    Produit *p3 = new Produit(103,"souris",100,33);
    Produit *p4 = new Produit(104,"usb",100,18);
    GestionProduits Liste;
    Liste.ajouteProduit(p1);
    Liste.ajouteProduit(p2);
    Liste.ajouteProduit(p3); 
    Liste.ajouteProduit(p4); //remplir la liste par 4 produits
    Liste.afficheProduit();
    cout<<"///////////////////////////////////////////////////////////////////////////"<<endl;
    cout<<"ona trouvé l'élement dans la position: "<<Liste.rechercheProduit(101)<<endl;
                                      //recherche le produit qu'ont l'id 101
    cout<<"//////////////////////////////////////////////////////////////////////////"<<endl;
    Liste.supprimerProduitDebut();
    Liste. suprrimerProduitId(102);
    Liste.supprimerProduitFin();
    Liste.afficheProduit();// il faut affiche just 2 produit
    cout<<"/////////////////////////////////////////////////////////////////////////";






  Notification *n = new Notification(101,"smartphone","2222222");
    Commande *c = new Commande(101,"smartphone",2);





    delete n;
    delete c;
    
    
   GestionNotification pile;
   Notification *n1 = new Notification(1,"smartphone","2025,03,24' 10:45");
   Notification *n2 = new Notification(2,"clavier","2025,03,25' 10:50");
      Notification *n4 = new Notification(4,"smartphone","2025,03,24' 10:45");
   Notification *n5 = new Notification(5,"clavier","2025,03,25' 10:20");
   cout<<"empiler des notifications: "<<endl;
   pile.emplirNotification(n1);
   pile.emplirNotification(n2);
   cout<<"affichage tout les botification"<<endl;
   pile.afficheNotifiaction();
   cout<<"consulter la notification la plus recente"<<endl;
   pile.consulNotification();
   cout<<"depiler la derniere notificaton"<<endl;
   pile.depilerNotification();
   pile.depilerNotification();
   cout<<"affciher apres depilement"<<endl;
   pile.afficheNotifiaction();
   pile.emplirNotification(n4);
   pile.emplirNotification(n5);
   pile.afficheNotifiaction();
*/
     GestionCommands file;
    Commande *c1 = new Commande(1,"clavier",2);
    Commande *c2 = new Commande(2,"smartphone",1);
    Commande *c3 = new Commande(3,"clavier",3);
    Commande *c4 = new Commande(4,"souris",1);
    cout<<"enfiler des commandes: "<<endl;
    file.enfiler(c1);
    file.enfiler(c2);
    file.enfiler(c3);
    cout<<"liste des commandes en attende"<<endl;
    file.affichecommande();
    cout<<"consulter la commande en tete: "<<endl;
    file.consulterCommande();
    cout<<"defiler la premier commande sans la retirer: "<<endl;
    file.defiler();
    cout<<"liste apres defiler la premiere commande: "<<endl;
    file.affichecommande();

    


    return 0;

}
