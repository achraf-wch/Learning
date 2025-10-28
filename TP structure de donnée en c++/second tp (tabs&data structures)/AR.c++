#include <iostream>
using namespace std;

// ==================== STRUCTURE NOEUD ====================
struct Noeud {
    int cle;
    Noeud* parent;
    Noeud* gFils;
    Noeud* dFils;

    Noeud(int valeur) {
        cle = valeur;
        parent = NULL;
        gFils  = NULL;
        dFils  = NULL;
    }
};

// ==================== CLASSE ARBRE ====================
class Arbre {
private:
    Noeud* racine;

    // Methode recursive pour liberer la memoire
    void detruireArbre(Noeud* noeud);

public:
    // ==== Constructeur et destructeur ====
    Arbre(){
        racine=NULL;
    }
    ~Arbre(){
        delete racine;
    }

    // ==== Accesseurs de la racine ====
    void setRacine(Noeud* r){
        racine = r;
    }      // Affecter une racine
    Noeud* getRacine(){
        return racine;
    }          // Obtenir la racine
    void afficherRacine(){
        cout<<"Racine : "<<racine->cle;
    }        // Afficher la cle de la racine

    // ==== Parcours recursifs ====
     // ==== Parcours recursifs du premier ====
    // Prefixe
    void parcourirRGD(Noeud* noeud){
        afficher(noeud->cle);//Racine
        afficher(noeud->gFils->cle);//Gauche
        afficher(noeud->dFils->cle);//Droit
    } 
    // Infixe
    void parcourirGRD(Noeud* noeud){
        afficher(noeud->gFils->cle);//Racine
        afficher(noeud->cle);//Gauche
        afficher(noeud->dFils->cle);//Droit
    }
    // Postfixe
    void parcourirGDR(Noeud* noeud){
        afficher(noeud->gFils->cle);//Gauche
        afficher(noeud->dFils->cle);//Droit
        afficher(noeud->cle);//Racine
    } 
    
    // ==== Parcours recursifs du deuxieme ====
   
    void parcourirRGD1(Noeud* noeud){
        if(noeud == nullptr) return;
        cout<<noeud->cle<<" ";
        parcourirRGD1(noeud->gFils);
        parcourirRGD1(noeud->dFils);
    } 
    
    void parcourirGRD1(Noeud* noeud){
        if(noeud == nullptr) return;
        parcourirGRD1(noeud->gFils);
        cout<<noeud->cle<<" ";
        parcourirGRD1(noeud->dFils);
    }
   
    void parcourirGDR1(Noeud* noeud){
        if(noeud == nullptr) return;
        parcourirGDR1(noeud->gFils);
        parcourirGDR1(noeud->dFils);
        cout<<noeud->cle<<" ";
        } 

    // ==== Fonctions principales ====
     void ajouterNoeud(Noeud* new_noeud) {
        if (racine == nullptr) {
            racine = new_noeud;
            return;
        }

        Noeud* courant = racine;
        Noeud* emplacement = nullptr;

        while (courant != nullptr) {
            emplacement = courant;
            if (new_noeud->cle < courant->cle) {
                courant = courant->gFils;
            } else {
                courant = courant->dFils;
            }
        }
        new_noeud->parent=emplacement;
        if (new_noeud->cle < emplacement->cle) {
            emplacement->gFils = new_noeud;
        } else {
            emplacement->dFils = new_noeud;
        }
    }
    Noeud* rechercher(int valeur);
    void supprimerNoeud(Noeud* cible);
    void afficher(int cle){
        cout<<cle<<" ";
    }

    // ==== Fonctions supplementaires ====
    Noeud* feuilleDroiteIterative();              // Derniere feuille droite (iteratif)
    Noeud* feuilleDroiteRecursive(Noeud* noeud);  // Derniere feuille droite (recursif)
    int degre(Noeud* noeud){
        int d=0;
        if(noeud->gFils!=NULL)  d++;
        if(noeud->dFils!=NULL)  d++;
        return d;
    }                    // Nombre de fils du noeud
};


// ==================== FONCTION MAIN ====================

int main() {
    //code 1ere sous arbre
    Arbre abr , abr1 , abr2;
    Noeud* noeud11=new Noeud(11);
    Noeud* noeud7=new Noeud(7);
    Noeud* noeud20=new Noeud(20);
    Noeud* noeud17=new Noeud(17);
    Noeud* noeud23=new Noeud(23);
    Noeud* noeud19=new Noeud(19);
    Noeud* noeud3=new Noeud(3);
    Noeud* noeud28=new Noeud(28);
    Noeud* noeud2=new Noeud(2);
    noeud11->gFils=noeud7;
    noeud11->dFils=noeud20;
    noeud7->parent=noeud11;
    noeud20->parent=noeud11;
    abr.setRacine(noeud11);
    
    Noeud* noeuds[10];
    for(int i=0 ; i<10 ; i++){
        
    }
    
    cout<<"le parcour de 1ere sous arbre est : "<<endl;
    cout<<"RGD : ";
    abr.parcourirRGD(noeud11);
    cout<<endl;
    cout<<"GRD : ";
    abr.parcourirGRD(noeud11);
    cout<<endl;
    cout<<"GDR : ";
    abr.parcourirGDR(noeud11);
    cout<<endl;
    
    //code 2eme sous arbre
    Noeud* noeud9=new Noeud(9);
    Noeud* noeud8=new Noeud(8);
    Noeud* noeud10=new Noeud(10);
    noeud9->gFils=noeud8;
    noeud9->dFils=noeud10;
    noeud8->parent=noeud9;
    noeud10->parent=noeud9;
    abr1.setRacine(noeud9);
    
    cout<<"le parcour de 2eme sous arbre est : "<<endl;
    cout<<"RGD : ";
    abr1.parcourirRGD(noeud9);
    cout<<endl;
    cout<<"GRD : ";
    abr1.parcourirGRD(noeud9);
    cout<<endl;
    cout<<"GDR : ";
    abr1.parcourirGDR(noeud9);
    cout<<endl;
    
    //TP3 : l'arbre complet
    
    noeud7->dFils=noeud9;
    noeud9->parent=noeud7;
    cout<<"le parcours de l'arbre est : "<<endl;
    cout<<"RGD : ";
    abr.parcourirRGD1(noeud11);
    cout<<endl;
    cout<<"GRD : ";
    abr.parcourirGRD1(noeud11);
    cout<<endl;
    cout<<"GDR : ";
    abr.parcourirGDR1(noeud11);
    cout<<endl;
    
    //TP04 : Ajout de noeuds
    abr.ajouterNoeud(noeud17);
    abr.ajouterNoeud(noeud23);
    abr.ajouterNoeud(noeud19);
    abr.ajouterNoeud(noeud3);
    abr.ajouterNoeud(noeud28);
    abr.ajouterNoeud(noeud2);
    cout<<"le parcours de l'arbre complet est : "<<endl;
    cout<<"RGD : ";
    abr.parcourirRGD1(noeud11);
    cout<<endl;
    cout<<"GRD : ";
    abr.parcourirGRD1(noeud11);
    cout<<endl;
    cout<<"GDR : ";
    abr.parcourirGDR1(noeud11);
    cout<<endl;
    
    //TP05 : Implementation d'un arbre
    
    
    




    // // Declaration de la liste de valeurs à inserer
    // int Liste[] = {11, 7, 20, 9, 8, 10, 17, 23, 19, 3, 28, 2};
    
    // // Creation d'un tableau de pointeurs vers Noeud
    // Noeud* N[12];
    // for (int i = 0; i < 12; ++i) {
    //     N[i] = new Noeud(Liste[i]);
    // }

    // // Creation des arbres
    // Arbre abr, abr1, abr2;

    // // Affichage des racines
    // cout << "--- Verification des racines ---" << endl;
    // cout << "abr : "; abr1.afficherRacine();
    // cout << "abr1 : "; abr2.afficherRacine();

    // // Construction automatique de l arbre principal "abr"
    //  cout << "--- Construction de l'arbre abr ---" << endl;
    // for (int i = 6; i < 12; ++i) {
    //     abr.ajouterNoeud(N[i]);
    // }

    // // Parcours pour verification
    //  cout << "Parcours prefixe (RGD) : ";
    // abr.parcourirRGD(abr.getRacine());

    //  cout << "Parcours infixe (GRD) : ";
    // abr.parcourirGRD(abr.getRacine());

    //  cout << "Parcours postfixe (GDR) : ";
    // abr.parcourirGDR(abr.getRacine());

    // // Recherche noeud
    //   cout << "--- Recherche du noeud 17 ---" << endl;
    // Noeud* cherche = abr.rechercher(17);
    // if (cherche)
    //     cout << "Non trouve la cle : " << cherche->cle << endl;
    // else
    //     cout << "Non trouve." << endl;

    // // Affichage de la dernire  feuille droite
    //  cout << "--- Derniere feuille droite (iteratif) ---" << endl;
    // Noeud* feuille = abr.feuilleDroiteIterative();
    // if (feuille)
    //     cout << "Derniere feuille droite : " << feuille->cle << endl;

    // // Calcul du degre d un noeud
    //  cout << "--- Degre du noeud 17 ---" << endl;
    // if (cherche)
    //     cout << "Degre de 17 = " << abr.degre(cherche) << endl;

    // // Suppression du noeud 17
    //  cout << "--- Suppression du noeud 17 ---" << endl;
    // if (cherche)
    //     abr.supprimerNoeud(cherche);

    // // Verification apres suppression
    //  cout << "Parcours infixe (GRD) apres suppression : ";
    // abr.parcourirGRD(abr.getRacine());

    //   cout << "Programme termine." << endl;
    return 0;
}