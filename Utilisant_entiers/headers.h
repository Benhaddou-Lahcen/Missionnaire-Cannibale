#ifndef FONCTIONS_H
#define FONCTIONS_H

typedef struct {
    int ncanibal;//a la cote final
    int nmission;
    int barque;//1 existe a la cote finale 0 si non
} etat;

typedef struct Noeud {
    etat Etat;
    struct Noeud *suivant;
    struct Noeud *precesseur;// precesseur c'est un pointeur sur le noeud parent du notre arbre
} noeud;

typedef struct {
    noeud *debut;
    noeud *fin;
} liste;

int n;
liste listeNoeuds;

//breadth-first search functions
void Insererprecesseur(etat nouveauetat, liste *pliste, noeud *nprecesseur);
void Inserer(etat nouveauetat, liste *pliste);
int Vide(liste listeNoeuds);
noeud* Extraire(liste* listenoeuds);
void genereSuccesseurs(noeud* noeudCourantp);
int Appartient(etat etatCourant, liste NoeudsDejaTraites);
int RechercheLargeur(etat etatInitial, etat etatfinal, void genereSuccesseurs());

//depth-first search functions
void Insererprecesseurprofond(etat nouveauetat, liste *pliste, noeud *nprecesseur);
void Insererprofond(etat nouveauetat, liste *pliste);
noeud* Extraireprofond(liste* listenoeuds);
void genereSuccesseursprofond(noeud* noeudCourantp);
int Appartientprofond(etat etatCourant, liste NoeudsDejaTraites);
int Videprofond(liste listeNoeuds);
int Rechercheprofondeur(etat etatInitial, etat etatfinal, void genereSuccesseursprofond());

int etatSolution(etat etatCourant, etat etatfinal);
void afficher(noeud* noeudCourantp);


#include "functions.c"
#endif /* FONCTIONS_H */
