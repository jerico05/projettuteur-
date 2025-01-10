#include <stdio.h>
#include "affichage.h"
#include "fichiers.h"


void afficher_menu() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Jouer une partie\n");
    printf("2. Règles\n");
    printf("3. Archives\n");
    printf("4. Quitter\n");
    printf("======================\n");
    printf("Votre choix : ");
}

void afficher_regles() {
    printf("\n=== Règles du jeu ===\n");
    printf("1. L'ordinateur choisit un nombre aléatoire.\n");
    printf("2. Votre objectif est de deviner ce nombre.\n");
    printf("3. Vous recevrez des indices : 'Plus grand' ou 'Plus petit'.\n");
    printf("4. Vous avez un nombre limité de tentatives selon le niveau choisi.\n");
    printf("5. Bonne chance !\n");
    printf("======================\n");
}





