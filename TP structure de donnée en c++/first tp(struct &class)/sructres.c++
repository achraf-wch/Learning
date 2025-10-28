#include <iostream>
using namespace std;

struct CompteBancaire{
    string titulaire;
    float solde;
    string telephone;
};
void afficherCompte(struct CompteBancaire *c) 
   {
      cout<<"titulaire: "<<c->titulaire<<endl;
      cout<<"solde: "<<c->solde<<endl;
      cout<<"tlephone: "<<c->telephone<<endl;
    }
bool deposer(struct CompteBancaire *c, float montant)
    {
    if(montant>0)
    {
    c->solde+=montant;
    return true;
    }
    else return false;
     }
bool retirer(struct CompteBancaire *c, float montant)
    {
    if(c->solde>montant)
       {
        c->solde-=montant;
        return true;

         }
    return false;
    }
void modifier(struct CompteBancaire *c,string nouveunum)
      {
    c->telephone = nouveunum; } 
int main(){
    CompteBancaire CompteStatique;
    CompteStatique.titulaire = "ahmed";
    CompteStatique.solde = 5000;
    CompteStatique.telephone = "0611223344";
    afficherCompte(&CompteStatique);
    if(deposer(&CompteStatique,1000))
       cout<<"ca marche"<<endl;
    else 
        cout<<"ca marche pas"<<endl;
    if(retirer(&CompteStatique,2000))
        cout<<"ca marche"<<endl;
    else 
        cout<<"ca marche pas"<<endl;
      
    modifier(&CompteStatique,"0622334455");
    afficherCompte(&CompteStatique);
    
    ////////////////////////////////////////////////

    CompteBancaire *CompteDynamique = new CompteBancaire;;
    CompteDynamique->titulaire = "ahmed";
    CompteDynamique->solde = 5000;
    CompteDynamique->telephone = "0611223344";
    afficherCompte(CompteDynamique);
    if(deposer(CompteDynamique,1000))
        cout<<"ca marche"<<endl;
    else 
        cout<<"ca marche pas"<<endl;
    afficherCompte(CompteDynamique);
    if(retirer(CompteDynamique,2000))
        cout<<"ca marche"<<endl;
    else 
        cout<<"ca marche pas"<<endl;
    afficherCompte(CompteDynamique);
    modifier(CompteDynamique,"0622334455");
    afficherCompte(CompteDynamique);
    delete CompteDynamique;
     return 0;
}     
    int main()
    {
        
    }



