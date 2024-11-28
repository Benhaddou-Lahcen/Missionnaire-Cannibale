#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main(){

    int n;
    etat etatInitial={0,0,0};etat etatfinal;
    int choix;
    int a, b,c;
    printf("Entrer votre etat finale souhaitee : \n Entrer le nombre du canibal a la cote finale:");
    scanf("%d", &a);
    printf(" Entrer le nombre du missionnaire a la cote finale:");
    scanf("%d", &b);
    printf(" Entrer la position de la barque [cote final (1) cote initiale(0)] :");
    scanf("%d", &c);

    etatfinal.ncanibal=a;
    etatfinal.nmission=b;
    etatfinal.barque=c;

    do {
        printf("\n\nMenu:\n");
        printf("1. Recherche en largeur\n");
        printf("2. Recherche en profondeur\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                    n=RechercheLargeur( etatInitial , etatfinal , genereSuccesseurs);
                break;
            case 2:
                c=Rechercheprofondeur( etatInitial , etatfinal , genereSuccesseursprofond);
                break;
            case 3:
                printf("Programme termine.\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);


        return 0;
}
