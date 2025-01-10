#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include "jeu.h"
#include "affichage.h"
#include "fichiers.h"

int main()
{
    setlocale(LC_ALL, "fr_FR.UTF-8");
    char pseudo[50];
    int choix;
    Niveau niveau;
    int tentatives_utilisees;
    printf("Entrez votre pseudo: ");
    scanf("%s", &pseudo);
    enregistrer_pseudo(pseudo);
    do {
        afficher_menu();
        scanf("%d",&choix);

        switch(choix){
            case 1: {
                choisir_niveau(&niveau);
                jouer_partie(pseudo, niveau);

            }
            case 2:
                afficher_regles();
                break;
            case 3:
                consulter_archives();
                break;
            case 4:
                printf("Au revoir  %s ! Merci d'avoir participer au jeu\n", pseudo);
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");


        }
    }while(choix !=4);


    return 0;
}
