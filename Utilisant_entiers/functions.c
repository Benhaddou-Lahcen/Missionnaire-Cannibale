
void Insererprecesseur(etat nouveauetat, liste *pliste,noeud *nprecesseur){
    // "nprecesseur": c'est un pointeur sur le noeud parent du notre arbre
    // cette fonction cree un noeud ayant l'etat "nouveauetat" et un precesseur "nprecesseur" et l'insere sur la file "pliste"
    //Dans une pile le suivant est celui qui le suit dans la liste
    liste L1=*pliste;
    noeud *nouveaunoeaud=malloc(sizeof(noeud));//pointeur pour que la variable de type noeud ne soit pas supprimer
    nouveaunoeaud->Etat=nouveauetat;
    nouveaunoeaud->suivant=NULL;
    nouveaunoeaud->precesseur=nprecesseur;
    if (L1.debut==NULL)
    {L1.debut=nouveaunoeaud;
    L1.fin=nouveaunoeaud;}
    else{(L1.fin)->suivant=nouveaunoeaud;
    (L1.fin)=nouveaunoeaud;

    }
    *pliste=L1;
}

void Inserer(etat nouveauetat, liste *pliste){//inserer un noeud sur une file
    noeud *nprecesseur=NULL;
    Insererprecesseur(nouveauetat,pliste,nprecesseur);
}

int Vide(liste listeNoeuds){
return (listeNoeuds.debut==NULL);
}

noeud* Extraire (liste* listenoeuds){// extraire un noeud du file"listenoeus"
    noeud * temp;
    if(listenoeuds->debut== listenoeuds->fin)listenoeuds->fin=NULL;
   temp=(listenoeuds->debut);
   listenoeuds->debut=temp->suivant;

      return temp;
}

int etatSolution (etat etatCourant,etat etatfinal){
    return (etatCourant.ncanibal == etatfinal.ncanibal && etatCourant.nmission == etatfinal.nmission && etatCourant.barque == etatfinal.barque  );}

void genereSuccesseurs(noeud* noeudCourantp) {
void regle1(noeud* noeudCourant){//deplacer deux canibals
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if(3-nbreCanibals+2<=3 && (3-nbreMission>=3-nbreCanibals+2 || 3-nbreMission==0) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission;
                nouveauetat.ncanibal=etatCourant.ncanibal-2;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if(3-nbreCanibals+2<=3 && (3-nbreMission>=3-nbreCanibals+2 || 3-nbreMission==0) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission;
                nouveauetat.ncanibal=etatCourant.ncanibal+2;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}

void regle2(noeud* noeudCourant){//deplacer deux missionnaires
  etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if(3-nbreMission+2<=3 &&(3-nbreMission+2>=3-nbreCanibals && (nbreMission-2>=nbreCanibals || nbreMission-2==0) )){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission-2;
                nouveauetat.ncanibal=etatCourant.ncanibal;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if(3-nbreMission+2<=3 &&(3-nbreMission+2>=3-nbreCanibals && (nbreMission-2>=nbreCanibals || nbreMission-2==0) )){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission+2;
                nouveauetat.ncanibal=etatCourant.ncanibal;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}


void regle3(noeud* noeudCourant){//deplacer un missionnaire et un canibal
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if( 3-nbreMission+1<=3 && 3-nbreMission+1<=3 && (nbreMission-1==0 || (3-nbreMission+1>=3-nbreCanibals+1 && nbreMission-1>=nbreCanibals-1) )){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission-1;
                nouveauetat.ncanibal=etatCourant.ncanibal-1;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if( 3-nbreMission+1<=3 && 3-nbreMission+1<=3 && (nbreMission-1==0 || (3-nbreMission+1>=3-nbreCanibals+1 && nbreMission-1>=nbreCanibals-1) )){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission+1;
                nouveauetat.ncanibal=etatCourant.ncanibal+1;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}

void regle4(noeud* noeudCourant){//deplacer un missionnaire
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if( 3-nbreMission+1<=3 && (nbreMission-1==0 || nbreMission-1>=nbreCanibals) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission-1;
                nouveauetat.ncanibal=etatCourant.ncanibal;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if( 3-nbreMission+1<=3 && (nbreMission-1==0 || nbreMission-1>=nbreCanibals) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission+1;
                nouveauetat.ncanibal=etatCourant.ncanibal;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}

void regle5(noeud* noeudCourant){//deplacer un canibal
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if( 3-nbreCanibals+1<=3 &&(3-nbreMission==0 || 3-nbreMission>=3-nbreCanibals+1) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission;
                nouveauetat.ncanibal=etatCourant.ncanibal-1;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if( 3-nbreCanibals+1<=3 &&(3-nbreMission==0 || 3-nbreMission>=3-nbreCanibals+1) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission;
                nouveauetat.ncanibal=etatCourant.ncanibal+1;
                nouveauetat.barque=(etatCourant.barque+1)%2;
                Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}
regle1(noeudCourantp);
regle2(noeudCourantp);
regle3(noeudCourantp);
regle4(noeudCourantp);
regle5(noeudCourantp);
}

int Appartient (etat etatCourant , liste NoeudsDejaTraites){
noeud* p=NoeudsDejaTraites.debut;
  while(p!=NULL){
    if (p->Etat.nmission==etatCourant.nmission && p->Etat.ncanibal==etatCourant.ncanibal && p->Etat.barque==etatCourant.barque) return 1;
    p=p->suivant;
  }
  return 0;
}

int RechercheLargeur(etat etatInitial ,etat etatfinal , void genereSuccesseurs()){

liste NoeudsDejaTraites;
etat etatCourant;
noeud* noeudCourantp;
listeNoeuds.debut =listeNoeuds.fin =NULL;
Inserer(etatInitial,&listeNoeuds);
NoeudsDejaTraites.debut=NoeudsDejaTraites.fin =NULL;
while(!Vide (listeNoeuds))
      {
         noeudCourantp=Extraire(&listeNoeuds);
         etatCourant=noeudCourantp->Etat;
            n++;


if (etatSolution (etatCourant ,etatfinal))
{
    printf("\nSucess ! arret sur le noeud :(%d,%d,%d)\nNombre de noeuds explores :%d\n",etatCourant.nmission,etatCourant.ncanibal,etatCourant.barque,n);
    afficher(noeudCourantp);//affiche le chemin des preccesseurs depuis la liste NoeudsDejaTraites
    return (0);
}
else if(!Appartient (etatCourant ,NoeudsDejaTraites)){
        genereSuccesseurs(noeudCourantp);//stocke les preccesseur
        Inserer(etatCourant, &NoeudsDejaTraites);//Inserer(noeudCourantp, &NoeudsDejaTraites);
        }

    }
    puts("\nPas de solution");

}

void afficher (noeud* noeudCourantp){
noeud* p=noeudCourantp;
printf("le chemin pour avoir %d canibal ,%d missionaire a la cote finale est comme suit :\n",(p->Etat.ncanibal),p->Etat.nmission);
  while(p!=NULL){
    printf("-(%d,%d,%d)-",(p->Etat.ncanibal),p->Etat.nmission,p->Etat.barque) ;
    p=p->precesseur;
  }
}

void Insererprecesseurprofond(etat nouveauetat, liste *pliste,noeud *nprecesseur){
     // cette fonction cree un noeud ayant l'etat "nouveauetat" et un precesseur "nprecesseur" et l'insere sur la file "pliste"
    //Dans une pile le suivant est celui qui le precede dans la liste
    liste L1=*pliste;
    noeud *nouveaunoeaud=malloc(sizeof(noeud));//pointeur pour que la variable de type noeud ne soit pas supprimer
    nouveaunoeaud->Etat=nouveauetat;
    nouveaunoeaud->suivant=NULL;
    nouveaunoeaud->precesseur=nprecesseur;
    if (L1.fin==NULL)
    {L1.fin=nouveaunoeaud;}
    else{nouveaunoeaud->suivant=(L1.fin);
    (L1.fin)=nouveaunoeaud;
    }
    *pliste=L1;
}

void Insererprofond(etat nouveauetat, liste *pliste){
    noeud *nprecesseur=NULL;
    Insererprecesseurprofond(nouveauetat,pliste,nprecesseur);
}

noeud* Extraireprofond(liste* listenoeuds){
    noeud * temp;
   temp=(listenoeuds->fin);
   listenoeuds->fin=temp->suivant;

      return temp;
}

void genereSuccesseursprofond(noeud* noeudCourantp) {
void regle1(noeud* noeudCourant){//deplacer deux canibals
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if(3-nbreCanibals+2<=3 && (3-nbreMission>=3-nbreCanibals+2 || 3-nbreMission==0) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission;
                nouveauetat.ncanibal=etatCourant.ncanibal-2;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if(3-nbreCanibals+2<=3 && (3-nbreMission>=3-nbreCanibals+2 || 3-nbreMission==0) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission;
                nouveauetat.ncanibal=etatCourant.ncanibal+2;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}

void regle2(noeud* noeudCourant){//deplacer deux missionnaires
  etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if(3-nbreMission+2<=3 &&(3-nbreMission+2>=3-nbreCanibals && (nbreMission-2>=nbreCanibals || nbreMission-2==0) )){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission-2;
                nouveauetat.ncanibal=etatCourant.ncanibal;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if(3-nbreMission+2<=3 &&(3-nbreMission+2>=3-nbreCanibals && (nbreMission-2>=nbreCanibals || nbreMission-2==0) )){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission+2;
                nouveauetat.ncanibal=etatCourant.ncanibal;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}


void regle3(noeud* noeudCourant){//deplacer un missionnaire et un canibal
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if( 3-nbreMission+1<=3 && 3-nbreMission+1<=3 && (nbreMission-1==0 || (3-nbreMission+1>=3-nbreCanibals+1 && nbreMission-1>=nbreCanibals-1) )){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission-1;
                nouveauetat.ncanibal=etatCourant.ncanibal-1;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if( 3-nbreMission+1<=3 && 3-nbreMission+1<=3 && (nbreMission-1==0 || (3-nbreMission+1>=3-nbreCanibals+1 && nbreMission-1>=nbreCanibals-1) )){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission+1;
                nouveauetat.ncanibal=etatCourant.ncanibal+1;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}

void regle4(noeud* noeudCourant){//deplacer un missionnaire
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if( 3-nbreMission+1<=3 && (nbreMission-1==0 || nbreMission-1>=nbreCanibals) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission-1;
                nouveauetat.ncanibal=etatCourant.ncanibal;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if( 3-nbreMission+1<=3 && (nbreMission-1==0 || nbreMission-1>=nbreCanibals) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission+1;
                nouveauetat.ncanibal=etatCourant.ncanibal;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}

void regle5(noeud* noeudCourant){//deplacer un canibal
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.barque==1 ){//barque a la cote finale
            int nbreCanibals=etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=etatCourant.nmission;
            if( 3-nbreCanibals+1<=3 &&(3-nbreMission==0 || 3-nbreMission>=3-nbreCanibals+1) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission;
                nouveauetat.ncanibal=etatCourant.ncanibal-1;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
        if (etatCourant.barque==0 ){//barque a la cote initiale
            int nbreCanibals=3-etatCourant.ncanibal;//nbre des canibals a la cotedu barque
            int nbreMission=3-etatCourant.nmission;
            if( 3-nbreCanibals+1<=3 &&(3-nbreMission==0 || 3-nbreMission>=3-nbreCanibals+1) ){
                etat nouveauetat;
                nouveauetat.nmission=etatCourant.nmission;
                nouveauetat.ncanibal=etatCourant.ncanibal+1;
                nouveauetat.barque=(etatCourant.barque+1)%2;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
            }
    }
}
regle1(noeudCourantp);
regle2(noeudCourantp);
regle3(noeudCourantp);
regle4(noeudCourantp);
regle5(noeudCourantp);
}

int Appartientprofond (etat etatCourant , liste NoeudsDejaTraites){
noeud* p=NoeudsDejaTraites.fin;
  while(p!=NULL){
    if (p->Etat.nmission==etatCourant.nmission && p->Etat.ncanibal==etatCourant.ncanibal && p->Etat.barque==etatCourant.barque) return 1;
    p=p->suivant;
  }
  return 0;
}

int Videprofond(liste listeNoeuds){
return (listeNoeuds.fin==NULL);
}

int Rechercheprofondeur(etat etatInitial ,etat etatfinal , void genereSuccesseursprofond()){
liste NoeudsDejaTraites;
etat etatCourant;
noeud* noeudCourantp;
listeNoeuds.debut =listeNoeuds.fin =NULL;
Insererprofond(etatInitial,&listeNoeuds);
NoeudsDejaTraites.debut=NoeudsDejaTraites.fin =NULL;
while(!Videprofond (listeNoeuds))
      {
         noeudCourantp=Extraireprofond(&listeNoeuds);
         etatCourant=noeudCourantp->Etat;
            n++;
if (etatSolution (etatCourant ,etatfinal))
{
    printf("\nSucess ! arret sur le noeud :(%d,%d,%d)\nNombre de noeuds explores :%d\n",etatCourant.nmission,etatCourant.ncanibal,etatCourant.barque,n);
    afficher(noeudCourantp);//affiche le chemin des preccesseurs depuis la liste NoeudsDejaTraites
    return (0);
}
else if(!Appartientprofond (etatCourant ,NoeudsDejaTraites)){
        genereSuccesseursprofond(noeudCourantp);//stocke les preccesseur
        Insererprofond(etatCourant, &NoeudsDejaTraites);//Inserer(noeudCourantp, &NoeudsDejaTraites);
        }

    }
    puts("\nPas de solution");

}

